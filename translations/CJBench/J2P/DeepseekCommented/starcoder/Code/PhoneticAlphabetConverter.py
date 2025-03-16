import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Main:
    # Static block to initialize the PHONETIC_MAP with character mappings
    PHONETIC_MAP = {}
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

    # Main method to run the program
    def main(self):
        scanner = Scanner(System.in)
        while True:
            input = scanner.nextLine().strip() # Read input and trim whitespace
            if input.lower() == "exit": # Check if the user wants to exit
                print("Exiting...")
                break
            if input.strip() == "": # Check if the input is blank
                print("Invalid Input: Input cannot be blank")
                continue
            result = self.textToPhonetic(input) # Convert input to phonetic alphabet
            print("Phonetic Alphabet: " + result) # Print the result
        scanner.close() # Close the scanner

    # Method to convert text to phonetic alphabet
    def textToPhonetic(self, text):
        phonetic = ""
        for c in text.upper(): # Convert text to uppercase and iterate over characters
            if c.isspace(): # Skip whitespace characters
                continue
            phonetic += self.PHONETIC_MAP.get(c, c) + " " # Append phonetic equivalent or character itself with a space
        return phonetic.strip() # Return the final string, trimmed of trailing spaces

# 