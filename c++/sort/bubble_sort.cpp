// BUBBLE SORT IN C++

/*
Working of the bubble sort algorithm -
this sorting algorithm works by comparision of elements. It basically compares 2 adjacent elements and checks if they are sorted or not. for 2 elements there are only 2 possiblities - a[i + 1] > a[i] or a[i] < a[i + 1].
if the first case is true, it swaps the 2 elements so that the 2 elements is sorted.
this is done for all the elements in the array, till the largest element of the array reaches its designated position, that is, the largest element reaches the last position of the array (bubbles to the end of the array, hence bubble sort).
thus, this process is repeated till all the elements are in their desired positions.
*/

/*
Time complexity of the algorithm - O(n^2)
Space complexiy - O(1)
*/

#include <iostream>
#include <vector> //for vector arrays
using namespace std;

//bubble sort function
void bubblesort(vector <int>* a) {

     int n = (*a).size();

     //main loop for all the elements
     for (int i = 0; i < n; i++) {

          //internal loop for doing the sorting
          // NOTE - (j < n - i), since after i elements being sorted at the end, there is no need to reach those elements.
          for (int j = 1; j < n - i; j++) {
               if ((*a)[j - 1] > (*a)[j]) {

                    //swap
                    swap((*a)[j], (*a)[j - 1]);
               }
          }

     }

     return;
}

// Driver Code
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
     bubblesort(&a);

     //output
     cout << "Sorted array (using bubble sort) = ";
     for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
     }
     cout << "\n";

     return 0;
}