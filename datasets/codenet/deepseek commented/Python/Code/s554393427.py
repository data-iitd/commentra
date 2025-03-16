
N=int(input())  # Read the number of elements
mo=[]  # Initialize an empty list to store the elements

# Read N elements, each consisting of a float x and a string u
for _ in range(N):
    x, u = input().split()
    x = float(x)  # Convert x to a float
    mo.append([x, u])  # Append the float and string to the list

okz = 0  # Initialize a variable to store the result

# Iterate through the list of elements
for i in mo:
    if i[1] == "JPY":  # Check if the unit is JPY
        okz += i[0]  # Add the value of x to okz
    else:  # If the unit is not JPY
        okz += i[0] * 380000  # Multiply x by 380000 and add it to okz

print(okz)  # Print the final result

