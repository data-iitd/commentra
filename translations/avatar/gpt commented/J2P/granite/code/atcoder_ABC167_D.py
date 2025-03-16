
import sys

# Constants for modulo and limits
MOD = 1000000007
MAX = sys.maxsize
LMAX = sys.maxsize

# Length for the array
len = 1000001

def doIt():
    # Read the number of elements N and the long value K
    N = int(input())
    K = int(input())

    # Initialize the array A to store the input values
    A = [int(input()) for _ in range(N)]

    # Set to track used indices and arrays to store index and position
    used = set()
    idx = [0] * N
    pos = [0] * N

    # Initialize variables for the cycle detection
    next = 0
    cur = 0

    # Detect the cycle in the array using the 'used' set
    while next not in used:
        used.add(next)
        idx[next] = cur
        pos[cur] = next
        next = A[next] - 1
        cur += 1

    # Calculate the lengths of the cycle and the position of the next element
    a = cur - idx[next]
    b = idx[next]

    # Calculate the answer based on the cycle length and K
    ans = (10000 * a + K - b) % a + b

    # If b is greater than K, set ans to K
    if b > K:
        ans = K

    # Output the result, adjusting for 1-based indexing
    print(pos[ans] + 1)

# Call the doIt function
doIt()

