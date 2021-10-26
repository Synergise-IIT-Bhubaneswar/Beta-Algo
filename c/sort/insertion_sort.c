/*
Algorithm 

To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element

*/

#include <stdio.h>

void insertion_sort(int *a, int n)
{
    int i, min, j;
    for (i = 1; i < n; i++)
    {
        min = a[i]; //To keep the track of the ith variable
        j = i - 1;

        //This will check the element should be greater than current ith element and if it is greater then it will swap the values
        while (j >= 0 && a[j] > min)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = min;
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

    insertion_sort(a, n);

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