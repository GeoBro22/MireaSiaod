#include <iostream>
using namespace std;
int CSqrt(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
int RecCSqrt(int n,int s) {
    s += n % 10;
    n /= 10;
    if (n == 0) {
        return s;
    }
    else {
        return RecCSqrt(n,s);
    }
}
struct node {
    int data;
    node* next, * prv;
};
void set(node*& L, node*& t) {
    int d;
    cin >> d;
    node* n = new node;
    if (n != NULL) {
        n->data = d;
        n->next = NULL;
        if (L == NULL) {
            n->prv = NULL;
            L = n;
        }
        else {
            node* tmp = L;
            while ((tmp->next) != NULL)
                tmp = tmp->next;
            tmp->next = n;
            n->prv = t;
        }
        t = n;
    }
}
int Old(node*& f,int k) {
    if (!f) 
        return k;
    else{
        if (f->data % 2 == 0)
            k += 1;
        f = f->prv;
        return Old(f,k);
    }
}
void printN(node*& L)
{
    node* p = L;
    cout << "Ваш список:" << endl;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    while (true) {
        int menu1 = 3, menu2 = 3, n=-1;
        while (menu1 < 0 || menu1>2){
            cout << "Какое задание Вы желаете выполнить?\n    1-Найти цифровой корень числа\n    2-Найти количество чётных элементов в двунаправленом списке\n    0-Выйти\n";
            cin >> menu1;
        } 
        if (menu1 == 1) {
            while (menu2 < 1 || menu2>2) {
                cout << "Как вы хотите найти цифровой корень?\n    1-Использовать итерационный алгоритм\n    2-Использовать рекурсивный алгоритм\n";
                cin >> menu2;
            }
            cout << "Введите число : ";
            cin >> n;
            if (menu2 == 1)
                cout << "Цифровой корень числа равен " << CSqrt(abs(n)) << "\n\n";
            else {
                int sum = 0;
                cout << "Цифровой корень числа равен " << RecCSqrt(abs(n),sum) << "\n\n";
            }
        }
        else if (menu1 == 2) {
            node* L = NULL, * t = NULL;
            while (n < 1) {
                cout << "Сколько элементов будет в списке?\n";
                cin >> n;
            }
            cout << "Введите " << n << " значений через пробел : ";
            for (int i = 0; i < n; i++) {
                set(L,t);
            }
            printN(L);
            node* f = t;
            int k = 0;
            cout << "\nВ списке " << Old(t,k) << " чётных чисел\n\n";
        }
        else
            return 0;
    }
}