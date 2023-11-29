#include "SplayTree.hpp"


void SplayTree::insert(int &year, string &movie, string &actor, string &category, string &movieID) {
    this->root = insertHelper(this->root, year, movie, actor, category, movieID);
}

//O(n)
//Insert nodes into the tree by movieID
Node* SplayTree::insertHelper(Node* &head, int &year, string &movie, string &actor, string &category, string &movieID) {
    if (head == nullptr) {
        return new Node(year, movie, actor, category, movieID);
    }

    head = splay(root, movieID);

    if (head->movieID == movieID) {
        return root;
    }

    Node* newnode = new Node(year, movie, actor, category, movieID);

    if (head->movieID > movieID) {
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

//O(1) 
Node* SplayTree::rightRotate(Node* &head) {
    Node* newhead = head->left;
    head->left = newhead->right;
    newhead->right = head;
    return newhead;
}

//O(1) 
Node* SplayTree::leftRotate(Node* &head) {
    Node* newhead = head->right;
    head->right = newhead->left;
    newhead->left = head;
    return newhead;
}

//O(n)
Node* SplayTree::splay(Node* &head, string &movieID) {
    //If we found a movie with the ID we are looking for or the tree is empty return the head
    if (head == nullptr || head->movieID == movieID) {
        return head;
    }

    //If there is a movie with the ID we are looking for in the left subtree
    if (movieID < head->movieID) {
        if (head->left == nullptr) 
            return head;
    
        if (movieID < head->left->movieID) {
            head->left->left = splay(head->left->left, movieID);
            head = rightRotate(head);
        } 

        else if (movieID > head->left->movieID) {
            head->left->right = splay(head->left->right, movieID);
            if (head->left->right != nullptr) 
                head->left = leftRotate(head->left);   
        }

        return (head->left == nullptr) ? head : rightRotate(head);

    } 
    //If the movie with the ID we are looking for is in the right subtree 
    else {
        if (head->right == nullptr) 
            return head;

        if (movieID < head->right->movieID) {
            head->right->left = splay(head->right->left, movieID);
            if (head->right->left != nullptr) 
                head->right = rightRotate(head->right);
        }

        else if (movieID > head->right->movieID) {
            head->right->right = splay(head->right->right, movieID);
            head = leftRotate(head);
        }

        return (head->right == nullptr) ? head : leftRotate(head);
    }
}
//O(n)
//This function will iterate through the tree and find all the movies with the same category
 void SplayTree::search(vector<Node*>& movies, string &category) {
    queue<Node*> similarMovies;
    similarMovies.push(this->root);
    while (!similarMovies.empty()) {
        Node* temp = similarMovies.front();
        similarMovies.pop();
        if (temp->category == category) {
            movies.push_back(temp);
        }
        if (temp->left != nullptr) {
            similarMovies.push(temp);
        }
        if (temp->right != nullptr) {
            similarMovies.push(temp);
        }
    }
}

//Funcion to remove a node from the tree
void SplayTree::removeNode(string &movieID) {
    this->root = removeHelper(this->root, movieID);
}

//O(n)
//Function to remove a node from the tree
Node* SplayTree::removeHelper(Node* &head, string &movieID) {
    //If theres no node passed
    if (head == nullptr) {
        return nullptr;
    }

    //Bring the node we are looking for to the top
    head = splay(root, movieID);

    //If the node does not exist, just ignore it
    if (head->movieID != movieID) {
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
        head = splay(head->left, movieID);
        head->right = temp->right;
        delete temp;
        return head;
    }
}