#ifndef SEARCH_ENGINE_AVLTREE_H
#define SEARCH_ENGINE_AVLTREE_H
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>


struct TreeNode{
    T key;            ///Key contained within node
    vector<T> values;
    TreeNode<T>* left;     ///Pointer to left child node
    TreeNode<T>* right;    ///Pointer to right child node
    int height;         ///Contains height value of node
};

template<class T>

class AVLTree{
public:
    struct ForwardIterator{
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = TreeNode<T>;
        using pointer = TreeNode<T>*;
        using reference = TreeNode<T>&;

        ForwardIterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }


        ForwardIterator& operator++() {
            if(*m_ptr->left != nullptr){
                m_ptr = *m_ptr->left;
            }
            else if(*m_ptr->right != nullptr){
                m_ptr = *m_ptr->right;
            }
            return *this;
        }


        ForwardIterator operator++(int) { ForwardIterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const ForwardIterator& a, const ForwardIterator& b) { return a.m_ptr != b.m_ptr; };
    private:
        pointer m_ptr;
    };

    //ForwardIterator begin() { return ForwardIterator(&(*head)); }
    //ForwardIterator end()   { return ForwardIterator(&(*tail->getNext())); }

    static TreeNode<T>* newNode(T key){
        auto* node = new TreeNode<T>();
        node->key = std::move(key);
        node->height = 1;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    };
    static TreeNode<T>* newNodeValue(const T& key, const T& value) {        //Makes new node containing query and ID
        auto* node = new TreeNode<T>();
        node->key = key;
        node->values.push_back(value);
        node->height = 1;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }

    static int height(TreeNode<T>*& node){      //Returns height of node
        if(node == nullptr){
            return 0;
        }
        return node->height;
    }

    static int balanceFactor(TreeNode<T>*& node){           //Determines balance factor at node
        if(node == nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    static TreeNode<T>* rotateLeft(TreeNode<T>*& lower){        //Performs left rotation at given node
        TreeNode<T>* upper = lower->right;
        TreeNode<T>* subTree = upper->left;

        upper->left = lower;
        lower->right = subTree;

        lower->height = 1 + max(height(lower->left), height(lower->right));
        upper->height = 1 + max(height(upper->left), height(upper->right));
        return upper;
    }

    static TreeNode<T>* rotateRight(TreeNode<T>*& upper){       //Performs right rotation at given node
        TreeNode<T>* lower = upper->left;
        TreeNode<T>* subTree = lower->right;

        lower->right = upper;
        upper->left = subTree;

        lower->height = 1 + max(height(lower->left), height(lower->right));
        upper->height = 1 + max(height(upper->left), height(upper->right));
        return lower;
    }

    TreeNode<T>* insert(TreeNode<T>* root, const T& key){
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

    TreeNode<T>* insertValue(TreeNode<T>*& root, const T& key, const T& value) {     //Insert function for query and ID
        if(root == nullptr){                    //Adds node if tree is empty
            return newNodeValue(key, value);
        }

        if(key == root->key){                                         //Checks if word has been found
            if(!count(root->values.begin(), root->values.end(), value)) {         //Adds ID if it isn't in the node
                root->values.push_back(value);
            }
            return root;
        }
        else if(key < root->key) {                                    //Insert into left subtree
            root->left = insertValue(root->left, key, value);
        }
        else if(key > root->key){                                     //Insert into right subtree
            root->right = insertValue(root->right, key, value);
        }

        root->height = 1 + max(height(root->left), height(root->right));    //Set height
        int balanceFactor = AVLTree::balanceFactor(root);


        if(root->left && balanceFactor > 1 && key < root->left->key){
            return rotateRight(root);
        }
        if(root->left && root->left->right && balanceFactor > 1 && key > root->left->key){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if(root->right && balanceFactor < -1 && key > root->right->key){
            return rotateLeft(root);
        }
        if(root->right && root->right->left && balanceFactor < -1 && key < root->right->key){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    TreeNode<T>* search(TreeNode<T>*& root, const T*& key){         //Returns node containing specified word
        if(root->key == key)                      //Returns node if it contains the query
            return root;
        else if(key < root->key)                  //Moves to left subtree
            return search(root->left, key);
        else if(key > root->key)                  //Moves to right subtree
            return search(root->right, key);
    }

    void preOrderTraversal(TreeNode<T>* root){          //Prints a pre-order traversal of AVLTree
        if(root == nullptr)
            return;
        cout << root->key << ", ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void inOrderTraversal(TreeNode<T>* root){           //Prints an in-order traversal of AVLTree
        if(root == nullptr)
            return;
        inOrderTraversal(root->left);
        cout << root->key << ", ";
        inOrderTraversal(root->right);
    }
    void postOrderTraversal(TreeNode<T>* root){         //Prints a post-order traversal of AVLTree
        if(root == nullptr)
            return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << ", ";
    }

    /*ForwardIterator begin() { return ForwardIterator(&data[0]); }
    ForwardIterator end()   { return ForwardIterator(&data[size]); }*/
};



#endif //SEARCH_ENGINE_AVLTREE_H
