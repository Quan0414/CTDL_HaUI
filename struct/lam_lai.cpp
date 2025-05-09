#include <bits/stdc++.h>
using namespace std;

struct student
{
    string hoTen;
    float diemTB;
};

struct node
{
    student s;
    node *next;
};

typedef struct node* sv;

sv create()
{
    student s;
    cout << "Nhap ten sv: ";
    getline(cin, s.hoTen);
    cout << "Nhap diem trung binh: ";
    cin >> s.diemTB;
    cin.ignore();
    sv tmp = new node();
    tmp->s = s;
    tmp->next = NULL;

    return tmp;
}

void getInput(sv &L, int n)
{
    sv P = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap tt sv thu: " << i + 1 << endl;
        sv newS = create();
        if (L == NULL)
        {
            L = newS;
            P = newS;
        }
        else
        {
            P->next = newS;
            P = newS;
        }
    }
}

void display(sv L)
{
    cout << "Danh sach sinh vien:\n";
    //in ra dang bang
    cout << left << setw(20) << "Ho ten" << setw(15) << "Diem TB" << endl;
    cout << "----------------------------------------" << endl;
    sv current = L;
    while (current != NULL)
    {
        cout << left << setw(20) << current->s.hoTen << setw(15) << current->s.diemTB << endl;
        current = current->next;
    }
}

sv timMax(sv L)
{
    if (L == NULL)
        return NULL;

    sv maxSV = L;
    sv current = L->next;

    while (current != NULL)
    {
        if (current->s.diemTB > maxSV->s.diemTB)
        {
            maxSV = current;
        }
        current = current->next;
    }

    return maxSV;
}

void delFirstMax(sv &L)
{
    if (L == NULL)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    sv maxDTB = timMax(L);
    float maxDiem = maxDTB->s.diemTB;

    sv prev = NULL;
    sv current = L;

    while (current != NULL)
    {
        if (current->s.diemTB == maxDiem)
        {
            if (prev == NULL)
            {
                sv temp = L;
                L = L->next;    
                delete temp;
            }
            else
            {
                prev->next = current->next;
                delete current;
            }

            cout << "Da xoa sinh vien co diem TB cao nhat dau tien.\n";
            break;
        }

        prev = current;
        current = current->next;
    }
}

void delAllSvAn(sv &L, string hoTen)
{
    if (L == NULL)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    sv prev = NULL;
    sv current = L;

    while (current != NULL)
    {
        if (current->s.hoTen == hoTen)
        {
            if (prev == NULL)
            {
                sv temp = L;
                L = L->next;
                delete temp;
            }
            else
            {
                prev->next = current->next;
                delete current;
            }

            cout << "\n Da xoa sinh vien co ten: " << hoTen << endl;
            break;
        }

        prev = current;
        current = current->next;
    }
}

int main()
{
    sv L = NULL;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    getInput(L, n);
    
    display(L);

    delFirstMax(L);
    cout << "Danh sach sau khi xoa sinh vien diem cao nhat:\n";
    display(L);

    delAllSvAn(L, "An");
    cout << "Danh sach sau khi xoa sinh vien co ten An:\n";
    display(L);
    


    return 0;
}