#include<iostream>
using namespace std;
int main(){
	int arr[100],pos,ele,size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
    	cin>>arr[i];
	}
	cout<<"enter position: ";
	cin>>pos;
	cout<<"Enter new element: ";
	cin>>ele;
	for(int i=size;i>pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=ele;
	size++;
	cout<<"Updated array is :";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<",";
	}
}
