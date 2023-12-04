#pragma once
#pragma comment(linker, "/STACK:4000000")

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
    string category;
    string movieID;
    Node* left;
    Node* right;
    Node(int year, string movie, string category, string movieID) : year(year), movie(movie), category(category),movieID(movieID),left(nullptr), right(nullptr){}
    ~Node() {
        left = nullptr;
        right = nullptr;
        delete left;
        delete right;
    }
};

class SplayTree{
        Node* root = nullptr;
        Node* insertHelper(Node* &head, int &year, string &movie, string &category, string &movieID);
        Node* removeHelper(Node* &head, string &movieID);
        void searchHelper(Node* &head, vector<Node*>& movies, string &category);
        Node* rightRotate(Node* &head);
        Node* leftRotate(Node* &head);
        Node* splay(Node* &head, string &movieID);

        public:
            void insert(int &year, string &movie, string &category, string &movieID);
            void removeNode(string &movieID);
            void search(vector<Node*> &movies, string &category);

};