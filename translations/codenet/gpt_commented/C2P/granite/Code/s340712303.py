
# Python code to solve the problem

# Read the number of elements for the first set
num1 = int(input())

# Initialize the first element of the math array to 1
math = [1] * (num1 + 1)

# Loop to read each element and update the possible sums
for i in range(num1):
    a = int(input())
    sum += a

    # Update the math array to reflect the new possible sums
    for j in range(sum - a, -1, -1):
        if math[j] == 1:
            math[j + a] = 1

# Read the number of queries for possible sums
num2 = int(input())

# Loop to check if each queried sum is possible
for i in range(num2):
    ans = int(input())
    # Check if the queried sum is possible and print the result
    print("yes" if math[ans] == 1 else "no")

