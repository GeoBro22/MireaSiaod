#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int countc(int n) {
    if (n / 10 != 0)
        return 2;
    return 1;
}
void changeP(char s[], char f[], int n, int s_len, int k, int i) {
    for (int j = i; j < s_len; j++) {
        f[k++] = s[j];
    }
    k = 0;
    for (int j = i + n + 2 - countc(n); j < s_len; j++) {
        s[j] = f[k++];
    }
    for (int j = 0; j < n + 2; j++) {
        if (j == 0)
            s[j + i - countc(n)] = '(';
        else if (j == n + 1)
            s[j + i - countc(n)] = ')';
        else s[j + i - countc(n)] = '+';
    }

}
void changeM(char s[], char f[], int n, int s_len, int k, int i) {
    for (int j = i; j < s_len; j++) {
        f[k++] = s[j];
    }
    k = 0;
    for (int j = i + n + 2 - countc(n); j < s_len; j++) {
        s[j] = f[k++];
    }
    for (int j = 0; j < n + 2; j++) {
        if (j == 0)
            s[j + i - countc(n)] = '(';
        else if (j == n + 1)
            s[j + i - countc(n)] = ')';
        else s[j + i - countc(n)] = '-';
    }
}
void changeNULL(char s[], char f[], int n, int s_len, int k, int i) {
    for (int j = i + 1; j < s_len; j++) {
        f[k++] = s[j];
    }
    k = 0;
    for (int j = i + 3; j < s_len; j++) {
        s[j] = f[k++];
    }
    for (int j = 0; j < 3; j++) {
        if (j == 0)
            s[j + i] = '(';
        else if (j == 2)
            s[j + i] = ')';
        else s[j + i] = '+';
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    while (true) {
        cout<< "Выберите, что хотите использовать: 1)Строку; 2)Массив символов; 0)Выход:";
        int menu;
        cin >> menu;
        if (menu == 1) {
            int n;
            string str, p, n_s = "";
            cout << "Введите строку, пожалуйста:" << endl;
            getline(cin, p);
            getline(cin, str);
            str += " ";
            n = 0;
            for (int i = 0; i < str.length(); i++) {
                if (isdigit(str[i])) {
                    n = n * 10 + str[i] - '0';
                    if (n == 0) {
                        n_s += "(+)";
                    }
                }
                else {
                    if (n >= 1 && n <= 19) {
                        n_s += "(";
                        if (n % 2 == 0) {
                            for (int j = 1; j <= n; j++) {
                                n_s += '+';
                            }
                        }
                        else {
                            for (int j = 1; j <= n; j++) {
                                n_s += '-';
                            }
                        }
                        n_s += ")";
                    }
                    n_s += str[i];
                    n = 0;
                }
            }
            cout << "Изменённая строка" << endl;
            for (int i = 0; i < n_s.length(); i++)
                cout << n_s[i];
            cout << endl << endl;
        }
        else if (menu == 2) {
            char s[256], f[256];
            int n, s_len;
            cout << "Введите строку, пожалуйста:" << endl;
            cin.getline(f, 256);
            cin.getline(s, 256);
            s_len = strlen(s) + 1;
            n = 0;
            for (int i = 0; i < s_len; i++) {
                if (isdigit(s[i]) && n < 10) {
                    n = n * 10 + s[i] - '0';

                    if (n == 0) {
                        int k = 0;
                        s_len += 3;
                        changeNULL(s, f, n, s_len, k, i);
                    }
                }
                else {
                    if (n >= 1 && n <= 19) {
                        if (n % 2 == 0) {
                            int k = 0;
                            s_len += n + 2 - countc(n);
                            changeP(s, f, n, s_len, k, i);
                        }
                        else {

                            int k = 0;
                            s_len += n + 2 - countc(n);
                            changeM(s, f, n, s_len, k, i);
                        }
                    }

                    n = 0;
                }

            }
            cout << "Изменённая строка" << endl;
            int c = 0;
            while (s[c] != '\0')
                cout << s[c++];
            cout <<endl <<endl;
        }
        else if (menu == 0)
            break;
    }
    return(0);
}