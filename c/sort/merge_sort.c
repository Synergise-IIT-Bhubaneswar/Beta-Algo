/*
Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 

*/

#include <stdio.h>

//This will swap the values of the two variables passed to the function
void swaping(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//Merge Sort to sort the array
void merge(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
    {
        larr[i] = array[l + i];
    }

    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    //merge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { //extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    { //extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void merge_sort(int *a, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        
        // Sort first and second arrays
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        //Then merge the first and second array
        merge(a, l, m, r);
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

    merge_sort(a,0, n-1);

    //Array after sorting is done
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
/*
Time Complexity:  θ(nLogn)
Space Complexity: O(n)
Output:
Enter the no of element:10
Enter the element of array:-
32 323 4 34 341291 343483 32323 34 446 
Sorted Array:
4 32 34 34 323 446 7856 32323 341291 
*/