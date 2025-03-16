import sys

# next_int reads the next integer from the input.
def next_int():
    return int(sys.stdin.readline().strip())  # Read and convert the next line to an integer

# reva reverses a slice of integers in place.
def reva(b):
    b.reverse()  # Use the built-in reverse method to reverse the list in place

def main():
    n = next_int()  # Read the number of elements in the array
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the array of integers

    q = next_int()  # Read the number of queries
    for _ in range(q):
        b, e = map(int, sys.stdin.readline().strip().split())  # Read the starting and ending indices for the reversal
        reva(a[b:e])  # Reverse the slice from index b to e

    print(" ".join(map(str, a)))  # Print the modified array

if __name__ == "__main__":
    main()

# <END-OF-CODE>
