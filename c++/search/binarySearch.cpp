/*Binary search is an efficient approach to search a particular element from a sorted array of numbers.

You have a sorted array consisting of X elements, and you input the value to be found in it. The algorithm compares your input value with the key value of the array's middle element.
So here we have the following 3 scenarios:

1)If input key value matches the key value of the middle element, then its index is returned.
2)If input key value is lesser than the key value of middle element, then we do a search on the sub array to the left of the middle element.
3)Similarly if the input key value is greater than key value of middle element, then we do a search on the sub array to the right of the middle element.*/


#include <bits/stdc++.h>
using namespace std;

//It is assumed that the given array is sorted in ascending order beforehand.

//Iterative Approach: Time Complexity is O(log(N))
int binarySearchIterative(int l, int r, int key, int arr[])
{
	while(r>=l)
	{
		// Find the mid
		int mid=(l+r)/2;
		// Check if key is present at mid
		if(arr[mid]==key)
			return mid;
		// Since key is not present at mid, we will check in which region it is present and then repeat the Search operation in that region
		else if(arr[mid]<key)
		{
			// The key lies in between mid and r
			l=mid+1;
		}
		else
		{
			// The key lies in between l and mid
			r=mid-1;
		}
	}
	// Key not found then return -1
	return -1;
}

//Recursive Approach: Time Complexity is O(log(N))
int binarySearchRecursive(int l, int r, int key, int arr[])
{
	if(r>=l)
	{
		// Find the mid
		int mid=(l+r)/2;
		// Check if key is present at mid
		if(arr[mid]==key)
		{
			return mid;
		}
		// Since key is not present at mid, we will check in which region it is present and then repeat the Search operation in that region
		else if(arr[mid]>key)
		{
			// The key lies in between l and mid
			return binarySearchRecursive(l, mid-1, key, arr);
		}
		else
		{
			// The key lies in between mid and r
			return binarySearchRecursive(mid+1, r, key, arr);
		}
	}
	// Key not found then return -1
	return -1;
}

int main()
{
	int left, right, key, ans;
	cout<<"Enter number of elements in the array: "<<endl;
	cin>>right;//Length of array
	int arr[right];
	cout<<"Enter the elements of array in ascending order: "<<endl;
	for(int i=0;i<right;i++)
	{
		cin>>arr[i];
	}
	left=0;// Starting index
	cout<<"Enter the element to be searched: "<<endl;
	cin>>key;// Key to be searched in the array
	ans=binarySearchIterative(left, right, key, arr);// Search the key in array using Iterative Binary Search
	if(ans!=-1)// Check if key is there in array or not
		cout<<"Iterative Approach: Index of "<<key<<" is "<<ans<<endl;
	else
		cout<<"Iterative Approach: Element not found in array"<<endl;
	ans=binarySearchRecursive(left, right, key, arr);// Search the key in array using Recursive Binary Search
	if(ans!=-1)// Check if key is there in array or not
		cout<<"Recursive Approach: Index of "<<key<<" is "<<ans<<endl;
	else
		cout<<"Recursive Approach: Element not found in array"<<endl;;
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
Iterative Approach: Index of 14 is 6
Recursive Approach: Index of 14 is 6
*/