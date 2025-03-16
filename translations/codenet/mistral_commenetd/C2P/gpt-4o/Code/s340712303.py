# Initialize variables
N = 2000
num1 = 0
math = [0] * (N + 1)

# Initialize the first element of math array as 1
math[0] = 1

# Read the number of integers to be input
num1 = int(input("Enter the number of integers to be input:\n"))

# Read each integer and calculate its sum
sum = 0
for i in range(num1):
    a = int(input("Enter an integer:\n"))

    # Add the current integer to the sum
    sum += a

    # Mark all the previous numbers as visited
    for j in range(sum - a, -1, -1):
        if math[j] == 1:
            math[j + a] = 1

# Read the number of integers to be checked
num2 = int(input("Enter the number of integers to be checked:\n"))

# Check each integer and print the result
for i in range(num2):
    ans = int(input("Enter an integer to check:\n"))

    # Check if the current integer is marked as visited
    if math[ans] == 1:
        print("yes")
    else:
        print("no")

# End of code
# <END-OF-CODE>
