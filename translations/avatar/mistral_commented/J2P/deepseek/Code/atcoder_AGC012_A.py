import sys

def main():
    # Reading the number of elements in the array from the standard input
    n = int(sys.stdin.readline().strip())
    # Creating an integer array of size 3 times the number of elements
    array = [int(x) for x in sys.stdin.readline().strip().split()]

    # Sorting the array in ascending order
    array.sort()

    head = len(array) - 2
    res = 0

    # Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for i in range(n):
        res += array[head]
        head -= 2

    # Printing the result
    print(res)

if __name__ == "__main__":
    main()

