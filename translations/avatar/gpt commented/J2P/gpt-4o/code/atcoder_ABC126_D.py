class Point:
    def __init__(self, name):
        self.name = name  # Unique identifier for the point
        self.friends = {}  # Dictionary to store friends and their friendship lengths

    def become_friend(self, p, length):
        self.friends[p] = length  # Add friend with the specified length


def dfs(p, length):
    global colors
    # Check if the point has already been colored
    if colors[p.name] != -1:
        return  # Exit if already colored

    # Assign color based on the length (even or odd)
    if length % 2 == 0:
        colors[p.name] = 0  # Even length -> color 0
    else:
        colors[p.name] = 1  # Odd length -> color 1

    # Recursively visit all friends of the current point
    for friend, length2 in p.friends.items():
        dfs(friend, length + length2)  # Recursive DFS call


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    # Read the number of points (nodes)
    n = int(data[0])  
    m = n - 1  # Calculate the number of edges (m = n - 1 for a tree)

    # Initialize colors array with -1 (indicating uncolored)
    colors = [-1] * n

    # Create an array of Point objects
    points = [Point(i) for i in range(n)]

    # Read edges and establish friendships between points
    for i in range(1, m + 1):
        me, you, length = map(int, data[i].split())
        me -= 1  # Convert to 0-indexed
        you -= 1  # Convert to 0-indexed

        # Establish friendship in both directions
        points[me].become_friend(points[you], length)
        points[you].become_friend(points[me], length)

    # Start DFS from the first point (index 0)
    dfs(points[0], 0)

    # Output the colors assigned to each point
    for c in colors:
        print(c)

# <END-OF-CODE>
