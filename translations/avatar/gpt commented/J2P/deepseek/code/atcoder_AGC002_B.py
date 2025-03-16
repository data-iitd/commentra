class Box:
    def __init__(self, n, r):
        self.num = n
        self.red = r

    def move_to(self, other):
        if self.num == 0:
            return
        elif self.num == 1:
            self.num = 0
            other.num += 1
            if self.red:
                other.red = True
            self.red = False
        else:
            self.num -= 1
            other.num += 1
            if self.red:
                other.red = True


def main():
    # Read the number of boxes (N) and the number of moves (M)
    N, M = map(int, input().split())
    
    # Initialize a list of Box objects
    B = [Box(1, False) if i != 0 else Box(1, True) for i in range(N)]
    
    # Process M moves based on user input
    for _ in range(M):
        # Read the indices of the boxes to move from and to
        x, y = map(int, input().split())
        # Move the contents from box x to box y
        B[x - 1].move_to(B[y - 1])
    
    # Count the number of red boxes after all moves
    counter = sum(1 for b in B if b.red)
    
    # Output the count of red boxes
    print(counter)


if __name__ == "__main__":
    main()
