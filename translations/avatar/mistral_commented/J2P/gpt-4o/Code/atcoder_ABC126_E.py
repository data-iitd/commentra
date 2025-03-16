class UnionFindTree:  # Defining the UnionFindTree class
    def __init__(self, n):  # Constructor of UnionFindTree class
        self.n = n  # Setting the number of vertices
        self.par = list(range(n))  # Initializing the parent array
        self.rank = [0] * n  # Initializing the rank array

    def find(self, x):  # Method to find the root of a vertex
        if self.par[x] == x:  # Base case: if the current vertex is the root
            return x  # Return the current vertex
        else:  # Recursive case: find the root of the parent of the current vertex
            self.par[x] = self.find(self.par[x])  # Path compression
            return self.par[x]  # Return the root

    def unite(self, x, y):  # Method to merge two vertices
        x = self.find(x)  # Finding the root of vertex x
        y = self.find(y)  # Finding the root of vertex y
        if x == y:  # Return if the vertices are already connected
            return
        if self.rank[x] < self.rank[y]:  # If the rank of y is greater, make x the parent of y
            self.par[x] = y
        else:  # Otherwise, make y the parent of x and increment its rank if they have the same rank
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):  # Method to check if two vertices are connected
        return self.find(x) == self.find(y)  # Return true if they have the same root


def main():  # Main function to run the program
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Reading the number of vertices n from the input
    utf = UnionFindTree(n)  # Creating an instance of UnionFindTree class with n vertices
    m = int(data[1])  # Reading the number of edges m from the input

    # Processing the edges
    for i in range(m):
        x, y, z = map(int, data[i + 2].split())  # Reading the source vertex x, destination vertex y, and weight z
        utf.unite(x - 1, y - 1)  # Merging the two vertices x and y (adjusting for 0-based index)

    cnt = sum(1 for i in range(n) if utf.par[i] == i)  # Counting the number of connected components
    print(cnt)  # Printing the number of connected components


if __name__ == "__main__":  # Entry point of the program
    main()  # Calling the main function

# <END-OF-CODE>
