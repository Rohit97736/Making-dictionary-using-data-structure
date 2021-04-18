# Making-dictionary-using-data-structure


IMPLEMENTATION OF DICTIONARY AND SEARCH OPERATION

In this project, I have implemented a Dictionary(an associative array) with help of AVL trees(self balancing trees) and implemented a search operation using effective dynamic programming.

Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree.


INSERTION IN AVL TREES:

Let the newly inserted node be w
	
         1) Perform standard BST insert for w. Comparison of strings is done with help of string.compare() function available in STL.
           Thus alphabetical sorting is ensured.
	
        2) Starting from w, travel up and find the first unbalanced node. Let z be the first unbalanced node, y be the child of z that comes on the path from w to z and x be                the grandchild of z that comes on the path from w to z.
	
        3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z. There can be 4 possible cases that needs to be handled as x, y and z can be                arranged in 4 ways. Following are the possible 4 arrangements:
			
           
             a) y is left child of z and x is left child of y (Left Left Rotation)
			
             b) y is left child of z and x is right child of y (Left Right Rotation)
			
             c) y is right child of z and x is right child of y (Right Right Rotation)
			
             d) y is right child of z and x is left child of y (Right Left Rotation)
             
             
  SEARCH FOR USER ENTERED WORD:        
             
    Search in an AVL tree is similar  to search in BST tree and of time complexity O(logn). To search a given key in Binary Search Tree, we first compare it with root, if the        key is present at root, we return root. If key is greater than root’s key, we recur for right subtree of root node. Otherwise we recur for left subtree.	

    Suppose if the word requested by user is not found , then we proceed to suggest closest possible word available in dictionary with the help of dynamic programming.
 
    We traverse through the tree and compare the user entered string with dictionary and find the edit distance at each instance , and  return the dictionary word with minimum       edit distance.
   
   
   EDIT DISTANCE FOR EACH PAIR OF STRING
	
	
      The idea is process all characters one by one staring from either from left or right sides of both strings.
	
      Let us traverse from right corner, there are two possibilities for every pair of character being traversed. 
	
      Create a matrix L with size mxn( m- size of user entered string and n- size of dictionary string)
      
      
      
      If the user is satisfied with the suggested word then we give the meaning of the same, else user requested word is absent in dictionary.
