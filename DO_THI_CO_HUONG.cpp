#include <iostream>
using namespace std;
int a[100][100];
int n;
int main(){
	cout << "nhap so dinh: ";
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if (i != j){
		
			
			cout <<"dinh " << i << " co noi dinh" << j << " ko(0/1): ";
			cin >> a[i][j];
			
			if (a[i][j] == 1) a[j][i] = 1;	}
		}
	}
	cout << " nhap dinh 1: ";
	int u;
	cin >> u;
	cout << " nhap dinh 2: ";
	int v;
	cin >> v;
	
	if(a[u][v] == 1) cout << "co cung tu dinh " << u << "den dinh" << v;
	else cout << "KO co cung tu dinh " << u << "den dinh " << v;
	return 0;
}


