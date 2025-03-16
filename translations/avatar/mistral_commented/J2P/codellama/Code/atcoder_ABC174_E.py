
import sys

def solve ( n , k , logsLength ):
    # Initialize the minimum and maximum possible days
    min = 1
    max = 1000000000

    # Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
    while min < max:
        mid = (min + max) // 2
        if nei(mid, logsLength, k):
            max = mid
        else:
            min = mid + 1

    # Print the minimum day as the output
    print(min)

def nei ( mid , logsLength , k ):
    daysNeeded = 0

    # Iterate through all the logs and calculate the days needed to cut them
    for log in logsLength:
        daysNeeded += (log + mid - 1) // mid
        k -= daysNeeded
        if k < 0:
            return False

    # If all the logs have been cut, return true to indicate that the middle day is the answer
    return True

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())
    logsLength = list(map(int, sys.stdin.readline().strip().split()))
    solve(n, k, logsLength)

