Title: Readme
Author: Zübeyir Bodur
ID: 21702382
Assignment: 2

First thing to notice in my code is that, it works for small data.
If we try to increase size of input.txt, i.e. we add larger words, we
will eventually get segmentation fault if we don't increase n.
This happens because the height of the binary search three 
increases very quickly as more data inserted. Since the height increases,
number of recursions needed also increases. If the three was an AVL tree
instead of a BST, we would have stored more n-grams because an AVL tree
would have less height, resulting less function calls. In my code, segmentation fault was encountered
after 16 n-grams.

Another remark is in the function isFull. In that function, it is not guarenteed
that all nodes are filled down to the level h. But it ensures that all nodes 
have two children. For example, the left subtree of a root can have height 
h-1 and the right subtree can have  height h-k while both subtrees are full BSTs.
To solve this problem, a nodes height could have been calculated and then stored.
And then isComplete function could have been used to check if the nodes down to the level
h-1 are full. Then the nodes in the last level could have been checked one by one.

Finally, there were 4 extra classes other than indicated in the assignment. They were
TreeNode.h, TreeNode.cpp, TreeException.h, Item.h. TreeNode class was for the nodes of
NgramTree class. Item class was for the ngram string and its integer count. TreeException 
class was for handling exceptions while searching/adding/deleting ngrams in/to/from the tree.
