#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAX_Khach_Hang = 100;

struct KhachHang{
    string HoTen,TenPhim,PhongChieu;
    int SoDienThoai,SoVeNguoiLon,SoVeTreEm,Tien;
    float XuatChieu;
};

struct DanhSachKhachHang{
    int n;
    KhachHang kh[MAX_Khach_Hang];
};

bool DocFile(DanhSachKhachHang &dskh, const string &tentep){
    ifstream file(tentep);
    if(!file.is_open()){
        cout<<"Khong Mo Duoc File!"<<endl;
        return false;
    }
    int i= 0;
    string line;
    while(i < MAX_Khach_Hang && getline(file,line)){
        istringstream iss(line);
        string token;
        if(getline(iss,token,',')){
            dskh.kh[i].HoTen = token;
        }
        if(getline(iss,token,',')){
            dskh.kh[i].TenPhim = token;
        }
        if(getline(iss,token,',')){
            dskh.kh[i].PhongChieu = token;
        }
        if(getline(iss,token,',')){
            dskh.kh[i].SoDienThoai = stoi(token);
        }
        if(getline(iss,token,',')){
            dskh.kh[i].SoVeNguoiLon = stoi(token);
        }
        if(getline(iss,token,',')){
            dskh.kh[i].SoVeTreEm = stoi(token);
        }
        if(getline(iss,token,',')){
            dskh.kh[i].XuatChieu = stoi(token);
        }
        i++;
    }
    cout<<"Da Doc File Thanh Cong!"<<endl;
    dskh.n = i;
    file.close();
    return true;
}

void XuatDanhSach(DanhSachKhachHang &dskh){
    for(int i = 0;i<dskh.n;i++){
        cout<<"---------- Khach Hang so "<<i+1<<" ----------"<<endl;
        cout<<"Ho va Ten: "<<dskh.kh[i].HoTen<<endl;
        cout<<"Ten Phim: "<<dskh.kh[i].TenPhim<<endl;
        cout<<"Phong Chieu: "<<dskh.kh[i].PhongChieu<<endl;
        cout<<"So Dien Thoai: "<<dskh.kh[i].SoDienThoai<<endl;
        cout<<"So Ve Nguoi Lon: "<<dskh.kh[i].SoVeNguoiLon<<endl;
        cout<<"So Ve Tre Em: "<<dskh.kh[i].SoVeTreEm<<endl;
        cout<<"So Tien Phai Tra: "<<dskh.kh[i].Tien<<" Dong"<<endl;
        cout<<"Xuat Chieu: "<<dskh.kh[i].XuatChieu<<" Hour"<<endl;
    }
}

void GiaVe(DanhSachKhachHang &dskh){
    for (int i = 0;i<dskh.n;i++){
        dskh.kh[i].Tien = dskh.kh[i].SoVeNguoiLon*40000 + dskh.kh[i].SoVeTreEm*20000;
    }
}

void TongDoanhThu(DanhSachKhachHang &dskh){
    int DoanhThu;
    for(int i= 0;i<dskh.n;i++){
        DoanhThu += dskh.kh[i].Tien;
    }
    cout<<"==> Tong Doanh Thu: "<<DoanhThu<<" Dong"<<endl;
}

void TimKiem(DanhSachKhachHang &dskh){
    string x;
    float y;
    cout<<"Nhap Ma Phong Chieu: ";
    cin>>x;
    cout<<"Nhap Xuat Chieu: ";
    cin>>y;
    for (int i = 0;i<dskh.n;i++){
        if(dskh.kh[i].PhongChieu == x && dskh.kh[i].XuatChieu == y){
            cout<<"---------- Khach Hang so "<<i+1<<" ----------"<<endl;
            cout<<"Ho va Ten: "<<dskh.kh[i].HoTen<<endl;
            cout<<"Ten Phim: "<<dskh.kh[i].TenPhim<<endl;
            cout<<"Phong Chieu: "<<dskh.kh[i].PhongChieu<<endl;
            cout<<"So Dien Thoai: "<<dskh.kh[i].SoDienThoai<<endl;
            cout<<"So Ve Nguoi Lon: "<<dskh.kh[i].SoVeNguoiLon<<endl;
            cout<<"So Ve Tre Em: "<<dskh.kh[i].SoVeTreEm<<endl;
            cout<<"So Tien Phai Tra: "<<dskh.kh[i].Tien<<" Dong"<<endl;
            cout<<"Xuat Chieu: "<<dskh.kh[i].XuatChieu<<" Hour"<<endl;
        }
    }
}

void SapXepTangDan(DanhSachKhachHang &dskh)
{
    for (int i =0;i<dskh.n;i++){
        for(int j = i+1;j<dskh.n;j++){
            if(dskh.kh[i].Tien > dskh.kh[j].Tien){
                swap(dskh.kh[i],dskh.kh[j]);
            }
        }
    
    }
}

void SapXepHoTenTangDan(DanhSachKhachHang &dskh){
    for (int i=0;i<dskh.n;i++){
        for(int j = i+1;j<dskh.n;j++){
            if(dskh.kh[i].HoTen > dskh.kh[j].HoTen){
                swap(dskh.kh[i],dskh.kh[j]);
            }
        }
    }
}

void TimKiemTen(DanhSachKhachHang &dskh){
    cin.ignore();
    cout<<"Nhap Ten Can Tim: ";
    string ziz;
    getline(cin, ziz);
    cout<<endl;
    for(int i = 0; i < dskh.n;i++){
        if(ziz.compare(dskh.kh[i].HoTen) == 0){
        cout<<"---------- Khach Hang so "<<i+1<<" ----------"<<endl;
        cout<<"Ho va Ten: "<<dskh.kh[i].HoTen<<endl;
        cout<<"Ten Phim: "<<dskh.kh[i].TenPhim<<endl;
        cout<<"Phong Chieu: "<<dskh.kh[i].PhongChieu<<endl;
        cout<<"So Dien Thoai: "<<dskh.kh[i].SoDienThoai<<endl;
        cout<<"So Ve Nguoi Lon: "<<dskh.kh[i].SoVeNguoiLon<<endl;
        cout<<"So Ve Tre Em: "<<dskh.kh[i].SoVeTreEm<<endl;
        cout<<"So Tien Phai Tra: "<<dskh.kh[i].Tien<<" Dong"<<endl;
        cout<<"Xuat Chieu: "<<dskh.kh[i].XuatChieu<<" Hour"<<endl;        
            }
    }
}

int main()
{
    DanhSachKhachHang dskh;
    int chon;
    do{
    cout<<endl;
    cout<<"----------- MENU -----------"<<endl;
    cout<<"1. Doc File"<<endl;
    cout<<"2. Xuat Danh Sach"<<endl;
    cout<<"3. Tinh Doanh Thu"<<endl;
    cout<<"4. Tim Kiem Thong Tin Khach Hang Theo Phong Chieu Va Xuat Chieu"<<endl;
    cout<<"5. Sap Xep Danh Sach Theo So Tien Phai Tra"<<endl;
    cout<<"6. Sap Xep Danh Sach Theo Ho Ten"<<endl;
    cout<<"7. Tim Kiem Thong Tin Khach Hang Theo Ho Ten"<<endl;
    cout<<"0. Thoat"<<endl;
    cout<<"Ban Chon: ";
    cin>>chon;
    switch (chon){
        case 1:
            cout<<endl; 
            DocFile(dskh,"dskh.txt");
            break;
        case 2:
            cout<<endl;
            GiaVe(dskh);
            XuatDanhSach(dskh);
            break;
        case 3:
            cout<<endl;
            GiaVe(dskh);
            TongDoanhThu(dskh);
            break;
        case 4:
            cout<<endl;
            GiaVe(dskh);
            TimKiem(dskh);
            break;
        case 5:
            cout<<endl;
            GiaVe(dskh);
            SapXepTangDan(dskh);
            XuatDanhSach(dskh);
            break;
        case 6:
            cout<<endl;
            GiaVe(dskh);
            SapXepHoTenTangDan(dskh);
            XuatDanhSach(dskh);
            break;
        case 7:
            cout<<endl;
            GiaVe(dskh);
            TimKiemTen(dskh);

            break;
        case 0:
            cout<<"Thoat Chuong Trinh!"<<endl;
            break;
        default:
            cout<<"Nhap Sai!"<<endl;
            break;
    }
    }while(chon != 0);
    return 0;
}