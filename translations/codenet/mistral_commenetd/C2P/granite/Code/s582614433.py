
import sys

def pom(a, n, m):
    x = 1
    for a %= m:
        n //= 2
        if n:
            if n & 1:
                x = x * a % m
            a = a * a % m
    return x

MOD = 1000000007  # constant value for the modulo

# Data structure for an edge with source string, destination vertex, and weight
class Edge:
    def __init__(self, s, p, i):
        self.s = s  # source string
        self.p = p  # destination vertex
        self.i = i  # index of the edge in the data array

def esort(a, b):
    if a.s!= b.s:
        return cmp(a.s, b.s)
    if a.p < b.p:
        return 1
    return -1

data = []  # array to store edges
n = int(input())  # number of vertices
for i in range(n):
    s, p = input().split()
    p = int(p)
    data.append(Edge(s, p, i))  # assign the index of the edge to the edge itself

data.sort(key=cmp_to_key(esort))  # sort the edges based on their source strings and destination vertices
for i in range(n):
    print(data[i].i + 1)  # print the indices of the sorted edges

