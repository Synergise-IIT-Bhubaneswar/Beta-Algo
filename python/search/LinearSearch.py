# LINEAR SEARCH

# This algorithm checks whether the given element is present in the array or not.
# If the element is found in the array it returns the index of that element else 
# it returns -1 if the element is not found in the array.

def LinearSearch(arr,key):
    # we use a for loop to iterate through the array. 
    for i in range(len(arr)):
        if arr[i]==key:
            return i   # this returns the index if the key is found
    
    return -1   # this value is returned if the key is not found in the array



# Starting with the main code
# Creating array of the size n
# Size would be taken into the variable n from user
def main():
    print("please enter the size of the array :")
    n=int(input()) # takes size as input
    array=[]
    print("please enter the elements of the array :")
    for j in range(n):     # for loop for taking the elements as input
        array.append(int(input()))
    print("please enter the key element :")    
    x=int(input())         # the key is taken as input
    print(LinearSearch(array,x))    # linear search is called  and the result is printed

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