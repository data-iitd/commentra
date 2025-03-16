# Importing necessary classes from the built-in modules
import sys

def main():
    # Reading the number of elements to be processed from the standard input
    n = int(sys.stdin.readline().strip())
    
    # Reading n long integers from input and storing them in a list
    numbers = list(map(int, sys.stdin.readline().strip().split()))
    
    # Initializing a list to store odd numbers and a variable to hold the sum
    odd = []
    total_sum = 0
    
    # Iterating through the list to separate even and odd numbers
    for num in numbers:
        if num % 2 == 0:
            # If the number is even, add it to the sum
            total_sum += num
        else:
            # If the number is odd, add it to the odd list
            odd.append(num)
    
    # Sorting the list of odd numbers in ascending order
    odd.sort()
    
    # Adding all odd numbers to the sum
    for num in odd:
        total_sum += num
    
    # If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if len(odd) % 2 != 0:
        total_sum -= odd[0]
    
    # Printing the final calculated sum
    print(total_sum)

if __name__ == "__main__":
    main()
