# Declare a string variable 's' and read its value from the standard input using input().
s = input()

# Start a for loop that iterates through all the lowercase letters from 'a' to 'z'.
for i in range(ord('a'), ord('z') + 1):
    a = 0  # Initialize an integer variable 'a' to 0.

    # Start another for loop that iterates through all the characters in the string 's'.
    for j in range(len(s)):
        # Inside the inner for loop, we check if the current character 'i' matches the character at the current position 'j' in the string 's'. If it does, we increment the value of 'a'.
        if chr(i) == s[j]:
            a += 1

    # After the inner for loop, we check if the value of 'a' is 0. If it is, it means that the character 'i' does not appear in the string 's', so we print it to the standard output and break out of the outer for loop using the 'break' statement.
    if a == 0:
        print(chr(i))
        break

    # If the character 'i' is 'z', we print "None" to the standard output and break out of the outer for loop using the 'break' statement.
    if i == ord('z'):
        print("None")
        break

# <END-OF-CODE>
