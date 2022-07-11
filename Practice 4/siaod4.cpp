#include "Arr.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu, s,menu1;

    bool flg = true;
    cout << "На каком массиве вы хотите выполнить задание(1-Динамический массив; 2-Vector): ";
    cin >> menu;
    if (menu == 1) {
        int** a = new int*[10];
        for (int i = 0; i < 7; i++)
            a[i] = new int[7];
        do {
            cout << "Как вы хотите ввести пользователей?\n    0-Автоматически\n    1-Сами\n";
            cin >> s;
        } while (s < 0);

        nman tek;
        if (s == 0) {
            tek = { 0, 6, new man[6] };
            man t = { "89884174664", "Георги","Джиадзе", 24, 7,2003,"Студенческая 33" };
            add_man(tek, t);
            t = { "89324343214", "Артём","Демидов", 12, 12,2002,"Садовая 57" };
            add_man(tek, t);
            t = { "89153231243", "Ростислав","Кашенцев", 20, 12,2003,"Кузнецкая 12" };
            add_man(tek, t);
            t = { "89392389212", "Элеонора","Чакрян", 5, 1,2004,"Олимпийская 23" };
            add_man(tek, t);
            t = { "89124353223", "Максим","Колиснеченко", 8, 10,2003,"Ленина 22" };
            add_man(tek, t);
            t = { "89123291921", "Виктор","Макушенко", 12, 2,2003,"Кутузовская 12" };
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
            cout << "Варианты заданий:\n 1 - Добавить запись\n 2 - Удалить запись по номеру \n 3 - Друзья, родившиеся в конкретный месяц\n 4 - Номер и дата рождения друга по фамилии\n 0 - Выход\n";
            while (true) {
                cin >> menu1;
                if (menu1 > 4 || menu1 < 0)
                    cout << "Неверный номер\n";
                else
                    break;
            }
            switch (menu1) {
            case 1: {
                man temp;
                cout << "Создание записи\n";
                set_elem(temp);
                add_man(tek, temp);
                show_note(tek);
                break;
            }
            case 2: {
                string number;
                cout << "Введите номер друга\n";
                cin >> number;
                delete_man(tek, number);
                show_note(tek);
                break;
            }
            case 3: {
                int month;
                cout << "Введите месяц рождения \n";
                cin >> month;
                show_man_to(tek, month);
                break;
            }
            case 4: {
                string surname;
                cout << "Введите фамилию\n";
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
            cout << "Как вы хотите ввести пользователей?\n    0-Автоматически\n    1-Сами\n";
            cin >> s;
        } while (s < 0);
        if (s == 0) {
            //
            man t = { "89884174664", "Георги","Джиадзе", 24, 7,2003,"Студенческая 33" };
            add_man(note, t);
            t = { "89324343214", "Артём","Демидов", 12, 12,2002,"Садовая 57" };
            add_man(note, t);
            t = { "89153231243", "Ростислав","Кашенцев", 20, 12,2003,"Кузнецкая 12" };
            add_man(note, t);
            t = { "89392389212", "Элеонора","Чакрян", 5, 1,2004,"Олимпийская 23" };
            add_man(note, t);
            t = { "89124353223", "Максим","Колиснеченко", 8, 10,2003,"Ленина 22" };
            add_man(note, t);
            t = { "89123291921", "Виктор","Макушенко", 12, 2,2003,"Кутузовская 12" };
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
            cout << "Варианты заданий:\n 1 - Добавить запись\n 2 - Удалить запись по номеру \n 3 - Друзья, родившиеся в конкретный месяц\n 4 - Номер и дата рождения друга по фамилии\n 0 - Выход\n";
            while (true) {
                cin >> menu1;
                if (menu1 > 4 || menu1 < 0)
                    cout << "Неверный номер\n";
                else
                    break;
            }
            switch (menu1) {
            case 1: {
                man temp;
                cout << "Создание записи\n";
                set_elem(temp);
                add_man(note, temp);
                show_note(note);
                break;
            }
            case 2: {
                string number;
                cout << "Введите номер друга\n";
                cin >> number;
                delete_man(note, number);
                show_note(note);
                break;
            }
            case 3: {
                int month;
                cout << "Введите месяц рождения \n";
                cin >> month;
                show_man_to(note, month);
                break;
            }
            case 4: {
                string surname;
                cout << "Введите фамилию\n";
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
