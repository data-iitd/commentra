N = 2000

# Initialize variables
num1 = int(input("Enter the number of integers to be input:\n"))
math = [0] * (N + 1)

# Initialize math array with first element as 1
math[0] = 1

# Read each integer and calculate its sum
sum_ = 0
for i in range(num1):
    a = int(input("Enter an integer:\n"))
    sum_ += a

    # Mark all the previous numbers as visited
    for j in range(sum_ - a, -1, -1):
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

# Return 0 to indicate successful execution
