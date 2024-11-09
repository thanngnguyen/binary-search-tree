#include <iostream>
#include "node_BT.cpp"
#ifndef __NODE_ITERATOR__
#define __NODE_ITERATOR__
using namespace std;

template<typename T>
class Node_iterator{
private:
    Node_BT<T>* curr;
    // tim node tien nhiem cua curr trong cay con ben trai
    Node_BT<T>* find_pre_left (Node_BT<T>* node) {
        Node_BT<T>* pre = node->left;
        while (pre->right && pre->right != node) {
            pre = pre->right;
        }
        return pre;
    }
public:
    Node_iterator(Node_BT<T>* root) : curr(root) {
        // tim den node nho nhat
        while (curr && curr->left) {
            Node_BT<T>* pre = find_pre_left(curr);
            if (pre->right == nullptr) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = nullptr;
                break;
            }
        }
    }

    Node_iterator& operator++() {
        if (!curr) return *this; 

        if (curr->right == nullptr) {
            Node_BT<T>* pre = find_pre_left(curr);
            if (pre && pre->right == curr) {
                pre->right = nullptr;
            }
            curr = curr->right;
        } else {
            Node_BT<T>* pre = find_pre_left(curr);
            if (pre->right == nullptr) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = nullptr;
                curr = curr->right;
            }
        }
        return *this;
    }

    T operator* () const {
        return curr->value;
    }

    bool operator!= (const Node_iterator& ptu_khac) {
        return curr != ptu_khac.curr;
    }
};
#endif