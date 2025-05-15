#include <bits/stdc++.h>
using namespace std;

struct matHang
{
    string maHang;
    string tenHang;
    int soLuong;
};

struct node
{
    matHang mh;
    node *next;
};

typedef struct node *mh;

mh create()
{
    matHang e;
    cout << "Nhap ma hang: ";
    getline(cin, e.maHang);
    cout << "Nhap ten hang: ";
    getline(cin, e.tenHang);
    cout << "Nhap so luong: ";
    cin >> e.soLuong;
    cin.ignore();

    mh tmp = new node();
    tmp->mh = e;
    tmp->next = nullptr;

    return tmp;
}

void getInput(mh &L, int n)
{
    mh P = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin mat hang thu " << i + 1 << ": " << endl;
        mh newMH = create();
        if (L == nullptr)
        {
            L = newMH;
            P = newMH;
        }
        else
        {
            P->next = newMH;
            P = newMH;
        }
    }
}

void displayList(mh L)
{
    cout << "Danh sach mat hang:\n";
    cout << left << setw(20) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "So luong" << endl;
    cout << "--------------------------------------------------------" << endl;
    mh current = L;
    while (current != nullptr)
    {
        cout << left << setw(20) << current->mh.maHang
             << setw(20) << current->mh.tenHang
             << setw(15) << current->mh.soLuong
             << endl;
        current = current->next;
    }
}

//hien thi mat hang co so luong lon nhat
void findMax(mh L)
{
    mh maxNode = L;
    mh current = L->next;

    while (current != nullptr)
    {
        if (current->mh.soLuong > maxNode->mh.soLuong)
        {
            maxNode = current;
        }
        current = current->next;
    }

    cout << "Mat hang co so luong lon nhat:\n";
    cout << left << setw(20) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "So luong" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(20) << maxNode->mh.maHang
         << setw(20) << maxNode->mh.tenHang
         << setw(15) << maxNode->mh.soLuong
         << endl;
}

//xoa mat hang co so luong lon nhat
void delMax(mh &L)
{
    if (L == nullptr)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    mh maxNode = L;
    mh prevMax = nullptr;
    mh current = L;
    mh prev = nullptr;

    while (current != nullptr)
    {
        if (current->mh.soLuong > maxNode->mh.soLuong)
        {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    if (maxNode == L)
    {
        L = L->next;
        delete maxNode;
    }
    else
    {
        prevMax->next = maxNode->next;
        delete maxNode;
    }

    cout << "Da xoa mat hang co so luong lon nhat.\n";
}

void insertAfterMax(mh &L, matHang e)
{
    mh newMH = new node();
    newMH->mh = e;
    newMH->next = nullptr;

    if (L == nullptr)
    {
        L = newMH;
        return;
    }

    mh maxNode = L;
    mh current = L->next;

    while (current != nullptr)
    {
        if (current->mh.soLuong > maxNode->mh.soLuong)
        {
            maxNode = current;
        }
        current = current->next;
    }

    newMH->next = maxNode->next;
    maxNode->next = newMH;

    // Sắp xếp tăng dần theo số lượng
    for (mh i = L; i != nullptr; i = i->next)
    {
        for (mh j = i->next; j != nullptr; j = j->next)
        {
            if (i->mh.soLuong > j->mh.soLuong)
            {
                swap(i->mh, j->mh);
            }
        }
    }

    cout << "Danh sach sau khi chen mat hang:\n";
    displayList(L);
}


int main()
{
    mh L = nullptr;
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    cin.ignore();

    getInput(L, n);
    displayList(L);

    findMax(L);

    delMax(L);

    cout << "Danh sach sau khi xoa mat hang co so luong lon nhat:\n";
    displayList(L);

    cout << "Nhap thong tin mat hang can chen:\n";
    
    mh newMH = create();
    insertAfterMax(L, newMH->mh);

    return 0;
}