# LINEAR SEARCH

# This algorithm checks whether the given element is present in the array or not.
# If the element is found in the array it returns the index of that element else 
# it returns -1 if the element is not found in the array.

def LinearSearch(arr,key):
    for i in range(len(arr)):
        if arr[i]==key:
            return i   # this returns the index if the key is found
    
    return -1   # this value is returned if the key is not found in the array



# Starting with the main code
# Creating array of the size n
# Size would be taken into the variable n from user
def main():
main()


""""
SAMPLE INPUT:
5
1
5
7
2
9
7
SAMPLE OUTPUT:
Enter the size of array : Enter elements :
The elements entered are:
[1, 5, 7, 2, 9]
The sorted array is:
[1, 2, 5, 7, 9]
Enter the element to be searched: Element found at index 3
Time Complexity  : O(n)
Space Complexity : O(1)
"""        