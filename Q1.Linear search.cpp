#include<iostream>
using namespace std;
int main()
{
    int size,e;
    cout<<"enter size of array-->";
    cin>>size;
    cout<<"Enter the values in array-->"<<"\n";
    int arr[100];
    for (int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter element to search-->";
    cin>>e;
    bool p=false;
    for(int i=0;i<=size;i++){
        if(arr[i]==e){
        cout<<"Element "<<e<< " found at index "<<i<<endl;
        p=true;
//        break;     use break if no duplicate elements are there in array but if they are there don't use break it will tell all the positions the element is on.
        }
    }
    if(!p)
    cout<<"element not found in array: ";
}
