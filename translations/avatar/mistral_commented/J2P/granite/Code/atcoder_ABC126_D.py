

import sys

def main():
    n = int(input()) # Reading the number of points 'n' from the console
    m = n - 1 # Calculating the number of friendships'm'
    colors = [-1] * n # Initializing the 'colors' array with '-1' to represent unvisited points
    points = [Point(i) for i in range(n)] # Creating a list of 'Point' objects with size 'n'

    for i in range(m): # Reading and processing friendships between points
        me = int(input()) - 1 # Reading the index of the first point
        you = int(input()) - 1 # Reading the index of the second point
        length = int(input()) # Reading the length of the friendship
        points[me].becomeFriend(points[you], length) # Establishing friendship between 'points[me]' and 'points[you]'
        points[you].becomeFriend(points[me], length) # Establishing friendship between 'points[you]' and 'points[me]'

    dfs(points[0], 0) # Starting Depth-First Search from the first point

    for c in colors: # Printing the colors of all points
        print(c)

def dfs(p, length): # Depth-First Search function
    alreadyKnown = colors[p.name]!= -1 # Checking if the current point is already visited
    if alreadyKnown: return # Returning if the current point is already visited

    if length % 2 == 0: # Assigning color '0' to even-length friendships
        colors[p.name] = 0
    else: # Assigning color '1' to odd-length friendships
        colors[p.name] = 1

    for friend, length2 in p.friends.items(): # Iterating through the friends of the current point
        dfs(friend, length + length2) # Recursively calling DFS on the friend point

class Point: # Definition of the 'Point' class
    def __init__(self, name): # Constructor of the 'Point' class
        self.name = name
        self.friends = {} # Initializing the 'friends' map

    def becomeFriend(self, p, length): # Function to establish a friendship between two points
        self.friends[p] = length # Adding the friend and their friendship length to the 'friends' map

if __name__ == "__main__":
    main() # Calling the main function

