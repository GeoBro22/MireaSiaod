#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fill(int n, int m[6][6]) 
{
	int l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "Введите число расположенное на месте" << i + 1 << j + 1 << ":";
			cin >> l;
			m[i][j] = l;
		}
}
void fillDynam(int n, int **m)
{
	int l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "Введите число расположенное на месте" << i + 1 << j + 1 << ":";
			cin >> l;
			m[i][j] = l;
		}
}
void findmin(int n, int m[6][6]) 
{
	int k = n, min = m[0][0];
	for (int i = 0; i < n; i++) {
		k--;
		for (int j = 0; j < k; j++)
			if (m[i][j] < min)
				min = m[i][j];
	}
	cout << "Минимальное число выше побочной диагонали - " << min << endl;
}
void findminDynam(int n, int **m)
{
	int k = n, min = m[0][0];
	for (int i = 0; i < n; i++) {
		k--;
		for (int j = 0; j < k; j++)
			if (m[i][j] < min)
				min = m[i][j];
	}
	cout <<"Минимальное число выше побочной диагонали - " << min << endl;
}
double findPlace(vector <int> a, vector <int> b, vector <int> c) {
	return fabs((a[0] - c[0]) * (b[1] - c[1]) - (b[0] - c[0]) * (a[1] - c[1]));
}

bool inTriangle(vector <int> p, vector <int> a, vector <int> b, vector <int> c) {
	return (findPlace(a, b, c) >= (findPlace(p, b, c) + findPlace(a, p, c) + findPlace(a, b, p)));
}

int main()
{


	setlocale(LC_ALL, "Russian");
	int menu, n, newNum, menu2;
	int* mas2;
check1:
	cout << "1-Использовать статический массив; 2-Использовать динамический массив; 3-Задача с вектором:";
	cin >> menu;
	if (menu > 3 || menu < 1) goto check1;
check2:
	if (menu == 1 || menu == 2) {
		cout << "Введите размерность матрицы не более 6:";
		cin >> n;
		if (n > 10 || n < 1) goto check2;
	}

	if (menu == 1) {
		int mas1[6][6] = {
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0},
				{0,0,0,0,0,0}
		};
		fill(n, mas1);
		cout << "Ваша матрица:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mas1[i][j] << " ";
			}
			cout << endl;
		}
		findmin(n, mas1);
	}
	else if (menu == 2) {
		int** mas2 = new int* [n];
		for (int i = 0; i < n; i++)
			mas2[i] = new int[n];
		fillDynam(n, mas2);
		cout << "Ваша матрица:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mas2[i][j] << " ";
			}
			cout << endl;
		}
		findminDynam(n, mas2);
	}
	else{
		const int n = 7;
		vector <int> p[n] = { {0, 0},
					  {1, 1},
					  {2, 2},
					  {5, 0},
					  {7, 3},
					  {0, 5},
					  {2, 5} };
		int ax, bx, cx, ay, by, cy;
		int dif = n;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					int t = 0;
					for (int x = 0; x < n; x++) {
						if ((x - i) * (x - j) * (x - k)) {
							if (inTriangle(p[x], p[i], p[j], p[k])) {
								t++;
							}
							else {
								t--;
							}
						}
						else {
							continue;
						}
					}
					t = abs(t);
					if (t < dif) {
						dif = t;
						ax = p[i][0];
						ay = p[i][1];
						bx = p[j][0];
						by = p[j][1];
						cx = p[k][0];
						cy = p[k][1];
					}
					if (t == 0) {
						goto last;
					}
				}
			}
		}
	last:
		cout <<"Координаты вершин: " << '(' << ax << ';' << ay << ')' << ' ' << '(' << bx << ';' << by << ')' << ' ' << '(' << cx << ';' << cy << ')';
		
	}
}
