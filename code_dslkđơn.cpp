#include<iostream>
using namespace std;

// Dinh nghia cau truc Node
struct Node{
    int info; // Du lieu
    Node* next; // Con tro den node tiep theo
};

// Ham tao mot node moi
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// 1. Khoi tao danh sach rong 
void Init(Node* &pHead) {
    pHead = NULL;
}

// 2. Kiem tra danh sach rong
bool isEmpty(Node* pHead) {
    return pHead == NULL;
}

// 3. Them mot phan tu vao dau danh sach
void InsertFirst(Node* &pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

// 4. Tim kiem mot phan tu trong danh sach
Node* Search(Node* pHead, int x) {
    Node* p = pHead;
    while (p != NULL) {
        if (p->info == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 5. Loai bo mot phan tu co noi dung x
void Remove(Node* &pHead, int x) {
    Node* p = pHead;
    Node* tp = NULL; // Node truoc p
    bool found = false;

    while (p != NULL && !found) {
        if (p->info == x) {
            found = true;
        } else {
            tp = p;
            p = p->next;
        }
    }

    if (found) {
        if (p == pHead) {
            pHead = p->next;
        } else {
            tp->next = p->next;
        }
        delete p;
    }
}

// 6. Lay noi dung cua mot phan tu tai vi tri pos
int Truy_xuat(Node* pHead, int pos) {
    Node* p = pHead;
    int count = 0;
    while (p != NULL) {
        if (count == pos) {
            return p->info;
        }
        p = p->next;
        count++;
    }
    return -1; // Tra ve -1 neu vi tri khong hop le	
}

// 7. Duyet danh sach
void Traverse(Node* pHead) {
    Node* p = pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

// 8. Huy bo danh sach
void Clear(Node* &pHead) {
    Node* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// 9. Sap xep danh sach tang dan (Selection Sort)
void Selection_Sort(Node* &pHead) {
    Node *p, *q, *pmin;
    int vmin;
    for (p = pHead; p != NULL && p->next != NULL; p = p->next) {
        vmin = p->info;
        pmin = p;
        for (q = p->next; q != NULL; q = q->next) {
            if (q->info < vmin) {
                vmin = q->info;
                pmin = q;
            }
        }
        // Hoan doi gia tri
        int temp = p->info;
        p->info = pmin->info;
        pmin->info = temp;
    }
}

// Ham main de nhap du lieu va test chuc nang
int main() {
    Node* pHead;
    Init(pHead); // Khoi tao danh sach rong

    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    cout << "Nhap " << n << " gia tri: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        InsertFirst(pHead, x);
    }

    cout << "Danh sach vua nhap: ";
    Traverse(pHead);

    // Tim kiem phan tu
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    Node* result = Search(pHead, x);
    if (result != NULL) {
        cout << "Tim thay " << x << " trong danh sach!" << endl;
    } else {
        cout << "Khong tim thay " << x << " trong danh sach!" << endl;
    }

    // Lay noi dung phan tu tai vi tri nhap vao
    int pos;
    cout << "Nhap vi tri can truy xuat: ";
    cin >> pos;
    int value = Truy_xuat(pHead, pos);
    if (value != -1) {
        cout << "Gia tri tai vi tri " << pos << ": " << value << endl;
    } else {
        cout << "Vi tri khong hop le!" << endl;
    }

    // Sap xep danh sach
    Selection_Sort(pHead);
    cout << "Danh sach sau khi sap xep tang dan: ";
    Traverse(pHead);

    // Xoa mot phan tu
    cout << "Nhap gia tri can xoa: ";
    cin >> x;
    Remove(pHead, x);
    cout << "Danh sach sau khi xoa phan tu " << x << ": ";
    Traverse(pHead);

    // Xoa danh sach
    Clear(pHead);
    cout << "Danh sach sau khi xoa toan bo: ";
    Traverse(pHead);

    return 0;
}

