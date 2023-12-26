#include <iostream>
#include <cmath>

using namespace std;

// Hàm nhập mảng
void nhapMang(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

// Hàm tạo mảng ngẫu nhiên
void taoMangNgauNhien(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100; // Số ngẫu nhiên từ 0 đến 99
    }
}

// Hàm xuất mảng
void xuatMang(int *a, int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// Hàm xuất phần tử có phần nguyên là số nguyên tố
void xuatSoNguyenTo(int *a, int n) {
    cout << "Cac phan tu co phan nguyen la so nguyen to: ";
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(a[i])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

// Hàm xuất phần thập phân của mỗi phần tử
void xuatPhanThapPhan(int *a, int n) {
    cout << "Cac phan thap phan cua cac phan tu: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] - static_cast<int>(a[i]) << " ";
    }
    cout << endl;
}

// Hàm đếm số phần tử có phần nguyên chứa chữ số 2
int demSoChuaChuSoHai(int *a, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int phanNguyen = abs(static_cast<int>(a[i]));
        while (phanNguyen > 0) {
            if (phanNguyen % 10 == 2) {
                ++count;
                break;
            }
            phanNguyen /= 10;
        }
    }
    return count;
}

// Hàm xóa các phần tử có phần nguyên là lẻ
void xoaPhanTuLe(int *&a, int &n) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (static_cast<int>(a[i]) % 2 == 0) {
            a[j++] = a[i];
        }
    }
    n = j;
}

// Hàm tìm số lần xuất hiện của phần tử x trong mảng
int timSoLanXuatHien(int *a, int n, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) {
            ++count;
        }
    }
    return count;
}

// Hàm xóa phần tử max/min
void xoaPhanTuMaxMin(int *&a, int &n) {
    if (n <= 1) {
        delete[] a;
        a = nullptr;
        n = 0;
        return;
    }

    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        } else if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }

    // Xóa phần tử max
    for (int i = maxIndex; i < n - 1; ++i) {
        a[i] = a[i + 1];
    }

    // Xóa phần tử min
    for (int i = minIndex; i < n - 2; ++i) {
        a[i] = a[i + 2];
    }

    n -= 2;
}

// Hàm thêm x vào sau số lớn nhất của a
void themXVaoSauMax(int *&a, int &n, int x) {
    if (n == 0) {
        a = new int[1]{x};
        ++n;
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }

    // Tạo mảng mới có kích thước lớn hơn
    int *newArray = new int[n + 1];

    // Sao chép các phần tử từ a sang newArray
    for (int i = 0; i <= maxIndex; ++i) {
        newArray[i] = a[i];
    }

    // Thêm x vào sau số lớn nhất
    newArray[maxIndex + 1] = x;

    // Sao chép phần còn lại của a sang newArray
    for (int i = maxIndex + 2; i < n + 1; ++i) {
        newArray[i] = a[i - 1];
    }

    delete[] a;
    a = newArray;
    ++n;
}

// Hàm thêm x vào trước số nhỏ nhất của a
void themXVaoTruocMin(int *&a, int &n, int x) {
    if (n == 0) {
        a = new int[1]{x};
        ++n;
        return;
    }

    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }

    // Tạo mảng mới có kích thước lớn hơn
    int *newArray = new int[n + 1];

    // Sao chép các phần tử từ a sang newArray
    for (int i = 0; i < minIndex; ++i) {
        newArray[i] = a[i];
    }

    // Thêm x vào trước số nhỏ nhất
    newArray[minIndex] = x;

    // Sao chép phần còn lại của a sang newArray
    for (int i = minIndex + 1; i < n + 1; ++i) {
        newArray[i] = a[i - 1];
    }

    delete[] a;
    a = newArray;
    ++n;
}

// Hàm sắp xếp mảng theo thuật toán Interchange Sort
void interchangeSort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

// Hàm sắp xếp mảng theo thuật toán Selection Sort
void selectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

// Hàm sắp xếp mảng theo thuật toán Quick Sort
void quickSort(int *a, int left, int right) {
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(a, left, j);
    }
    if (i < right) {
        quickSort(a, i, right);
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int *a = new int[n];

    // Chọn chức năng
    int choice;
    do {
        cout << "\nChon chuc nang:\n";
        cout << "1. Nhap mang\n";
        cout << "2. Tao mang ngau nhien\n";
        cout << "3. Xuat so nguyen to\n";
        cout << "4. Xuat phan thap phan\n";
        cout << "5. Dem so phan tu co phan nguyen chua chu so 2\n";
        cout << "6. Xoa cac phan tu co phan nguyen la le\n";
        cout << "7. Tim so lan xuat hien cua mot phan tu\n";
        cout << "8. Xoa phan tu max/min\n";
        cout << "9. Them phan tu vao sau so lon nhat\n";
        cout << "10. Them phan tu vao truoc so nho nhat\n";
        cout << "11. Sap xep tang/giam theo Interchange Sort, Selection Sort, Quick Sort\n";
        cout << "0. Thoat\n";

        cin >> choice;

        switch (choice) {
            case 1:
                nhapMang(a, n);
                break;
            case 2:
                taoMangNgauNhien(a, n);
                break;
            case 3:
                xuatSoNguyenTo(a, n);
                break;
            case 4:
                xuatPhanThapPhan(a, n);
                break;
            case 5:
                cout << "So phan tu co phan nguyen chua chu so 2: " << demSoChuaChuSoHai(a, n) << endl;
                break;
            case 6:
                xoaPhanTuLe(a, n);
                xuatMang(a, n);
                break;
            case 7:
                int x;
                cout << "Nhap phan tu can tim: ";
                cin >> x;
                cout << "So lan xuat hien cua " << x << " la: " << timSoLanXuatHien(a, n, x) << endl;
                break;
            case 8:
                xoaPhanTuMaxMin(a, n);
                xuatMang(a, n);
                break;
            case 9:
                cout << "Nhap gia tri can them: ";
                cin >> x;
                themXVaoSauMax(a, n, x);
                xuatMang(a, n);
                break;
            case 10:
                cout << "Nhap gia tri can them: ";
                cin >> x;
                themXVaoTruocMin(a, n, x);
                xuatMang(a, n);
                break;
            case 11:
                cout << "Chon thu tu sap xep:\n1. Tang dan\n2. Giam dan\n";
                int sortOrder;
                cin >> sortOrder;
                switch (sortOrder) {
                    case 1:
                        interchangeSort(a, n);
                        xuatMang(a, n);
                        break;
                    case 2:
                        selectionSort(a, n);
                        xuatMang(a, n);
                        break;
                    case 3:
                        quickSort(a, 0, n - 1);
                        xuatMang(a, n);
                        break;
                    default:
                        cout << "Lua chon khong hop le.\n";
                        break;
                }
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
    } while (choice != 0);

    delete[] a; // Giải phóng bộ nhớ
    return 0;
}
