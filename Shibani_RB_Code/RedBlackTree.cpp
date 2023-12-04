#include "RedBlackTree.hpp"

void RedBlackTree::insert(int &year, string &movie, string &category, string &movieID) {
    this->root = insertHelper(this->root, year, movie, category, movieID);
    this->root->isRed = false;
}

//O(log(n))
Node* RedBlackTree::insertHelper(Node* &head, int &year, string &movie, string &category, string &movieID) {
    //If the head is null, create a new node and return it
    if (head == nullptr) {
        head = new Node(year, movie, category, movieID);
        if(head != root)
            head->isRed = true;
        return head;
    }

    //If the current year is less or  the current year is the same but the movie is less than the current movie, go left
    else if (movieID < head->movieID) {
        head->left = insertHelper(head->left, year, movie, category, movieID);
        head->left->parent = head;
        balanceTree(head->left);
    } 

    //If the current year is greater or the current year is the same but the movie is greater than the current movie, go right
    else{
        head->right = insertHelper(head->right, year, movie, category, movieID);
        head->right->parent = head;
        balanceTree(head->right);
    }

    //Ensure that the tree is balanced


    return head;
}
//O(1) 
// Rotateleft 
void RedBlackTree::leftRotate(Node* &head) {
    Node* newHead = head->right;
    head->right = newHead->left;
    if (newHead->left != nullptr) 
        newHead->left->parent = head;
    
    newHead->parent = head->parent;
    if (head->parent == nullptr) 
        root = newHead;
    
    else if (head == head->parent->left) 
        head->parent->left = newHead;
     
    else 
        head->parent->right = newHead;
    
    newHead->left = head;
    head->parent = newHead;
}

//O(1) 
// Rotate right
void RedBlackTree::rightRotate(Node* &head) {
    Node* newHead = head->left;
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
void RedBlackTree::balanceTree(Node* &head) {

    //Balance the tree until the head is black or the root
    while (head->parent->parent != root && head->parent->isRed) {
        Node* parent = head->parent;
        Node* grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            //If the uncle is Red
            if (uncle != nullptr && uncle->isRed) {
                parent->isRed = false;
                uncle->isRed = false;
                grandparent->isRed = true;
                //head = head->parent->parent;
            } 

            //If the uncle is black
            else {
                if (head == parent->right) {
                    head = parent;
                    leftRotate(head);
                    parent = head->parent;
                } 

                //Recolor and do right rotation
                parent->isRed = false;
                grandparent->isRed = true;
                rightRotate(grandparent);
            }
        } 
        else {
            Node* uncle = grandparent->left;

            //If the uncle is red
            if (uncle != nullptr && uncle->isRed) {
                parent->isRed = false;
                uncle->isRed = false;
                grandparent->isRed = true;
                //head = grandparent;
            } 

            //If the uncle is black
            else {
                if (head == parent->left) {
                    head = parent;
                    rightRotate(head);
                    parent = head->parent;
                }

                //Recolor and do left rotation
                parent->isRed = false;
                grandparent->isRed = true;
                leftRotate(grandparent);
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
Node* RedBlackTree::removeHelper(Node* &head, int &year, string &movie, string &category, string &movieID) {
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
            Node* temp = (head->left != nullptr) ? head->left : head->right;

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
            Node* successor = findSuccessor(head);
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
Node* RedBlackTree::findSuccessor(Node* node) {
    node = node->right;
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}
//O(n)
//This function finds the movies that match the category and adds them to the vector to be returned
void RedBlackTree::searchHelper(Node* head, vector<Node*> &movies, string &category) {

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
void RedBlackTree::search(vector<Node*> &movies, string &category) {
    movies.clear(); //Makes sure the vector's empty
    //Populate the vector with the movies that match the category
    searchHelper(this->root, movies, category);

}