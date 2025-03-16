# Import necessary modules
from collections import defaultdict

# Initialize a dictionary named PHONETIC_MAP to store the mapping between characters and their phonetic alphabet representations
PHONETIC_MAP = {
    'A': "Alpha", 'B': "Bravo", 'C': "Charlie", 'D': "Delta", 'E': "Echo",
    'F': "Foxtrot", 'G': "Golf", 'H': "Hotel", 'I': "India", 'J': "Juliett",
    'K': "Kilo", 'L': "Lima", 'M': "Mike", 'N': "November", 'O': "Oscar",
    'P': "Papa", 'Q': "Quebec", 'R': "Romeo", 'S': "Sierra", 'T': "Tango",
    'U': "Uniform", 'V': "Victor", 'W': "Whiskey", 'X': "X-ray", 'Y': "Yankee",
    'Z': "Zulu", '0': "Zero", '1': "One", '2': "Two", '3': "Three",
    '4': "Four", '5': "Five", '6': "Six", '7': "Seven", '8': "Eight", '9': "Nine"
}

def text_to_phonetic(text):
    """Convert a given text string to its phonetic alphabet representation."""
    phonetic = []  # Initialize a list to store the phonetic alphabet representation
    for c in text.upper():  # Iterate through each character in the user input string
        if c.isspace():  # Check if the character is a whitespace character
            continue  # Skip the character if it is a whitespace character
        phonetic.append(PHONETIC_MAP.get(c, c))  # Append the phonetic alphabet representation or the character itself
    return ' '.join(phonetic)  # Return the final phonetic alphabet representation of the user input string

def main():
    """Main method to run the phonetic alphabet converter."""
    while True:  # Infinite loop to keep the program running until the user enters "exit"
        input_text = input().strip()  # Read a line of user input and trim any leading/trailing whitespaces
        if input_text.lower() == "exit":  # Check if the user entered "exit" to exit the program
            print("Exiting...")  # Print a message to indicate that the program is exiting
            break  # Exit the loop
        if not input_text:  # Check if the user entered an empty line
            print("Invalid Input: Input cannot be blank")  # Print an error message if the input is empty
            continue  # Continue to the next iteration of the loop
        result = text_to_phonetic(input_text)  # Call the text_to_phonetic method to convert the user input
        print("Phonetic Alphabet:", result)  # Print the phonetic alphabet representation of the user input

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
