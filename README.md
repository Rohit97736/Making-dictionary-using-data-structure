# Making-dictionary-using-data-structure


IMPLEMENTATION OF DICTIONARY AND SEARCH OPERATION

In this project, I have implemented a Dictionary(an associative array) with help of AVL trees(self balancing trees) and implemented a search operation using effective dynamic programming.

AVL is nothing it is BST also which satisfies the condition for balance(-1 <= balance <= 1). Most of the BST operations (e.g., Search, Max, Min, Insert, Delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) where n is no. of node for a skewed Binary tree which is worst. If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree.


INSERTION IN AVL TREES:

Let the newly inserted node be W
	
         1) Perform standard BST insert for W Comparison of strings is done with help of string.compare() function available in STL.
           Thus Alphabetical sorting is ensured.
	
        2) Starting from W, travel up and find the first Unbalanced Node.
	
        3) Re-balance the tree by performing appropriate rotations. There can be 4 possible cases that needs to be handled as X, Y and Z can be  arranged in 4 ways.
         
         Following are the possible 4 arrangements:
			
             -> Left Left Rotation
			
             -> Left Right Rotation
			
             -> Right Right Rotation
			
             -> Right Left Rotation
             
             
  SEARCH FOR USER ENTERED WORD:        
             
     -Search in an AVL tree is similar  to search in BST tree and of time complexity O(logn). To search a given key in Binary Search Tree, We first compare it with root, if the         key is present at root, we return root. If key is greater than root key, we recur for right subtree of root node. Otherwise for left subtree.	

     - Suppose if the word requested by user is not found, then we proceed to suggest closest possible word available in dictionary with the help of dynamic programming(dp).
 
       We traverse through the tree and compare the user entered string with dictionary and find the edit distance at each instance, and return the dictionary word with minimum       edit distance.
   
   
   EDIT DISTANCE FOR EACH PAIR OF STRING
	
      -The idea is all characters one by one staring from either from left or right sides of both Strings.
	
       Let us traverse, there are two possibilities: 
        
	For substrings size i & j we have following possibilities
	
           -> If the last two characters are same then edit distance.
	
           -> If the last two characters are not same then compute minimum edit cost  
	
    
      If the User is satisfied with the suggested word then we give the meaning of the same, else user requested word is absent and close to dictionary.
