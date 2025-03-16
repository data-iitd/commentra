import sys
from collections import defaultdict

class Point:
    def __init__(self, name):
        self.name = name
        self.friends = {}  # Dictionary to store friends and their friendship lengths

    def become_friend(self, p, length):
        self.friends[p] = length  # Establishing friendship

def dfs(p, length):
    if colors[p.name] != -1:  # Check if the point is already visited
        return

    colors[p.name] = 0 if length % 2 == 0 else 1  # Assign color based on length

    for friend, length2 in p.friends.items():  # Iterate through friends
        dfs(friend, length + length2)  # Recursive DFS call

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())  # Read number of points
    m = n - 1  # Number of friendships
    colors = [-1] * n  # Initialize colors array with -1
    points = [Point(i) for i in range(n)]  # Create points

    for _ in range(m):  # Read friendships
        me, you, length = map(int, sys.stdin.readline().strip().split())
        me -= 1  # Adjusting index
        you -= 1  # Adjusting index
        points[me].become_friend(points[you], length)  # Establish friendship
        points[you].become_friend(points[me], length)  # Establish friendship

    dfs(points[0], 0)  # Start DFS from the first point

    for c in colors:  # Print colors of all points
        print(c)

# <END-OF-CODE>
