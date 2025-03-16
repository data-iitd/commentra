MAX = 21

def init(i):
    global x, y, fld
    x = y = 10  # Set the initial position of the player
    fld = [[0] * MAX for _ in range(MAX)]  # Initialize the field with zeros
    for _ in range(i):  # Read and store the obstacles' positions
        a, b = map(int, input().split())
        fld[b][a] = 1

def move(i):
    global n, x, y
    for _ in range(i):  # Iterate through all moves
        buf, a = input().split()
        a = int(a)
        d = {'N': 0, 'E': 1, 'S': 2, 'W': 3}[buf[0]]  # Determine the direction based on the first character
        for _ in range(a):  # Move the player in the given direction
            if d % 2:  # If the direction is odd, move horizontally
                if d == 1:  # East
                    x += 1
                else:  # West
                    x -= 1
            else:  # If the direction is even, move vertically
                if d == 0:  # North
                    y += 1
                else:  # South
                    y -= 1
            if fld[y][x]:  # If there's an obstacle at the current position, remove it and decrease the number of available moves
                fld[y][x] = 0
                n -= 1

if __name__ == "__main__":
    while True:  # Infinite loop until user inputs a non-positive number for n
        n = int(input())
        if n >= 0:  # If n is non-negative, initialize the game and read m
            init(n)
            m = int(input())
            move(m)
            print("No" if n else "Yes")  # Print whether it's possible to make all moves
        else:
            break  # If n is non-positive, break the loop

# <END-OF-CODE>
