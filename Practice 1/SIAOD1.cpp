#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;

int Perf_index(int mas1[], int l)
{
    bool perfect = 0;
    int perf_index = 0;
    for (int i = 0; i < l; i++)
    {
        int m = 1;
        for (int j = 2; j < mas1[i]; j++)
        {
            if (mas1[i] % j == 0)
                m += j;
        }
        if (mas1[i] == m)
        {
            perfect = 1;
            perf_index = i;
            break;
        }
    }
    if (perfect == 1) return perf_index;
    else return -1;
}
int Perf_indexVec(vector <int> mas1, int l)
{
    bool perfect = 0;
    int perf_index = 0;
    for (int i = 0; i < l; i++)
    {
        int m = 1;
        for (int j = 2; j < mas1[i]; j++)
        {
            if (mas1[i] % j == 0)
                m += j;
        }
        if (mas1[i] == m)
        {
            perfect = 1;
            perf_index = i;
            break;
        }
    }
    if (perfect == 1) return perf_index;
    else return -1;

}
void ShiftRight(int m[], int l, int index, int now)
{
    for (int i = l + 1; i > index; i--)
        m[i + 1] = m[i];
    m[index + 1] = now;
    cout << "Ваш массив:";
    for (int i = 0; i < l + 1; i++)
        cout << m[i] << " ";
    cout << endl;
}

void ShiftLeft(int m[], int l, int index)
{
    for (int i = index - 1; i < l - 1; i++)
        m[i] = m[i + 1];
    m[l] = 0;
    cout << "Ваш массив:";
    for (int i = 0; i < l - 1; i++)
        cout << m[i] << " ";
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int menu, n, perfindex, newNum, menu2;
    int* mas2;
    cout<<"Какой массив вы хотите использовать?" << endl;
check1:
    cout << "1-Использовать статический массив; 2-Использовать динамический массив; 3-Использовать вектор:";
    cin >> menu;
    if (menu > 3 || menu < 1) {
        cout << "Неверное число" << endl;
        goto check1;
    }
    if (menu == 1) {
    check2:
        cout << "Сколько из 10 чисел вы будете вводить:";
        cin >> n;
        if (n > 10 || n < 1) {
            cout << "Лимит количества элементов для статичсекого массива-10" << endl;
            goto check2;
        
        }
    }
    else {
        cout << "Сколько чисел вы будете вводить:";
        cin >> n;
    }
    mas2 = new int[n];

    switch (menu)
    {
    case 1:
        int mas[10];



        for (int i = 0; i < n; i++) cin >> mas[i];
        cout << "Ваш набор числел:";
        for (int i = 0; i < n; i++) cout << mas[i] << " ";
        cout << endl;
        while (n <= 10) {
        again3:
            cout << "1-Найти совершенное число; 2-Добавить элемент после совершенного; 3-Удалить элемент перед совершенным числом; 0-Выйти:";
            cin >> menu2;
            switch (menu2) {
            case 1:
                if (Perf_index(mas, n) == -1) {
                    cout << "Совершенных чисел нет" << endl;
                    return(0);
                }
                else cout << "Индекс совершенного=" << Perf_index(mas, n) << endl;
                goto again3;

            case 2:
                if (n == 10) {
                    cout << "Нет места" << endl;
                    goto again3;
                }

                cout << "Вставить число:";
                cin >> newNum;
                perfindex = Perf_index(mas, n);
                if (perfindex == -1) {
                    cout << "Совершенных чисел нет" << endl;
                    return(0);
                }
                ShiftRight(mas, n, perfindex, newNum);
                n++;
                goto again3;

            case 3:
                int com;
                perfindex = Perf_index(mas, n);
                if (perfindex == -1) {
                    cout << "Совершенных чисел нет" << endl;
                    return(0);
                }
                if (perfindex != 0) {
                    ShiftLeft(mas, n, perfindex);
                    n--;
                    perfindex--;
                    goto again3;
                }
                else {
                    cout << "Нечего удалять"<<endl;
                    goto again3;             
                }
                
            case 0:
                return(0);
            }
            break;
        }
        break;
    case 2:
        int ko;
        for (int i = 0; i < n; i++) {
            cin >> ko;
            mas2[i] = ko;
        }
        cout << "Ваш набор числел:";
        for (int i = 0; i < n; i++) cout << mas2[i] << " ";
        cout << endl;
    again7:
        cout << "1-Найти совершенное число; 2-Добавить элемент после совершенного; 3-Удалить элемент перед совершенным числом; 0-Выйти:";
        cin >> menu2;
        switch (menu2)
        {
        case 1:
            if (Perf_index(mas2, n) == -1) {
                cout << "Совершенных чисел нет" << endl;
                return(0);
            }
            else cout << "Индекс совершенного=" << Perf_index(mas2, n) << endl;
            goto again7;
        case 2:
            cout << "Вставить число:";
            cin >> newNum;
            perfindex = Perf_index(mas2, n);
            if (perfindex == -1)
            {
                cout << "Совершенных чисел нет" << endl;
                return(0);
            }

            mas2 = (int*)realloc(mas2, sizeof(int) * (n + 1));
            ShiftRight(mas2, n, perfindex, newNum);
            n++;
            goto again7;

        case 3:
            int com;
            perfindex = Perf_index(mas2, n);
            if (perfindex == -1)
            {
                cout << "Совершенных чисел нет" << endl;
                return(0);
            }
            if (perfindex != 0)
            {
                ShiftLeft(mas2, n, perfindex);
                n--;
                mas2 = (int*)realloc(mas2, sizeof(int) * n);
                perfindex--;
                goto again7;
            }
            else
            {
                cout << "Нечего удалять"<<endl;
                goto again7;
            }
            goto again7;
        case 0:
            break;

        }
        break;

    case 3:
        vector <int> mas3;
        int num;

        for (int i = 0; i < n; i++) {
            cin >> num;
            mas3.push_back(num);
        }
        cout << "Ваш набор числел:";
        for (int i = 0; i < n; i++) cout << mas3[i] << " ";
        cout << endl;
    again4:
        cout << "1-Найти совершенное число; 2-Добавить элемент после совершенного; 3-Удалить элемент перед совершенным числом; 0-Выйти:";
        cin >> menu2;
        switch (menu2)
        {
        case 1:
            if (Perf_indexVec(mas3, n) == -1) {
                cout << "Совершенных чисел нет" << endl;
                return(0);
            }
            else cout << "Индекс совершенного=" << Perf_indexVec(mas3, n) << endl;
            goto again4;

        case 2:
            cout << "Вставить число:";
            cin >> newNum;
            perfindex = Perf_indexVec(mas3, n);
            if (perfindex == -1)
            {
                cout << "Совершенных чисел нет" << endl;
                return(0);
            }
            mas3.insert(mas3.begin() + perfindex + 1, newNum);
            n++;
            cout << "Ваш набор числел:";
            for (int i = 0; i < n; i++) cout << mas3[i] << " ";
            cout << endl;
            goto again4;

        case 3:
            int com;
            perfindex = Perf_indexVec(mas3, n);
            if (perfindex == -1)
            {
                cout << "Совершенных чисел нет" << endl;
                return(0);
            }
            if (perfindex != 0)
            {
                mas3.erase(mas3.begin() + perfindex - 1);
                perfindex--;
                n--;
                cout << "Ваш набор числел:";
                for (int i = 0; i < n; i++) cout << mas3[i] << " ";
                cout << endl;
                goto again4;
            }
            else
            {
                cout << "Нечего удалять" << endl;
                goto again4;
            }
        case 0:
            break;
        }
    }

    return(0);
}
