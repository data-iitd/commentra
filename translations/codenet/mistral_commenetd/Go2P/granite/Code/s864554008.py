

# Define a custom data structure
class Data:
    def __init__(self, n, m, n_img, m_img):
        self.n = n
        self.m = m
        self.n_img = n_img
        self.m_img = m_img

# Main function
def main():
    # Initialize a new data object
    d = Data()
    # Check if data already exists
    if d.exist():
        print("Yes")
    else:
        print("No")

# Initialize a new data object
def Data():
    # Read dimensions from user input
    n, m = map(int, input().split())
    # Load image data as strings
    n_img = load(n)
    m_img = load(m)

    # Initialize data object with loaded data
    return Data(n, m, n_img, m_img)

# Load image data as strings
def load(cnt):
    # Allocate memory for image data
    ret = []
    # Read image data from user input
    for _ in range(cnt):
        ret.append(input())

    # Return loaded image data
    return ret

# Check if data already exists in the larger image
def exist(self):
    # Iterate through all possible positions in larger image
    for i in range(self.n - self.m + 1):
        for j in range(self.n - self.m + 1):
            # Check if current position matches the smaller image
            if match(self, i, j):
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
            if self.n_img[x + i][y + j]!= self.m_img[i][j]:
                # If mismatch is found, return false
                return False
    # If all pixels match, return true
    return True

# End of code
