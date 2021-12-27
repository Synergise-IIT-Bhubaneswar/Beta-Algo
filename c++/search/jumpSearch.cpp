/*Jump search is a searching algorithm for sorted arrays. In this algorithm, we jump ahead by a fixed number of steps each time, instead
of traversing the whole array. Suppose array is of size 10, and jump is 3, then, we check array[0], array[3], array[6], array[9]. We get
an interval in which we are searching for is present. We then traverse the interval lineally to get the exact index of the element.
The optimal jump size is sqrt(size of the array). This can be easily proved.*/

#include <bits/stdc++.h>
using namespace std;

//It is assumed that the given array is sorted in ascending order beforehand.

int jumpSearch(int arr[], int key, int len)
{
   // Find the size to jump
   int jump=sqrt(len);
   int start=0;
   //Find the interval in which key is present
   while(jump<len && arr[jump]<=key)
   {
      start=jump;
      jump+=sqrt(len);
      if(jump>len)
      {
         jump=len;
      }
   }
   //Find the index at which key is present inside the found interval
   for(int i=start;i<=jump;i++)
   {
      if(arr[i]==key)
         return i;
   }
   // Key not found then return -1
   return -1;
}

int main()
{
   int right, key;
   cout<<"Enter number of elements in the array: "<<endl;
   cin>>right;//Length of array
   int arr[right];
   cout<<"Enter the elements of array in ascending order: "<<endl;
   for(int i=0;i<right;i++)
   {
      cin>>arr[i];
   }
   cout<<"Enter the element to be searched: "<<endl;
   cin>>key;// Key to be searched in the array
   int ans=jumpSearch(arr, key, right);// Search the key in array using Jump Search technique
   if(ans!=-1)// Check if key is there in array or not
      cout<<"Index of "<<key<<" is "<<ans<<endl;
   else
      cout<<"Element not found in array"<<endl;
}
/*
Time Complexity: O(Square root(N))
Sample I/O:
INPUT:
Enter number of elements in the array:
10
Enter the elements of array in ascending order:
2
4
6
8
10
12
14
16
18
20
Enter the element to be searched:
14
OUTPUT:
Index of 14 is 6
*/