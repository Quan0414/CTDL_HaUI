#include <bits/stdc++.h>

using namespace std;

struct sinhVien
{
    string hoDem;
    string ten;
    string gioiTinh;
    int diemTK;
};

struct Node
{
    sinhVien sv;
    Node *next;
};

typedef struct Node *node;

node create()
{
    sinhVien s;
    cout << "Nhap ho: ";
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
        cout << "Nhap tt sv thu " << i + 1 << ": ";
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
    cout << "Danh sach: \n";
    cout << left << setw(10) << "Ho" << setw(10) << "Ten" << setw(10) << "Gioi Tinh" << setw(10) << "Diem TK" << endl;
    node cur = L;
    while (cur != NULL)
    {
        cout << left << setw(10) << cur->sv.hoDem << setw(10) << cur->sv.ten << setw(10) << cur->sv.gioiTinh << setw(10) << cur->sv.diemTK << endl;
        cur = cur->next;
    }
}

void find(node L, string s)
{
    node tmp = L;
    while (tmp != NULL)
    {
        if (tmp->sv.ten == s)
        {
            cout << "TT sinh vien " << s << ": \n";
            cout << left << setw(10) << "Ho" << setw(10) << "Ten" << setw(10) << "Gioi Tinh" << setw(10) << "Diem TK" << endl;
            cout << left << setw(10) << tmp->sv.hoDem << setw(10) << tmp->sv.ten << setw(10) << tmp->sv.gioiTinh << setw(10) << tmp->sv.diemTK << endl;
            return;
        }
        else
            tmp = tmp->next;
    }
}

void del(node &L, string s)
{
    // xóa sv vừa tìm thấy
    node cur = L;
    node prev = NULL;
    while (cur != NULL)
    {
        if (cur->sv.ten == s)
        {
            if (prev == NULL)
            {
                L = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
            cout << "Da xoa sinh vien " << s << endl;
            cout << "Danh sach sau khi xoa: \n";
            display(L);

            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void insert(node &L)
{
    cout << "Nhap tt sinh vien can chen: ";
    node tmp = create();

    node cur = L;
    for(int i = 0; i < 1; i++)
    {
        cur = cur->next;
    }
    tmp->next = cur->next;
    cur->next = tmp;

  
    cout << "Da chen sinh vien vao vi tri thu 3.\n";
    cout << "Danh sach sau khi chen: \n";
    display(L);
}

//chèn vào đầu
void insertFirst(node &L)
{
    cout << "Nhap tt sinh vien can chen: ";
    node tmp = create();
    tmp->next = L;
    L = tmp;

    cout << "Da chen sinh vien vao vi tri dau.\n";
    cout << "Danh sach sau khi chen: \n";
    display(L);
}

//chèn vào cuối
void insertLast(node &L)
{
    cout << "Nhap tt sinh vien can chen: ";
    node tmp = create();
    if (L == NULL)
    {
        L = tmp;
    }
    else
    {
        node cur = L;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
    }

    cout << "Da chen sinh vien vao vi tri cuoi.\n";
    cout << "Danh sach sau khi chen: \n";
    display(L);
}

int main()
{
    node L = NULL;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    getInput(L, n);
    display(L);

    string ten;
    cout << "Nhap ten can tim: ";
    getline(cin, ten);
    find(L, ten);

    insert(L);


    return 0;
}
