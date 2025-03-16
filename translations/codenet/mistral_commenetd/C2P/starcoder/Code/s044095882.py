
# <START-OF-CODE>

n = int(input("Enter the number of elements: "))

a = [int(input("Enter a number: ")) for i in range(n)]

count = [0 for i in range(n)]

print("Initializing count array with zeros:")
for i in range(n):
    count[i] = 0

print("Counting occurrences:")
for i in range(n):
    count[a[i]-1] += 1

print("Printing the contents of the count array:")
for i in range(n):
    print(count[i])

print("Program completed successfully.")

# 