/*Segment Tree is a basically a binary tree used for storing the intervals or segments. 
Each node in the segment tree represents an interval.When there is need to update an interval 
in the range in Lazy propagation method, instead of updating each element one by one which will
turn complexity O(n) we will update a node and mark its child that it needs to be updated and update it when needed. 
For this we need an array of the same size as that of segment tree. Initially all the elements of the array will be 0 representing that there is no pending update. 
If there is non-zero element then this element needs to update node  in the segment tree before making any query operation. */

class segmentree {
    final int MAX = 1000; // Max tree size
    int tree[] = new int[MAX]; // stors segment tree
    int lazy[] = new int[MAX]; // stores pending updates

    void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {

        if (lazy[si] != 0) {
            // Makes pdates using value stored in lazy nodes
            tree[si] += (se - ss + 1) * lazy[si];

            if (ss != se) {

                lazy[si * 2 + 1] += lazy[si];
                lazy[si * 2 + 2] += lazy[si];
            }

            // Assigned the lazy value for current node as 0 as it has been updated
            lazy[si] = 0;
        }

        // out of range
        if (ss > se || ss > ue || se < us)
            return;

        // Current segment is fully in range
        if (ss >= us && se <= ue) {
            // Add the difference to current node
            tree[si] += (se - ss + 1) * diff;

            if (ss != se) {

                lazy[si * 2 + 1] += diff;
                lazy[si * 2 + 2] += diff;
            }
            return;
        }

        int mid = (ss + se) / 2;
        updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
        updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

        tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
    }

    // Function to update a range of values in segment tree

    void updateRange(int n, int us, int ue, int diff) {
        updateRangeUtil(0, 0, n - 1, us, ue, diff);
    }

    int getSumUtil(int ss, int se, int qs, int qe, int si) {

        if (lazy[si] != 0) {

            tree[si] += (se - ss + 1) * lazy[si];

            if (ss != se) {

                lazy[si * 2 + 1] += lazy[si];
                lazy[si * 2 + 2] += lazy[si];
            }

            lazy[si] = 0;
        }

        // Out of range
        if (ss > se || ss > qe || se < qs)
            return 0;

        if (ss >= qs && se <= qe)
            return tree[si];

        int mid = (ss + se) / 2;
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
                getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
    }

    // Returns the sum of elements in range from index qs (query start) to qe (query
    // end).
    int getSum(int n, int qs, int qe) {

        if (qs < 0 || qe > n - 1 || qs > qe) {
            System.out.println("Invalid Input");
            return -1;
        }

        return getSumUtil(0, n - 1, qs, qe, 0);
    }

    /*
     * A recursive function that constructs Segment Tree for
     * array[ss..se]. si is index of current node in segment
     * tree st.
     */
    void constructSTUtil(int arr[], int ss, int se, int si) {

        if (ss > se)
            return;

        if (ss == se) {
            tree[si] = arr[ss];
            return;
        }

        int mid = (ss + se) / 2;
        constructSTUtil(arr, ss, mid, si * 2 + 1);
        constructSTUtil(arr, mid + 1, se, si * 2 + 2);

        tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
    }

    /*
     * Function to construct segment tree from given array.
     * This function allocates memory for segment tree and
     * calls constructSTUtil() to fill the allocated memory
     */
    void constructST(int arr[], int n) {

        constructSTUtil(arr, 0, n - 1, 0);
    }

    // Driver program to test above functions
    public static void main(String args[]) {
        int arr[] = { 1, 3, 5, 7, 9, 11 };
        int n = arr.length;
        segmentree tree = new segmentree();

        // Build segment tree from given array
        tree.constructST(arr, n);

        // Print sum of values in array from index 1 to 4
        System.out.println("Sum of values in given range = " + tree.getSum(n, 1, 4));

        // Add 10 to all nodes at indexes from 1 to 6.
        tree.updateRange(n, 1, 6, 10);

        // Find sum after the value is updated
        System.out.println("Updated sum of values in given range = " + tree.getSum(n, 1, 4));
    }
}
/*
 * output:-
 * Sum of values in given range = 24
 * Updated sum of values in given range = 64
 * Time complexity= O(log(n))
 */