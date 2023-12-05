#pragma once

#define REDBLACKTREE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

struct RB_Node {
    int year;
    string movie;
    string category;
    string movieID;
    RB_Node* left;
    RB_Node* right;
    RB_Node* parent;
    bool isRed;
    RB_Node(int year, string movie, string category, string movieID) : year(year), movie(movie), category(category), movieID(movieID),isRed(true),left(nullptr), right(nullptr), parent(nullptr){}
    ~RB_Node() {
        left = nullptr;
        right = nullptr;
        delete left;
        delete right;
    }
};

class RedBlackTree{
        RB_Node* root = nullptr;
        RB_Node* insertHelper(RB_Node* &head, int &year, string &movie, string &category, string &movieID);
        RB_Node* removeHelper(RB_Node* &head, int &year, string &movie, string &category, string &movieID);
        RB_Node* balance_tree(RB_Node* &head);
        void leftRotate(RB_Node* &head);
        void rightRotate(RB_Node* &head);
        void balanceTree(RB_Node* &head);
        RB_Node* findSuccessor(RB_Node* node);
        void searchHelper(RB_Node* head, vector<RB_Node*> &movies, string &category);
    public:
        void insert(int &year, string &movie, string &category, string &movieID);
        void removeNode(int &year, string &movie, string &category, string &movieID);
        void search(vector<RB_Node*> &movies, string &category);
};
