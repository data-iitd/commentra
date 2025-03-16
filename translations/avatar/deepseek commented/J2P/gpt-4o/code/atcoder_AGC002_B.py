class Box:
    def __init__(self, n, r):
        self.num = n
        self.red = r

    def move_to(self, other):
        if self.num == 0:
            return  # Do nothing if the box is already empty
        elif self.num == 1:
            self.num = 0  # Set the current box to empty
            other.num += 1  # Increment the destination box's number
            if self.red:
                other.red = True  # If the current box was red, make the destination box red
            self.red = False  # The current box is no longer red
        else:
            self.num -= 1  # Decrement the current box's number
            other.num += 1  # Increment the destination box's number
            if self.red:
                other.red = True  # If the current box was red, make the destination box red


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the number of boxes
    M = int(data[1])  # Read the number of moves
    B = [None] * N
    B[0] = Box(1, True)  # Initialize the first box with num=1 and red=True
    for i in range(1, N):
        B[i] = Box(1, False)  # Initialize the rest of the boxes with num=1 and red=False

    index = 2
    for _ in range(M):
        x = int(data[index]) - 1  # Read the source box index (0-based)
        y = int(data[index + 1]) - 1  # Read the destination box index (0-based)
        B[x].move_to(B[y])  # Move the box from source to destination
        index += 2

    counter = sum(1 for b in B if b.red)  # Count the number of red boxes
    print(counter)  # Print the count of red boxes


if __name__ == "__main__":
    main()

# <END-OF-CODE>
