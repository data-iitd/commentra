# Import the necessary module
import bisect

def main():
    # Initialize the variable 'n' to read the number of elements in the array 'a'
    n = int(input())

    # Create a list 'a' to store the input elements
    a = [int(input()) for _ in range(n)]

    # Initialize an empty list 'b' to store the unique elements
    b = []

    # Iterate through each element 'v' in list 'a'
    for v in a:
        # Use 'bisect.bisect_left' to find the index 'x' where 'v' should be inserted in list 'b'
        x = bisect.bisect_left(b, v)

        # If 'x' is equal to the length of list 'b', it means 'v' is not present in the list, so append it
        if x == len(b):
            b.append(v)
        else:
            # Otherwise, replace the element at index 'x' in list 'b' with 'v'
            b[x] = v

    # Print the length of list 'b' as the output
    print(len(b))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
