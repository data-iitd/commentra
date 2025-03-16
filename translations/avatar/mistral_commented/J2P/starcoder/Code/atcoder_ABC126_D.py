
import sys

class Main:
    colors = [] # Declaring an integer array 'colors' to store colors of points

    def __init__(self):
        self.sc = sys.stdin # Creating a Scanner object to read input from the console
        self.n = int(self.sc.readline()) # Reading the number of points 'n' from the console
        self.m = self.n - 1 # Calculating the number of friendships'm'
        self.colors = [-1] * self.n # Initializing the 'colors' array with '-1' to represent unvisited points
        self.points = [Point(i) for i in range(self.n)] # Creating an array of 'Point' objects with size 'n'

    def run(self):
        while self.m > 0: # Reading and processing friendships between points
            me = int(self.sc.readline()) - 1 # Reading the index of the first point
            you = int(self.sc.readline()) - 1 # Reading the index of the second point
            length = int(self.sc.readline()) # Reading the length of the friendship
            self.points[me].becomeFriend(self.points[you], length) # Establishing friendship between 'points[me]' and 'points[you]'
            self.points[you].becomeFriend(self.points[me], length) # Establishing friendship between 'points[you]' and 'points[me]'
            self.m -= 1

        self.dfs(self.points[0], 0) # Starting Depth-First Search from the first point

        for c in self.colors: # Printing the colors of all points
            print(c)

    def dfs(self, p, length): # Depth-First Search function
        alreadyKnown = self.colors[p.name]!= -1 # Checking if the current point is already visited
        if alreadyKnown: return # Returning if the current point is already visited

        if length % 2 == 0: # Assigning color '0' to even-length friendships
            self.colors[p.name] = 0
        else: # Assigning color '1' to odd-length friendships
            self.colors[p.name] = 1

        for friend, length2 in p.friends.items(): # Iterating through the friends of the current point
            self.dfs(friend, length + length2) # Recursively calling DFS on the friend point

class Point: # Definition of the 'Point' class
    def __init__(self, name): # Constructor of the 'Point' class
        self.name = name
        self.friends = {} # Initializing the 'friends' map

    def becomeFriend(self, p, length): # Function to establish a friendship between two points
        self.friends[p] = length # Adding the friend and their friendship length to the 'friends' map

if __name__ == "__main__":
    obj = Main()
    obj.run()

# 