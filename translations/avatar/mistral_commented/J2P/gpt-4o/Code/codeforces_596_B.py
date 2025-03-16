# Import the necessary module for reading input
import sys

def main():
    # Read the first integer `n` from the standard input stream
    n = int(sys.stdin.readline().strip())

    # Create a new list `arr` of size `n`
    arr = [0] * n

    # Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the list `arr`
    for i in range(n):
        arr[i] = int(sys.stdin.readline().strip())

    # Initialize the variable `answer` with the absolute value of the first element of the list `arr`
    answer = abs(arr[0])

    # Use a for loop to iterate over the remaining elements of the list `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
    for i in range(1, n):
        answer += abs(arr[i] - arr[i - 1])

    # Print the value of the variable `answer` to the standard output stream
    print(answer)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
