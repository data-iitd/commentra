
import sys

# Read the number of boxes (N) and the number of moves (M)
N, M = map(int, input().split())

# Initialize a list of Box objects
B = [Box(1, True) for _ in range(N)]

# Process M moves based on user input
for _ in range(M):
    # Read the indices of the boxes to move from and to
    x, y = map(int, input().split())
    # Move the contents from box x to box y
    B[x-1].moveTo(B[y-1])

# Count the number of red boxes after all moves
counter = sum(1 for b in B if b.red)

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

