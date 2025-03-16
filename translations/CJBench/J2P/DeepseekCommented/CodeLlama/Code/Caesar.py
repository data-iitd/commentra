
# Import the Scanner class from the java.util package
from java.util import Scanner

# Define the Main class
class Main:
    # Define the encode method
    def encode(self, message, shift):
        # Normalize the shift value to ensure it is within the range of 0-25
        shift %= 26
        # Initialize an empty string to store the encoded message
        encoded = ""
        # Iterate over each character in the message
        for current in message:
            # Check if the character is an uppercase Latin letter and shift it
            if current.isupper():
                current = chr((ord(current) + shift - 65) % 26 + 65)
                encoded += current
            elif current.islower(): # Check if the character is a lowercase Latin letter and shift it
                current = chr((ord(current) + shift - 97) % 26 + 97)
                encoded += current
            else:
                # Append the character as is if it is not a Latin letter
                encoded += current
        # Return the encoded message
        return encoded
    
    # Define the decode method
    def decode(self, encrypted_message, shift):
        # Normalize the shift value to ensure it is within the range of 0-25
        shift %= 26
        # Initialize an empty string to store the decoded message
        decoded = ""
        # Iterate over each character in the encrypted message
        for current in encrypted_message:
            # Check if the character is an uppercase Latin letter and shift it back
            if current.isupper():
                current = chr((ord(current) - shift - 65) % 26 + 65)
                decoded += current
            elif current.islower(): # Check if the character is a lowercase Latin letter and shift it back
                current = chr((ord(current) - shift - 97) % 26 + 97)
                decoded += current
            else:
                # Append the character as is if it is not a Latin letter
                decoded += current
        # Return the decoded message
        return decoded
    
    # Define the bruteforce method
    def bruteforce(self, encrypted_message):
        # Initialize an empty list to store the decoded messages
        list_of_all_the_answers = []
        # Attempt to decode the message using each possible shift
        for i in range(27):
            list_of_all_the_answers.append(self.decode(encrypted_message, i))
        # Return the list of decoded messages
        return list_of_all_the_answers

# Create a new instance of the Main class to call the encode method
cipher = Main()

# Initialize the Scanner to read input from the console
scanner = Scanner(System.in)

# Read the operation type from the input
operation = scanner.nextLine().strip().lower()

# Check which operation is selected and proceed accordingly
if operation == "encode":
    # Read the plaintext message from the input
    plaintext = scanner.nextLine()
    # Read the shift value from the input
    shift = scanner.nextInt()
    # Print the encoded message
    print("Encoded Message: " + cipher.encode(plaintext, shift))
elif operation == "decode":
    # Read the encrypted message from the input
    encrypted_text = scanner.nextLine()
    # Read the shift value from the input
    shift = scanner.nextInt()
    # Print the decoded message
    print("Decoded Message: " + cipher.decode(encrypted_text, shift))
elif operation == "bruteforce":
    # Read the encrypted message from the input
    encrypted_text = scanner.nextLine()
    # Get all possible decoded messages using bruteforce
    possible_solutions = cipher.bruteforce(encrypted_text)
    # Print each decoded message with its corresponding shift
    for i in range(len(possible_solutions)):
        print("Shift " + str(i) + ": " + possible_solutions[i])
else:
    # Print an error message if the operation is invalid
    print("Invalid operation. Please enter encode, decode, or bruteforce.")

# Close the Scanner to free up resources
scanner.close()

# End of code
