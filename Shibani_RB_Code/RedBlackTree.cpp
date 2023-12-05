#include "RedBlackTree.hpp"

void RedBlackTree::insert(int &year, string &movie, string &category, string &movieID) {
    RB_Node* insertedN = insertHelper(this->root, year, movie, category, movieID);
    if(insertedN != nullptr) {
        balanceTree(insertedN);
    }

    this->root->isRed = false;
}

//O(log(n))
RB_Node* RedBlackTree::insertHelper(RB_Node* &head, int &year, string &movie, string &category, string &movieID) {
    //If the head is null, create a new node and return it
    if (head == nullptr) {
        head = new RB_Node(year, movie, category, movieID);
        return head;
    }

    //If the current year is less or  the current year is the same but the movie is less than the current movie, go left
    else if (movieID < head->movieID) {
        RB_Node* insertedN = insertHelper(head->left, year, movie, category, movieID);
        if(head->left != nullptr)
            head->left->parent = head;
        return insertedN;
    } 

    //If the current year is greater or the current year is the same but the movie is greater than the current movie, go right
    else{
        RB_Node* insertedN = insertHelper(head->right, year, movie, category, movieID);
        if(head->right != nullptr)
            head->right->parent = head;
        return insertedN;
    }
}
//O(1) 
// Rotateleft 
void RedBlackTree::leftRotate(RB_Node* &head) {
    RB_Node* newHead = head->right;
    head->right = newHead->left;
    if (newHead->left != nullptr) 
        newHead->left->parent = head;
    
    newHead->parent = head->parent;
    if (head->parent == nullptr) 
        this->root = newHead;
    
    else if (head == head->parent->left) 
        head->parent->left = newHead;
     
    else 
        head->parent->right = newHead;
    
    newHead->left = head;
    head->parent = newHead;
}

//O(1) 
// Rotate right
void RedBlackTree::rightRotate(RB_Node* &head) {
    RB_Node* newHead = head->left;
    head->left = newHead->right;

    if (newHead->right != nullptr)
        newHead->right->parent = head;
    
    newHead->parent = head->parent;
    if (head->parent == nullptr) 
        root = newHead;
    
    else if (head == head->parent->left) 
        head->parent->left = newHead;
    
    else 
        head->parent->right = newHead;
    
    newHead->right = head;
    head->parent = newHead;
}

//O(1) since its rotations
//Rebalances the red black tree when any of the rules are broken
void RedBlackTree::balanceTree(RB_Node* &head) {

    //Balance the tree until the head is black or the root
    while (head->parent != nullptr && head->parent->parent != nullptr && head->parent->isRed) {
        RB_Node* parent = head->parent;
        RB_Node* grandparent = head->parent->parent;

        if (parent == grandparent->left) {
            RB_Node* uncle = grandparent->right;

            //If the uncle is Red
            if (uncle != nullptr && uncle->isRed) {
                parent->isRed = false;
                uncle->isRed = false;
                grandparent->isRed = true;
                head = grandparent;
            } 

            //If the uncle is black
            else {
                if (head == parent->right) {
                    head = parent;
                    leftRotate(head);
                    parent = head->parent;
                } 

                if(parent) {
                    parent->isRed = false;
                    grandparent->isRed = true;
                    rightRotate(grandparent);
                }

            }
        } 
        else {
            RB_Node* uncle = grandparent->left;

            //If the uncle is red
            if (uncle != nullptr && uncle->isRed) {
                parent->isRed = false;
                uncle->isRed = false;
                grandparent->isRed = true;
                head = grandparent;
            } 

            //If the uncle is black
            else {
                if (head == parent->left) {
                    head = parent;
                    rightRotate(head);
                    parent = head->parent;
                }

                //Recolor and do left rotation
                if(parent) {
                    parent->isRed = false;
                    grandparent->isRed = true;
                    leftRotate(grandparent);
                }

            }
        }
    }

    //Make sure the root is black after balancing
    root->isRed = false;
}

void RedBlackTree::removeNode(int &year, string &movie, string &category, string &movieID) {
    this->root = removeHelper(this->root, year, movie, category, movieID);
    if (this->root != nullptr) {
        this->root->isRed = false; // Ensures root is black after deletion
    }
}

//O(log(n))
RB_Node* RedBlackTree::removeHelper(RB_Node* &head, int &year, string &movie, string &category, string &movieID) {
    //If the head is empty then return null
    if (head == nullptr) {
        return nullptr;
    }

    if (year < head->year || (year == head->year && movie < head->movie)) {
        head->left = removeHelper(head->left, year, movie, category, movieID);
    } 

    else if (year > head->year || (year == head->year && movie > head->movie)) {
        head->right = removeHelper(head->right, year, movie, category, movieID);
    } 

    else {
        // Node to be removed found
        if (head->left == nullptr || head->right == nullptr) {
            RB_Node* temp = (head->left != nullptr) ? head->left : head->right;

            // No child
            if (temp == nullptr) {
                temp = head;
                head = nullptr;
            } 
            // Node with one child
            else {
                *head = *temp; // Copy the contents of the non-null child
            }

            delete temp;
        } 
        //If 2 children
        else {
            //Finds inorder successor of the node to be removed
            RB_Node* successor = findSuccessor(head);
            head->year = successor->year;
            head->movie = successor->movie;
            head->category = successor->category;

            // Recursively remove the successor node
            head->right = removeHelper(head->right, successor->year, successor->movie, successor->category, successor->movieID);
        }
    }

    // Ensures the tree is balanced after deletion
    balanceTree(head);

    return head;
}
//O(log(n)) 
//This function finds the successor of the node that is being removed
RB_Node* RedBlackTree::findSuccessor(RB_Node* node) {
    node = node->right;
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}
//O(n)
//This function finds the movies that match the category and adds them to the vector to be returned
void RedBlackTree::searchHelper(RB_Node* head, vector<RB_Node*> &movies, string &category) {

    if (head == nullptr) {
        return;
    }

    searchHelper(head->left, movies, category);

    if (head->category == category) {
        movies.push_back(head);
    }

    searchHelper(head->right, movies, category);
}

// Search function implementation
void RedBlackTree::search(vector<RB_Node*> &movies, string &category) {
    movies.clear(); //Makes sure the vector's empty
    //Populate the vector with the movies that match the category
    searchHelper(this->root, movies, category);

}