/*Jump search is a searching algorithm for sorted arrays. In this algorithm, we jump ahead by a fixed number of steps each time, instead
of traversing the whole array. Suppose array is of size 10, and jump is 3, then, we check array[0], array[3], array[6], array[9]. We get
an interval in which we are searching for is present. We then traverse the interval lineally to get the exact index of the element.
The optimal jump size is sqrt(size of the array). This can be easily proved.*/

import java.util.*;

//It is assumed that the given array is sorted in ascending order beforehand.

public class jumpSearch
{
	int jump_Search(int arr[], int key, int len)
	{
   		// Find the size to jump
   		int jump=(int)Math.floor(Math.sqrt(len));
   		int start=0;
   		//Find the interval in which key is present
   		while(arr[Math.min(jump, len)-1]<key)
   		{
      		start=jump;
      		jump+=(int)Math.floor(Math.sqrt(len));
      		if(start>=len)
      			return -1;
   		}
   		//Find the index at which key is present inside the found interval
   		while(arr[start]<key)
   		{
   			start++;
   			if(start==Math.min(jump, len))
   				return -1;
   		}
   		if(arr[start]==key)
   			return start;
   		// Key not found then return -1
   		return -1;
	}

	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		jumpSearch obj=new jumpSearch();
		System.out.println("Enter the length of the array: ");
		int len=sc.nextInt();// Length of array
		int arr[]=new int[len];
		System.out.println("Enter the elements of the array in ascending order: ");
		for(int i=0;i<len;i++)
		{
			arr[i]=sc.nextInt();
		}
		System.out.println("Enter the element to be searched: ");
		int key=sc.nextInt();// Key to be searched in the array
		int ans=obj.jump_Search(arr, key, len);// Search the key in array using Jump Search Technique
		if(ans!=-1)// Check if key is there in array or not
			System.out.println("Index of "+key+" is "+ans);
		else
			System.out.println("Element not found in array");
	}
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