import sys

def main():
    # Read the number of elements
    n = int(input())
    
    # Initialize a list to store the input integers
    lst = []
    
    # Read n integers from input and add them to the list
    for _ in range(n):
        lst.append(int(input()))
    
    # Sort the list of integers in ascending order
    lst.sort()
    
    # Initialize a counter to track the maximum consecutive integer
    c = 1
    
    # Iterate through the sorted list to find the maximum consecutive integer
    for num in lst:
        # If the current integer is greater than or equal to the counter, increment the counter
        if num >= c:
            c += 1
    
    # Print the result which is the maximum consecutive integer found
    print(c)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
