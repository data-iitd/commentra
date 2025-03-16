# Import necessary modules
from typing import List

def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Read the value of k
    k = int(input())
    
    # Initialize a list to hold the input numbers
    arr = []
    
    # Read n long integers into the list
    for _ in range(n):
        arr.append(int(input()))
    
    # Sort the array to facilitate the processing of elements
    arr.sort()
    
    # Create a set to store unique elements that meet the criteria
    unique_elements = set()
    
    # Initialize a counter to keep track of valid elements
    count = 0
    
    # Iterate through the sorted array to apply the conditions
    for num in arr:
        # Check if the current element is not divisible by k
        if num % k != 0:
            count += 1  # Increment count for valid element
            unique_elements.add(num)  # Add the element to the set
        # Check if the current element is divisible by k and its corresponding k-factor is not in the set
        elif (num // k) not in unique_elements:
            count += 1  # Increment count for valid element
            unique_elements.add(num)  # Add the element to the set
    
    # Output the final count of valid elements
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
