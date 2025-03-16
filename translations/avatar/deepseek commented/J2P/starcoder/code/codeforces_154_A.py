
import sys

def main():
    # Reading input from standard input
    arr = sys.stdin.readline().strip()
    N = len(arr)
    # Initialize a HashSet to store unique strings and read the number of test cases
    set = set()
    K = int(sys.stdin.readline())
    # Initialize the result variable to store the final count
    res = 0
    # Loop to process each test case
    for k in range(K):
        input = sys.stdin.readline().strip()
        a = 0
        b = 0
        # Iterate over the characters of the input array
        for i in range(N):
            if arr[i] == input[0]:
                a += 1
            elif arr[i] == input[1]:
                b += 1
            else:
                res += min(a, b)
                a = b = 0
        res += min(a, b)
    # Print the final result
    print(res)

if __name__ == "__main__":
    main()

