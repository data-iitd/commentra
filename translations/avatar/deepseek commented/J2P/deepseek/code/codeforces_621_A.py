def main():
    n = int(input())  # Read the number of elements
    numbers = list(map(int, input().split()))  # Read the elements and store them in a list
    
    even_sum = 0  # Initialize sum of even numbers
    odd_numbers = []  # List to store odd numbers
    
    for number in numbers:  # Iterate through the list
        if number % 2 == 0:
            even_sum += number  # Add to sum if the number is even
        else:
            odd_numbers.append(number)  # Add to odd list if the number is odd
    
    odd_numbers.sort()  # Sort the list of odd numbers
    
    for number in odd_numbers:
        even_sum += number  # Add all odd numbers to the sum
    
    if len(odd_numbers) % 2 != 0:
        even_sum -= odd_numbers[0]  # Subtract the smallest odd number if the count of odd numbers is odd
    
    print(even_sum)  # Print the final sum


main()
