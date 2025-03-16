a = int(input())  # Take an integer input from the user and store it in variable a

# Calculate and output the hours, minutes, and seconds
print(f"{a // (60 * 60)}:{(a % (60 * 60)) // 60}:{(a % (60 * 60)) % 60}")

# Return 0 to indicate successful execution (not needed in Python)
# <END-OF-CODE>
