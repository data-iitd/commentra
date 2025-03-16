def main():
    # Read the first integer `n` from the standard input stream and assign it to the variable `n`
    n = int(input())

    # Read `n` integers from the standard input stream and assign them to the list `arr`
    arr = list(map(int, input().split()))

    # Initialize the variable `answer` with the absolute value of the first element of the list `arr`
    answer = abs(arr[0])

    # Use a for loop to iterate over the remaining elements of the list `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
    for i in range(1, n):
        answer += abs(arr[i] - arr[i - 1])

    # Print the value of the variable `answer` to the standard output stream
    print(answer)

# Call the main function to execute the program
main()
