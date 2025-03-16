
# Class representing a Cube with 6 faces
class Cube:
    def __init__(self):
        self.f = [0] * 6 # Array to hold the values of the cube's faces

    # Method to roll the cube around the Z-axis
    def roll_z(self):
        t = self.f[1]
        self.f[1] = self.f[2]
        self.f[2] = self.f[4]
        self.f[4] = self.f[3]
        self.f[3] = t

    # Method to roll the cube around the Y-axis
    def roll_y(self):
        t = self.f[0]
        self.f[0] = self.f[2]
        self.f[2] = self.f[5]
        self.f[5] = self.f[3]
        self.f[3] = t

    # Method to roll the cube around the X-axis
    def roll_x(self):
        t = self.f[0]
        self.f[0] = self.f[1]
        self.f[1] = self.f[5]
        self.f[5] = self.f[4]
        self.f[4] = t

# Function to check if two cubes are equal
def eq(c1, c2):
    for i in range(6):
        if c1.f[i]!= c2.f[i]: return False # Return false if any face differs
    return True # Return true if all faces are equal

# Function to check if two cubes can be made equal through rotations
def equal(c1, c2):
    for i in range(6): # Iterate through each face of the cube
        for j in range(4): # Try 4 rotations around the Z-axis
            if eq(c1, c2): return True # Check if cubes are equal after rotation
            c1.roll_z() # Roll the cube around the Z-axis
        # Alternate rolling around Y and X axes based on the iteration index
        if i % 2 == 0: c1.roll_y() # Roll around Y-axis for even indices
        else: c1.roll_x() # Roll around X-axis for odd indices
    return False # Return false if no configuration matches

c1 = Cube() # Create two Cube objects
c2 = Cube()

# Input values for the first cube's faces
for i in range(6): c1.f[i] = int(input())
# Input values for the second cube's faces
for i in range(6): c2.f[i] = int(input())

# Check if the two cubes can be made equal and print the result
if equal(c1, c2): print("Yes") # Print "Yes" if they are equal
else: print("No") # Print "No" if they are not equal

