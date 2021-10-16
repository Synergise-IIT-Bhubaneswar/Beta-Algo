#INORDER BINARY TREE TRAVERSAL

# In this algorithm we print the value of the nodes present in the binary tree in inorder 
# fashion.
# Here we first traverse the left subtree and then print the root and finally we
# visit the right subtree.
# The sequence is as follows -
#    Left->Root->Right



class node (): #node class 
    def __init__(self,val):  #constructor that takes the node value as parameter
        self.left=None
        self.right=None
        self.val=val
class Tree():  # Tree class
    def __init__(self):
        self.root=None
    def buildtree(self): #method to take the nodes of the trees as input
        root=int(input())
        if root==-1:
            return
        root=node(root)
        left=self.buildtree() #building the left subtree
        right=self.buildtree() #building the right subtree
        root.left=left         #Assigning the left and the right subtree to the root
        root.right=right
        return root

    def inorder(self,root): #inorder traversal method
        if root is None:     #in case the root is empty we return from there
            return 
        self.inorder(root.left)
        print(root.val)
        self.inorder(root.right)

# Starting with the main code
def main():
    tree=Tree()        #creating the Tree object
    print("Enter the values of the tree :")
    tree.root=tree.buildtree()   #buiding the tree
    print("The order of the elements in inorder fashion is given as :")
    tree.inorder(tree.root)

main()            

"""
EXAMPLE TEST CASES

              1
1)          /   \
           2     3

Enter the values ot the tree :
1
2
-1
-1
3
-1
-1
The order of the elements in inorder fashion is given as :
2
1
3

2)          1
          /   \
         2     3
       /   \    \
      4    5     6 
Enter the values of the tree :
1
2
4
-1
-1
5
-1
-1
3
-1
6
-1
-1
The order of the elements in inorder fashion is given as :
4
2
5
1
3
6

Time Complexity: O(n) 
Space Complexity: O(1) or O(h) if size of stack of function calls is considered
Here, h is the height of the tree

"""