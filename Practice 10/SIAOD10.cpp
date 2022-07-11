#include <iostream>
#include <string>  
#include <chrono> 
#include <regex> 
#include <Windows.h>
using namespace std;
void rabin_karp(string& text, string& pattern, int q)
{

    int m = pattern.length();
    int f = 0;
    int n = text.length();
    int p = 0, t = 0, h = 1, d = 26;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;//pattern;
        t = (d * t + text[i]) % q;//substring;
    }
    for (int i = 0; i <= n - m; i++)
    {

        if (p == t)
        {
            int flag = 0;
            for (int j = 0; j < m; j++)
            {

                if (text[i + j] != pattern[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                f++;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
    if (f>1 && f<5)
        cout<<pattern << " встрречается " << f <<" раза" << endl;
    else
        cout<<pattern<< " встречается " << f << " раз" << endl;

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int l = 100000;
    string s = "War and Peace (Romanized: Voyna i mir; [vɐjˈna i ˈmʲir]) is a literary work mixed with chapters on history and philosophy by the Russian author Leo Tolstoy.It was first published serially, then published in its entirety in 1869. It is regarded as one of Tolstoy's finest literary achievements and remains an internationally praised classic of world literature.";


    for (int i = 0; i < (l - 360) / 2; i++) {
        s = "a" + s;
    }

    for (int i = 0; i < (l - 360) / 2; i++) {
        s = s + "wart";
    }

    while (true) {
        int menu = -1;
        while (menu < 0 || menu>2) {
            cout << "Какое задание хотите выполнить?\n    1) Поиск колличества вождений образцов в текст\n    2) Поиск артикулов в тексте\n    0) Выход\n>";
            cin >> menu;
        }
        if (menu == 1) {

            
            
            string f;
            int k;
            cout << "---------------------------------------------------------\n";
            cout << "Сколько подстрок вы хотите проверить на вхождение?\n>";
            cin >> k;
            string* mas = new string[k];
            for (int i = 0; i < k; i++) {
                cout << "Введите " << i + 1 << " подстроку\n>";
                cin >> mas[i];
            }
            cout << "---------------------------------------------------------\n";
            for (int i = 0; i < k; i++) {
                rabin_karp(s, mas[i], 52);
            }
            cout << "---------------------------------------------------------\n";
        }
        else if (menu == 2) {
            string s = "aa22:162f:30a1:fc10";
            //string s;
            smatch k;
            cout << "---------------------------------------------------------\n";
            cout << s << endl;
            //cout << "Введите строку и в конце обязательно поставьте точку\n>";
            //getline(cin, s, '.');
            cout << "---------------------------------------------------------\n";
            cout << "Артикулы:" << endl;
            while (regex_search(s, k, regex("(([a-f\d]{4}:){4})")) > 0) {
                cout << k[0] << endl;
                string l = k[0];
                s = regex_replace(s, regex(l), "");
            }
            cout << "---------------------------------------------------------\n";
        }
        else
            break;
    }
}
