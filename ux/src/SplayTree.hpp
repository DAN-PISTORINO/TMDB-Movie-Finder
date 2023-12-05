#pragma once

#define SPLAYTREE_HPP
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Node_Sp {
    int year;
    string movie;
    string category;
    string movieID;
    Node_Sp* left;
    Node_Sp* right;
    Node_Sp(int year, string movie, string category, string movieID) : year(year), movie(movie), category(category), movieID(movieID), left(nullptr), right(nullptr) {}
    ~Node_Sp() {
        left = nullptr;
        right = nullptr;
        delete left;
        delete right;
    }
};

class SplayTree{
private:
    Node_Sp* root = nullptr;
    Node_Sp* insertHelper(Node_Sp* &head, int &year, string &movie, string &category, string &movieID);
    Node_Sp* removeHelper(Node_Sp* &head, string &movieID);
    Node_Sp* rightRotate(Node_Sp* &head);
    Node_Sp* leftRotate(Node_Sp* &head);
    Node_Sp* splay(Node_Sp* &head, string &movieID);

    public:
        void insert(int &year, string &movie, string &category, string &movieID);
        void removeNode(string &movieID);
        void search(vector<Node_Sp*> &movies, string &category);
};