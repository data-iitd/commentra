class Box:
    def __init__(self, n, r):
        self.num = n  # Number of items in the box
        self.red = r  # Indicates if the box is red

    def move_to(self, other):
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


def main():
    # Read the number of boxes (N) and the number of moves (M)
    N, M = map(int, input().split())

    # Initialize an array of Box objects
    B = [None] * N

    # Create the first box as red and the rest as not red
    B[0] = Box(1, True)
    for i in range(1, N):
        B[i] = Box(1, False)

    # Process M moves based on user input
    for _ in range(M):
        x, y = map(int, input().split())
        # Move the contents from box x to box y
        B[x - 1].move_to(B[y - 1])

    # Count the number of red boxes after all moves
    counter = sum(1 for b in B if b.red)

    # Output the count of red boxes
    print(counter)


if __name__ == "__main__":
    main()

# <END-OF-CODE>
