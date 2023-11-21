#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_Sinh_Vien = 1000;

struct SinhVien{
    string HoTen;
    int MSSV;
    float Diem;
};

struct DanhSachSinhVien{
    int n;
    SinhVien sv[MAX_Sinh_Vien];
};

bool DocFile(DanhSachSinhVien &dssv, const string &tep){
    ifstream file(tep);
    if(!file.is_open()){
        cout<<"Khong mo duoc file!!";
        return false;
    }
    int i=0;
    string line;
    while(i<MAX_Sinh_Vien && getline(file,line)){
        istringstream iss(line);
        string token;
        if(getline(iss,token,'/')){
            dssv.sv[i].HoTen = token;
        }
        if(getline(iss,token,'/')){
            dssv.sv[i].MSSV = stoi(token);
        }
        if(getline(iss,token,'/')){
            dssv.sv[i].Diem = stod(token);
        }
        i++;
    }
    cout<<"Doc File Thanh Cong UWU"<<endl;
    dssv.n = i;
    file.close();
    return true;
}

void XuatDssv(DanhSachSinhVien &dssv)
{
    for(int i = 0;i<dssv.n;i++){
        cout<<"-------- SINH VIEN "<<i+1<<" --------"<<endl;
        cout<<"Ho va ten sinh vien: "<<dssv.sv[i].HoTen<<endl;
        cout<<"Ma so sinh vien: "<<dssv.sv[i].MSSV<<endl;
        cout<<"Diem so: "<<dssv.sv[i].Diem<<endl;
    }
}

int main()
{
    DanhSachSinhVien dssv;
    DocFile(dssv,"dssv.txt");
    XuatDssv(dssv);
    return 0;
}