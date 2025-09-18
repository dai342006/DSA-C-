#include <iostream>
using namespace std;
#define MAX_LEN 100

class MyQueue {
private:
    int arr[MAX_LEN];
    int front;
    int rear;
public:
    MyQueue(int fr = -1, int re = -1) {
        front = fr;
        rear = re;
    }

    void init() {
        front = -1;
        rear = -1;
    }

    bool isempty() {
        return (front == -1 && rear == -1);
    }

    bool isfull() {
        return (rear + 1) % MAX_LEN == front;
    }

    int size() {
        if (isempty()) return 0;
        if (rear >= front) return rear - front + 1;
        return MAX_LEN - (front - rear - 1);
    }

    void enqueue(int x) {
        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isempty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_LEN;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            init();
        } else {
            front = (front + 1) % MAX_LEN;
        }
    }

    int getfirst() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isempty()) {
            cout << "[]" << endl;
            return;
        }
        int i = front;
        cout << "[";
        while (true) {
            cout << arr[i];
            if (i == rear) break;
            cout << " ";
            i = (i + 1) % MAX_LEN;
        }
        cout << "]" << endl;
    }
};

int main() {
    MyQueue q;
    q.init();

    cout << "isempty() \t" << q.isempty() << "\t"; q.display();

    cout << "enqueue(5) \t"; q.enqueue(5); cout << "\t"; q.display();
    cout << "enqueue(7) \t"; q.enqueue(7); cout << "\t"; q.display();
    cout << "enqueue(9) \t"; q.enqueue(9); cout << "\t"; q.display();

    cout << "getfirst() \t" << q.getfirst() << endl;
    cout << "size() \t\t" << q.size() << endl;

    cout << "dequeue() \t"; q.dequeue(); cout << "\t"; q.display();
    cout << "dequeue() \t"; q.dequeue(); cout << "\t"; q.display();

    cout << "enqueue(11) \t"; q.enqueue(11); cout << "\t"; q.display();
    cout << "enqueue(13) \t"; q.enqueue(13); cout << "\t"; q.display();

    cout << "size() \t\t" << q.size() << endl;
    cout << "getfirst() \t" << q.getfirst() << endl;

    cout << "dequeue() \t"; q.dequeue(); cout << "\t"; q.display();
    cout << "dequeue() \t"; q.dequeue(); cout << "\t"; q.display();
    cout << "dequeue() \t"; q.dequeue(); cout << "\t"; q.display(); // test queue empty

    return 0;
}
