/*
#include "AVLTree.h"
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

TreeNode* AVLTree::rotateLeft(TreeNode*& lower) {                                   //Left Rotate
    TreeNode* upper = lower->right;
    TreeNode* subTree = upper->left;

    upper->left = lower;
    lower->right = subTree;

    lower->height = 1 + max(height(lower->left), height(lower->right));
    upper->height = 1 + max(height(upper->left), height(upper->right));
    return upper;
}

TreeNode* AVLTree::rotateRight(TreeNode*& upper) {                                  //Right Rotate
    TreeNode* lower = upper->left;
    TreeNode* subTree = lower->right;

    lower->right = upper;
    upper->left = subTree;

    lower->height = 1 + max(height(lower->left), height(lower->right));
    upper->height = 1 + max(height(upper->left), height(upper->right));
    return lower;
}

TreeNode* AVLTree::insert(TreeNode* root, const string& key) {                   //Insert function for string
    if(root == nullptr){
        return newNode(key);
    }

    if(key < root->key) {
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFactor = AVLTree::balanceFactor(root);

    if(balanceFactor > 1 && key < root->left->key){
        return rotateRight(root);
    }
    if(balanceFactor > 1 && key > root->left->key){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balanceFactor < -1 && key > root->right->key){
        return rotateLeft(root);
    }
    if(balanceFactor < -1 && key < root->right->key){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void AVLTree::preOrderTraversal(TreeNode* root) {           //Printing pre-order traversal of tree
    if(root == nullptr)
        return;
    cout << root->key << ", ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void AVLTree::inOrderTraversal(TreeNode* root) {            //Printing in-order traversal of tree
    if(root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->key << ", ";
    inOrderTraversal(root->right);
}

void AVLTree::postOrderTraversal(TreeNode* root) {          //Printing post-order traversal of tree
    if(root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->key << ", ";
}

TreeNode* AVLTree::newNode(string key) {                   //Makes new node containing string
    auto* node = new TreeNode();
    node->key = std::move(key);
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

TreeNode* AVLTree::newNodeID(const string& key, const string& id) {        //Makes new node containing query and ID
    auto* node = new TreeNode();
    node->key = key;
    node->ids.push_back(id);
    node->instances.push_back(0);
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int AVLTree::height(TreeNode*& node) {                      //Returns height of given node
    if(node == nullptr){
        return 0;
    }
    return node->height;
}

int AVLTree::balanceFactor(TreeNode*& node) {               //Finds balance factor of given node
    if(node == nullptr){
        return 0;
    }
    return height(node->left) - height(node->right);    //returns difference between height of right and left subtree
}

TreeNode* AVLTree::search(TreeNode*& root, const string& key) {            //Finds query in tree
    if(root->key == key)                      //Returns node if it contains the query
        return root;
    else if(key < root->key)                  //Moves to left subtree
        return search(root->left, key);
    else if(key > root->key)                  //Moves to right subtree
        return search(root->right, key);
}





*/
