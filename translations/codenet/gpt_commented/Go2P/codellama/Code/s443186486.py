
import sys

def main():
    # Read the number of elements
    n = int(sys.stdin.readline())

    # Initialize a list to hold the input integers
    a = list()
    # Read n integers from input
    for i in range(n):
        a.append(int(sys.stdin.readline()))

    # Initialize a list to hold the cumulative sums
    s = list()
    s.append(0)
    for i in range(n):
        s.append(s[i] + a[i]) # Calculate cumulative sum

    # Sort the cumulative sum list
    s.sort()

    # Initialize variables to count pairs of equal sums
    ans = 0
    count = 0
    # Iterate through the sorted cumulative sums to find duplicates
    for i in range(n):
        if s[i] == s[i+1]:
            count += 1 # Increment count if current and next sums are equal
        else:
            if count > 0:
                # If we found duplicates, calculate combinations and reset count
                ans += combi(count+1, 2)
                count = 0 # Reset count for the next unique sum

    # Handle the case where the last sums were duplicates
    if count > 0:
        ans += combi(count+1, 2)

    # Output the total number of pairs of equal sums
    print(ans)

# Function to calculate combinations C(n, r)
def combi(n, r):
    c = 1
    # Calculate the combination using the formula C(n, r) = n! / (r! * (n - r)!)
    for i in range(1, r+1):
        c = c * (n - i + 1) / i
    return c # Return the calculated combination


