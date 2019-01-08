#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void Xuatm (int a[], int &m){				// input : m
	cout << "Nhap m :" ;					// output : 1 den m;
	cin >> m;								
		for (int i = 1; i <= m; i++){
			cout << i << "\t";
		}
}
void Timsongaunhien (int a[], int n, int m){ 
	do
	{
		cout << "\nNhap n: ";
		cin >> n; 							// input : n;
	}										// output : n neu n < m
	while (n >= m);
	srand (time (NULL));					// ham thay doi bien moi khi xuat so ngau nhien
	for (int i = 1; i <= n; i++){
		a[i] = rand () % (m);				// luu so ngau nhien tu 1 den m
		cout << a[i] << "\t";				// Xuat  n so ngau nhien tu 1 den m
	}
}
int main(){
	int a[50], m, n;
	Xuatm (a, m);
	Timsongaunhien (a, n ,m);
}
