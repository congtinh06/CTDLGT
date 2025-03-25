#include <iostream>
using namespace std;
// Cau truc Node cho danh sach so nguyen
struct Node {
    int data;  // Gia tri cua node
    Node* next;  // Con tro tro den node ke tiep trong danh sach
};
// Lop danh sach lien ket so nguyen
class ListInt {
public:
    Node* head;  // Con tro dau danh sach
    ListInt() { head = NULL; } // Ham khoi tao danh sach rong
    // Ham them phan tu vao dau danh sach
    void insert(int value) {
        Node* newNode = new Node{value, head}; // Tao node moi tro den head hien tai
        head = newNode; // Cap nhat head de tro vao node moi
    }
    // Ham xoa mot phan tu khoi danh sach
    void remove(int value) {
        Node** temp = &head; // Con tro gian tiep giup duyet danh sach
        while (*temp && (*temp)->data != value) // Tim phan tu co gia tri can xoa
            temp = &((*temp)->next);
        if (*temp) { // Neu tim thay phan tu can xoa
            Node* toDelete = *temp; // Luu node can xoa
            *temp = (*temp)->next; // Bo qua node can xoa
            delete toDelete; // Giai phong bo nho
        }
    }
    // Ham in danh sach lien ket
    void print() {
        Node* temp = head; // Bat dau tu node dau tien
        while (temp) { // Duyet qua tung node
            cout << temp->data << " "; // In gia tri node hien tai
            temp = temp->next; // Di chuyen den node tiep theo
        }
        cout << endl;
    }
    // Ham gop danh sach thu hai vao danh sach hien tai
    void merge(ListInt& other) {
        if (!head) head = other.head; // Neu danh sach hien tai rong gan head tu danh sach khac
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next; // Duyet den node cuoi cung
            temp->next = other.head; // Noi danh sach khac vao cuoi danh sach hien tai
        }
        other.head = NULL; // Dat danh sach thu hai thanh rong sau khi gop
    }
    // Ham xoa toan bo danh sach
    void clear() {
        while (head) { // Duyet tu dau den cuoi danh sach
            Node* temp = head;
            head = head->next; // Di chuyen head den node tiep theo
            delete temp; // Giai phong bo nho cua node cu
        }
    }
};
int main() {
    ListInt list1;
    cout << "Nhap 10 so nguyen: ";
    for (int i = 0; i < 10; i++) { // Nhap 10 so nguyen tu ban phim
        int num;
        cin >> num;
        list1.insert(num); // Them vao danh sach
    }
    cout << "Danh sach thu nhat: ";
    list1.print(); // In danh sach thu nhat
    int k;
    cout << "Nhap so can xoa: ";
    cin >> k;
    list1.remove(k); // Xoa so k khoi danh sach
    cout << "Danh sach sau khi xoa: ";
    list1.print();
    ListInt list2;
    cout << "Nhap 5 so nguyen cho danh sach thu hai: ";
    for (int i = 0; i < 5; i++) { // Nhap 5 so nguyen tu ban phim vao danh sach thu hai
        int num;
        cin >> num;
        list2.insert(num);
    }
    cout << "Danh sach thu hai: ";
    list2.print(); // In danh sach thu hai
    list1.merge(list2); // Gop danh sach thu hai vao danh sach thu nhat
    cout << "Danh sach sau khi gop: ";
    list1.print();
    list1.clear(); // Giai phong bo nho truoc khi ket thuc chuong trinh 
    return 0;
}
