#include <iostream>
using namespace std;

const int VO_CUC = 32000;   // Gi� tr? v� c�ng l?n (coi nhu 8)
const int MAX = 100;        // S? d?nh t?i da trong d? th?

// ?? H�m t�m d?nh c� kho?ng c�ch nh? nh?t chua du?c x�t
int timDinhNhoNhat(int khoangCach[], bool daXet[], int soDinh) {
    int nhoNhat = VO_CUC;
    int chiSoNho = -1;
    for (int i = 1; i <= soDinh; i++) {
        if (!daXet[i] && khoangCach[i] < nhoNhat) {
            nhoNhat = khoangCach[i];
            chiSoNho = i;
        }
    }
    return chiSoNho;
}

// ??? H�m in du?ng di t? d?nh b?t d?u -> d?nh k?t th�c
void inDuongDi(int truoc[], int batDau, int ketThuc) {
    if (ketThuc == batDau) {
        cout << batDau;
        return;
    }
    if (truoc[ketThuc] == 0) {
        cout << "Khong co duong di!";
        return;
    }
    inDuongDi(truoc, batDau, truoc[ketThuc]);
    cout << " -> " << ketThuc;
}

// ?? Thu?t to�n Dijkstra
void dijkstra(int doThi[MAX][MAX], int soDinh, int batDau, int ketThuc) {
    int khoangCach[MAX];  // Luu kho?ng c�ch ng?n nh?t t? d?nh b?t d?u
    int truoc[MAX];       // Luu d?nh tru?c d� trong du?ng di
    bool daXet[MAX];      // ��nh d?u d?nh d� x�t

    // ?? Bu?c 1: Kh?i t?o ban d?u
    for (int i = 1; i <= soDinh; i++) {
        khoangCach[i] = VO_CUC;
        truoc[i] = 0;
        daXet[i] = false;
    }

    khoangCach[batDau] = 0;     // Kho?ng c�ch t? d?nh b?t d?u d?n ch�nh n� = 0
    daXet[batDau] = true;       // ��nh d?u d� x�t d?nh b?t d?u

    // ?? Bu?c 2: G�n kho?ng c�ch t?m th?i cho c�c d?nh k?
    for (int i = 1; i <= soDinh; i++) {
        if (doThi[batDau][i] != 0 && doThi[batDau][i] < VO_CUC) {
            khoangCach[i] = doThi[batDau][i];
            truoc[i] = batDau;
        }
    }

    // ?? Bu?c 3: Duy?t c�c d?nh c�n l?i
    for (int i = 1; i <= soDinh - 2; i++) {
        int u = timDinhNhoNhat(khoangCach, daXet, soDinh);
        if (u == -1) break; // Kh�ng c�n d?nh n�o c� th? di t?i
        daXet[u] = true;

        // ?? Bu?c 4: C?p nh?t kho?ng c�ch d?n c�c d?nh chua x�t
        for (int v = 1; v <= soDinh; v++) {
            if (!daXet[v] && doThi[u][v] != 0 && doThi[u][v] < VO_CUC
                && khoangCach[u] + doThi[u][v] < khoangCach[v]) {
                khoangCach[v] = khoangCach[u] + doThi[u][v];
                truoc[v] = u;
            }
        }
    }

    // ?? Bu?c 5: In k?t qu?
    cout << "\n?? Do dai duong di ngan nhat tu " << batDau
         << " den " << ketThuc << " la: " << khoangCach[ketThuc] << endl;
    cout << "?? Duong di: ";
    inDuongDi(truoc, batDau, ketThuc);
    cout << endl;
}

int main() {
    int soDinh = 6;

    // ?? Ma tr?n tr?ng s? c?a d? th?
    int doThi[MAX][MAX] = {
        {0},
        {0, 0, 4, 0, 1, 0, 0},
        {0, 4, 0, 0, 2, 4, 0},
        {0, 0, 0, 0, 6, 10, 0},
        {0, 1, 2, 6, 0, 3, 0},
        {0, 0, 4, 10, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    int batDau, ketThuc;
    cout << "Nhap dinh bat dau: ";
    cin >> batDau;
    cout << "Nhap dinh ket thuc: ";
    cin >> ketThuc;

    dijkstra(doThi, soDinh, batDau, ketThuc);
    return 0;
}
