#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val = 0, Node* nxt = nullptr) {
        data = val;
        next = nxt;
    }
};

class MyQueue {
public:
    Node* head;
    Node* tail;

    MyQueue(Node* h = nullptr, Node* t = nullptr) {
        head = h;
        tail = t;
    }

    void init() {
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* i = head;
        cout << "[";
        while (i != nullptr) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << "]" << endl;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        Node* i = head;
        while (i != nullptr) {
            count++;
            i = i->next;
        }
        return count;
    }

    void enqueue(int x) {
        Node* p = new Node(x);
        if (isEmpty()) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* p = head;
        head = head->next;
        delete p;
        if (head == nullptr) tail = nullptr;
    }

    int getFirst() {
        if (isEmpty()) {
            return -1; // giá trị báo lỗi
        }
        return head->data;
    }
};

int main() {
    MyQueue q;
    q.init();

    cout << "isEmpty() \t" << q.isEmpty() << "\t"; q.display();

    cout << "enqueue(5) \t"; q.enqueue(5); cout << "- \t"; q.display();
    cout << "enqueue(7) \t"; q.enqueue(7); cout << "- \t"; q.display();

    cout << "size()\t\t" << q.size(); cout << " \t"; q.display();

    cout << "dequeue() \t"; q.dequeue(); cout << "- \t"; q.display();

    cout << "enqueue(2) \t"; q.enqueue(2); cout << "- \t"; q.display();

    cout << "getFirst() \t" << q.getFirst(); cout << "\t"; q.display();

    return 0;
}
