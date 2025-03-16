
a = input()  # Take an input from the user
vo = ['a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y']  # Define a list of vowels

# Iterate over the input string in reverse order
for i in range(len(a) - 1, -1, -1):
    if a[i] == ' ' or a[i] == '?':  # Check if the current character is a space or a question mark
        continue  # Continue to the next iteration
    else:
        if a[i] in vo:  # Check if the current character is a vowel
            print("YES")  # Print "YES" if the character is a vowel
        else:
            print("NO")  # Print "NO" if the character is not a vowel and break the loop
        break  # Break the loop after printing the result

