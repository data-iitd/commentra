import fractions  # Import the fractions module for calculating the greatest common divisor (GCD)
import math  # Import the math module (not used in the code but can be useful for mathematical operations)

# Read two integers from input: n (an upper limit) and num (a number to be processed)
n, num = map(int, input().split())

# Read a set of integers from input and convert them to a set to ensure uniqueness
num_set = set(map(lambda x: int(x), input().split()))

# Initialize an empty set to store values related to the two times condition
two_times_set = set()

# Iterate through each number in the unique set
for i in num_set:
    # Check how many times the number can be divided by 2
    for j in range(1, 30):
        i //= 2  # Divide the number by 2
        if i % 2 != 0:  # Check if the result is odd
            two_times_set.add(j)  # Add the count of divisions to the set
            break  # Exit the inner loop if an odd number is found

    # If more than one unique count of divisions by 2 is found, print 0 and exit
    if len(two_times_set) != 1:
        print(0)
        break
else:
    # If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
    num_list = list(num_set)  # Convert the set back to a list for processing
    lcm = num_list[0]  # Initialize LCM with the first element of the list

    # Calculate the LCM of all numbers in the list
    for i in range(1, len(num_list)):
        lcm = lcm * num_list[i] // fractions.gcd(lcm, num_list[i])  # Update LCM using the GCD

    # Calculate and print the final result based on the LCM and the input number
    print((num - lcm // 2) // (lcm) + 1)
