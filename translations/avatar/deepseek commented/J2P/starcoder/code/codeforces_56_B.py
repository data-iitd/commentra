
import sys

def main():
    # Read the length of the array
    len = int(sys.stdin.readline())
    # Initialize the array with the length read
    a = [0] * len
    for i in range(len):
        # Read the elements of the array
        a[i] = int(sys.stdin.readline())
    l = 0
    r = 0
    flag = False
    isTrue = False
    # Loop through the array
    for i in range(len):
        if a[i]!= i + 1 and not flag:
            l = i + 1
            flag = True
            continue
        if a[i]!= i + 1 and flag:
            r = i + 1
            if (a[r - 1] - a[r - 2] > 0):
                isTrue = True
                break
    # Print the indices or "0 0" if no such segment exists
    print((not isTrue) and (l, r) or (0, 0))

if __name__ == "__main__":
    main()

