#pragma once

#define REDBLACKTREE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

struct Node {
    int year;
    string movie;
    string actor;
    string category;
    string movieID;
    Node* left;
    Node* right;
    Node* parent;
    bool isRed;
    Node(int year, string movie, string actor, string category, string movieID) : year(year), movie(movie), actor(actor), category(category), movieID(movieID),isRed(true),left(nullptr), right(nullptr), parent(nullptr){}
    ~Node() {
        left = nullptr;
        right = nullptr;
        delete left;
        delete right;
    }
};

class RedBlackTree{
        Node* root = nullptr;
        Node* insertHelper(Node* &head, int &year, string &movie, string &actor, string &category, string &movieID);
        Node* removeHelper(Node* &head, int &year, string &movie, string &actor, string &category, string &movieID);
        Node* balance_tree(Node* &head);
        void leftRotate(Node* &head);
        void rightRotate(Node* &head);
        void balanceTree(Node* &head); 
        Node* findSuccessor(Node* node);
        void searchHelper(Node* head, vector<Node*> &movies, string &category);
    public:
        void insert(int &year, string &movie, string &actor, string &category, string &movieID);
        void removeNode(int &year, string &movie, string &actor, string &category, string &movieID);
        void search(vector<Node*> &movies, string &category);
};
