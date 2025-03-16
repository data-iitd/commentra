
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the user
sc = Scanner(System.in)

# Read the number of boxes (N) and the number of moves (M)
N = sc.nextInt()
M = sc.nextInt()

# Initialize an array of Box objects
B = [None] * N

# Create the first box as red and the rest as not red
B[0] = Box(1, True)
for i in range(1, N):
    B[i] = Box(1, False)

# Process M moves based on user input
for i in range(M):
    # Read the indices of the boxes to move from and to
    x = sc.nextInt() - 1
    y = sc.nextInt() - 1
    # Move the contents from box x to box y
    B[x].moveTo(B[y])

# Count the number of red boxes after all moves
counter = 0
for b in B:
    if b.red:
        counter += 1

# Output the count of red boxes
print(counter)

# Box class representing a box with a number and a color state
class Box:
    def __init__(self, n, r):
        self.num = n
        self.red = r

    # Method to move items from this box to another box
    def moveTo(self, other):
        # If this box is empty, do nothing
        if self.num == 0:
            return
        # If this box has one item, transfer it to the other box
        elif self.num == 1:
            self.num = 0
            other.num += 1
            # If this box is red, the other box becomes red
            if self.red:
                other.red = True
            self.red = False  # This box is no longer red
        # If this box has more than one item, transfer one item to the other box
        else:
            self.num -= 1
            other.num += 1
            # If this box is red, the other box becomes red
            if self.red:
                other.red = True


