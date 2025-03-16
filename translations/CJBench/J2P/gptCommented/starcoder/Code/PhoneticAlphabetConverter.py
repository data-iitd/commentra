import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # A map to hold the phonetic representations of characters and digits
    PHONETIC_MAP = {}
    
    # Static block to initialize the PHONETIC_MAP with character mappings
    def __init__(self):
        PHONETIC_MAP['A'] = "Alpha"
        PHONETIC_MAP['B'] = "Bravo"
        PHONETIC_MAP['C'] = "Charlie"
        PHONETIC_MAP['D'] = "Delta"
        PHONETIC_MAP['E'] = "Echo"
        PHONETIC_MAP['F'] = "Foxtrot"
        PHONETIC_MAP['G'] = "Golf"
        PHONETIC_MAP['H'] = "Hotel"
        PHONETIC_MAP['I'] = "India"
        PHONETIC_MAP['J'] = "Juliett"
        PHONETIC_MAP['K'] = "Kilo"
        PHONETIC_MAP['L'] = "Lima"
        PHONETIC_MAP['M'] = "Mike"
        PHONETIC_MAP['N'] = "November"
        PHONETIC_MAP['O'] = "Oscar"
        PHONETIC_MAP['P'] = "Papa"
        PHONETIC_MAP['Q'] = "Quebec"
        PHONETIC_MAP['R'] = "Romeo"
        PHONETIC_MAP['S'] = "Sierra"
        PHONETIC_MAP['T'] = "Tango"
        PHONETIC_MAP['U'] = "Uniform"
        PHONETIC_MAP['V'] = "Victor"
        PHONETIC_MAP['W'] = "Whiskey"
        PHONETIC_MAP['X'] = "X-ray"
        PHONETIC_MAP['Y'] = "Yankee"
        PHONETIC_MAP['Z'] = "Zulu"
        PHONETIC_MAP['0'] = "Zero"
        PHONETIC_MAP['1'] = "One"
        PHONETIC_MAP['2'] = "Two"
        PHONETIC_MAP['3'] = "Three"
        PHONETIC_MAP['4'] = "Four"
        PHONETIC_MAP['5'] = "Five"
        PHONETIC_MAP['6'] = "Six"
        PHONETIC_MAP['7'] = "Seven"
        PHONETIC_MAP['8'] = "Eight"
        PHONETIC_MAP['9'] = "Nine"

    # Method to convert text to its phonetic representation
    def textToPhonetic(self, text):
        phonetic = ""
        
        # Iterate over each character in the input text
        for c in text.upper():
            # Skip whitespace characters
            if c.isspace():
                continue
            # Append the phonetic representation of the character or the character itself if not found
            phonetic += PHONETIC_MAP.get(c, c) + " "
        
        # Return the phonetic string, trimmed of any trailing spaces
        return phonetic.strip()

    # Main method
    def main(self):
        # Create a scanner object to read input from the console
        scanner = Scanner(System.in)
        
        # Loop to continuously accept user input until "exit" is entered
        while True:
            input = scanner.nextLine().strip()
            
            # Check if the user wants to exit the program
            if input.equalsIgnoreCase("exit"):
                print("Exiting...")
                break
            
            # Check for empty input and prompt the user
            if input.isEmpty():
                print("Invalid Input: Input cannot be blank")
                continue
            
            # Convert the input text to its phonetic representation
            result = textToPhonetic(input)
            # Output the phonetic representation
            print("Phonetic Alphabet: " + result)
        
        # Close the scanner to free resources
        scanner.close()

# 