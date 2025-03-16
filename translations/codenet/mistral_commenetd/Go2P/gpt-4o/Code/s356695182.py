import sys

# Function to read an integer from standard input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read multiple integers from standard input
def scan_nums(length):
    return list(map(int, sys.stdin.readline().strip().split()))[:length]

# Function to calculate the first pattern
def pattern1(l):
    n = (l[0] * l[3]) + (l[1] * l[4])
    return n

# Function to calculate the second pattern
def pattern2(l):
    max_num = max(l[3], l[4])
    n = 2 * l[2] * max_num
    return n

# Function to calculate the third pattern
def pattern3(l):
    min_num = min(l[3], l[4])
    n = 2 * l[2] * min_num + doch(l)
    return n

# Helper function to calculate the difference between the larger and smaller of two numbers
def doch(l):
    if l[3] > l[4]:
        return l[0] * (l[3] - l[4])
    else:
        return l[1] * (l[4] - l[3])

# Main function to read input and call the pattern functions
def main():
    length = 5
    l = scan_nums(length)
    print(min(pattern1(l), pattern2(l), pattern3(l)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
