/*
QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.
*/

#include <stdio.h>

//This will swap the values of the two variables passed to the function
void swaping(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swaping(&arr[i], &arr[j]);
        }
    }
    swaping(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/*  
    a[] is the array, p is starting index, that is 0, 
    and r is the last index of array.  
*/
void quick_sort(int a[], int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

int main()
{
    int n, i;

    printf("Enter the no of element:");
    scanf("%d", &n);
    int a[n];

    //Taking array input's
    printf("Enter the element of array:-\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a,0, n-1);

    //Array after sorting is done
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
/*
Time Complexity: O(nLogn)
worst case time complexity of QuickSort is O(n2) 
Space Complexity: O(n)
Output:
Enter the no of element:10
Enter the element of array:-
32 323 4 34 341291 343483 32323 34 446 
Sorted Array:
4 32 34 34 323 446 7856 32323 341291 
*/