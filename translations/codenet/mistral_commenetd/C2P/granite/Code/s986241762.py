

# Python code
n = int(input("Enter the number of elements in the array: "))
a = [int(input("Enter element number {}: ".format(i+1))) for i in range(n)]
sum = 0
for i in range(1, n):
    if a[i-1] > a[i]:
        sum += a[i-1] - a[i]
        a[i] = a[i-1]
print("The sum of the differences is:", sum)

