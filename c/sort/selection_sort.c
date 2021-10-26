/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. 
*/

#include <stdio.h>

//This will swap the values of the two variables passed to the function
void swaping(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int *a, int n)
{
    int i, j, index;

    // One by one move of element
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
                index = j;
        }

        // Swap the found minimum element with the first element
        swaping(&a[index], &a[i]);
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

    selection_sort(a, n);

    //Array after sorting is done
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
/*
Time Complexity: O(n*2)
Space Complexity: O(1)
Output:
Enter the no of element:10
Enter the element of array:-
32 323 4 34 341291 343483 32323 34 446 
Sorted Array:
4 32 34 34 323 446 7856 32323 341291 
*/