# Declare variables A and B to hold input values, and flag to indicate if a condition is met
A, B = map(int, input().split())
flag = 0

# Loop through the values 1 to 3
for i in range(1, 4):
    # Check if the product of A, B, and i is odd
    if (A * B * i) % 2 == 1:
        # Set flag to 1 if the condition is met and exit the loop
        flag = 1
        break

# Print "Yes" if flag is set, indicating at least one odd product was found; otherwise print "No"
if flag:
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
