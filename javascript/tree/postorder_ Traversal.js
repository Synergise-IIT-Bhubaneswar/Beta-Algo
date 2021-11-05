/*
 Postorder (Left, Right, Root) 

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


console.log("Postorder Traversal of Binary Tree:-");
post_traversal(root);

/*  Binary Tree
                1
             /    \
            2      3
          /  \      \
         4    5      6
         
Postorder Traversal of Binary Tree:-
4
5
2
6
3
1 
*/
