# Initialize an empty list to store results
results = []

# Infinite loop to continuously read input until a termination condition is met
while True:
    # Read two integers and an operator from the user
    user_input = input().strip()
    a, m, b = user_input.split()
    a = int(a)
    b = int(b)

    # Check if the operator is '?' to terminate the loop
    if m == '?':
        break  # Exit the loop if the termination operator is encountered

    # Perform addition if the operator is '+'
    if m == '+':
        results.append(a + b)  # Store the result of addition in the results list

    # Perform subtraction if the operator is '-'
    elif m == '-':
        results.append(a - b)  # Store the result of subtraction in the results list

    # Perform multiplication if the operator is '*'
    elif m == '*':
        results.append(a * b)  # Store the result of multiplication in the results list

    # Perform division if the operator is '/'
    elif m == '/':
        results.append(a // b)  # Store the result of division in the results list

# Print all results stored in the results list
for result in results:
    print(result)  # Output each result on a new line

# <END-OF-CODE>
