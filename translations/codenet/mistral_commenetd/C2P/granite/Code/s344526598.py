
# Initialize array x with zeros
x = [0] * 10000

# Read the first integer input and store it in the array x at index i
x[0] = int(input())

# Read remaining integers and store them in the array x
i = 0
while x[i]!= 0:
    i += 1
    x[i] = int(input())

# Print the results
for j in range(i):
    print(f"Case {j+1}: {x[j]}")

# Signal successful termination of the program
print("