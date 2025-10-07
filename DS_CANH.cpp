#include <iostream>
using namespace std;
int a[100][100];
int n;
int main(){
	cout << "nhap so canh do thi: ";
	cin >> n;
	int u, v;
	for (int i = 1; i <= n; i++){
		cout << " dinh dinh: ";
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}

	cout << " nhap dinh 1: ";
	cin >> u;
	cout << " nhap dinh 2: ";
	cin >> v;
	
	if(a[u][v] == 1) cout << "co canh noi dinh  " << u << "den dinh" << v;
	else cout << "KO co canh noi dinh " << u << "den dinh " << v;
	return 0;
}


