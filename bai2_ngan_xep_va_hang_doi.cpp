// input
// Nhap so luong phan tu can them: 5
// Nhap cac phan tu: 10 20 30 40 50
// Nhap so luong phan tu can xoa: 2
// output
// Hang doi: 10 20 30 40 50
// Hang doi: 30 40 50
#include <iostream>
using namespace std;
//  hang doi dung mang
class QueueInt {
private:
    int *arr;
    int dau, cuoi, sucChua;
public:
    QueueInt(int kichThuoc) {
        sucChua = kichThuoc;
        arr = new int[sucChua];
        dau = cuoi = -1;
    }
    ~QueueInt() { delete[] arr; }
    bool Rong() { return dau == -1; }
    bool Day() { return (cuoi + 1) % sucChua == dau; }

    void Them(int x) {
        if (Day()) return;
        if (Rong()) dau = 0;
        cuoi = (cuoi + 1) % sucChua;
        arr[cuoi] = x;
    }
    void Xoa() {
        if (Rong()) return;
        if (dau == cuoi) dau = cuoi = -1;
        else dau = (dau + 1) % sucChua;
    }
    int Xem() { return Rong() ? -1 : arr[dau]; }
    void hienThi() {
        if (Rong()) {
            cout << "Hang doi rong\n";
            return;
        }
        cout << "Hang doi: ";
        int i = dau;
        while (true) {
            cout << arr[i] << " ";
            if (i == cuoi) break;
            i = (i + 1) % sucChua;
        }
        cout << endl;
    }
};

//  HANG DOI DUNG DANH SACH LIEN KET 
struct Nut {
    int duLieu;
    Nut* keTiep;
    Nut(int giaTri) : duLieu(giaTri), keTiep(NULL) {}
};
class HangDoiLienKet {
private:
    Nut *dau, *cuoi;
public:
    HangDoiLienKet() { dau = cuoi = NULL; }
    ~HangDoiLienKet() {
        while (!Rong()) Xoa();
    }
    bool Rong() { return dau == NULL; }
    void Them(int x) {
        Nut* nutMoi = new Nut(x);
        if (Rong()) dau = cuoi = nutMoi;
        else {
            cuoi->keTiep = nutMoi;
            cuoi = nutMoi;
        }
    }
    void Xoa() {
        if (Rong()) return;
        Nut* tam = dau;
        dau = dau->keTiep;
        delete tam;
        if (!dau) cuoi = NULL;
    }
    int Xem() { return Rong() ? -1 : dau->duLieu; }
    void hienThi() {
        if (Rong()) {
            cout << "Hang doi rong\n";
            return;
        }
        cout << "Hang doi: ";
        Nut* temp = dau;
        while (temp) {
            cout << temp->duLieu << " ";
            temp = temp->keTiep;
        }
        cout << endl;
    }
};
//  ham main 
int main() {
    int n, x;
    // Hang doi dung mang
    cout << "Nhap so luong phan tu can them: ";
    cin >> n;
    QueueInt q(n);
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.Them(x);
    }
    q.hienThi();
    cout << "Nhap so luong phan tu can xoa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        q.Xoa();
    }
    q.hienThi();
    return 0;
}
