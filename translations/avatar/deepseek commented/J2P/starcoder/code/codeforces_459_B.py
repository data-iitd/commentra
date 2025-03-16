import sys

def main():
    # Read the size of the array
    N = int(input())

    # Read the elements of the array
    A = [int(x) for x in input().split()]

    # Sort the array
    A.sort()

    # Find the minimum and maximum values in the array
    min = A[0]
    max = A[N-1]

    # Count the occurrences of the minimum and maximum values
    mins = 0
    maxs = 0
    for value in A:
        if value == min:
            mins += 1
        if value == max:
            maxs += 1

    # Special case: if min == max
    if min == max:
        print((max - min) + " " + mins * (mins - 1) / 2)
    # General case: if min!= max
    else:
        print((max - min) + " " + mins * maxs)

if __name__ == "__main__":
    main()

# 