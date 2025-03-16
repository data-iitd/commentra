import sys
input = sys.stdin.readline

mod = 1000000007

# 1MB
ioBufferSize = 1 * 1024 * 1024

def next():
    return input().strip()

def nextInt():
    return int(next())

def main():
    # Read the initial height `h` and the number of attacks `n`
    h = nextInt()
    n = nextInt()

    # Initialize a variable to keep track of the total damage dealt
    a = 0

    # Read each attack's damage and accumulate the total damage
    for i in range(n):
        a += nextInt()

    # Check if the total damage is greater than or equal to the initial height
    if h > a:
        print("No")
    else:
        print("Yes")

main()

