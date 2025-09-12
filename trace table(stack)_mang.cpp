#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];   // mảng để lưu phần tử
    int topIndex;   // vị trí phần tử trên cùng
public:
    Stack() {
        topIndex = -1; // stack rỗng
    }

    // thêm phần tử vào stack
    void push(int x) {
        if (topIndex < 99) {
            arr[++topIndex] = x;
        } else {
            cout << "Stack day!\n";
        }
    }

    // lấy phần tử trên cùng ra và trả về
    int pop() {
        if (topIndex >= 0) {
            return arr[topIndex--];
        } else {
            cout << "Stack rong!\n";
            return -1; // báo lỗi
        }
    }

    // xem phần tử trên cùng nhưng không xóa
    int top() {
        if (topIndex >= 0) {
            return arr[topIndex];
        } else {
            cout << "Stack rong!\n";
            return -1;
        }
    }

    // số phần tử trong stack
    int size() {
        return topIndex + 1;
    }

    // kiểm tra rỗng
    bool isEmpty() {
        return topIndex == -1;
    }

    // in toàn bộ stack
    void print() {
        cout << "(";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i];
            if (i < topIndex) cout << ", ";
        }
        cout << ")\n";
    }
};

int main() {
    Stack s;

    s.push(5); s.print();
    s.push(3); s.print();
    cout << "size: " << s.size() << endl;
    cout << "pop: " << s.pop() << endl; s.print();
    cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "pop: " << s.pop() << endl; s.print();
    cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "pop: " << s.pop() << endl; s.print();
    s.push(7); s.print();
    s.push(9); s.print();
    cout << "top: " << s.top() << endl;
    s.push(4); s.print();
    cout << "size: " << s.size() << endl;
    cout << "pop: " << s.pop() << endl; s.print();
    s.push(6); s.print();
    s.push(8); s.print();
    cout << "pop: " << s.pop() << endl; s.print();

    return 0;
}
