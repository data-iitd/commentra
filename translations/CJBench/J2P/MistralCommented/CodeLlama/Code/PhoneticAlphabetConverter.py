
import sys

# Initialize a dictionary named PHONETIC_MAP to store the mapping between characters and their phonetic alphabet representations
PHONETIC_MAP = {
    'A': 'Alpha',
    'B': 'Bravo',
    'C': 'Charlie',
    'D': 'Delta',
    'E': 'Echo',
    'F': 'Foxtrot',
    'G': 'Golf',
    'H': 'Hotel',
    'I': 'India',
    'J': 'Juliett',
    'K': 'Kilo',
    'L': 'Lima',
    'M': 'Mike',
    'N': 'November',
    'O': 'Oscar',
    'P': 'Papa',
    'Q': 'Quebec',
    'R': 'Romeo',
    'S': 'Sierra',
    'T': 'Tango',
    'U': 'Uniform',
    'V': 'Victor',
    'W': 'Whiskey',
    'X': 'X-ray',
    'Y': 'Yankee',
    'Z': 'Zulu',
    '0': 'Zero',
    '1': 'One',
    '2': 'Two',
    '3': 'Three',
    '4': 'Four',
    '5': 'Five',
    '6': 'Six',
    '7': 'Seven',
    '8': 'Eight',
    '9': 'Nine'
}

# Main method entry point
def main():
    while True: # Infinite loop to keep the program running until the user enters "exit"
        input = sys.stdin.readline().strip() # Read a line of user input and strip any leading/trailing whitespaces
        if input.lower() == "exit": # Check if the user entered "exit" to exit the program
            print("Exiting...") # Print a message to indicate that the program is exiting
            break # Exit the loop
        if not input: # Check if the user entered an empty line
            print("Invalid Input: Input cannot be blank") # Print an error message if the input is empty
            continue # Continue to the next iteration of the loop
        result = text_to_phonetic(input) # Call the text_to_phonetic method to convert the user input to its phonetic alphabet representation
        print("Phonetic Alphabet: " + result) # Print the phonetic alphabet representation of the user input

# Method to convert a given text string to its phonetic alphabet representation
def text_to_phonetic(text):
    phonetic = "" # Initialize an empty string to store the phonetic alphabet representation
    for c in text.upper(): # Iterate through each character in the user input string
        if c.isspace(): # Check if the character is a whitespace character
            continue # Skip the character if it is a whitespace character
        phonetic += PHONETIC_MAP.get(c, c) + " " # Append the phonetic alphabet representation of the character or its actual character representation followed by a space
    return phonetic.strip() # Return the final phonetic alphabet representation of the user input string

if __name__ == "__main__":
    main() # Call the main method to start the program

