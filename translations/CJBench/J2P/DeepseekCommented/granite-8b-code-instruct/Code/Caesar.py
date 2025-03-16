
import string

class Main:
    def __init__(self):
        pass
    
    def encode(self, message, shift):
        encoded = ""
        # Normalize the shift value to ensure it is within the range of 0-25
        shift %= 26
        # Iterate over each character in the message
        for current in message:
            # Check if the character is an uppercase Latin letter and shift it
            if current.isupper():
                encoded += chr((ord(current) - 65 + shift) % 26 + 65)
            # Check if the character is a lowercase Latin letter and shift it
            elif current.islower():
                encoded += chr((ord(current) - 97 + shift) % 26 + 97)
            # Append the character as is if it is not a Latin letter
            else:
                encoded += current
        # Return the encoded message
        return encoded
    
    def decode(self, encryptedMessage, shift):
        decoded = ""
        # Normalize the shift value to ensure it is within the range of 0-25
        shift %= 26
        # Iterate over each character in the encrypted message
        for current in encryptedMessage:
            # Check if the character is an uppercase Latin letter and shift it back
            if current.isupper():
                decoded += chr((ord(current) - 65 - shift) % 26 + 65)
            # Check if the character is a lowercase Latin letter and shift it back
            elif current.islower():
                decoded += chr((ord(current) - 97 - shift) % 26 + 97)
            # Append the character as is if it is not a Latin letter
            else:
                decoded += current
        # Return the decoded message
        return decoded
    
    def bruteforce(self, encryptedMessage):
        listOfAllTheAnswers = []
        # Attempt to decode the message using each possible shift
        for i in range(27):
            listOfAllTheAnswers.append(self.decode(encryptedMessage, i))
        # Return the array of decoded messages
        return listOfAllTheAnswers

# End of code
