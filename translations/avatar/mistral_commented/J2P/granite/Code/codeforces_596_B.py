
import sys

def main():
    # Create a new Scanner object to read input from the standard input stream
    scan = sys.stdin

    # Read the first integer `n` from the standard input stream and assign it to the variable `n`
    n = int(scan.readline())

    # Create a new list `arr` of size `n`
    arr = []

    # Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the list `arr`
    for i in range(n):
        arr.append(int(scan.readline()))

    # Initialize the variable `answer` with the absolute value of the first element of the list `arr`
    answer = abs(arr[0])

    # Use a for loop to iterate over the remaining elements of the list `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
    for i in range(1, n):
        answer += abs(arr[i] - arr[i - 1])

    # Print the value of the variable `answer` to the standard output stream
    print(answer)

if __name__ == "__main__":
    main()

