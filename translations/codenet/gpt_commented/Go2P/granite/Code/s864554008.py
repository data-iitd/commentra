
import sys

# Define a class to hold the dimensions and images
class Data:
    def __init__(self):
        self.n, self.m = map(int, input().split())  # Read the dimensions of the images from standard input
        self.nImg = [input() for _ in range(self.n)]  # Load the first image
        self.mImg = [input() for _ in range(self.m)]  # Load the second image

    def exist(self):
        # Iterate over possible starting positions in the first image
        for i in range(self.n - self.m + 1):
            for j in range(self.n - self.m + 1):
                # Check if the second image matches the first image at the current position
                if self.match(i, j):
                    return True  # Return True if a match is found
        return False  # Return False if no match is found after checking all positions

    def match(self, x, y):
        # Iterate over each cell of the second image
        for i in range(self.m):
            for j in range(self.m):
                # Compare the corresponding cells of the two images
                if self.nImg[x + i][y + j]!= self.mImg[i][j]:
                    return False  # Return False if any cell does not match
        return True  # Return True if all cells match

# Create a new data instance and check for the existence of a match
d = Data()
if d.exist():
    print("Yes")  # Print "Yes" if a match exists
else:
    print("No")  # Print "No" if no match is found

