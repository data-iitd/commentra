
s=input()  # The code takes an input from the user.
alphabets=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]  # Initializes a list of alphabets.
for i in range(len(alphabets)):  # It iterates over the list of alphabets.
    if alphabets[i]==s:  # It checks if the input matches any alphabet in the list.
        print(alphabets[i+1])  # If a match is found, it prints the next alphabet in the list.

