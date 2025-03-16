def min(a, b):
    # If 'a' is less than or equal to 'b', return 'a'. Otherwise, return 'b'.
    return a if a <= b else b

def Chain(b, n):
    a = b[:]  # Create a copy of the input array 'b' to modify it in the function

    # Check for chains of 4 identical elements in the array 'a'
    for i in range(n - 3):
        # If the current element is not zero and it is identical to the next three elements
        if a[i] != 0 and a[i] == a[i + 1] == a[i + 2] == a[i + 3]:
            count = 0
            color = a[i]

            # Find the length of the chain and replace the identified elements with zeros
            for j in range(i, n):
                if a[j] == color:
                    a[j] = 0
                    count += 1
                else:
                    break

            # Swap the elements to maintain the order of the array
            for j in range(n - count):
                if i + j + count < n:
                    a[i + j], a[i + j + count] = a[i + j + count], a[i + j]

    # Count the number of unprocessed non-zero elements in the array 'a'
    count = 0
    while count < n and a[count] != 0:
        count += 1

    # If the count is 4 and all elements in the chain are identical, return 0
    if count == 4 and a[0] == a[1] == a[2] == a[3]:
        return 0

    # Return the length of the longest chain found
    return count

def main():
    while True:
        a = [0] * 10000  # Initialize the array 'a' with zeros

        # Read the number of elements in the current test case
        n = int(input())
        if n == 0:
            break
        ans = n

        # Read the elements of the current test case
        a = list(map(int, input().split()))

        # Find the longest chain in the current test case
        for i in range(n - 3):
            count = [0, 0, 0]
            for j in range(i, i + 4):
                # Update the count array for the current element
                if a[j] - 1 >= 0:
                    count[a[j] - 1] += 1

            # Find the color of the chain
            color = 0
            for j in range(3):
                # If the count of the current color is greater than or equal to 3, set the color
                if count[j] >= 3:
                    color = j + 1
                    break

            # If a chain of length 4 is found, update the answer
            if color != 0:
                for j in range(i, i + 4):
                    buf = a[j]
                    a[j] = color
                    ans = min(ans, Chain(a, n))
                    a[j] = buf

        # Print the answer for the current test case
        print(ans)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
