
import sys

def out(x):
    print(x)

def getInt():
    return int(sys.stdin.readline())

def getString():
    return sys.stdin.readline().strip()

def max(a, b):
    if a > b:
        return a
    return b

def min(a, b):
    if a < b:
        return a
    return b

def asub(a, b):
    if a > b:
        return a - b
    return b - a

def abs(a):
    if a >= 0:
        return a
    return -a

def main():
    # Read input values
    N = getInt() # Number of passengers
    C = getInt() # Bus capacity
    K = getInt() # Time window

    # Array to store arrival times
    t = [0] * N
    for i in range(N):
        t[i] = getInt()

    # Sort the arrival times
    t.sort()

    # Initialize variables for the number of buses and passengers in the current bus
    ans = 1
    cnt = 1
    end = t[0] + K # Time when the bus will be full or the time window expires

    # Iterate through the sorted arrival times
    for i in range(1, N):
        if cnt < C and t[i] <= end:
            # The current passenger can fit in the bus
            cnt += 1
        else:
            # The current bus is full or the time window has expired
            # Increment the bus count, reset the count, and update the end time
            cnt = 1
            end = t[i] + K
            ans += 1

    # Output the number of buses required
    out(ans)

