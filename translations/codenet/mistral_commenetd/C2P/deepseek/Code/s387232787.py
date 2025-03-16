# Initialize an array 'c' of size 26 to store the count of each character.
c = [0] * 26

def main():
    while True:
        try:
            str = input()  # Read a string from the standard input.
        except EOFError:
            break  # Break the loop if the end of file is reached.
        
        # Traverse the string 'str'.
        for char in str:
            # Use nested if conditions to check if the current character is a lowercase or uppercase letter.
            if 'a' <= char <= 'z':
                # Increment the count of the corresponding character in the 'c' array.
                c[ord(char) - ord('a')] += 1
            elif 'A' <= char <= 'Z':
                # Increment the count of the corresponding character in the 'c' array.
                c[ord(char) - ord('A')] += 1

    # Use a loop to print the count of each character and its corresponding character.
    for i in range(26):
        print(f"{chr(i + ord('a'))} : {c[i]}")

# Call the main function to execute the program.
main()

