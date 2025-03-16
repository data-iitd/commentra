import sys
import bisect

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    # Read input: N and K
    N, K = read_int(), read_int()

    # Read input: N integers As
    As = read_ints(N)

    # Read input: N integers Fs
    Fs = read_ints(N)

    # Sort As in ascending order and Fs in descending order
    As.sort()
    Fs.sort(reverse=True)

    # Calculate the score for each element in As
    scores = [As[i] * Fs[i] for i in range(N)]

    # Sort scores in descending order
    scores.sort(reverse=True)

    # Binary search to find the answer
    ok = scores[0]
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2

        # Check if it's possible to distribute the flowers to K students with the given mid score
        is_ok = True
        k = K
        for i in range(N):
            if As[i] * Fs[i] > mid:
                # Subtract the difference between mid and the product of the current element from the remaining flowers
                k -= As[i] - mid // Fs[i]
            if k < 0:
                # If the remaining flowers are not enough to distribute to all students, it's not possible to distribute the flowers with the given mid score
                is_ok = False
                break

        if is_ok:
            # If it's possible to distribute the flowers with the given mid score, update ok with mid
            ok = mid
        else:
            # If it's not possible to distribute the flowers with the given mid score, update ng with mid
            ng = mid

    # Print the answer
    print(ok)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
