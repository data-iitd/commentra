# Importing necessary modules
from typing import List

def main():
    # Reading the number of elements to be processed
    n = int(input())
    
    # Initializing a list to store the input numbers
    numbers = list(map(int, input().split()))
    
    # Initializing a list to store odd numbers and a variable to hold the sum
    odd = []
    total_sum = 0
    
    # Iterating through the list to separate even and odd numbers
    for number in numbers:
        if number % 2 == 0:
            # If the number is even, add it to the sum
            total_sum += number
        else:
            # If the number is odd, add it to the odd list
            odd.append(number)
    
    # Sorting the list of odd numbers in ascending order
    odd.sort()
    
    # Adding all odd numbers to the sum
    total_sum += sum(odd)
    
    # If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if len(odd) % 2 != 0:
        total_sum -= odd[0]
    
    # Printing the final calculated sum
    print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
