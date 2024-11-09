#include <bits/stdc++.h>
#include "set.cpp"

#define int long long
#define Thang main
using namespace std;

template<typename T>
void input_file(Set<T>& a, const string& filename) {
    ifstream file(filename);
    if (file.is_open() == false) {
        cout << "error opening file xxx " << filename << endl;
        return;
    }
    T data;
    while (file >> data) {
        a.insert(data);
    }
    file.close();
}

Thang() {
    Set<int> A, B, C;

    input_file(A, "A.txt");
    input_file(B, "B.txt");
    input_file(C, "C.txt");

    cout << "Flie A ban dau la: ";
    A.out();

    cout << "File B ban dau la: ";
    B.out();

    cout << "File C ban dau la: ";
    C.out();

    cout << "Them lan luot cac ptu tap B vao tap A -> tap hop A va B: ";
    input_file(A, "B.txt");
    A.out();

    cout << "Bot dan cac phan tu C khoi A -> tap A con lai: ";
    ifstream fileC("C.txt");
    int data;
    while (fileC >> data) {
        A.remove(data);
    }
    A.out();
}