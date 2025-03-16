import sys

def out(*args):
    print(*args)

def get_int():
    return int(sys.stdin.readline().strip())

def main():
    # Read input values
    N = get_int()  # Number of passengers
    C = get_int()  # Bus capacity
    K = get_int()  # Time window

    # Array to store arrival times
    t = [get_int() for _ in range(N)]

    # Sort the arrival times
    t.sort()

    # Initialize variables for the number of buses and passengers in the current bus
    ans = 1
    cnt = 1
    end = t[0] + K  # Time when the bus will be full or the time window expires

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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
