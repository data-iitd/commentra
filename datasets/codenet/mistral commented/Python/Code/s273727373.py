
N = int(input())  # Read an integer input from the user and assign it to the variable N
A = list(map(int, input().split()))  # Read a list of space-separated integers from the user and assign it to the variable A
B = list(A)  # Create a copy of the list A and assign it to the variable B
count = 1  # Initialize a counter variable count to 1

for i in A:  # Iterate through each element i in the list A
  B[i-1] = count  # Set the (i-1)th element of the list B to the current value of the counter count
  count += 1  # Increment the counter by 1

print(*B)  # Print the list B using the * operator to unpack it and the print function.