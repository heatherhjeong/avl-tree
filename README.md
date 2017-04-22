this is an implementation of adelson-velsky and landis (avl) tree in c++

binary search tree has a run time of theta(h) for search, insert and remove where h is the height(a) of the tree. if we have a balanced binary search tree, then the h = theta(lg n) where n is the number of nodes in the tree, but if we don't, h could degenerate to theta(n).

avl tree is a self-balancing binary search tree with one constraint: the absolute value of the balance factor of each node cannot be greater than 1. the balance factor of a node is defined as the difference of the height of the subtree rooted at the right child of the node and the height of the subtree rooted at the left child of the node. the height of an avl tree is theta(lg n) where n is the number of nodes in that tree(b). so avl tree has theta(lg n) search, insert and remove functions

a removal or an insertion of a node may violate the constraint we impose on the avl tree and hence requires a "rebalancing" after each insertion or removal. to rebalance the tree, we must first recognize how a tree can be imbalanced. there are four ways an insertion or removal can imbalance a tree. suppose that after an insertion or a removal, node N violates the avl tree constraint, meaning that N has a balance factor of (1) -2 or (2) 2

  (1) since the balance factor of N is -2, N is left heavy (meaning that the height of the subtree rooted at the left child of N is greater than the height of the subtree rooted at the right child tree). the left child of N may have a balance factor of either (i) -1 or (ii) 1 
    
    (i) we can solve the imbalance with left left rotation (implemented as LLR)
    
    (ii) we can solve the imbalance with left right rotation (implemented as LRR)
  
  (2) since the balance factor of N is 2, N is right heavy. the right child of N may have a balance factor of either (i) -1 or (ii) 1 

    (i) we can solve the imbalance with right left rotation (implemented as LRR)  
    
    (ii) we can solve the imbalance with right right rotation (implemented as RRR) 

(a)height of a node is defined as the length of the longest path from it down to a leaf. it can also be defined recursively: height(node) = max{height(node->left), height(node->right)} + 1 where the height of nullptr is -1

(b)the height of an avl tree is at its largest when at any given node, the height of the subtree rooted at its right child is one larger than the height of the subtree rooted at its left child (or height of the subtree rooted at its left child is one larger than the height of the subtree rooted at its right child at any given node). let n_(h) denote the minimum number of nodes for an avl tree with height h. then n_(h) = 1 + n_(h-1) + n_(h-2) > 2 * n_(h-2) = theta(2^(h/2)) so we have that h < 2 lg n = theta(lg n)
