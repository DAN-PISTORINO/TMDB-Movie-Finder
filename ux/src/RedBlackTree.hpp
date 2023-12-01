#pragma once

#define REDBLACKTREE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "Movie.hpp"


using namespace std;

struct Node {
    int year;
    string movie;
    string actor;
    string category;
    Node* left;
    Node* right;
    Node* parent;
    bool isRed;
    Node(int year, string movie, string actor, string category) :
        year(year), movie(movie), actor(actor), category(category),
        isRed(true), left(nullptr), right(nullptr), parent(nullptr) 
        {;}
    ~Node() {
        left = nullptr;
        right = nullptr;
        delete left;
        delete right;
    }
};

class RedBlackTree{
    Node* root = nullptr;
    Node* insertHelper(Node* &head, int &year, string &movie, string &actor, string &category);
    Node* removeHelper(Node* &head, int &year, string &movie, string &actor, string &category);
    void balance_tree(Node* &head);
    void leftRotate(Node* &head);
    void rightRotate(Node* &head);
    void balanceTree(Node* &head); 
    Node* findSuccessor(Node* node);
    void searchHelper(Node* head, vector<string> &movies, string &category);
public:
    void insert(int &year, string &movie, string &actor, string &category);
    void removeNode(int &year, string &movie, string &actor, string &category);
    void search(vector<string> &movies, string &category);
};
