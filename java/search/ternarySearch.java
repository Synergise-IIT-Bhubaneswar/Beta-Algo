/*Ternary search is similar to binary search. The only difference is that in this algorithm, we divide the array in three and not two parts.
Here, we take two middle elements mid1 and mid2 instead of just mid as in Binary Search. Two-third of the search space is discarded at each iteration
until the key is found*/

import java.util.*;

//It is assumed that the given array is sorted in ascending order beforehand.

public class ternarySearch
{
	//Iterative Approach: Time Complexity is O(log3(N))
	static int ternarySearch_iterative(int l, int r, int key, int arr[])   
	{ 
    	while(l<=r)
    	{
			// Find the mid1 and mid2 
      	 	int mid1=l+(r-l)/3; 
       	 	int mid2=r-(r-l)/3; 
		 	// Check if key is present at any mid
     	   	if(arr[mid1]==key)
     	   	{ 
      	    	return mid1; 
       	 	} 
        	if(arr[mid2]==key)
        	{ 
        	    return mid2; 
       		} 
			// Since key is not present at mid, we will check in which region it is present and then repeat the Search operation in that region
        	if(key<arr[mid1])
        	{ 
	    		// The key lies in between l and mid1 
            	r=mid1-1; 
        	} 
        	else if(key>arr[mid2])
        	{ 
	    		// The key lies in between mid2 and r 
            	l=mid2+1; 
        	} 
        	else
        	{ 
	    		// The key lies in between mid1 and mid2 
            	l=mid1+1; 
            	r=mid2-1; 
        	}
    	} 
    	// Key not found then return -1
    	return -1; 
	}

	//Recursive Approach: Time Complexity is O(log3(N))
	static int ternarySearch_recursive(int l, int r, int key, int arr[]) 
	{
		if(r>=l)
		{ 
			// Find the mid1 and mid2
			int mid1=l+(r-l)/3;
			int mid2=r-(r-l)/3;
			// Check if key is present at any mid
			if(arr[mid1]==key)
			{ 
				return mid1; 
			} 
			if(arr[mid2]==key)
			{ 
				return mid2; 
			} 
			// Since key is not present at mid, we will check in which region it is present and then repeat the Search operation in that region
			if(key<arr[mid1])
			{
			 	// The key lies in between l and mid1 
				return ternarySearch_recursive(l, mid1-1, key, arr); 
			} 
			else if(key>arr[mid2])
			{ 
				// The key lies in between mid2 and r 
				return ternarySearch_recursive(mid2+1, r, key, arr); 
			} 
			else
			{
				// The key lies in between mid1 and mid2 
				return ternarySearch_recursive(mid1+1, mid2-1, key, arr); 
			} 
		} 
		// Key not found then return -1
		return -1; 
	}

	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the length of the array: ");
		int len=sc.nextInt();// Length of array
		int arr[]=new int[len];
		System.out.println("Enter the elements of the array in ascending order: ");
		for(int i=0;i<len;i++)
		{
			arr[i]=sc.nextInt();
		}
		int left=0;
		System.out.println("Enter the element to be searched: ");
		int key=sc.nextInt();// Key to be searched in the array
		int ans=ternarySearch_iterative(left, len, key, arr);// Search the key in array using Iterative Binary Search
		if(ans!=-1)// Check if key is there in array or not
			System.out.println("Iterative Approach: Index of "+key+" is "+ans);
		else
			System.out.println("Iterative Approach: Element not found in array");
		ans=ternarySearch_recursive(left, len, key, arr);// Search the key in array using Recursive Binary Search
		if(ans!=-1)// Check if key is there in array or not
			System.out.println("Recursive Approach: Index of "+key+" is "+ans);
		else
			System.out.println("Recursive Approach: Element not found in array");
	}
}
/*
Time Complexity: O(log(N))
Sample I/O:
INPUT:
Enter the length of the array: 
10
Enter the elements of the array in ascending order: 
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
Iterative Approach: Index of 14 is 6
Recursive Approach: Index of 14 is 6
*/