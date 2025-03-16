
# Create a Scanner object to read input from the console
import java.util.Scanner ;

# Create a Scanner object to read input from the console
in = java.util.Scanner(System.in) ;

# Read four integers from the console
x = in.nextInt()
y = in.nextInt()
a = in.nextInt()
b = in.nextInt()

# Initialize a counter variable
count = 0

# Find the number of pairs (i, j) that satisfy the condition i < j
for i in range(a, x + 1):
    for j in range(b, y + 1):
        # If i is less than j, continue to the next iteration of the inner loop
        if i <= j: continue

        # Increment the counter if the condition is satisfied
        count += 1

# Print the result
print(count)

# Print all pairs (i, j) that satisfy the condition i < j
for i in range(a, x + 1):
    for j in range(b, y + 1):
        # If i is less than j, print the pair
        if i <= j:
            print(i, j)

# Close the Scanner object to free system resources
in.close()

