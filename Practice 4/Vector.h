#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <regex>
using namespace std;

struct man {
    string number,name, surname;
    int day, month, year;
    string adress;
};
void set_elem(man &n) {
    cout << "Введите номер \n";
    cin >> n.number;
    cout << "Введите имя\n";
    cin>> n.name;
    cout << "Введите фамилию\n";
    cin>> n.surname;
    while (true) {
        cout << "Введите день рождения\n";
        cin >> n.day;
        if (n.day > 0 && n.day <= 28)
            break;
        else cout << "Неверная дата\n";
    }
    while (true) {
        cout << "Введите месяц рождения\n";
        cin >> n.month;
        if (n.month > 0 && n.month<= 12)
            break;
        else cout << "Неверный месяц\n";
    }
    while (true) {
        cout << "Введите год рождения\n";
        cin >> n.year;
        if (n.year > 0 && n.year<= 2021)
            break;
        else cout << "Неверный год\n";
    }
    cout << "Введите адрес\n";

    cin>> n.adress;
}

void show_note(vector<man> &note) {
    cout<<"‘Список друзей:\n";
    for (int i = 0; i < note.size(); i++) {
        cout << " Номер: " << note[i].number <<"; Имя: " << note[i].name<<"; Фамилия: "<< note[i].surname<<"; Дата рождения: " << note[i].day << "."<< note[i].month << "."<< note[i].year <<"; Адрес: "<< note[i].adress << "." << endl;
    }
}
void add_man(vector<man> &note, man &t) {
    for(int i = 0;i<note.size();i++)
        if (t.surname[0] == note[i].surname[0]) {
            note.insert(note.begin() + i, t);
            return;
        }
    note.push_back(t);
}

void delete_man(vector<man> &note, string number) {
    bool flag = false;
    for (int i = 0; i < note.size(); i++) {
        if (note[i].number == number) {
            note.erase(note.begin() + i);
            flag = true;
            break;
        }
    }
    if (!flag) cout << "Такого человека нет\n";
}

void show_man_to(vector<man> &note, int month) {
    bool flag = false;
    for (int i = 0; i < note.size(); i++) {
        if (note[i].month == month) {
            cout << "Номер: " << note[i].number <<"; Имя: " << note[i].name<<"; Фамилия: "<< note[i].surname<<"; Дата рождения: " << note[i].day << "."<< note[i].month << "."<< note[i].year <<"; Адрес: "<< note[i].adress << "." << endl;
            flag = true;
        }
    }
    if (!flag) cout << "Такого человека нет\n";
}
void find_date_num(vector<man> &note, string surname){
    for (int i = 0; i < note.size(); i++)
        if (note[i].surname == surname) {
            cout << " Номер: " << note[i].number << "; Дата рождения: " << note[i].day << "." << note[i].month << "."<< note[i].year << ".\n";
            return;
        }
    cout << "Такого человека нет\n";
}