
# Define a class to hold the data for the images
class Data:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.nImg = []
        self.mImg = []

    # Function to initialize a new data instance by reading image dimensions and data from standard input
    def newData(self):
        self.n, self.m = map(int, input().split()) # Read the dimensions of the images

        # Load the images from standard input
        self.nImg = load(self.n)
        self.mImg = load(self.m)

        # Return a new data instance with the loaded images and dimensions
        return self

    # Function to read a specified number of strings from standard input and return them as a list of strings
    def load(self, cnt):
        ret = []
        for i in range(cnt):
            ret.append(input()) # Read each string from standard input
        return ret

    # Method to check if the smaller image exists within the larger image
    def exist(self):
        # Iterate over all possible positions where the smaller image could fit within the larger image
        for i in range(self.n-self.m+1):
            for j in range(self.n-self.m+1):
                if self.match(i, j): # Check if the smaller image matches the corresponding part of the larger image at the current position
                    return True
        return False

    # Method to check if the smaller image matches the corresponding part of the larger image at a given position
    def match(self, x, y):
        # Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
        for i in range(self.m):
            for j in range(self.m):
                if self.nImg[x+i][y+j] != self.mImg[i][j]: # If any pixel does not match, return false
                    return False
        return True # If all pixels match, return true

# Create a new data instance
d = Data()

# Check if the smaller image exists within the larger image and print the result
if d.exist():
    print("Yes")
else:
    print("No")

# END-OF-CODE
