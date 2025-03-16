# Step 1: Import necessary modules
import sys

# Step 2: Define main function
def main():
    # Step 3: Read input
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    curr = 0
    for i in range(n):
        # Step 4: Process the array
        if a[i] == curr + 1:
            curr += 1

    # Step 5: Output the result
    if curr > 0:
        print(n - curr)
    else:
        print(-1)

# Step 6: Call main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
