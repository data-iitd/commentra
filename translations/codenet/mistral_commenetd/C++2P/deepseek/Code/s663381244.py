import sys

# Initialize cin and ios streams to disable buffering and synchronization
input = sys.stdin.readline

# Initialize an empty list 'm' to store the multipliers
m = [10, 50, 100, 500]

# Main loop to read the input money and calculate the change
while True:
    # Read the input money
    money = int(input())
    
    # Break the loop if the input money is 0
    if money == 0:
        break
    
    # Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
    num = list(map(int, input().split()))
    sum_products = sum(n * m[i] for i, n in enumerate(num))
    
    # Calculate the change
    change = sum_products - money
    
    # Adjust the numbers to get the exact change
    for i in range(3, -1, -1):
        # If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
        if change // m[i]:
            num[i] -= change // m[i]
            change %= m[i]
    
    # Print the numbers that still have a positive value
    for i in range(4):
        if num[i] > 0:
            print(m[i], num[i])
    print()  # Print a newline character to separate the outputs

# <END-OF-CODE>