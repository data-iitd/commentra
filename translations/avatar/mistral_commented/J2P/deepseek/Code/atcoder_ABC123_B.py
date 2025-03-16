import sys
from collections import TreeMap

def main():
    # Reading input from stdin
    a = list(map(int, sys.stdin.readline().split()))
    r = [0] * 5
    map = TreeMap()

    # Reading input elements of array 'a' and storing their remainders in array 'r'
    for i in range(len(a)):
        r[i] = a[i] % 10

        b = 10
        if r[i] != 0:
            b = 10 - r[i]
            map[b] = a[i]

    ans = 0

    # Checking if the TreeMap is empty
    if len(map) == 0:
        for i in range(len(a)):
            ans += a[i]
        print(ans)
        return

    last = map[map.keys()[-1]]
    idx = 0

    # Finding the index of the last element in array 'a'
    for i in range(len(a)):
        if a[i] == last:
            idx = i
            break

    # Calculating the sum of all elements in array 'a' except the last one
    for i in range(len(a)):
        if i != idx:
            if a[i] % 10 == 0:
                ans += a[i]
            else:
                ans += a[i] + (10 - r[i])

    # Adding the last element of array 'a' to the sum 'ans'
    ans += last

    print(ans)

if __name__ == "__main__":
    main()
