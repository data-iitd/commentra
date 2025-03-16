class Data:
    def __init__(self, n, m, n_img, m_img):
        self.n = n  # number of rows in the first image
        self.m = m  # number of rows in the second image
        self.n_img = n_img  # first image as a list of strings
        self.m_img = m_img  # second image as a list of strings

    def exist(self):
        # Iterate over possible starting positions in the first image
        for i in range(self.n - self.m + 1):
            for j in range(self.n - self.m + 1):
                # Check if the second image matches the first image at the current position
                if self.match(i, j):
                    return True  # Return true if a match is found
        return False  # Return false if no match is found

    def match(self, x, y):
        # Iterate over each cell of the second image
        for i in range(self.m):
            for j in range(self.m):
                # Compare the corresponding cells of the two images
                if self.n_img[x + i][y + j] != self.m_img[i][j]:
                    return False  # Return false if any cell does not match
        return True  # Return true if all cells match


def load(cnt):
    ret = []
    for _ in range(cnt):
        # Read each line of the image into the list
        ret.append(input().strip())
    return ret


def new_data():
    # Read the dimensions of the images from standard input
    n, m = map(int, input().split())
    # Load the first image and the second image based on the dimensions
    n_img = load(n)
    m_img = load(m)
    # Return a Data instance containing the dimensions and images
    return Data(n, m, n_img, m_img)


if __name__ == "__main__":
    # Create a new Data instance and check for the existence of a match
    d = new_data()
    if d.exist():
        print("Yes")  # Print "Yes" if a match exists
    else:
        print("No")  # Print "No" if no match is found

# <END-OF-CODE>
