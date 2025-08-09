#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,j;
    cout<<"Enter the size of array: ";
    cin>>n;
   int arr[n],m,o;
   cout<<"Enter the elements of array: ";
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   for(int i=0,j=n-1;i<j;i++,j--){
       
           int temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
           
   }
   cout << "Reversed array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}


