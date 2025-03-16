def main():
    # Reading the number of elements in the array
    n = int(input())
    
    # Initializing an array of size n + 1 to store the input integers
    array = [0] * (n + 1)
    
    # Loop to read n integers from the user and store them in the array
    for i in range(1, n + 1):
        array[i] = int(input())  # Storing each integer in the array
    
    # Initializing counters for odd and even numbers and their latest indices
    odd, even = 0, 0
    odd_ind, even_ind = 0, 0
    
    # Loop to count odd and even numbers and track their latest indices
    for i in range(1, n + 1):
        if array[i] % 2 == 0:  # Checking if the number is even
            even += 1  # Incrementing the even counter
            even_ind = i  # Updating the index of the last even number
        else:  # The number is odd
            odd += 1  # Incrementing the odd counter
            odd_ind = i  # Updating the index of the last odd number
    
    # Comparing the counts of odd and even numbers to determine which index to print
    if odd > even:
        print(even_ind)  # Print the index of the last even number if there are more odds
    else:
        print(odd_ind)  # Print the index of the last odd number otherwise

# Calling the main function
if __name__ == "__main__":
    main()
