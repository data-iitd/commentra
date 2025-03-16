def main():
    # Declare and initialize variables
    n,i,id,l,r = 0,0,0,0,0
    p = 0

    # Read the number of nodes in the tree
    n = int(input())

    # Initialize the tree
    init(n)

    # Read the input and build the tree
    for i in range(n):
        # Read the id, left child, and right child of the current node
        id,l,r = map(int,input().split())

        # If the left child is not -1, assign it to the left child of the current node
        if(l!= -1):
            N[id].l = l
            N[l].par = id

        # If the right child is not -1, assign it to the right child of the current node
        if(r!= -1):
            N[id].r = r
            N[r].par = id

    # Find the root node and perform tree traversals
    for i in range(n):
        if(N[i].par == -1):
            p = i
            break

    # Print the tree traversals in Preorder, Inorder, and Postorder
    print("Preorder")
    Preorder(p)
    print("")

    print("Inorder")
    Inorder(p)
    print("")

    print("Postorder")
    Postorder(p)
    print("")

# Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.

