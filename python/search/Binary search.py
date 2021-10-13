# BINARY SEARCH

# This algorithm checks whether the given element is present in the array or not.
# If the element is found in the array it returns the index of that element else 
# it returns -1 if the element is not found in the array.
# The recursive and iterative approaches are highlighted here.

def BinaryRecursive(arr,key,lower,upper):
    if lower>upper: # base case 
        return -1
    mid=(lower+upper)//2
    if arr[mid]==key:
        return mid  # the mid index is returned if the key is found 
    elif arr[mid]>key:
        return BinaryRecursive(arr,key,lower,mid-1)  # if key is less than arr[mid] then we search in the left part of the array
    else:
        return BinaryRecursive(arr,key,mid+1,upper)  # if key is greater than arr[mid] then we search in the right part of the array          

def BinaryIterative(arr,key):
    lower=0
    upper=len(arr)-1
    while lower<=upper:
        mid=(lower+upper)//2
        if arr[mid]==key:
            return mid     # the mid index is returned if the key is found
        elif arr[mid]>key:  # if key is less than arr[mid] then we search in the left part of the array
            upper=mid-1
        else:               # if key is greater than arr[mid] then we search in the right part of the array
            lower=mid+1        
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
    
    ans1=BinaryIterative(array,x)    # BinaryIterative is called  and the result is stored
    
    print("The ans obtained by iterative binary search is:")
    
    if ans1==-1:
        print("element is not found")
    else:
        print(f'the element is found at index {ans1}')
    
    print()    
    ans2=BinaryRecursive(array,x,0,n-1)    # BinaryRecursive is called  and the result is stored
    
    print("The ans obtained by recursive binary search is:")
    if ans2==-1:
        print("element is not found")
    else:
        print(f'the element is found at index {ans2}')        


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

The ans obtained by iterative binary search is:
the element is found at index 3

The ans obtained by recursive binary search is:
the element is found at index 3

2)



Time Complexity  : O(logn)
Space Complexity : O(1)
"""        