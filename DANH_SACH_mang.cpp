#include <iostream>
using namespace std;

class IntList {
private:
    int DS[100];  
    int size;     

public:
    
    IntList(int arr[], int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            DS[i] = arr[i];
        }
    }

    // in toàn bộ danh sách
    void printList() {
        cout << "Danh sach: ";
        for (int i = 0; i < size; i++) {
            cout << DS[i] << " ";
        }
        cout << endl;
    }

    // lấy con trỏ đến phần tử thứ p
    int* getAt(int p) {
        if (p < 0 || p >= size) {
            return nullptr;
        }
        return &DS[p];
    }

    // sửa giá trị tại vị trí p
    void setAt(int p, int value) {
        int* ptr = getAt(p);
        if (ptr != nullptr) {
            *ptr = value;
        } else {
            cout << "Vi tri khong hop le!" << endl;
        }
    }
};

int main() {
    int initArr[5] = {3, 5, 6, 8, 2};
    IntList list(initArr, 5);

    cout << "Ban dau: ";
    list.printList();

    int p;
    cout << "Nhap vi tri muon sua (0..4): ";
    cin >> p;

    
    list.setAt(p, 999);

    cout << "Sau khi thay doi:" << endl;
    list.printList();

    return 0;
}
