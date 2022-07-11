#include "queue.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void InfToPref(string str)
{
    vector <char> que;
    int counter = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            que.push_back(str[i]);
            str.erase(i, 1);
        }
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (i + 1 < str.size() && (str[i + 1] == '*' || str[i + 1] == '/'))
        {
            que.push_back(str[i + 1]);
            que.push_back(str[i]);
            i++;
        }
        else que.push_back(str[i]);
    }
    cout << "В префиксном виде это выражение будет выглядеть: ";
    for (int i = 0; i < que.size(); i++)
        cout << que[i];
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice=-1,menu=-1,size;
    string elem;
    while (choice > 2 || choice < 1) {
        cout << "Какое задание вы хотите выполнить? (1-Первое задание, 2-Второе задание):\n";
        cin >> choice;
    }
    if (choice == 1) {
        while (menu > 2 || menu < 1) {
            cout << "На чём вы хотите построить очередь? (1-Массив; 2-Однонаправленный список):\n";
            cin >> menu;
        }
        if (menu == 1) {
            cout << "Введите длину очереди: ";
            cin >> size;
            string* a = new string[size];
            for (int i = 0; i < size; i++) {
                a[i] = "_";
            }
            queueM ob(a, size);
            while (true) {
                int menu2 = -1;
                while (menu2 > 5 || menu2 < 0) {
                    cout << "Введите номер задания:\n    1-Втолкнуть элемент в очередь\n    2-Вытолкнуть элемент из очереди\n    3-Найти значение элемента в вершине\n    4-Очистить очередь\n    5-Проверить, пуста ли очередь\n    0-Выход\n";
                    cin >> menu2;
                }
                switch (menu2)
                {
                case 1:
                    ob.push();
                    break;
                case 2:
                    ob.kick();
                    break;
                case 3:
                    ob.findlast();
                    break;
                case 4:
                    ob.CleanUp();
                    break;
                case 5:
                    ob.isClean();
                    break;
                case 0:
                    return(0);
                }
            }
        }
        else if (menu == 2) {
            cout << "Введите длину очереди: ";
            cin >> size;
            queueS::node* L = NULL;
            queueS ob1(L, size);
            ob1.set();
            while (true) {
                int menu2 = -1;               
                while (menu2 > 5 || menu2 < 0) {
                    cout << "Введите номер задания:\n    1-Втолкнуть элемент в очередь\n    2-Вытолкнуть элемент из очереди\n    3-Найти значение элемента в вершине\n    4-Очистить очередь\n    5-Проверить, пуста ли очередь\n    0-Выход\n";
                    cin >> menu2;
                }
                switch (menu2)
                {
                case 1:
                    ob1.push();
                    break;
                case 2:
                    ob1.kick();
                    break;
                case 3:
                    ob1.findlast();
                    break;
                case 4:
                    ob1.CleanUp();
                    break;
                case 5:
                    ob1.isClean();
                    break;
                case 0:
                    return(0);
                }
            }

        }
    }
    else {
        string c;
        cout << "Введите инфиксное выражение\n";
        cin >> c;
        InfToPref(c);
    }
}
