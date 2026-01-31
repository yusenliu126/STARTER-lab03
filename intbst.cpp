// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (!root) {
        root = new Node(value);
        return true;
    } else {
        return insert(value, root);
    }
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) {
        return false;
    } else if (value < n->info) {
        if (n->left) {
            return insert(value, n->left);
        } else {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    } else { // value > n->info
        if (n->right) {
            return insert(value, n->right);
        } else {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}
    


// print tree data pre-order
void IntBST::printPreOrder() const {
    if (root) {
        printPreOrder(root); 
        cout << endl;
    }
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (n) {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
    else {
        return;
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    if (root) {
        printInOrder(root); 
        cout << endl;
    }
}
void IntBST::printInOrder(Node *n) const {
    if (n) {
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
    else {
        return;
    }
}
// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    if (root) {
        printPostOrder(root); 
        cout << endl;
    }
}

void IntBST::printPostOrder(Node *n) const {
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
    else {
        return;
    }
}

// return sum of values in tree
int IntBST::sum() const {
    if (!root) {
        return 0;
    }
    return sum(root); 
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (!n) {
        return 0;
    }
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    if (!root) {
        return 0;
    }
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (!n) {
        return 0;
    }
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (!n) {
        return nullptr; 
    }
    if (value == n->info) {
        return n;
    }
    else if (value < n->info) {
        return getNodeFor(value, n->left);
    }
    else {
        return getNodeFor(value, n->right);
    }
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return getNodeFor(value, root) != nullptr;
}

//additional helper functions
IntBST::Node* IntBST::subtreeMin(Node* n) const {
    if (!n) return NULL;
    while (n->left) n = n->left;
    return n;
}

IntBST::Node* IntBST::subtreeMax(Node* n) const {
    if (!n) return NULL;
    while (n->right) n = n->right;
    return n;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    if (!root) {
        return NULL; 
    }
    Node* target = getNodeFor(value, root);
    if (!target) {
        return NULL;
    }
    if (target->left) {
        return subtreeMax(target->left);
    }
    Node* curr = target; 
    Node* par = curr->parent;
    while (par && curr == par->left) {
        curr = par; 
        par = par->parent;
    }
    return par;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* predNode = getPredecessorNode(value);
    if (predNode) {
        return predNode->info;
    } else {
        return 0;
    }
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    if (!root) {
        return NULL; 
    }
    Node* target = getNodeFor(value, root);
    if (!target) {
        return NULL;
    }
    if (target->right) {
        return subtreeMin(target->right);
    }
    Node* curr = target; 
    Node* par = curr->parent;
    while (par && curr == par->right) {
        curr = par; 
        par = par->parent;
    }
    return par;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* succNode = getSuccessorNode(value);
    if (succNode) {
        return succNode->info;
    } else {
        return 0;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    if (!root) {
        return false; 
    }
    Node* target = getNodeFor(value, root); 
    if (!target) {
        return false;
    }
    // Case 1: target has no children
    if (!target->left && !target->right) {
        if (target == root) {
            delete root;
            root = NULL;
        } else {
            Node* par = target->parent;
            if (par->left == target) {
                par->left = NULL;
            } else {
                par->right = NULL;
            }
            delete target;
        }
    }
    // Case 2: target has one child
    else if (!target->left || !target->right) {
        Node* child = target->left ? target->left : target->right;
        if (target == root) {
            root = child;
            child->parent = NULL;
            delete target;
        } else {
            Node* par = target->parent;
            if (par->left == target) {
                par->left = child;
            } else {
                par->right = child;
            }
            child->parent = par;
            delete target;
        }
    }
    // Case 3: target has two children
    else {
        Node* succ = getSuccessorNode(value);
        target->info = succ->info; // copy successor's value to target
        // Now remove the successor node
        Node* succPar = succ->parent;
        Node* succChild = succ->right; // successor cannot have left child
        if (succPar->left == succ) {
            succPar->left = succChild; 
        } else {
            succPar->right = succChild;
        }
        if (succChild) {
            succChild->parent = succPar;
        }
        delete succ;
    }
    return true;
}
