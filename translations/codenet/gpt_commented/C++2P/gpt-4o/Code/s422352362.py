# Import necessary libraries
import sys

# Declare arrays to store input values, prefix sums, and suffix sums
a = [0] * 200005
pre = [0] * 200005
last = [0] * 200005

def main():
    n = int(sys.stdin.readline().strip())
    
    # Read the input values into the array 'a'
    for i in range(1, n + 1):
        a[i] = int(sys.stdin.readline().strip())

    sumpre = 0
    sumlast = 0

    # Calculate prefix sums and store them in 'pre' array
    for i in range(1, n):
        sumpre += a[i]
        pre[i] = sumpre
        # Debugging output for prefix sums (commented out)
        # print(f"{pre[i]}++")

    # Calculate suffix sums and store them in 'last' array
    for i in range(n, 1, -1):
        sumlast += a[i]
        last[i] = sumlast
        # Debugging output for suffix sums (commented out)
        # print(f"{last[i]}+++")

    # Initialize 'd' to a large value to find the minimum difference
    d = (1 << 60)

    # Calculate the minimum absolute difference between prefix and suffix sums
    for i in range(1, n):
        # Debugging output for the difference calculation (commented out)
        # print(pre[i] - last[i + 1])
        d = min(d, abs(pre[i] - last[i + 1]))

    # Output the minimum difference found
    print(d)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
