//SELECTION SORT IN C++

/*
Working of the selection sort algorithm -
this algorithm works by finding out the minimum element of the array, and placing it at the front of the array, and repeating it for every element in the array. It is similiar to the working of bubble sort, but here instead of placing the highest element to the extreme right, we do the opposite.
*/

/*
Time complexity - O(n^2)
Space complexity - O(1)
*/

#include <iostream>
#include <vector> //for vector arrays
using namespace std;

//Selection sort function
void selectionsort(vector <int>* a) {

     //variables initialization
     int n = a->size();

     //main loop for all the elements
     for (int i = 0; i < n; i++) {

          //finding minimum element
          int min = (*a)[i];
          int minpos = i;
          for (int j = i + 1; j < n; j++) { //loop for finding minimum element
               if (min > (*a)[j]) {
                    min = (*a)[j];
                    minpos = j;
               }
          }

          //updating final array and swapping minimum and current element
          swap((*a)[i], (*a)[minpos]);
     }
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
     selectionsort(&a);

     //output
     cout << "Sorted array (using bubble sort) = ";
     for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
     }
     cout << "\n";

     return 0;
}