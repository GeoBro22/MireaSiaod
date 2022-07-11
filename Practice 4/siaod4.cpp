#include "Arr.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu, s,menu1;

    bool flg = true;
    cout << "�� ����� ������� �� ������ ��������� �������(1-������������ ������; 2-Vector): ";
    cin >> menu;
    if (menu == 1) {
        int** a = new int*[10];
        for (int i = 0; i < 7; i++)
            a[i] = new int[7];
        do {
            cout << "��� �� ������ ������ �������������?\n    0-�������������\n    1-����\n";
            cin >> s;
        } while (s < 0);

        nman tek;
        if (s == 0) {
            tek = { 0, 6, new man[6] };
            man t = { "89884174664", "������","�������", 24, 7,2003,"������������ 33" };
            add_man(tek, t);
            t = { "89324343214", "����","�������", 12, 12,2002,"������� 57" };
            add_man(tek, t);
            t = { "89153231243", "���������","��������", 20, 12,2003,"��������� 12" };
            add_man(tek, t);
            t = { "89392389212", "��������","������", 5, 1,2004,"����������� 23" };
            add_man(tek, t);
            t = { "89124353223", "������","������������", 8, 10,2003,"������ 22" };
            add_man(tek, t);
            t = { "89123291921", "������","���������", 12, 2,2003,"����������� 12" };
            add_man(tek, t);
            show_note(tek);
        }
        else {
            tek = { 0, s, new man[s] };
            for (int k = 0; k < s; k++) {
                man temp;
                set_elem(temp);
                add_man(tek, temp);
            }
        }
        do {
            cout << "�������� �������:\n 1 - �������� ������\n 2 - ������� ������ �� ������\n 3 - ������, ���������� � ���������� �����\n 4 - ����� � ���� �������� ����� �� �������\n 0 - �����\n";
            while (true) {
                cin >> menu1;
                if (menu1 > 4 || menu1 < 0)
                    cout << "�������� �����\n";
                else
                    break;
            }
            switch (menu1) {
            case 1: {
                man temp;
                cout << "�������� ������\n";
                set_elem(temp);
                add_man(tek, temp);
                show_note(tek);
                break;
            }
            case 2: {
                string number;
                cout << "������� ����� �����\n";
                cin >> number;
                delete_man(tek, number);
                show_note(tek);
                break;
            }
            case 3: {
                int month;
                cout << "������� ����� ���������\n";
                cin >> month;
                show_man_to(tek, month);
                break;
            }
            case 4: {
                string surname;
                cout << "������� �������\n";
                cin >> surname;
                find_date_num(tek, surname);
                break;
            }
            case 0:
            {
                flg = false;
                break;
            }
            }
        } while (flg);
    }
    else if (menu == 2) {
        vector<man> note;
        do {
            cout << "��� �� ������ ������ �������������?\n    0-�������������\n    1-����\n";
            cin >> s;
        } while (s < 0);
        if (s == 0) {
            //
            man t = { "89884174664", "������","�������", 24, 7,2003,"������������ 33" };
            add_man(note, t);
            t = { "89324343214", "����","�������", 12, 12,2002,"������� 57" };
            add_man(note, t);
            t = { "89153231243", "���������","��������", 20, 12,2003,"��������� 12" };
            add_man(note, t);
            t = { "89392389212", "��������","������", 5, 1,2004,"����������� 23" };
            add_man(note, t);
            t = { "89124353223", "������","������������", 8, 10,2003,"������ 22" };
            add_man(note, t);
            t = { "89123291921", "������","���������", 12, 2,2003,"����������� 12" };
            add_man(note, t);

        }
        else {
            for (int k = 0; k < s; k++) {
                man temp;
                set_elem(temp);
                add_man(note, temp);
            }
        }
        show_note(note);
        do {
            cout << "�������� �������:\n 1 - �������� ������\n 2 - ������� ������ �� ������\n 3 - ������, ���������� � ���������� �����\n 4 - ����� � ���� �������� ����� �� �������\n 0 - �����\n";
            while (true) {
                cin >> menu1;
                if (menu1 > 4 || menu1 < 0)
                    cout << "�������� �����\n";
                else
                    break;
            }
            switch (menu1) {
            case 1: {
                man temp;
                cout << "�������� ������\n";
                set_elem(temp);
                add_man(note, temp);
                show_note(note);
                break;
            }
            case 2: {
                string number;
                cout << "������� ����� �����\n";
                cin >> number;
                delete_man(note, number);
                show_note(note);
                break;
            }
            case 3: {
                int month;
                cout << "������� ����� ���������\n";
                cin >> month;
                show_man_to(note, month);
                break;
            }
            case 4: {
                string surname;
                cout << "������� �������\n";
                cin >> surname;
                find_date_num(note, surname);
                break;
            }
            case 0: {
                flg = false;
                break;
            }
            }
        } while (flg);
    }


}
