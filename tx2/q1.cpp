#include <bits/stdc++.h>
using namespace std;

struct sinhVien
{
    string hoDem;
    string ten;
    string gioiTinh;
    float diemTK;
};

struct Node
{
    sinhVien sv;
    Node *next;
};

typedef Node *node;

node create()
{
    sinhVien s;
    cout << "Nhap ho dem: ";
    getline(cin, s.hoDem);
    cout << "Nhap ten: ";
    getline(cin, s.ten);
    cout << "Nhap gioi tinh: ";
    getline(cin, s.gioiTinh);
    cout << "Nhap diem tk: ";
    cin >> s.diemTK;
    cin.ignore();

    node tmp = new Node();
    tmp->sv = s;
    tmp->next = NULL;

    return tmp;
}

void getInput(node &L, int n)
{
    node P = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << ": \n";
        node tmp = create();
        if (L == NULL)
        {
            L = tmp;
            P = tmp;
        }
        else
        {
            P->next = tmp;
            P = tmp;
        }
    }
}

void display(node L)
{
    cout<<"Danh sach sinh vien: \n";
    cout<<left<<setw(20)<<"Ho dem"<<setw(10)<<"Ten"<<setw(10)<<"Gioi tinh"<<setw(10)<<"Diem TK"<<endl;
    node cur = L;
    while(cur != NULL)
    {
        cout<<left<<setw(20)<<cur->sv.hoDem<<setw(10)<<cur->sv.ten<<setw(10)<<cur->sv.gioiTinh<<setw(10)<<cur->sv.diemTK<<endl;
        cur = cur->next;
    }
}

void find(node L, string s)
{
    node cur = L;
    while(cur != NULL)
    {
        if(cur->sv.ten == s){
            cout<<left<<setw(20)<<"Ho dem"<<setw(10)<<"Ten"<<setw(10)<<"Gioi tinh"<<setw(10)<<"Diem TK"<<endl;
            cout<<left<<setw(20)<<cur->sv.hoDem<<setw(10)<<cur->sv.ten<<setw(10)<<cur->sv.gioiTinh<<setw(10)<<cur->sv.diemTK<<endl;
            return;
        }
        cur = cur->next;
    }
}

void delSV(node &L, string s)
{
    node cur = L;
    node prev = NULL;

    while (cur != NULL)
    {
        if(cur->sv.ten == s)
        {
            if(prev == NULL)
            {
                L = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            delete cur;
            cout<<"Xoa thanh cong\n";
            display(L);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void insert(node &L)
{
    cout<<"Nhap tt sinh vien can chen: \n";
    node tmp = create();

    node cur = L;
    for (int i = 0; i < 1; i++)
    {
        cur = cur->next;
    }

    tmp->next = cur->next;
    cur->next = tmp;

    // sap xep danh sach theo diem tk
    node p = L;
    while (p != NULL)
    {
        node q = p->next;
        while (q != NULL)
        {
            if (p->sv.diemTK > q->sv.diemTK)
            {
                sinhVien temp = p->sv;
                p->sv = q->sv;
                q->sv = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    cout<<"Danh sach sau khi chen va sap xep: \n";
    display(L);

}

int main()
{
    node L = NULL;
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    cin.ignore();
    getInput(L, n);
    display(L);

    string s;
    cout<<"Nhap ten sinh vien can tim: ";
    getline(cin, s);
    find(L, s);
    delSV(L, s);

    insert(L);

    return 0;
}

