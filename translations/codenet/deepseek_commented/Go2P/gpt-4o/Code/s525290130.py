import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to reverse a segment of the list in place
def reva(b):
    b.reverse()

# Main function
def main():
    n = next_int()  # Reads the number of elements
    a = list(map(int, sys.stdin.readline().strip().split()))  # Reads the elements into a list
    q = next_int()  # Reads the number of queries
    for _ in range(q):
        b = next_int()  # Reads the start index of the segment to reverse
        e = next_int()  # Reads the end index of the segment to reverse
        reva(a[b:e])  # Reverses the segment of the array
    print(" ".join(map(str, a)))  # Prints the final array

if __name__ == "__main__":
    main()

# <END-OF-CODE>
