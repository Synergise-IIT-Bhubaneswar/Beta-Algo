/*
(a) Inorder (Left, Root, Right) 
(b) Preorder (Root, Left, Right) 
(c) Postorder (Left, Right, Root) 

Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 

Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)

Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.
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

//Function for inorder traversal
function inorder_traversal(root) {
  //If function is at null then it should return
  if (root == null) return;

  //For left child of root
  inorder_traversal(root.left);

  //For printing the values of root
  console.log(`${root.data} `);

  //For right child of root
  inorder_traversal(root.right);
}

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

//Function for postorder traversal
function post_traversal(root) {
  //If function is at null then it should return
  if (root == null) return;

  //For left child of root
  inorder_traversal(root.left);

  //For right child of root
  inorder_traversal(root.right);

  //For printing the values of root
  console.log(`${root.data} `);
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

console.log("Inorder Traversal of Binary Tree:-");
inorder_traversal(root);

console.log("Postorder Traversal of Binary Tree:-");
post_traversal(root);

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
Inorder Traversal of Binary Tree:-  
4
2
5
1
3
6
Postorder Traversal of Binary Tree:-
4
5
2
6
3
1 
*/
