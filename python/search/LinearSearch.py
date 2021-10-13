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
    print()
    ans=LinearSearch(array,x)    # linear search is called  and the result is stored
    if ans==-1:
        print("element is not found")
    else:
        print(f'the element is found at index {ans}')    


main()


""""
Example Test Cases:
1)

please enter the size of the array :
5
please enter the elements of the array :
1
2
3
4
5
please enter the key element :
4

the element is found at index 3

2)

please enter the size of the array :
5
please enter the elements of the array :
1
2
3
4
5
please enter the key element :
7

element is not found

Time Complexity  : O(n)
Space Complexity : O(1)
"""        