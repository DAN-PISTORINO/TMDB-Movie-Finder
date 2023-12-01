#include "SplayTree.hpp"


void SplayTree::insert(int &year, string &movie, string &actor, string &category) {
    this->root = insertHelper(this->root, year, movie, actor, category);
}

//Insert nodes into the tree by category
Node* SplayTree::insertHelper(Node* &head, int &year, string &movie, string &actor, string &category) {
    if (head == nullptr) {
        return new Node(year, movie, actor, category);
    }

    head = splay(root, movie);

    if (head->movie == movie) {
        return root;
    }

    Node* newnode = new Node(year, movie, actor, category);

    if (head->movie > movie) {
        newnode->right = root;
        newnode->left = root->left;
        root->left = nullptr;
    } 
    else {
        newnode->left = root;
        newnode->right = root->right;
        root->right = nullptr;
    }

    return newnode;
}

Node* SplayTree::rightRotate(Node* &head) {
    Node* newhead = head->left;
    head->left = newhead->right;
    newhead->right = head;
    return newhead;
}

Node* SplayTree::leftRotate(Node* &head) {
    Node* newhead = head->right;
    head->right = newhead->left;
    newhead->left = head;
    return newhead;
}

Node* SplayTree::splay(Node* &head, string &movie) {
    //If we found a movie with the category we are looking for or the tree is empty return the head
    if (head == nullptr || head->movie == movie) {
        return head;
    }

    //If there is a movie with the category we are looking for in the left subtree
    if (movie < head->movie) {
        if (head->left == nullptr) 
            return head;
    
        if (movie < head->left->movie) {
            head->left->left = splay(head->left->left, movie);
            head = rightRotate(head);
        } 

        else if (movie > head->left->movie) {
            head->left->right = splay(head->left->right, movie);
            if (head->left->right != nullptr) 
                head->left = leftRotate(head->left);   
        }

        return (head->left == nullptr) ? head : rightRotate(head);

    } 
    //If the movie with the category we are looking for is in the right subtree 
    else {
        if (head->right == nullptr) 
            return head;

        if (movie < head->right->movie) {
            head->right->left = splay(head->right->left, movie);
            if (head->right->left != nullptr) 
                head->right = rightRotate(head->right);
        }

        else if (movie > head->right->movie) {
            head->right->right = splay(head->right->right, movie);
            head = leftRotate(head);
        }

        return (head->right == nullptr) ? head : leftRotate(head);
    }
}

 void SplayTree::search(vector<string>& movies, string &category) {
    //Splay the tree to put a movie with the category we are looking for at the top
    this->root = splay(this->root, category);

    Node* current = this->root;

    //Check the left subtree for movies with the category
    while (current != nullptr) {
        if (current->category == category) 
            movies.push_back(current->movie);

        current = current->left;
    }

    // Reset to the root to check the right subtree
    this->root = splay(this->root, category);
    current = this->root->right;

    //Check the right subtree for movies with the category
    while (current != nullptr) {
        if (current->category == category) 
            movies.push_back(current->movie);
        
        current = current->right;
    }
}

//Funcion to remove a node from the tree
void SplayTree::removeNode(int &year, string &movie, string &actor, string &category) {
    this->root = removeHelper(this->root, year, movie, actor, category);
}

Node* SplayTree::removeHelper(Node* &head, int &year, string &movie, string &actor, string &category) {
    //If theres no node passed
    if (head == nullptr) {
        return nullptr;
    }

    //Bring the node we are looking for to the top
    head = splay(root, movie);

    //If the node does not exist, just ignore it
    if (head->movie != movie) {
        return head; // Node not found
    }

    //If the node exists, delete it
    Node* temp;
    if (head->left == nullptr) {
        temp = head->right;
        delete head;
        return temp;
    }
    else {
        temp = head;
        head = splay(head->left, movie);
        head->right = temp->right;
        delete temp;
        return head;
    }
}