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
    n = int(input())  # Read the number of boxes
    m = int(input())  # Read the number of moves
    boxes = [Box(1, True)] + [Box(1, False) for _ in range(n - 1)]
    for _ in range(m):
        x, y = map(lambda i: int(i) - 1, input().split())  # Read the source and destination box indices
        boxes[x].move_to(boxes[y])  # Move the box from source to destination
    counter = sum(box.red for box in boxes)  # Count the number of red boxes
    print(counter)  # Print the count of red boxes


main()
