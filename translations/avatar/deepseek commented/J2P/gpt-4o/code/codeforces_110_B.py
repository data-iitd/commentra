n = int(input())  # Read the size of the array from the user
c = [''] * n  # Initialize the character array of size n

p = 97  # Starting ASCII value for 'a'
# Nested loops to assign characters to the array
for i in range(4):
    for j in range(i, n, 4):
        c[j] = chr(p)  # Assign character and increment ASCII value
    p += 1  # Increment the ASCII value for the next character

# Print the character array to the console
for i in range(n):
    print(c[i], end='')

# <END-OF-CODE>
