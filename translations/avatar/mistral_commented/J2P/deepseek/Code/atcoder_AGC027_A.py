import sys

def main():
    # Reading the number of elements in the list and the target value from the standard input
    N = int(sys.stdin.readline().strip())
    x = int(sys.stdin.readline().strip())

    # Reading the elements of the list from the standard input
    sweet = list(map(int, sys.stdin.readline().strip().split()))

    # Sorting the list in ascending order
    sweet.sort()

    # Initializing a variable to keep track of the number of elements that can be subtracted from x
    num = 0

    # Finding the number of elements that can be subtracted from x
    for i in range(N):
        if x - sweet[num] >= 0:
            x -= sweet[num]
            num += 1
        else:
            break

    # Adjusting the num variable if all the elements in the list have been subtracted from x and x is still greater than 0
    if num == N and x > 0:
        num -= 1

    # Printing the number of elements that can be subtracted from x
    print(num)

if __name__ == "__main__":
    main()

