def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize a list to hold the input integers
    a = list(map(int, input().split()))
    
    # Variable to hold the cumulative XOR of all elements
    r = 0
    
    # Compute the cumulative XOR of all elements
    for num in a:
        r ^= num
    
    # For each element in the array, print the result of XORing the cumulative XOR with the element
    for i, num in enumerate(a):
        if i != 0:
            print(" ", end="")  # Print a space before the next number if it's not the first element
        print(r ^ num, end="")  # Print the result of XORing the cumulative XOR with the current element

if __name__ == "__main__":
    main()
