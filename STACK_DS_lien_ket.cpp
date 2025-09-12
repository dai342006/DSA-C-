#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head = nullptr;
    int count = 0;

    bool isEmpty() { return head == nullptr; }
    int size() { return count; }

    void push(int x) {
        head = new Node{x, head};
        count++;
    }

    int top() {
        if (isEmpty()) return -1;
        return head->data;
    }

    void pop() {
        if (isEmpty()) return;
        Node* t = head;
        head = head->next;
        delete t;
        count--;
    }

    void displayStack() {
        for (Node* p = head; p; p = p->next) cout << p->data << " ";
        cout << "\n";
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.displayStack();             // 30 20 10
    cout << "Top: " << st.top() << "\n"; 
    st.pop();
    st.displayStack();             // 20 10
}
