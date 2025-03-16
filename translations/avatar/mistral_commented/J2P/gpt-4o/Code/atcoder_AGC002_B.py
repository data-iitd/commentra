class Box:  # Defining the Box class
    def __init__(self, n, r):  # Constructor for initializing the Box object
        self.num = n  # Initializing the number property
        self.red = r  # Initializing the red property

    # Method for moving the box to another box
    def move_to(self, other):
        if self.num == 0:  # If the current box is empty
            return  # Do nothing
        elif self.num == 1:  # If the current box has only one item
            self.num = 0  # Setting the current box to be empty
            other.num += 1  # Incrementing the number of items in the other box
            if self.red:  # If the current box was red
                other.red = True  # Setting the other box to be red
            self.red = False  # Setting the current box to be empty and not red
        else:  # If the current box has more than one item
            self.num -= 1  # Decrementing the number of items in the current box
            other.num += 1  # Incrementing the number of items in the other box
            if self.red:  # If the current box was red
                other.red = True  # Setting the other box to be red


def main():
    import sys
    input = sys.stdin.read
    data = input().split()  # Reading all input at once
    N = int(data[0])  # Reading the first integer input (number of boxes)
    M = int(data[1])  # Reading the second integer input (number of moves)
    
    B = [None] * N  # Creating an array of Box objects with size N

    # Initializing the first box with red color
    B[0] = Box(1, True)

    # Initializing the remaining boxes with red color set to false
    for i in range(1, N):
        B[i] = Box(1, False)

    # Reading the moves from the input and performing them on the boxes
    index = 2  # Starting index for moves in the data list
    for _ in range(M):
        x = int(data[index]) - 1  # Reading the x-coordinate of the source box
        y = int(data[index + 1]) - 1  # Reading the y-coordinate of the destination box
        B[x].move_to(B[y])  # Moving the box at index x to the box at index y
        index += 2  # Move to the next pair of moves

    # Counting the number of red boxes
    counter = sum(1 for b in B if b.red)  # Counting red boxes using a generator expression

    # Printing the result
    print(counter)


if __name__ == "__main__":
    main()

# <END-OF-CODE>
