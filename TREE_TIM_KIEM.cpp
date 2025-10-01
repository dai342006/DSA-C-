#include <iostream>              // Thư viện nhập/xuất chuẩn (cout, cin)
using namespace std;            // Để dùng cout, cin không cần std::

struct Node {
    int data;                   // Dữ liệu lưu trong node
    Node *left, *right;         // Con trái và con phải của node

    // Constructor khởi tạo node (có giá trị mặc định)
    Node(int data=0, Node* left=nullptr, Node* right=nullptr) {
        this->data = data;      // Gán giá trị data cho node
        this->left = left;      // Gán con trái (mặc định là nullptr)
        this->right = right;    // Gán con phải (mặc định là nullptr)
    }
};

struct Mytree {
    Node* root;                 // Gốc của cây
    Mytree(){ root = nullptr; } // Constructor: ban đầu cây rỗng

    // ===== Hàm chèn giá trị vào cây =====
    void insert(Node* &r, int x) {
        if (r == nullptr) {     // Nếu vị trí này chưa có node
            r = new Node(x);    // Tạo node mới chứa x
            return;             // Dừng đệ quy
        }
        if (x == r->data) return;       // Nếu trùng giá trị thì bỏ qua (BST không chứa trùng)
        else if (x < r->data) insert(r->left, x);   // Nếu x nhỏ hơn → chèn về bên trái
        else insert(r->right, x);                  // Nếu x lớn hơn → chèn về bên phải
    }
    void insert(int x){ insert(root, x); } // Hàm tiện lợi: gọi insert từ gốc

    // ===== Duyệt PreOrder (NLR) =====
    void preOrder(Node* r){
        if (r == nullptr) return;       // Nếu node rỗng thì dừng
        cout << r->data << " ";         // Xử lý node trước
        preOrder(r->left);              // Duyệt con trái
        preOrder(r->right);             // Duyệt con phải
    }
    void preOrder(){ preOrder(root); cout << endl; } // Hàm gọi từ gốc

    // ===== Duyệt InOrder (LNR) =====
    void inOrder(Node* r){
        if (r == nullptr) return;
        inOrder(r->left);               // Duyệt trái trước
        cout << r->data << " ";         // Xử lý node giữa
        inOrder(r->right);              // Duyệt phải sau
    }
    void inOrder(){ inOrder(root); cout << endl; }

    // ===== Duyệt PostOrder (LRN) =====
    void postOrder(Node* r){
        if (r == nullptr) return;
        postOrder(r->left);             // Duyệt trái
        postOrder(r->right);            // Duyệt phải
        cout << r->data << " ";         // Xử lý node cuối cùng
    }
    void postOrder(){ postOrder(root); cout << endl; }

    // ===== Tính chiều cao cây =====
    int height(Node* r){
        if (r == nullptr) return 0;     // Nếu cây rỗng → cao = 0
        int l = height(r->left);        // Chiều cao nhánh trái
        int rgt = height(r->right);     // Chiều cao nhánh phải
        return max(l, rgt) + 1;         // Chiều cao = nhánh cao nhất + 1
    }
    int height(){ return height(root); } // Gọi từ gốc

    // ===== Đếm node lá =====
    int countLeaf(Node* r){
        if (r == nullptr) return 0;     // Cây rỗng → không có lá
        if (r->left == nullptr && r->right == nullptr) return 1; // Nếu node không có con → là lá
        return countLeaf(r->left) + countLeaf(r->right);         // Cộng lá trái và lá phải
    }
    int countLeaf(){ return countLeaf(root); }

    // ===== Đếm node có 1 con =====
    int countOneChild(Node* r){
        if (r == nullptr) return 0;
        int cnt = 0;
        if ((r->left == nullptr) ^ (r->right == nullptr)) cnt = 1; 
        // ^ là XOR: true nếu chỉ 1 trong 2 khác nullptr (node có đúng 1 con)
        return cnt + countOneChild(r->left) + countOneChild(r->right);
    }
    int countOneChild(){ return countOneChild(root); }

    // ===== Đếm node có 2 con =====
    int countTwoChild(Node* r){
        if (r == nullptr) return 0;
        int cnt = 0;
        if (r->left && r->right) cnt = 1; // Nếu có cả trái và phải → node có 2 con
        return cnt + countTwoChild(r->left) + countTwoChild(r->right);
    }
    int countTwoChild(){ return countTwoChild(root); }

    // ===== Tìm node nhỏ nhất (dùng khi xóa) =====
    Node* findMin(Node* r){
        while (r && r->left) r = r->left;  // Lặp đến khi hết con trái
        return r;
    }

    // ===== Xóa node trong BST =====
    
    Node* deleteNode(Node* r, int x){
        if (r == nullptr) return r;        // Nếu rỗng → trả về luôn
        if (x < r->data) r->left = deleteNode(r->left, x);   // Tìm bên trái
        else if (x > r->data) r->right = deleteNode(r->right, x); // Tìm bên phải
        else { // Tìm thấy node cần xóa
            if (r->left == nullptr && r->right == nullptr){  // TH1: không có con
                delete r; return nullptr;
            } else if (r->left == nullptr){                  // TH2: chỉ có con phải
                Node* temp = r->right;
                delete r; return temp;
            } else if (r->right == nullptr){                 // TH2: chỉ có con trái
                Node* temp = r->left;
                delete r; return temp;
            } else {                                         // TH3: có 2 con
                Node* temp = findMin(r->right);              // Tìm node nhỏ nhất bên phải
                r->data = temp->data;                        // Copy giá trị sang node hiện tại
                r->right = deleteNode(r->right, temp->data); // Xóa node nhỏ nhất bên phải
            }
        }
        return r; // Trả về node gốc sau khi xóa
    }
    void deleteNode(int x){ root = deleteNode(root, x); }
};

int main(){
    Mytree t;                          // Tạo cây mới
    int arr[] = {40, 25, 68, 20, 45, 55, 90, 10, 88, 20, 70};
    for (int x : arr) t.insert(x);     // Chèn từng phần tử vào cây

    cout << "PreOrder: "; t.preOrder();
    cout << "InOrder: "; t.inOrder();
    cout << "PostOrder: "; t.postOrder();

    cout << "Chieu cao: " << t.height()-1 << " (so canh)\n";
    cout << "Node la: " << t.countLeaf() << endl;
    cout << "Node co 1 con: " << t.countOneChild() << endl;
    cout << "Node co 2 con: " << t.countTwoChild() << endl;

    // Xóa các node
    t.deleteNode(20);
    t.deleteNode(10);
    t.deleteNode(68);

    cout << "\nCay sau khi xoa 20, 10, 68 (InOrder): ";
    t.inOrder();
    cout << "Node la sau khi xoa: " << t.countLeaf() << endl;
}
