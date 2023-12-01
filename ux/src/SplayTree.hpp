#pragma once

#define SPLAYTREE_HPP
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>


using namespace std;

struct Node {
    int year;
    string movie;
    string actor;
    string category;
    Node* left;
    Node* right;
    Node(int year, string movie, string actor, string category) : year(year), movie(movie), actor(actor), category(category),left(nullptr), right(nullptr){}
    ~Node() {
        left = nullptr;
        right = nullptr;
        delete left;
        delete right;
    }
};

class SplayTree{
        Node* root = nullptr;
        Node* insertHelper(Node* &head, int &year, string &movie, string &actor, string &category);
        Node* removeHelper(Node* &head, int &year, string &movie, string &actor, string &category);
        Node* rightRotate(Node* &head);
        Node* leftRotate(Node* &head);
        Node* splay(Node* &head, string &category);

        public:
            void insert(int &year, string &movie, string &actor, string &category);
            void removeNode(int &year, string &movie, string &actor, string &category);
            void search(vector<string> &movies, string &category);

};