import sys
import bisect

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    # Read the number of elements N and the threshold K
    N = read_int()
    K = read_int()
    
    # Read the two slices of integers As and Fs
    As = read_ints(N)
    Fs = read_ints(N)

    # Sort the As slice in ascending order
    As.sort()
    # Sort the Fs slice in descending order
    Fs.sort(reverse=True)
    
    # Create a list to hold the scores calculated from As and Fs
    scores = [As[i] * Fs[i] for i in range(N)]
    
    # Sort the scores in descending order
    scores.sort(reverse=True)

    # Initialize binary search boundaries
    ok = scores[0]  # The maximum possible score
    ng = -1         # The minimum possible score

    # Perform binary search to find the maximum score that can be achieved
    while ok - ng > 1:
        mid = (ok + ng) // 2  # Calculate the midpoint of the current range

        is_ok = True  # Flag to check if the current mid is achievable
        k = K         # Remaining threshold to adjust scores
        for i in range(N):
            # If the current score exceeds mid, calculate how much we need to reduce
            if As[i] * Fs[i] > mid:
                k -= As[i] - mid // Fs[i]
            # If we exceed the allowed threshold, mark is_ok as false
            if k < 0:
                is_ok = False
                break

        # Adjust binary search boundaries based on whether mid is achievable
        if is_ok:
            ok = mid  # If achievable, move the upper boundary
        else:
            ng = mid  # If not achievable, move the lower boundary

    # Print the maximum achievable score
    print(ok)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
