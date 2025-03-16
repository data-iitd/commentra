class Cube:
    def __init__(self):
        self.f = [0] * 6  # Array to hold the values of the cube's faces

    def roll_z(self):
        self.roll(1, 2, 4, 3)  # Roll around the Z-axis

    def roll_y(self):
        self.roll(0, 2, 5, 3)  # Roll around the Y-axis

    def roll_x(self):
        self.roll(0, 1, 5, 4)  # Roll around the X-axis

    def roll(self, i, j, k, l):
        t = self.f[i]  # Store the value of face i temporarily
        self.f[i] = self.f[j]  # Move value of face j to face i
        self.f[j] = self.f[k]  # Move value of face k to face j
        self.f[k] = self.f[l]  # Move value of face l to face k
        self.f[l] = t  # Assign the temporary value to face l

def eq(c1, c2):
    return c1.f == c2.f  # Check if two cubes are equal

def equal(c1, c2):
    for i in range(6):  # Iterate through each face of the cube
        for j in range(4):  # Try 4 rotations around the Z-axis
            if eq(c1, c2):
                return True  # Check if cubes are equal after rotation
            c1.roll_z()  # Roll the cube around the Z-axis
        # Alternate rolling around Y and X axes based on the iteration index
        if i % 2 == 0:
            c1.roll_y()  # Roll around Y-axis for even indices
        else:
            c1.roll_x()  # Roll around X-axis for odd indices
    return False  # Return false if no configuration matches

if __name__ == "__main__":
    c1 = Cube()  # Create the first Cube object
    c2 = Cube()  # Create the second Cube object

    # Input values for the first cube's faces
    c1.f = list(map(int, input().split()))
    # Input values for the second cube's faces
    c2.f = list(map(int, input().split()))

    # Check if the two cubes can be made equal and print the result
    if equal(c1, c2):
        print("Yes")  # Print "Yes" if they are equal
    else:
        print("No")  # Print "No" if they are not equal

# <END-OF-CODE>
