# TERNARY SEARCH

# This algorithm checks whether the given element is present in the array or not.
# If the element is found in the array it returns the index of that element else 
# it returns -1 if the element is not found in the array.
# The recursive and iterative approaches are highlighted here.

def TernaryRecursive(arr,key,lower,upper):
    if lower>upper: # base case 
        return -1
    mid1=lower+(upper-lower)//3
    mid2=upper-(upper-lower)//3
    if arr[mid1]==key:
        return mid1  # the mid1 index is returned if the key is found
    if arr[mid2]==key:
        return mid2     # the mid2 index is returned if the key is found
    if  key<arr[mid1]:
        return TernaryRecursive(arr,key,lower,mid1-1) # the key is between mid1 and lower
    if key>arr[mid2]:
        return TernaryRecursive(arr,key,mid2+1,upper)  # the key is between mid2 and upper
    return TernaryRecursive(arr,key,mid1+1,mid2-1)     # the key is between mid1 and mid2

def TernaryIterative(arr,key):
    lower=0
    upper=len(arr)-1
    while lower<=upper:
        mid1=lower+(upper-lower)//3
        mid2=upper-(upper-lower)//3
        if arr[mid1]==key:
            return mid1     # the mid1 index is returned if the key is found
        if arr[mid2]==key:
            return mid2     # the mid2 index is returned if the key is found

        if key<arr[mid1]:    # the key is between mid1 and lower
            upper=mid1-1
        elif key>arr[mid2]:  # the key is between mid2 and upper
            lower=mid2+1
        else:                # the key is between mid1 and mid2
            lower=mid1+1
            upper=mid2-1             
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
    
    ans1=TernaryIterative(array,x)    # TernaryIterative is called  and the result is stored
    
    print("The ans obtained by iterative ternary search is:")
    
    if ans1==-1:
        print("element is not found")
    else:
        print(f'the element is found at index {ans1}')
    
    print()    
    ans2=TernaryRecursive(array,x,0,n-1)    # TernaryRecursive is called  and the result is stored
    
    print("The ans obtained by recursive ternary search is:")
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

The ans obtained by iterative Ternary search is:
the element is found at index 3

The ans obtained by recursive Ternary search is:
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

The ans obtained by iterative Ternary search is:
element is not found

The ans obtained by recursive Ternary search is:
element is not found


Time Complexity  : O(log3(n))
Space Complexity : O(1)
"""        