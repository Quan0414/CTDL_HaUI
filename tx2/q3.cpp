#include <bits/stdc++.h>
using namespace std;

struct nhanVien
{
    string hoDem;
    string ten;
    string gioi_tinh;
    string maNV;
    float heSoLuong;
};

struct node
{
    /* data */
    nhanVien nv;
    node *next;
};

typedef struct node *nv;

nv create()
{
    nhanVien e;
    cout << "Nhap ho dem: ";
    getline(cin, e.hoDem);
    cout << "Nhap ten: ";
    getline(cin, e.ten);
    cout << "Nhap gioi tinh: ";
    getline(cin, e.gioi_tinh);
    cout << "Nhap ma nhan vien: ";
    getline(cin, e.maNV);
    cout << "Nhap he so luong: ";
    cin >> e.heSoLuong;
    cin.ignore();

    nv tmp = new node();
    tmp->nv = e;
    tmp->next = nullptr;

    return tmp;
}

void getInput(nv &L, int n)
{
    nv P = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ": " << endl;
        nv newNV = create();
        if (L == nullptr)
        {
            L = newNV;
            P = newNV;
        }
        else
        {
            P->next = newNV;
            P = newNV;
        }
    }
}

void displayList(nv L)
{
    cout << "Danh sach nhan vien:\n";
    cout << left << setw(20) << "Ho dem" << setw(20) << "Ten"
         << setw(20) << "Gioi tinh" << setw(20) << "Ma nhan vien"
         << setw(20) << "He so luong" << endl;
    nv cur = L;
    while (cur != nullptr)
    {
        /* code */
        cout << left << setw(20) << cur->nv.hoDem << setw(20)
             << cur->nv.ten << setw(20) << cur->nv.gioi_tinh << setw(20)
             << cur->nv.maNV << setw(20) << cur->nv.heSoLuong << endl;

        cur = cur->next;
    }
}

void find(nv L, string s)
{
    // tim nhan vien theo ma nhan vien
    nv cur = L;

    while (cur != nullptr)
    {
        if (cur->nv.maNV == s)
        {
            cout << "Thong tin nhan vien can tim:\n";
            cout << left << setw(20) << "Ho dem" << setw(20) << "Ten"
                 << setw(20) << "Gioi tinh" << setw(20) << "Ma nhan vien"
                 << setw(20) << "He so luong" << endl;
            cout << left << setw(20) << cur->nv.hoDem << setw(20)
                 << cur->nv.ten << setw(20) << cur->nv.gioi_tinh << setw(20)
                 << cur->nv.maNV << setw(20) << cur->nv.heSoLuong << endl;
            return;
        }
        cur = cur->next;
    }
}

// xóa nhân viên đứng sau nhân viên vừa tìm thấy
void delAfterFind(nv &L, string s)
{
    nv cur = L;

    while (cur != nullptr)
    {
        if (cur->nv.maNV == s)
        {
            if (cur->next != nullptr)
            {
                nv temp = cur->next;
                cur->next = temp->next;
                delete temp;

                cout << "Danh sach sau khi xoa nhan vien:\n";
                displayList(L);
            }
            else
            {
                cout << "Khong co nhan vien nao sau nhan vien " << s << endl;
            }
            return;
        }
        cur = cur->next;
    }
}

// chèn nhân viên vào đầu danh sách
void insertFirst(nv &L, nhanVien e)
{
    nv newNV = new node();
    newNV->nv = e;
    newNV->next = L;
    L = newNV;

    // hiển thị danh sách theo hệ số lương tăgn dần
    cout << "Danh sach da duoc sap xep theo he so luong tang dan.\n";

    for (nv i = L; i != nullptr; i = i->next)
    {
        for (nv j = i->next; j != nullptr; j = j->next)
        {
            if (i->nv.heSoLuong > j->nv.heSoLuong)
            {
                swap(i->nv, j->nv);
            }
        }
    }
    displayList(L);
}

int main()
{
    nv L = nullptr;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();

    getInput(L, n);
    displayList(L);

    string s;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> s;

    find(L, s);

    delAfterFind(L, s);

    cout << "Nhap thong tin nhan vien can chen vao dau danh sach:\n";
    cin.ignore();
    nv tmp = create();
    insertFirst(L, tmp->nv);

    return 0;
}