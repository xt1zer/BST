#include "BST.h"
#include <stack>
#include <queue>

Node* BST::root;

void BST::rDel(Node*& subNode, Node*& delNode) {
    if (subNode->right)
        rDel(subNode->right, delNode);
    else {
        delNode->key = subNode->key;
        delNode = subNode;
        subNode = subNode->left;
        delete delNode;
    }
}

int BST::rAdd(const int& key, Node*& r /* = root */) { // recursive
    if (!r) {
        r = new Node(key);
        return 0;
    } else {
        if (key < r->key)
            return rAdd(key, r->left);
        if (key > r->key)
            return rAdd(key, r->right);
        if (key == r->key)
            return 1; // value already exists
    }
    return -1; // something went wrong
}

int BST::add(const int &key) { // non-recursive
    if (!root) {
        root = new Node(key);
        return 0;
    }
    Node* current = root;
    while (current) {
        if (key < current->key)
            if (!current->left) {
                current->left = new Node(key);
                break;
            } else current = current->left;
        else if (key > current->key)
            if (!current->right) {
                current->right = new Node(key);
                break;
            } else current = current->right;
        else return 1; // value already exists
    }
    return 0;
}

int BST::rDeleteNode(const int& key, Node*& anode /* = root */) {
    if (!anode) return 1; // not found or tree is empty
    if (key < anode->key)
        rDeleteNode(key, anode->left);
    else if (key > anode->key)
        rDeleteNode(key, anode->right);
    else {
        Node* q = anode;
        if (!q->right) {
            anode = q->left;
            delete q;
        } else if (!q->left) {
            anode = q->right;
            delete q;
        } else rDel(q->left, q);
    }
    return 0;
}

Node * BST::rFind(const int& key, Node * anode /* = root */) const {
    if (anode) {
        if (anode->key == key)
            return anode;
        else if (key < anode->key)
            return rFind(key, anode->left);
        else
            return rFind(key, anode->right);
    } else
        return nullptr;
}

Node * BST::find(const int& key, Node * anode /* = root */) const {
    while (anode) {
        if (anode->key == key)
            return anode;
        if (key < anode->key)
            anode = anode->left;
        else
            anode = anode->right;
    }

    return nullptr;
}

int BST::getHeight(const Node * anode /* = root */) const {
    if (!anode)
        return -1;
    else {
        int lHeight = getHeight(anode->left);
        int rHeight = getHeight(anode->right);

        if (lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}

// NLR

string BST::r_PreOrderTraversal(const Node* anode /* = root */,
        string& output) const {
    if (anode) {
        output += std::to_string(anode->key) + " ";
        r_PreOrderTraversal(anode->left, output);
        r_PreOrderTraversal(anode->right, output);
    }
    return output;
}

string BST::rPreOrderTraversal(const Node* anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    return r_PreOrderTraversal(anode, output);
}

string BST::preOrderTraversal(Node * anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    std::stack<Node*>* nodeStack = new std::stack<Node*>;
    nodeStack->push(anode);

    while (!nodeStack->empty()) {
        Node* top = nodeStack->top();
        output += std::to_string(top->key) + " ";
        nodeStack->pop();

        if (top->right)
            nodeStack->push(top->right);
        if (top->left)
            nodeStack->push(top->left);
    }
    return output;
}

// LNR

string BST::r_InOrderTraversal(const Node* anode /* = root */,
        string& output) const {
    if (anode) {
        r_InOrderTraversal(anode->left, output);
        output += std::to_string(anode->key) + " ";
        r_InOrderTraversal(anode->right, output);
    }

    return output;
}

string BST::rInOrderTraversal(const Node* anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    return r_InOrderTraversal(anode, output);
}

// LRN

string BST::r_PostOrderTraversal(const Node* anode /* = root */,
        string& output) const {
    if (anode) {
        r_PostOrderTraversal(anode->left, output);
        r_PostOrderTraversal(anode->right, output);
        output += std::to_string(anode->key) + " ";
    }
    return output;
}

string BST::rPostOrderTraversal(const Node* anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    return r_PostOrderTraversal(anode, output);
}

string BST::breadthTraversal(Node * anode /* = root */) const {
    if (!anode) return "";
    string output = "";
    std::queue<Node*>* nodeQueue = new std::queue<Node*>;
    nodeQueue->push(anode);

    while (!nodeQueue->empty()) {
        if (nodeQueue->front()->left)
            nodeQueue->push(nodeQueue->front()->left);
        if (nodeQueue->front()->right)
            nodeQueue->push(nodeQueue->front()->right);
        output += std::to_string(nodeQueue->front()->key) + " ";
        nodeQueue->pop();
    }
    return output;
}

void BST::clear() {
    while (root)
        rDeleteNode(root->key);
}

bool BST::isEmpty() const {
    return !root;
}
