#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct Thuoc {
    string maThuoc;
    string tenThuoc;
    string nhaSanXuat;
    string dangThuoc;
    float donGia;
    string congDung;
};

// Hàm xuất thông tin của một thuốc
void xuatThongTinThuoc(const Thuoc &t) {
    cout << "Ma thuoc: " << t.maThuoc << endl;
    cout << "Ten thuoc: " << t.tenThuoc << endl;
    cout << "Nha san xuat: " << t.nhaSanXuat << endl;
    cout << "Dang thuoc: " << t.dangThuoc << endl;
    cout << "Don gia: "  << t.donGia << " VND" << endl;
    cout << "Cong dung: " << t.congDung << endl;
    cout << "-----------------------------------" << endl;
}

// Hàm tạo và xuất mảng chứa danh sách thuốc
void taoVaXuatDanhSachThuoc(Thuoc *dsThuoc, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho thuoc thu " << i + 1 << ":" << endl;
        cout << "Ma thuoc: ";
        cin >> dsThuoc[i].maThuoc;
        cout << "Ten thuoc: ";
        cin.ignore(); // Để tránh lỗi getline sau cin
        getline(cin, dsThuoc[i].tenThuoc);
        cout << "Nha san xuat: ";
        getline(cin, dsThuoc[i].nhaSanXuat);
        cout << "Dang thuoc (vien/nuoc): ";
        cin >> dsThuoc[i].dangThuoc;
        cout << "Don gia: ";
        cin >> dsThuoc[i].donGia;
        cout << "Cong dung: ";
        cin.ignore();
        getline(cin, dsThuoc[i].congDung);
    }

    cout << "Danh sach thuoc:" << endl;
    for (int i = 0; i < n; ++i) {
        xuatThongTinThuoc(dsThuoc[i]);
    }
}

// Hàm so sánh theo mã thuốc để sử dụng trong sắp xếp
bool soSanhTheoMaThuoc(const Thuoc &a, const Thuoc &b) {
    return a.maThuoc < b.maThuoc;
}

// Hàm sắp xếp danh sách thuốc tăng dần theo mã thuốc
void sapXepDanhSachTheoMaThuoc(Thuoc *dsThuoc, int n) {
    sort(dsThuoc, dsThuoc + n, soSanhTheoMaThuoc);
}

// Hàm tìm kiếm theo mã thuốc bằng giải thuật Binary Search
int binarySearchTheoMaThuoc(const Thuoc *dsThuoc, int left, int right, const string &maThuocCanTim) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (dsThuoc[mid].maThuoc == maThuocCanTim) {
            return mid;
        }
        if (dsThuoc[mid].maThuoc < maThuocCanTim) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    int n;
    cout << "Nhap so luong thuoc: ";
    cin >> n;

    Thuoc *dsThuoc = new Thuoc[n];

    taoVaXuatDanhSachThuoc(dsThuoc, n);

    // Sắp xếp danh sách thuốc theo mã thuốc
    sapXepDanhSachTheoMaThuoc(dsThuoc, n);
    cout << "Danh sach sau khi sap xep:" << endl;
    for (int i = 0; i < n; ++i) {
        xuatThongTinThuoc(dsThuoc[i]);
    }

    // Tìm kiếm theo mã thuốc
    string maThuocCanTim = "T01";
    int ketQuaTimKiem = binarySearchTheoMaThuoc(dsThuoc, 0, n - 1, maThuocCanTim);
    if (ketQuaTimKiem != -1) {
        cout << "Tim thay thuoc co ma " << maThuocCanTim << " tai vi tri " << ketQuaTimKiem + 1 << endl;
        xuatThongTinThuoc(dsThuoc[ketQuaTimKiem]);
    } else {
        cout << "Khong tim thay thuoc co ma " << maThuocCanTim << endl;
    }

    delete[] dsThuoc; // Giải phóng bộ nhớ
    return 0;
}
