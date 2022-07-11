#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>  
#include <chrono> 
#pragma warning(disable : 4996)

using namespace std;
struct inter
{
    int id, change;
};

struct record
{
    int id;
    char name[10];
};
bool cmp(inter& a, inter& b) {
    if (a.id < b.id) return true;
    return false;
}
void LinearSearch(int key)
{
    record* rec = new record;
    ifstream binFile2("binfile.bin", ios::binary);
    while (binFile2.read((char*)rec, sizeof(record))) {
        if (rec->id == key) {
            cout << rec->id << " " << rec->name << endl;
            break;
        }
    }
    binFile2.close();
}
void InterpolationalSearch(vector<inter>& a, int key)
{
    int l = 0, r = a.size() - 1, k = key, mid;
    while (l < r) {
        mid = l + abs((r - l) * (k - a[l].id) / (a[r].id - a[l].id));
        if (a[mid].id == k) {
            break;
        }
        else if (a[mid].id > k)
            r = mid;
        else
            l = mid + 1;
    }

    record* cd = new record;
    FILE* bin = fopen("binfile.bin", "ab+");
    fseek(bin, a[mid].change * sizeof(record), SEEK_SET);
    fread(cd, sizeof(record), 1, bin);

    cout << "\nИнтерполяционным поиском найдено:\n";
    cout << cd->id << " " << cd->name << endl;
}

int main()
{
    
    setlocale(LC_ALL, "Russian");
    vector <inter> a;
    ofstream binFile("binfile.bin", ios::binary);
    int n = 100000000;
    for (int i = 0; i < n-1; i++)
    {
        record rec = { rand() % 900001 + 100000, "company"};
        inter r = {rec.id,i};
        a.push_back(r);
        binFile.write((char*)&rec, sizeof(record));
    }
    record rec2 = { 563621, "company" };
    inter r2 = { rec2.id,n-1 };
    a.push_back(r2);
    binFile.write((char*)&rec2, sizeof(record));
    binFile.close();

    int key = 563621;
    cout << "Ключ: " << key << endl<<endl;
    sort(a.begin(), a.end(),cmp);
/////////////////////////////ЛИНЕЙНЫЙ ПОИСК//////////////////////////////////////
    auto begin = chrono::steady_clock::now();
    LinearSearch(key);
    auto end = chrono::steady_clock::now();
    cout << "Elapsed seconds:      "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
/////////////////////////////ИНТЕРПОЛЯЦИОННЫЙ ПОИСК//////////////////////////////////////
    begin = chrono::steady_clock::now();
    InterpolationalSearch(a, key);
    end = chrono::steady_clock::now();
    cout << "Elapsed seconds:      " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms\n";
}