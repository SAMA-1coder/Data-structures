//creating an array
#include<iostream>
using namespace std;
int main(){
	int arr[100],size;
	cout<<"Enter size of array: ";
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"Enter the elements of array: ";
		cin>>arr[i];
	}
	
	
	//displaying the array
	cout<<"Array is: ";
	for(int i=0;i<size;i++){		
		cout<<arr[i]<<",";
	}
	
}



