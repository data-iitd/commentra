
n = int(input())  # Read the number of elements in the list
l = input().split()  # Read the space-separated string and split it into a list of strings
max = -1e9;min = 1e9;sum = 0  # Initialize max, min, and sum variables
for i in range(n):  # Start a loop to iterate over the elements in the list
    sum+=int(l[i])  # Convert each element to an integer and add it to sum
    if max<int(l[i]):  # Check if the current element is greater than max
        max = int(l[i])  # Update max if the current element is greater
    if min>int(l[i]):  # Check if the current element is less than min
        min = int(l[i])  # Update min if the current element is less
print(min,max,sum)  # Print the minimum, maximum, and sum of the elements in the list



