
#include <iostream>
#include <vector>
using namespace std;
struct node{
        char data;
        node* next;
};
void set(node*& L) {
    char d;
    cin >> d;
    node *n = new node;
    if (n != NULL) {
        n->data = d;
        n->next = NULL;
        if (L == NULL)
            L = n;
        else {
            node *tmp = L;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = n;
        }
    }
}
void setN(node*& K,vector<char>m) {
    for (int i = 0; i < m.size(); i++) {
        node* n = new node;
        if (n != NULL) {
            n->data = m[i];
            n->next = NULL;
            if (K == NULL)
                K = n;
            else {
                node* tmp = K;
                while (tmp->next != NULL)
                    tmp = tmp->next;
                tmp->next = n;
            }
        }
    }
}
void change(node*& L) {

    node* p = L;
    while (p->next) {
        node* n = p->next;
        if (p->data == n->data)
            p->next = n->next;
        else
            p = p->next;
    }
}
void findmaxline(node*& L){
    node* p = L;
    int k = 1,m=1;
    while (p->next){
        node* n = p->next;
        if (p->data == n->data) {
            k++;
            m = max(m, k);
        }
        else
            k = 1;
        p = p->next;
    }
    cout <<"Максимальная последовательность равна - " << m << endl;

}
void print(node*& L)
{
    node* p = L;
    cout << "Ваш список:" << endl;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{   
    setlocale(LC_ALL, "Russian");
    int f,menu=1;
    cout << "Сколько элементов будет в списке?\n";
    cin >> f;
    node *L = NULL;
    cout << "Введите " << f << " значений через пробел : ";
    for (int i=0;i<f;i++){
        set(L);
    }
    print(L);
    while (menu != 0) {
        cout << endl;
        cout << "Какое задание вы хотите выполнить?\n";
        cout << "   1- Определить в списке L самую длинную последовательность, состоящую из одинаковых символов.\n";
        cout << "   2- В каждой последовательности одинаковых символов оставить только один.\n";
        cout << "   3- Создать новый список из цифр исходного, выполняя вставку элемента в новый список в порядке возрастания цифр без повторений.\n";
        cout << "   0- Выйти\n";
        cin >> menu;
        if (menu == 1)
            findmaxline(L);
        else if (menu == 2) {
            change(L);
            print(L);
        }
        else if (menu == 3) {
            vector <char> mas;
            node* K = NULL;
            node* p = L;
            while (p)
            {
                if (p->data >= 48 && p->data <= 57)
                    mas.push_back(p->data);
                p = p->next;
            }
            
            for (int i = 0; i < mas.size() - 1; i++) {
                int min = i;
                for (int j = i + 1; j < mas.size(); j++)
                    min = (mas[j] < mas[min]) ? j : min;
                if (i != min)
                {
                    char buf = mas[i];
                    mas[i] = mas[min];
                    mas[min] = buf;
                }
            }
            
            setN(K, mas);
            change(K);
            print(K);
        }
    }
}