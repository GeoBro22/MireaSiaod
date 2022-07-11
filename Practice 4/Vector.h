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
    cout << "������� �����\n";
    cin >> n.number;
    cout << "������� ���\n";
    cin>> n.name;
    cout << "������� �������\n";
    cin>> n.surname;
    while (true) {
        cout << "������� ���� ��������\n";
        cin >> n.day;
        if (n.day > 0 && n.day <= 28)
            break;
        else cout << "�������� ����\n";
    }
    while (true) {
        cout << "������� ����� ��������\n";
        cin >> n.month;
        if (n.month > 0 && n.month<= 12)
            break;
        else cout << "�������� �����\n";
    }
    while (true) {
        cout << "������� ��� ��������\n";
        cin >> n.year;
        if (n.year > 0 && n.year<= 2021)
            break;
        else cout << "�������� ���\n";
    }
    cout << "������� �����\n";

    cin>> n.adress;
}

void show_note(vector<man> &note) {
    cout<<"������� ������:\n";
    for (int i = 0; i < note.size(); i++) {
        cout << " �����: " << note[i].number <<"; ���: " << note[i].name<<"; �������: "<< note[i].surname<<"; ���� ��������: " << note[i].day << "."<< note[i].month << "."<< note[i].year <<"; �����: "<< note[i].adress << "." << endl;
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
    if (!flag) cout << "������ �������� ���\n";
}

void show_man_to(vector<man> &note, int month) {
    bool flag = false;
    for (int i = 0; i < note.size(); i++) {
        if (note[i].month == month) {
            cout << "�����: " << note[i].number <<"; ���: " << note[i].name<<"; �������: "<< note[i].surname<<"; ���� ��������: " << note[i].day << "."<< note[i].month << "."<< note[i].year <<"; �����: "<< note[i].adress << "." << endl;
            flag = true;
        }
    }
    if (!flag) cout << "������ �������� ���\n";
}
void find_date_num(vector<man> &note, string surname){
    for (int i = 0; i < note.size(); i++)
        if (note[i].surname == surname) {
            cout << " �����: " << note[i].number << "; ���� ��������: " << note[i].day << "." << note[i].month << "."<< note[i].year << ".\n";
            return;
        }
    cout << "������ �������� ���\n";
}