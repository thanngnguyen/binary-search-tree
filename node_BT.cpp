#include <iostream>
#ifndef __NODE_BT__
#define __NODE_BT__
using namespace std;

template<typename T>
class Node_BT {

public:
    Node_BT *left;
    Node_BT *right;
    T value;
    Node_BT(T val) {
        value = val;
        left = right = nullptr;
    }
};

#endif