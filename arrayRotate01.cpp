
// C++ program to rotate an array by d elements

#include <iostream>
using namespace std;

void leftRotatebyOne(int arr[], int n){
    int temp = arr[0];
    for(int i = 0; i < n -1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void leftRotate(int arr[], int d, int n){
    for(int i = 0; i < d; i++){
    leftRotatebyOne(arr, n);
    }
}
void printArr(int arr[],int n){
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
  int arr[] = {1,2,3,4,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  leftRotate(arr,3,n);
  printArr(arr,n);
  
}

//Time Complexity: O(n * d)
//Auxiliary Space: O(1)
