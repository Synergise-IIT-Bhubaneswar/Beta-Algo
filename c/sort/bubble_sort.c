/*
Sort by comparing each adjacent pair of items in a list in turn, swapping the items if necessary, and repeating the pass through the list until no swaps are done
*/

#include <stdio.h>

//This will swap the values of the two variables passed to the function
void swaping(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            //Swapping the value to get the correct order in array
            if (arr[j] > arr[j + 1])
                swaping(&arr[j], &arr[j + 1]);
        }
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

    bubble_sort(a, n);

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