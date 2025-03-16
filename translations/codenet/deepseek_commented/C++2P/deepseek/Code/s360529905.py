def main():
    N = int(input())  # Read the number of elements from the user
    a = list(map(int, input().split()))  # Read elements into array a
    b = a.copy()  # Copy the elements from array a to array b

    b.sort()  # Sort array b

    frontHalf = b[N // 2 - 1]  # Calculate the first half's middle value
    backHalf = b[N // 2]  # Calculate the second half's middle value

    for element in a:  # Loop to compare each element of array a
        if element < backHalf:  # Check if the element is less than the second middle value
            print(backHalf)  # Print the second middle value
        else:
            print(frontHalf)  # Print the first middle value

if __name__ == "__main__":
    main()
