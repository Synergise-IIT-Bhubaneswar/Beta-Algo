/*
Linear search is a sequential searching algorithm where we start from one end and check every element of the list until the desired element is found. It is the simplest searching algorithm
linear search:-
LinearSearch(array, key)
  for each item in the array
    if item == value
      return its index
*/
#include <stdio.h>

//Iterative Search: Time Complexity is O(n)
int searchLS(int array[], int n, int x) {
  
  // Going through array sequencially and comparing with the element to be searched
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}
//Recursive Approach: Time Complexity is O(n)
/*If the element that is searched is the first we directly return the index.
But if it is not the first element of array, we decrease the size of array by 1, 
by eliminating the first element of the array, 
which means when the RecursiveLS() is called second time the array size will be (n-1). 
This will go on until the element is found.*/


int RecursiveLS(int arr[], int size, int x) {
    int rec;
 
    size--;
 
    if (size >= 0) {
        if (arr[size] == x)
            return size;
        else
            rec = RecursiveLS(arr, size, x);
    }
    else
        return -1;
 
    return rec;
}
 

int main()
{
    int n, value, pos, m = 0, arr[100];
    printf("Enter the total elements in the array: ");
    scanf("%d", &n);
 
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    printf("Enter the element to search:");
    scanf("%d", &value);
 //Recursive way
 printf("---------- By Recursive Way -----------------");
    pos =  RecursiveLS(arr,n,value);
    if (pos != 0)
    {
        printf("Element found at position: %d ,index : %d\n", pos+1,pos);
    }
    else
    {
        printf("Element not found");
    }
//Iterative way
printf("---------- By Iterative Way -----------------");
    pos =  searchLS(arr, n, value);
    if (pos != 0)
    {
        printf("Element found at position: %d ,index : %d\n", pos+1,pos);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
/*
Time Complexity: O(N)
Space complexity: O(1)
Sample I/O:
INPUT:
Enter the total elements in the array: 10
Enter the array elements: 3 323 232 434 32 23 233 26575 545 890
Enter the element to search: 233
OUTPUT:

---------- By Recursive Way -----------------Element found at position: 7 ,index :6
---------- By Iterative Way -----------------Element found at position: 7 ,index :6
*/