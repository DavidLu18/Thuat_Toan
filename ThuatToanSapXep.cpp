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

void selectionSort(int a[],int n){
    for (int i = 0;i<n-1;i++){
        int minIndex = i;
        for (int j = i+1;j<n;j++){
            if(a[j]<a[minIndex]){
                minIndex = j;
            }
        }
        swap(a[i],a[minIndex]);
    }
}

void quickSort(int a[],int left,int right){
    int i = left;
    int j = right;
    int pivot = a[(left+right)/2];
    while(i<=j){
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(left<j){
        quickSort(a,left,j);
    }
    if(i<right){
        quickSort(a,i,right);
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
    cout<<"4/ Sap Xep Chon"<<endl;
    cout<<"5/ Sap Xep Nhanh"<<endl;
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
        
        case 4:
            selectionSort(a,n);
            cout<<"Mang sau khi sap xep: ";
            for (int i = 0; i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            break;
        case 5:
            quickSort(a,0,n-1);
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