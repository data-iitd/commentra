# Ask user for input string
s = input()

# Define a list of all alphabets
alphabets = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

# Iterate through each alphabet in the list
for i in range(len(alphabets)):
    # Check if the input string is equal to the current alphabet
    if alphabets[i] == s:
        # Print the next alphabet if the condition is true
        print(alphabets[i+1])