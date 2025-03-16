# Define a class to hold the data for the images
class Data:
    def __init__(self):
        self.n, self.m = map(int, input().split())  # Read the dimensions of the images
        self.nImg = self.load(self.n)  # Load the larger image
        self.mImg = self.load(self.m)  # Load the smaller image

    # Function to read a specified number of strings from standard input and return them as a list of strings
    def load(self, cnt):
        return [input().strip() for _ in range(cnt)]  # Read each string from standard input

    # Method to check if the smaller image exists within the larger image
    def exist(self):
        # Iterate over all possible positions where the smaller image could fit within the larger image
        for i in range(self.n - self.m + 1):
            for j in range(self.n - self.m + 1):
                if self.match(i, j):  # Check if the smaller image matches the corresponding part of the larger image
                    return True
        return False

    # Method to check if the smaller image matches the corresponding part of the larger image at a given position
    def match(self, x, y):
        # Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
        for i in range(self.m):
            for j in range(self.m):
                if self.nImg[x + i][y + j] != self.mImg[i][j]:  # If any pixel does not match, return false
                    return False
        return True  # If all pixels match, return true


# Main function to execute the program
if __name__ == "__main__":
    d = Data()  # Create a new Data instance
    # Check if the smaller image exists within the larger image and print the result
    if d.exist():
        print("Yes")
    else:
        print("No")

# <END-OF-CODE>
