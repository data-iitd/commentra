import sys

# Reads a single integer from standard input.
def scan_int():
    return int(sys.stdin.readline().strip())

def main():
    # Reads the number of arms.
    n = scan_int()
    
    # Defines a list to represent arms with left and right endpoints.
    arms = []
    
    # Reads each arm's range and stores the left and right endpoints.
    for _ in range(n):
        x, l = map(int, sys.stdin.readline().strip().split())
        arms.append((x - l, x + l))
    
    # Sorts the arms based on their right endpoints.
    arms.sort(key=lambda arm: arm[1])
    
    # Initializes the answer and the right endpoint reference.
    ans = 1
    r = arms[0][1]
    
    # Iterates through the sorted arms to count non-overlapping arms.
    for i in range(1, n):
        if arms[i][0] >= r:
            ans += 1
            r = arms[i][1]
    
    # Prints the count of non-overlapping arms.
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
