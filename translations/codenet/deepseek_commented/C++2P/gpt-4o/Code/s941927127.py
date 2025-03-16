# Step 1: Import necessary modules
# The code starts by importing the necessary modules for input/output operations.
W = input()

# Step 2: Read input
# The program reads a string `W` from the standard input.

# Step 3: Sort the string
# The string `W` is sorted in ascending order.
W = ''.join(sorted(W))

# Step 4: Check for character pairs
# The program iterates through the sorted string, checking if each character
# is followed by its identical pair.
for i in range(0, len(W), 2):
    if i + 1 >= len(W) or W[i] != W[i + 1]:
        # If a character is not followed by its pair, output "No" and exit.
        print("No")
        break
else:
    # Step 5: Output result
    # If all characters are in pairs, the program outputs "Yes".
    print("Yes")

# <END-OF-CODE>
