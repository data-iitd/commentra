

import sys

class UnionFindTree: # Defining a class named UnionFindTree
    def __init__(self, n): # Constructor of UnionFindTree class
        self.n = n # Setting the number of vertices
        self.par = list(range(n)) # Initializing the parent array
        self.rank = [0] * n # Initializing the rank array

    def find(self, x): # Method to find the root of a vertex
        if self.par[x] == x: # Base case: if the current vertex is the root
            return x # Return the current vertex
        else: # Recursive case: find the root of the parent of the current vertex
            self.par[x] = self.find(self.par[x]) # Update the parent of the current vertex to be the parent of its parent
            return self.par[x]

    def unite(self, x, y): # Method to merge two vertices
        x = self.find(x) # Finding the root of vertex x
        y = self.find(y) # Finding the root of vertex y
        if x == y: return # Return if the vertices are already connected
        if self.rank[x] < self.rank[y]: # If the rank of y is greater, make x the parent of y
            self.par[x] = y
        else: # Otherwise, make y the parent of x and increment its rank if they have the same rank
            self.par[y] = x
            if self.rank[x] == self.rank[y]: self.rank[x] += 1

    def same(self, x, y): # Method to check if two vertices are connected
        return self.find(x) == self.find(y) # Return true if they have the same root

def main(): # Main function to run the program
    n = int(input()) # Reading the number of vertices n from the standard input
    utf = UnionFindTree(n) # Creating an instance of UnionFindTree class with n vertices
    m = int(input()) # Reading the number of edges m from the standard input

    # Processing the edges
    for _ in range(m):
        x, y, z = map(int, input().split()) # Reading the source vertex x, destination vertex y, and weight z of the edge
        utf.unite(x - 1, y - 1) # Merging the two vertices x and y using the unite method of UnionFindTree class

    cnt = 0 # Initializing a counter variable for the number of connected components
    for i in range(n): # Iterating through all the vertices
        if utf.par[i] == i: # Checking if the current vertex is the root of a connected component
            cnt += 1 # Incrementing the counter if it is
    print(cnt) # Printing the number of connected components

if __name__ == "__main__": # Executing the main function if the script is run directly
    main() # Calling the main function

