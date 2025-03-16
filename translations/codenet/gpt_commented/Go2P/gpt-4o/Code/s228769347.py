import sys
import bisect

def main():
    # Read input from standard input or from a file if provided
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            n = int(f.readline().strip())
            ll = list(map(int, f.readline().strip().split()))
    else:
        n = int(input().strip())
        ll = list(map(int, input().strip().split()))

    ll.sort()  # Sort the list of integers

    ans = 0  # Initialize the answer counter
    # Iterate through pairs of integers to find valid triplets
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            # Use binary search to find the count of valid third elements
            l = j + 1
            r = n
            while l < r:
                m = (l + r) // 2  # Calculate the middle index
                if ll[m] < ll[i] + ll[j]:  # Check if the sum of the first two is greater than the middle element
                    l = m + 1  # Move the left boundary up
                else:
                    r = m  # Move the right boundary down
            # Count the number of valid third elements
            ans += l - (j + 1)  # Update the answer with the count of valid triplets

    print(ans)  # Print the result to the output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
