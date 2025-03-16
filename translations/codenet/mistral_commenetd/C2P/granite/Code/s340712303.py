

# Initialize variables
num1 = int(input("Enter the number of integers to be input: "))
sum = 0
math = [1] * (N + 1)

# Read each integer and calculate its sum
for i in range(num1):
    a = int(input("Enter an integer: "))
    sum += a

    # Mark all the previous numbers as visited
    for j in range(sum - a, -1, -1):
        if math[j] == 1:
            math[j + a] = 1

# Read the number of integers to be checked
num2 = int(input("Enter the number of integers to be checked: "))

# Check each integer and print the result
for i in range(num2):
    ans = int(input("Enter an integer to check: "))

    # Check if the current integer is marked as visited
    if math[ans] == 1:
        print("yes")
    else:
        print("no")

# Return 0 to indicate successful execution
return 0

