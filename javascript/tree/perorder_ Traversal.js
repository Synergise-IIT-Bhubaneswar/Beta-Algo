/*
Inorder (Left, Root, Right) 

Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
 */


//Class for binary tree
class Node {
    //Constructor for giving the values,left and right child of root
    constructor(data) {
      this.data = data;
      this.left = null;
      this.right = null;
    }
  }
  
  // Root of Binary Tree
  let root = null;
  
  //Function for preorder traversal
  function pre_traversal(root) {
    //If function is at null then it should return
    if (root == null) return;
  
    //For printing the values of root
    console.log(`${root.data} `);
  
    //For left child of root
    inorder_traversal(root.left);
  
    //For right child of root
    inorder_traversal(root.right);
  }
  
  //Buliding of the BT
  root = new Node(1);
  root.left = new Node(2);
  root.right = new Node(3);
  root.left.left = new Node(4);
  root.left.right = new Node(5);
  root.right.right = new Node(6);
  
  console.log("Perorder Traversal of Binary Tree:-");
  pre_traversal(root);
  
  /*  Binary Tree
                  1
               /    \
              2      3
            /  \      \
           4    5      6
  
  Output :
  Perorder Traversal of Binary Tree:-
  1
  2
  4
  5
  3
  6
  */
  