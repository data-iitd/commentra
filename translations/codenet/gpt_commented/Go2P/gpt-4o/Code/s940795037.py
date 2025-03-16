import sys

# Main function where the execution starts
def main():
    # Read the number of integers to process
    n = int(sys.stdin.readline().strip())
    ans = 0.0

    # Loop through each integer, calculate the reciprocal, and accumulate the sum
    for _ in range(n):
        tmp = 1 / float(int(sys.stdin.readline().strip()))
        ans += tmp

    # Print the harmonic mean of the input integers
    print(1 / ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
