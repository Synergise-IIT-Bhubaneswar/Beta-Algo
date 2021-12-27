/*Fibonacci search is very similar to binary search, except that the indexes used for comparison are based on Fibonacci numbers rather than the mean 
value of the endpoints. The idea is to first find the smallest Fibonacci number that is greater than or equal to the length of the given array. Let this
found Fibonacci number be the 'n' th Fibonacci number. Then, we use '(n-2)' th Fibonacci number as the index (If it is a valid index). Let '(n-2)' th
Fibonacci number be m, we compare arr[m] with key, and if key is same as arr[m], we return m. Else if key is greater, we recur for subarray after m,
else we recur for subarray before m*/

import java.util.*;

//It is assumed that the given array is sorted in ascending order beforehand.

public class fibonacciSearch
{
	int fibonacci_Search(int arr[], int key, int len)
	{
		// First initialize the first three consecutive Fibonacci numbers
		int fib1=0;
		int fib2=1;
		int fib3=fib1+fib2;
		// Now, fib3 will store the smallest Fibonacci number that is greater than or equal to the length of the given array
		while(fib3<len)
		{
			fib1=fib2;
			fib2=fib3;
			fib3=fib1+fib2;
		}
		int temp=-1;// Used to keep track of the eliminated range from the front
		while(fib3>1)
		{
			int i=Math.min(temp+fib1, len-1);
			//If key is greater than the value at index fib1, then we cut the subarray array from temp to i
			if(arr[i]<key)
			{
				fib3=fib2;
				fib2=fib1;
				fib1=fib3-fib2;
				temp=i;
			}
			//If key is greater than the value at index fib1, then we cut the subarray after i+1
			else if(arr[i]>key)
			{
				fib3=fib1;
				fib2-=fib1;
				fib1=fib3-fib2;
			}
			//If none of the above conditions is satisfied, then it means that we have found the key at index i
			else
			{
				return i;
			}
		}
		if(fib2==1 && arr[temp+1]==key)
		{
			return temp+1;
		}
		// Key not found then return -1
		return -1;
	}

	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		fibonacciSearch obj=new fibonacciSearch();
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
		int ans=obj.fibonacci_Search(arr, key, len);// Search the key in array using Jump Search Technique
		if(ans!=-1)// Check if key is there in array or not
			System.out.println("Index of "+key+" is "+ans);
		else
			System.out.println("Element not found in array");
	}
}
/*
Time Complexity: O(log(N))
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