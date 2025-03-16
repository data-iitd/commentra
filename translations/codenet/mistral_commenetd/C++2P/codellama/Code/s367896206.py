
#include<iostream>
using namespace std;

# Define a class named Cube with a public array 'f' of size 6
class Cube:
    def __init__(self):
        self.f = [0] * 6

    def roll_z(self):
        self.roll(1, 2, 4, 3)

    def roll_y(self):
        self.roll(0, 2, 5, 3)

    def roll_x(self):
        self.roll(0, 1, 5, 4)

    def roll(self, i, j, k, l):
        t = self.f[i]
        self.f[i] = self.f[j]
        self.f[j] = t

# Function to check if two cubes are equal
def eq(c1, c2):
    for i in range(6):
        if c1.f[i] != c2.f[i]:
            return False
    return True

# Function to check if two cubes are equal after rolling
def equal(c1, c2):
    for i in range(6):
        for j in range(4):
            if eq(c1, c2):
                return True
            c1.roll_z()
        if i % 2 == 0:
            c1.roll_y()
        else:
            c1.roll_x()
    return False

# Main function to read the cubes' states and compare them
def main():
    c1 = Cube()
    c2 = Cube()

    # Read the states of the cubes from the standard input
    for i in range(6):
        c1.f[i] = int(input())
    for i in range(6):
        c2.f[i] = int(input())

    # Compare the cubes and print the result
    if equal(c1, c2):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

