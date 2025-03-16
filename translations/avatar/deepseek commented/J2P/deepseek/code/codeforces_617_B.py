def main():
    n = int(input())  # Step 5: Read the number of elements.
    arr = []  # Step 6: Create a list to store the indices of elements equal to 1.

    for i in range(n):  # Step 7: Read the elements and store their indices if they are equal to 1.
        if int(input()) == 1:
            arr.append(i)

    if not arr:  # Step 8: Check if the list is empty.
        print(0)  # If the list is empty, print 0.
    else:
        result = 1  # Initialize the result variable to 1.
        for i in range(1, len(arr)):  # Step 9: Calculate the product of differences between consecutive indices.
            result *= arr[i] - arr[i - 1]
        print(result)  # Print the result.


main()
