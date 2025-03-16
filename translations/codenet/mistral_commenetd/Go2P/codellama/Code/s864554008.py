
# Define a custom data structure
class data:
    def __init__(self, n, m, nImg, mImg):
        self.n = n
        self.m = m
        self.nImg = nImg
        self.mImg = mImg

# Main function
def main():
    # Initialize a new data object
    d = newData()
    # Check if data already exists
    if d.exist():
        print("Yes")
    else:
        print("No")

# Initialize a new data object
def newData():
    # Read dimensions from user input
    n, m = map(int, input().split())
    # Load image data as strings
    nImg = load(n)
    mImg = load(m)

    # Initialize data object with loaded data
    return data(n, m, nImg, mImg)

# Load image data as strings
def load(cnt):
    # Allocate memory for image data
    ret = [None] * cnt
    # Read image data from user input
    for i in range(cnt):
        ret[i] = input()

    # Return loaded image data
    return ret

# Check if data already exists in the larger image
def exist(self):
    # Iterate through all possible positions in larger image
    for i in range(self.n - self.m + 1):
        for j in range(self.n - self.m + 1):
            # Check if current position matches the smaller image
            if self.match(i, j):
                # If match is found, return true
                return True

    # If no match is found, return false
    return False

# Check if smaller image matches at current position in larger image
def match(self, x, y):
    # Iterate through each pixel in smaller image
    for i in range(self.m):
        for j in range(self.m):
            # Check if corresponding pixel in larger image matches
            if self.nImg[x+i][y+j] != self.mImg[i][j]:
                # If mismatch is found, return false
                return False

    # If all pixels match, return true
    return True


