#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void LinearSearch(int a[],int n){
    int x;
    cout<<"Nhap X can tim: ";
    cin>>x;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            cout<<"Da tim thay X o vi tri "<<i<<endl;
        }
    }
}

void BinarySearch(int a[],int n){
    int x;
    cout<<"Nhap X can tim: ";
    cin>>x;
    int left = 0;
    int right = n-1;
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(a[mid]==x){
            cout<<"Da tim thay X o vi tri "<<mid<<endl;
            break;
        }
        else if(a[mid]<x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
}

void InterchangeSort(int a[],int n){
    for (int i = 0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

int main()
{
    int n;
    int chon;
    cout<<"Nhap So Luong Mang: ";
    cin>>n;
    int *a = new int [n];
    for (int i = 0; i<n;i++){
        cout<<"Nhap phan tu thu "<<i<<" : ";
        cin>>a[i];
    }
    do{
    cout<<endl;
    cout<<setw(20)<<right<<"---------- MENU ----------"<<endl;
    cout<<"1/ Tim Kiem Tuyen Tinh"<<endl;
    cout<<"2/ Tim Kiem Nhi Phan"<<endl;
    cout<<"3/ Sap Xep Doi Cho Truc Tiep"<<endl;
    cout<<"0/ Ket Thuc Chuong Trinh."<<endl;
    cout<<"Ban chon: ";
    cin>>chon;
    switch(chon)
    {
        case 0:
            cout<<"Da Thoat Chuong Trinh"<<endl;
            break;
        case 1:
            LinearSearch(a,n);
            break;
        case 2:
            BinarySearch(a,n);
            break;
        case 3:
            InterchangeSort(a,n);
            cout<<"Mang sau khi sap xep: ";
            for (int i = 0; i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            break;
        default:
            cout<<"Nhap Sai!"<<endl;
            break;
    }
    }while(chon!=0);
    delete []a;
    return 0;
}