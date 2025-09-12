#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int n; // đếm số phần tử
public:
    LinkedList() { head = nullptr; n = 0; }

    void init() { 
        head = nullptr; 
        n = 0; 
    }

    bool isEmpty() { return head == nullptr; }

    bool isFull() { 
        // danh sách liên kết gần như không bao giờ full
        return false; 
    }

    int size() { return n; }

    void insert(int pos, int x) {
        if (pos < 1 || pos > n + 1) return;
        Node* newNode = new Node{x, nullptr};
        if (pos == 1) { // chèn đầu
            newNode->next = head;
            head = newNode;
        } else {
            Node* p = head;
            for (int i = 1; i < pos - 1; i++)
                p = p->next;
            newNode->next = p->next;
            p->next = newNode;
        }
        n++;
    }

    void remove(int pos) {
        if (pos < 1 || pos > n) return;
        Node* temp;
        if (pos == 1) { // xóa đầu
            temp = head;
            head = head->next;
        } else {
            Node* p = head;
            for (int i = 1; i < pos - 1; i++)
                p = p->next;
            temp = p->next;
            p->next = temp->next;
        }
        delete temp;
        n--;
    }

    bool contain(int x) {
        Node* p = head;
        while (p != nullptr) {
            if (p->data == x) return true;
            p = p->next;
        }
        return false;
    }

    void print() {
        Node* p = head;
        cout << "[";
        while (p != nullptr) {
            cout << p->data;
            if (p->next != nullptr) cout << ", ";
            p = p->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    LinkedList myLi;
    myLi.init();
    cout << "isEmpty: " << myLi.isEmpty() << endl;
    cout << "isFull: " << myLi.isFull() << endl;
    cout << "size: " << myLi.size() << endl;
    myLi.print();

    myLi.insert(1, 5);
    myLi.print();

    myLi.insert(1, 6);
    myLi.print();

    cout << "contain 5 " << myLi.contain(5) << endl;

    myLi.insert(2, 5);
    myLi.print();

    cout << "size: " << myLi.size() << endl;

    myLi.remove(2);
    myLi.print();

    return 0;
}
