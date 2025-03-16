# Take input from the user
a = input()

# Define a list of vowels (both lowercase and uppercase)
vo = ['a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y']

# Iterate through the input string in reverse order
for i in range(len(a) - 1, -1, -1):
    # Check if the current character is a space or a question mark
    if (a[i] == ' ' or a[i] == '?'):
        continue  # Skip to the next iteration if it is a space or '?'
    else:
        # Check if the current character is a vowel
        if (a[i] in vo):
            print("YES")  # Print "YES" if it is a vowel
        else:
            print("NO")   # Print "NO" if it is not a vowel
        break  # Exit the loop after processing the first non-space character
