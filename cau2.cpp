#include <iostream>
using namespace std;
// Cau truc SinhVien
struct SinhVien {
    char hoTen[50];   // Ho ten sinh vien
    char diaChi[70];  // Dia chi
    char lop[10];     // Lop hoc
    int khoa;         // Khoa hoc
};
// Cau truc Node danh sach lien ket
struct Node {
    SinhVien data;
    Node* next;
};
// Cau truc danh sach sinh vien
struct ListSV {
    Node* head;
};
// Khoi tao danh sach
void khoiTao(ListSV &list) {
    list.head = NULL;
}
// Tao node moi
Node* taoNode(SinhVien sv) {
    Node* p = new Node;
    p->data = sv;
    p->next = NULL;
    return p;
}
// Them sinh vien vao cuoi danh sach
void themSinhVien(ListSV &list, SinhVien sv) {
    Node* p = taoNode(sv);
    if (list.head == NULL) {
        list.head = p;
    } else {
        Node* temp = list.head;
        while (temp->next != NULL) {
        	temp = temp->next;
        }
        	temp->next = p;
    }
}
// Xuat danh sach sinh vien
void xuatDanhSach(ListSV list) {
    Node* temp = list.head;
    while (temp != NULL) {
        cout << temp->data.hoTen << " - " << temp->data.diaChi << " - "
             << temp->data.lop << " - " << temp->data.khoa << endl;
        temp = temp->next;
    }
}
// So sanh chuoi 
bool soSanhChuoi(const char* a, const char* b) {
    while (*a && *b) {
        if (*a != *b) return false;
        ++a; ++b;
    }
    return (*a == '\0' && *b == '\0');
}
// Xoa sinh vien theo ten
void xoaSinhVien(ListSV &list, const char* ten) {
    Node* temp = list.head;
    Node* prev = NULL;
    while (temp != NULL && soSanhChuoi(temp->data.hoTen, ten)) {
        list.head = temp->next;
        delete temp;
        temp = list.head;
    }   
    while (temp != NULL) {
        if (soSanhChuoi(temp->data.hoTen, ten)) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}
int main() {
    ListSV list;
    khoiTao(list);
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cout << "Ho ten: "; cin.getline(sv.hoTen, 50);
        cout << "Dia chi: "; cin.getline(sv.diaChi, 70);
        cout << "Lop: "; cin.getline(sv.lop, 10);
        cout << "Khoa: "; cin >> sv.khoa;
        cin.ignore();
        themSinhVien(list, sv);
    }
    cout << "Danh sach sinh vien ban dau:\n";
    xuatDanhSach(list);
    xoaSinhVien(list, "Nguyen Van Teo");
    xoaSinhVien(list, "Nguyen Van Cu");
    cout << "Danh sach sau khi xoa:\n";
    xuatDanhSach(list); 
    SinhVien newSV = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    themSinhVien(list, newSV);
    cout << "Danh sach sau khi them sinh vien moi:\n";
    xuatDanhSach(list);
    return 0;
}

