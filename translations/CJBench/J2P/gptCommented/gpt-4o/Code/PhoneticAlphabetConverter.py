class PhoneticConverter:
    # A dictionary to hold the phonetic representations of characters and digits
    PHONETIC_MAP = {
        'A': "Alpha", 'B': "Bravo", 'C': "Charlie", 'D': "Delta",
        'E': "Echo", 'F': "Foxtrot", 'G': "Golf", 'H': "Hotel",
        'I': "India", 'J': "Juliett", 'K': "Kilo", 'L': "Lima",
        'M': "Mike", 'N': "November", 'O': "Oscar", 'P': "Papa",
        'Q': "Quebec", 'R': "Romeo", 'S': "Sierra", 'T': "Tango",
        'U': "Uniform", 'V': "Victor", 'W': "Whiskey", 'X': "X-ray",
        'Y': "Yankee", 'Z': "Zulu", '0': "Zero", '1': "One",
        '2': "Two", '3': "Three", '4': "Four", '5': "Five",
        '6': "Six", '7': "Seven", '8': "Eight", '9': "Nine"
    }

    @staticmethod
    def text_to_phonetic(text):
        phonetic = []
        # Iterate over each character in the input text
        for c in text.upper():
            # Skip whitespace characters
            if c.isspace():
                continue
            # Append the phonetic representation of the character or the character itself if not found
            phonetic.append(PhoneticConverter.PHONETIC_MAP.get(c, c))
        # Return the phonetic string joined by spaces
        return ' '.join(phonetic)

def main():
    # Loop to continuously accept user input until "exit" is entered
    while True:
        input_text = input().strip()
        
        # Check if the user wants to exit the program
        if input_text.lower() == "exit":
            print("Exiting...")
            break
        
        # Check for empty input and prompt the user
        if not input_text:
            print("Invalid Input: Input cannot be blank")
            continue
        
        # Convert the input text to its phonetic representation
        result = PhoneticConverter.text_to_phonetic(input_text)
        # Output the phonetic representation
        print("Phonetic Alphabet:", result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
