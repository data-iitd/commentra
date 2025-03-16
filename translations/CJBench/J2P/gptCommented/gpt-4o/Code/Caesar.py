class Main:
    def encode(self, message, shift):
        encoded = []
        shift %= 26  # Normalize the shift value to be within 0-25
        
        for current in message:
            if self.is_capital_latin_letter(current):
                current = chr(ord(current) + shift)  # Apply the shift
                # Wrap around if it exceeds 'Z'
                encoded.append(chr(ord(current) - 26) if current > 'Z' else current)
            elif self.is_small_latin_letter(current):
                current = chr(ord(current) + shift)  # Apply the shift
                # Wrap around if it exceeds 'z'
                encoded.append(chr(ord(current) - 26) if current > 'z' else current)
            else:
                encoded.append(current)  # Append the character as is
        return ''.join(encoded)  # Return the encoded message as a string

    def decode(self, encrypted_message, shift):
        decoded = []
        shift %= 26  # Normalize the shift value to be within 0-25
        
        for current in encrypted_message:
            if self.is_capital_latin_letter(current):
                current = chr(ord(current) - shift)  # Apply the reverse shift
                # Wrap around if it goes below 'A'
                decoded.append(chr(ord(current) + 26) if current < 'A' else current)
            elif self.is_small_latin_letter(current):
                current = chr(ord(current) - shift)  # Apply the reverse shift
                # Wrap around if it goes below 'a'
                decoded.append(chr(ord(current) + 26) if current < 'a' else current)
            else:
                decoded.append(current)  # Append the character as is
        return ''.join(decoded)  # Return the decoded message as a string

    @staticmethod
    def is_capital_latin_letter(c):
        return 'A' <= c <= 'Z'

    @staticmethod
    def is_small_latin_letter(c):
        return 'a' <= c <= 'z'

    def bruteforce(self, encrypted_message):
        list_of_all_the_answers = [None] * 27  # Array to hold all possible decoded messages
        for i in range(27):
            list_of_all_the_answers[i] = self.decode(encrypted_message, i)  # Decode with the current shift
        return list_of_all_the_answers  # Return the array of possible solutions


if __name__ == "__main__":
    import sys

    # Read the operation type (encode, decode, bruteforce) from the user input
    operation = input().strip().lower()
    cipher = Main()

    # Check if the operation is to encode a message
    if operation == "encode":
        plaintext = input()  # Read the plaintext message to be encoded
        shift = int(input())  # Read the shift value for encoding
        print("Encoded Message:", cipher.encode(plaintext, shift))
    # Check if the operation is to decode a message
    elif operation == "decode":
        encrypted_text = input()  # Read the encrypted message to be decoded
        shift = int(input())  # Read the shift value for decoding
        print("Decoded Message:", cipher.decode(encrypted_text, shift))
    # Check if the operation is to perform a brute force attack
    elif operation == "bruteforce":
        encrypted_text = input()  # Read the encrypted message for brute force decoding
        possible_solutions = cipher.bruteforce(encrypted_text)  # Get all possible decoded messages
        for i, solution in enumerate(possible_solutions):
            print(f"Shift {i}: {solution}")  # Print all possible solutions with their respective shift values
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")  # Handle invalid operation input

# <END-OF-CODE>
