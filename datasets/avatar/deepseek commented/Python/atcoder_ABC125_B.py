
N = int(input())  # Taking an integer input N, which represents the number of elements.
V = input().split(" ")  # Taking the first line of space-separated integers and storing them in list V.
V = [int(i) for i in V]  # Converting each element in V to an integer.
C = input().split(" ")  # Taking the second line of space-separated integers and storing them in list C.
C = [int(i) for i in C]  # Converting each element in C to an integer.

# Initializing a list named list with a single element 0 and an integer ans set to 0.
list = [0]
ans = 0
X = 0
Y = 0

# Entering a for loop that iterates N times.
for i in range(N):
    # Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
    if V[i] - C[i] > 0:
        X = V[i]  # Assigning the i-th element of V to X.
        Y = C[i]  # Assigning the i-th element of C to Y.
        list.append(X - Y)  # Appending the difference X - Y to the list.

# Printing the sum of the list.
print(sum(list))

