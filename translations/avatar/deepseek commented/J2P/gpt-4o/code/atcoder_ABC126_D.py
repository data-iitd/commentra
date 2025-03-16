class Point:
    def __init__(self, name):
        self.name = name
        self.friends = {}  # Initialize the friends dictionary

    def become_friend(self, p, length):
        self.friends[p] = length  # Add the friend and the length of the edge


def dfs(p, length):
    if colors[p.name] != -1:  # Check if the color of the current point is already known
        return  # If the color is already known, return

    colors[p.name] = 0 if length % 2 == 0 else 1  # Color the current point based on the length

    for friend, length2 in p.friends.items():  # Iterate through the friends of the current point
        dfs(friend, length + length2)  # Recursively call DFS for the friend


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    n = int(data[0])  # Read the number of nodes
    m = n - 1  # Calculate the number of edges
    colors = [-1] * n  # Initialize the colors array with size n and set all colors to -1

    points = [Point(i) for i in range(n)]  # Create an array to store the points (nodes)

    for i in range(1, m + 1):  # Read the edges and their lengths
        me, you, length = map(int, data[i].split())
        me -= 1  # Adjust for 0-based index
        you -= 1  # Adjust for 0-based index
        points[me].become_friend(points[you], length)  # Update the friends list for the first node
        points[you].become_friend(points[me], length)  # Update the friends list for the second node

    dfs(points[0], 0)  # Perform a DFS starting from the first point

    for c in colors:  # Output the color of each node
        print(c)

# <END-OF-CODE>
