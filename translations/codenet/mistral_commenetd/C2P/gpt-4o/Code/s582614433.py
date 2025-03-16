import sys
from functools import cmp_to_key

MOD = 1000000007  # constant value for the modulo

def pom(a, n, m):  # function to calculate (a^n) % m using modular exponentiation
    x = 1
    a %= m
    while n:
        if n & 1:
            x = x * a % m
        a = a * a % m
        n //= 2
    return x

class Edge:  # Data structure for an edge with source string, destination vertex, and weight
    def __init__(self, s, p, i):
        self.s = s  # source string
        self.p = p  # destination vertex
        self.i = i  # index of the edge

def esort(edge1, edge2):  # comparison function for sorting edges
    if edge1.s != edge2.s:
        return (edge1.s > edge2.s) - (edge1.s < edge2.s)  # compare source strings
    return (edge1.p < edge2.p) - (edge1.p > edge2.p)  # compare destination vertices

def main():
    n = int(sys.stdin.readline().strip())  # read the number of vertices
    data = []
    
    for i in range(n):  # for each vertex
        line = sys.stdin.readline().strip().split()
        s = line[0]  # source string
        p = int(line[1])  # destination vertex
        data.append(Edge(s, p, i))  # create an Edge object and append to the list

    data.sort(key=cmp_to_key(esort))  # sort the edges based on their source strings and destination vertices

    for edge in data:
        print(edge.i + 1)  # print the indices of the sorted edges

if __name__ == "__main__":
    main()

# <END-OF-CODE>
