#include <iostream>
#include <string>
#include <iomanip>

const int MAX = 100;

using namespace std;

void taoMangNgauNhien(int a[][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = rand()%100;
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void SapXepTangDan(int a[][MAX],int n){
     for(int i=0;i<n;i++){
        for(int j = 0;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(a[i][j] %2 == 0 && a[i][k]%2 == 0 &&  a[i][j]>a[i][k]){
                    swap(a[i][j],a[i][k]);
                }
            }
        }
     }
}

int main()
{
    int n;
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    int a[MAX][MAX];
    cout<<"Mang ngau nhien: "<<endl;
    taoMangNgauNhien(a,n);
    cout<<"Mang sau khi sap xep: "<<endl;
    SapXepTangDan(a,n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}