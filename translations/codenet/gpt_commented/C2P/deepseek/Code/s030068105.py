def main():
    # Read the number of elements from user input
    n = int(input())

    # Read 'n' integers from user input into a list
    data = list(map(int, input().split()))

    # Find the maximum value in the list and its index
    max_value = max(data)
    index = data.index(max_value)

    # Calculate the sum of all elements except the maximum
    a = sum(data) - max_value

    # Compare the sum of the other elements with the maximum value and print the result
    if a > max_value:
        print("Yes")
    else:
        print("No")

# Call the main function
if __name__ == "__main__":
    main()
