#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest=root;
   int right = root*2+2;
   int left = root*2+1;
   if (left<n && arr[left]>arr[largest]){

        largest = left;
   }

   if (right<n && arr[right]>arr[largest]){

        largest = right;
   }
   if (largest != root){
        swap(arr[root],arr[largest]);
        heapify(arr,n,largest);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for ( int i= (n/2)-1;i>=0;i--){
        heapify(arr,n,i);
   }

   // extracting elements from heap one by one
   for (int j=n-1;j>=0;j--){
        swap(arr[0],arr[j]);
        heapify(arr,j,0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i){
       cout << arr[i] << " ";
   }
   cout << "\n";
}

// main program
int main()
{
    int n=20;
    int heap_arr[n];
    for(int i=0;i<n;i++){
        heap_arr[i]=rand()%80;
    }

   cout<<"Input array :"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);
   cout << "Sorted array :"<<endl;

   displayArray(heap_arr, n);
}
