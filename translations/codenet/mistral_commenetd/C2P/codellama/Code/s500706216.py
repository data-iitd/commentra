#include <stdbool.h>
#include <stdio.h>
import sys

# Main function
def main():
    # Read input n and k
    n, k = map(int, sys.stdin.readline().split())

    # Read input array a
    a = list(map(int, sys.stdin.readline().split()))

    # Initialize light array based on initial a array
    light = [0] * (n + 1)
    for i in range(n):
        r = i - a[i]
        l = i + a[i]
        light[(r if r >= 0 else 0)] += 1
        light[(l + 1 if l + 1 <= n else n + 1)] -= 1

    # Perform k iterations
    for i in range(k):
        # Initialize temporary array tmpa
        sum = 0
        tmpa = [0] * n
        for j in range(n):
            tmpa[j] = a[j]
            sum += light[j]
            a[j] = sum

        # Update light array based on new a array
        for j in range(n):
            r = j - a[j]
            l = j + a[j]
            light[(r if r >= 0 else 0)] -= 1
            light[(l + 1 if l + 1 <= n else n + 1)] += 1
            r = j - a[j]
            l = j + a[j]
            light[(r if r >= 0 else 0)] += 1
            light[(l + 1 if l + 1 <= n else n + 1)] -= 1

        # Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
        isSame = True
        for j in range(n - 1):
            if a[j] != a[j + 1]:
                isSame = False
                break
        if isSame and a[0] == n:
            break

    # Print out updated a array
    for j in range(n):
        print(a[j], end=" " if j != n - 1 else "\n")

if __name__ == "__main__":
    main()
