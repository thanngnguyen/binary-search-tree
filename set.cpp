#include <iostream>
#include "node_BT.cpp"
#include "node_iterator.cpp"

#ifndef __SET__
#define __SET__
using namespace std;

template<typename T>
class Set {
private:
    Node_BT<T>* root;
    // them ptu
    Node_BT<T>* insert(Node_BT<T>* node, T val) {
        if (node == nullptr) return new Node_BT<T>(val);
        if (val < node->value) {
            node->left = insert(node->left, val);
        } else if (val > node->value) {
            node->right = insert(node->right, val);
        }
        return node;
    }
    // xoa ptu 
    Node_BT<T>* remove(Node_BT<T>* node, T val) {
        if (node == nullptr) return node;
        if (val < node->value) {
            node->left = remove(node->left, val);
        } else if (val > node->value) {
            node->right = remove(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node_BT<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node_BT<T>* temp = node->left;
                delete node;
                return temp;
            }
            Node_BT<T>* temp = find_min(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }
    // tim ptu min va chac chan roi -> no nam o ben trai cay =)))
    Node_BT<T>* find_min (Node_BT<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void duyet_tang(Node_BT<T>* node) {
        if (node != nullptr) {
            duyet_tang(node->left);
            cout << node->value << " ";
            duyet_tang(node->right);
        }
    }

public:
    Set() : root(nullptr) {}

    void insert(T val) {
        root = insert(root, val);
    }

    void remove(T val) {
        root = remove(root, val);
    }

    bool ktra(T val) {
        Node_BT<T>* curr = root;
        while (curr != nullptr) {
            if (val == curr->value) return true;
            else if (val < curr->value) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return false;
    }

    Node_iterator<T> begin() {
        return Node_iterator<T>(root);
    }
    Node_iterator<T> end() {
        return Node_iterator<T>(nullptr);
    }
    void out() {
        duyet_tang(root);
        cout << endl;
    }
};

#endif