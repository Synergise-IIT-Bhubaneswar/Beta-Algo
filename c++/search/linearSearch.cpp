/*
a linear search or sequential search is a method for finding an element within a list. It sequentially checks each element of the list until a match is found or the whole list has been searched.
linear search:-

(i) Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
(ii) If x matches with an element, return the index.
(iii) If x doesn’t match with any of elements, return -1.
*/
#include <bits/stdc++.h>
using namespace std;

//Iterative Search: Time Complexity is O(n)
int linearSearchIterative(int n, int key, vector<int> v)
{
    //Loop will run util key is found in the vector or will return -1 if element is not there
    for (int i = 0; i < n; i++)
        if (v[i] == key)
            return i;
    return -1;
}

//Recursive Approach: Time Complexity is O(n)
int linearSearchRecursive(int i, int n, int key, vector<int> v)
{
    //If element not found then we will return -1
    if (i == n || i > n)
        return -1;
    //If element found then returning the position of the element
    if (v[i] == key)
        return i;
    //Calling the linearSearchRecursive function for i+1 if key is not found at ithe position util i become greater or equal to n
    return linearSearchRecursive(i + 1, n, key, v);
}

int main()
{
    int n, key, elem;

    //Taking the no of element i b/w we have to search a particular element
    cout << "Element the no of element: ";
    cin >> n;
    vector<int> v;

    cout << "Element the element of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        v.push_back(elem);
    }

    cout << "Enter the element which is to find: ";
    cin >> key;

    //This is for Iterative Approach for the linear Search
    cout << "---------- By Iterative Way ------------------------\n";
    if (linearSearchIterative(n, key, v) > 0)
        cout << "Element found at " << linearSearchIterative(n, key, v) + 1 << " Position.\n";
    else
        cout << "Element not found.\n";

    //And this is for Recursive Approach for the linear Search
    cout << "---------- By Recursive Way ------------------------\n";
    if (linearSearchRecursive(0, n, key, v) > 0)
        cout << "Element found at " << linearSearchRecursive(0, n, key, v) + 1 << " Position.\n";
    else
        cout << "Element not found.\n";
}
/*
Time Complexity: O(N)
Space complexity: O(1)
Sample I/O:
INPUT:
Enter number of elements in the array: 10
Element the element of the array: 3 323 232 434 32 23 233 26575 545 890
Enter the element which is to find: 233

OUTPUT:
Enter the element which is to find: 233
---------- By Iterative Way ------------------------
Element found at 7 Position.
---------- By Recursive Way ------------------------
Element found at 7 Position.
*/