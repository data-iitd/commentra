class Cube:
    def __init__(self):
        self.f = [0] * 6  # Initialize an integer array 'f' of size 6

    def roll_z(self):
        self.roll(1, 2, 4, 3)  # Function to roll the cube along z-axis

    def roll_y(self):
        self.roll(0, 2, 5, 3)  # Function to roll the cube along y-axis

    def roll_x(self):
        self.roll(0, 1, 5, 4)  # Function to roll the cube along x-axis

    def roll(self, i, j, k, l):
        t = self.f[i]  # Swap the values of 'f[i]' and 'f[j]'
        self.f[i] = self.f[j]
        self.f[j] = t  # Swap the values of 'f[j]' and 't'


def eq(c1, c2):
    for i in range(6):  # Iterate through each element of the first cube 'c1'
        if c1.f[i] != c2.f[i]:  # If any element is not equal, return false
            return False
    return True  # If all elements are equal, return true


def equal(c1, c2):
    for i in range(6):  # Iterate through each rolling direction for the first cube 'c1'
        for j in range(4):  # Iterate through each rolling step in the current direction
            if eq(c1, c2):  # If the cubes are equal, return true
                return True
            c1.roll_z()  # Roll the cube along z-axis
        if i % 2 == 0:
            c1.roll_y()  # Roll the cube along y-axis if the current index 'i' is even
        else:
            c1.roll_x()  # Roll the cube along x-axis if the current index 'i' is odd
    return False  # If the cubes are not equal after all rolling directions and steps, return false


if __name__ == "__main__":
    c1 = Cube()  # Initialize an empty cube 'c1'
    c2 = Cube()  # Initialize an empty cube 'c2'

    # Read the states of the cubes from the standard input
    c1.f = list(map(int, input().split()))
    c2.f = list(map(int, input().split()))

    # Compare the cubes and print the result
    if equal(c1, c2):
        print("Yes")
    else:
        print("No")

# <END-OF-CODE>
