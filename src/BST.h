#pragma once
#include <string>
using std::string;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node() { }

    Node(const int& k) : key(k), left(nullptr), right(nullptr) { }
};

class BST {
private:
    static Node* root;

    void rDel(Node*& subNode, Node*& delNode);
    string r_PreOrderTraversal(const Node* anode, string& output) const;
    string r_InOrderTraversal(const Node* anode, string& output) const;
    string r_PostOrderTraversal(const Node* anode, string& output) const;

public:
    int rAdd(const int& key, Node*& r = root); // recursive

    int add(const int &key); // non-recursive
    
    int rDeleteNode(const int& key, Node*& anode = root);

    Node* rFind(const int& key, Node* anode = root) const;

    Node* find(const int& key, Node* anode = root) const;

    int getHeight(const Node* anode = root) const;

    // NLR
    string rPreOrderTraversal(const Node* anode = root) const;

    string preOrderTraversal(Node* anode = root) const;

    // LNR
    string rInOrderTraversal(const Node* anode = root) const;

    // LRN
    string rPostOrderTraversal(const Node* anode = root) const;

    string breadthTraversal(Node* anode = root) const;

    void clear();

    bool isEmpty() const;
};
