def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    numbers = list(map(int, data[1:n+1]))  # Read the elements and store them in the list
    
    odd = []  # List to store odd numbers
    total_sum = 0  # Initialize sum of numbers
    
    for number in numbers:  # Iterate through the list
        if number % 2 == 0:
            total_sum += number  # Add to sum if the number is even
        else:
            odd.append(number)  # Add to odd list if the number is odd
    
    odd.sort()  # Sort the list of odd numbers
    
    for number in odd:
        total_sum += number  # Add all odd numbers to the sum
    
    if len(odd) % 2 != 0:
        total_sum -= odd[0]  # Subtract the smallest odd number if the count of odd numbers is odd
    
    print(total_sum)  # Print the final sum

if __name__ == "__main__":
    main()

# <END-OF-CODE>
