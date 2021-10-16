//QUICK SORT IN C++

/*
Working of quick sort algorithm -
It works similiar to merge sort, and is a divide and conquer algorithm, and uses recursion as its main working principle. just like merge sort, it divides the array, but not long its center, but along its "pivot", which can be anything in the array. In this code, the pivot is the last element of the array.
the split() function takes the pivot and places all the elements smaller than the pivot on the left side of it, and the others on its right side, and returns the position of the pivot.
taking the pivot as the baseline, the array is split and the quicksort() function is applied recursively.
*/

/*
Time complexity - O(n^2) [worst case] || O(nlogn) [best case]
Space complexity - O(1)
*/

#include <iostream>
#include <vector> //for vector arrays
using namespace std;

//split function
int split(vector <int>* a, int l, int r) {

     //initialization of useful variables
     int pivot = (*a)[r];
     int iter = l - 1; //for keeping track of smaller elements

     //main loop
     for (int j = l; j < r; j++) {

          if ((*a)[j] <= pivot) {
               iter++;

               //placing smaller elements on the left side, and ignoring the rest
               swap((*a)[iter], (*a)[j]);
          }
     }

     //placing pivot on the elements ignored previously
     swap((*a)[iter + 1], (*a)[r]);

     //returning pivot's location
     return iter + 1;
}

//quick sort function
void quicksort(vector <int>* a, int l, int r) {

     //breaking condition
     if (l >= r) {
          return;
     }

     //recursive calls
     int p = split(a, l, r);
     quicksort(a, l, p - 1);
     quicksort(a, p, r);
}

int main() {

     //input parameters
     int n;
     cout << "Enter size of array = ";
     cin >> n;
     vector <int> a(n);
     cout << "Enter elements of array = ";
     for (int i = 0; i < n; i++) {
          cin >> a[i];
     }

     //function call
     quicksort(&a, 0, n - 1);

     //output
     cout << "Sorted array (using bubble sort) = ";
     for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
     }
     cout << "\n";

     return 0;
}