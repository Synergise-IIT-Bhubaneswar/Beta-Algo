//MERGE SORT IN C++

/*
Working of the merge sort algorithm -
It basically works on the principle of recursion. In this, we divide the array into 2 equal parts, and run the mergesort() function recursively on both the divided arrays, which become sorted throught mergesort() function. now, with a merge function, we combine the 2 arrays to form the full array.
the merge() function works by
*/

//Time complexity - O(nlogn)
//Space complexity - O(n) [since 2 new arrays are created for sorting and merging]

#include <iostream>
#include <vector> //for vector arrays
using namespace std;

//merge function
vector <int> merge(vector <int>* ls, vector <int>* rs) {

     //variables initialization
     vector <int> res;
     vector<int>::iterator lb = ls->begin(), rb = rs->begin();

     //placing the values from left and right arrays
     while (lb != ls->end() && rb != rs->end()) {
          if (*lb > *rb) {
               res.push_back(*rb);
               rb++;
          }
          else {
               res.push_back(*lb);
               lb++;
          }
     }

     //placing the remaning values
     while (lb != ls->end()) {
          res.push_back(*lb);
          lb++;
     }
     while (rb != rs->end()) {
          res.push_back(*rb);
          rb++;
     }

     return res;
}

//merge sort function
vector <int> mergesort(vector <int>* arr) {

     //variables initialization
     vector <int> res;
     int m = ((*arr).size() + 1) / 2;
     vector <int> ls;
     vector <int> rs;

     //breaking condition
     if ((*arr).size() <= 1) {
          return *arr;
     }

     //splitting into left and right arrays
     for (int i = 0; i < m; i++) {
          ls.push_back((*arr)[i]);
     }
     for (int i = m; i < (*arr).size(); i++) {
          rs.push_back((*arr)[i]);
     }

     //recursive calls
     ls = mergesort(&ls);
     rs = mergesort(&rs);
     res = merge(&ls, &rs);

     return res;
}

//Driver code
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
     a = mergesort(&a);

     //output
     cout << "Sorted array (using merge sort) = ";
     for (int i = 0; i < n; i++) {
          cout << a[i] << " ";
     }
     cout << "\n";

     return 0;
}