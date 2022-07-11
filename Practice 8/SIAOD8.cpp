#include <iostream>
#include<vector>
#include <chrono>
#include <algorithm>
using namespace std;
unsigned long long int compars = 0, swaps = 0;
bool cmp(int& a, int& b) {
    if (a > b) return true;
    return false;
}
int bubblesort(vector <int> &array, int len)
{
	int c;
	int k = 0;
	for (int i = len; i > 1; i--)
	{
		k = 0;
        for (int j = 1; j < i; j++) 
        {
            compars++;
            if (array[j] < array[j - 1])
            {
                c = array[j];
                array[j] = array[j - 1];
                array[j - 1] = c;
                swaps++;
                k = 1;
            }
        }
		if (k == 0) return 0;
	}
}
void hoarasort(vector <int> &a, int first, int last)
{

    int i = first, j = last-1;
    int tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        compars++;
        if (i <= j)
        {
            compars++;
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                swaps++;
            }
            i++;
            j--;
        }
    } while (i <= j);
    compars++;
    if (i < last)
        hoarasort(a, i, last);
    compars++;
    if (first < j)
        hoarasort(a, first, j);
}   
////////

//Сортировка слиянием
void MergeSort(vector <int> &arr, int start, int end) {
    if (end - start < 2)
        return;
    compars++;
    if (end - start == 2 && arr[start] > arr[end - 1]) {
        swap(arr[start], arr[end - 1]);
        swaps++;
        return;
    }
    compars += 2;
    //Делим массив пополам
    //Вызываем ф-ию сортировки для левой половины массива
    MergeSort(arr, start, (start + end) / 2);
    //Вызываем ф-ию сортировки для правой половины массива
    MergeSort(arr, (start + end) / 2, end);
    //Осуществляем слияние
    vector <int> add_arr;
    int start_1 = start, end_1 = (start + end) / 2;
    int start_2 = end_1, end_2 = end;
    while (add_arr.size() < end - start) {
        compars++;
        if ((start_1 >= end_1) || (start_2 < end_2 && arr[start_2] < arr[start_1])) {
            add_arr.push_back(arr[start_2]);
            swaps++;
            start_2++;
        }
        else {
            add_arr.push_back(arr[start_1]);
            swaps++;
            start_1++;
        }
        compars += 3;
    }
    compars++;
    for (int i = start; i < end; i++) {
        arr[i] = add_arr[i - start];
        swaps++;
    }
    compars++;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    vector <int> mas;
    auto begin = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    cout << "Введите размерность массива для проверки сортировки: ";
    int c;
    cin >> c;
    cout << "Выберите тип сортировки(1-Пузырёк; 2-Хоара; 3-Простого слияния) : ";
    int menu;
    cin >> menu;
    for (int i = 0; i < c; i++) {
        mas.push_back(rand());
    }
    if (menu == 1) {
        begin = chrono::steady_clock::now();
        bubblesort(mas, c);
        end = chrono::steady_clock::now();
        cout << "Random massive:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
        compars = 0;
        swaps = 0;

        begin = chrono::steady_clock::now();
        bubblesort(mas, c);
        end = chrono::steady_clock::now();
        cout << "Best:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;

        sort(mas.begin(), mas.end(), cmp);
        compars = 0;
        swaps = 0;

        begin = chrono::steady_clock::now();
        bubblesort(mas, c);
        end = chrono::steady_clock::now();
        cout << "Worst:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
    }
    else if (menu == 2) {

        begin = chrono::steady_clock::now();
        hoarasort(mas, 0, c);
        end = chrono::steady_clock::now();
        cout << "Random massive:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
        compars = 0;
        swaps = 0;

        begin = chrono::steady_clock::now();
        hoarasort(mas, 0, c);
        end = chrono::steady_clock::now();
        cout << "Best:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
        compars = 0;
        swaps = 0;

        sort(mas.begin(), mas.end(), cmp);

        begin = chrono::steady_clock::now();
        hoarasort(mas, 0, c);
        end = chrono::steady_clock::now();
        cout << "Worst:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
    }
    else if (menu == 3) {
        begin = chrono::steady_clock::now();
        MergeSort(mas, 0, c);
        end = chrono::steady_clock::now();
        cout << "Random massive:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
        compars = 0;
        swaps = 0;

        begin = chrono::steady_clock::now();
        MergeSort(mas, 0, c);
        end = chrono::steady_clock::now();
        cout << "Best:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
        compars = 0;
        swaps = 0;

        sort(mas.begin(), mas.end(), cmp);
        
        begin = chrono::steady_clock::now();
        MergeSort(mas, 0, c);
        end = chrono::steady_clock::now();
        cout << "Worst:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
        cout << compars + swaps << endl;
    }
	return 0;
}