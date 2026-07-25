#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int data[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack penuh!\n";
        } else {
            data[++top] = x;
        }
    }

    void print() {
        cout << "Isi Stack (Top -> Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(621);
    s.push(999);
    s.push(201);
    s.push(94);
    s.push(124);

    s.print();

    return 0;
}
