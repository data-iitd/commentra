import sys

# Static block to initialize the PHONETIC_MAP with character mappings
PHONETIC_MAP = {
    'A': "Alpha",
    'B': "Bravo",
    'C': "Charlie",
    'D': "Delta",
    'E': "Echo",
    'F': "Foxtrot",
    'G': "Golf",
    'H': "Hotel",
    'I': "India",
    'J': "Juliett",
    'K': "Kilo",
    'L': "Lima",
    'M': "Mike",
    'N': "November",
    'O': "Oscar",
    'P': "Papa",
    'Q': "Quebec",
    'R': "Romeo",
    'S': "Sierra",
    'T': "Tango",
    'U': "Uniform",
    'V': "Victor",
    'W': "Whiskey",
    'X': "X-ray",
    'Y': "Yankee",
    'Z': "Zulu",
    '0': "Zero",
    '1': "One",
    '2': "Two",
    '3': "Three",
    '4': "Four",
    '5': "Five",
    '6': "Six",
    '7': "Seven",
    '8': "Eight",
    '9': "Nine"
}

# Main method to run the program
def main():
    while True:
        input_ = input("Enter text to convert to phonetic alphabet: ").strip()
        if input_.lower() == "exit":
            print("Exiting...")
            break
        if not input_:
            print("Invalid Input: Input cannot be blank")
            continue
        result = text_to_phonetic(input_)
        print("Phonetic Alphabet:", result)

# Method to convert text to phonetic alphabet
def text_to_phonetic(text):
    phonetic = ""
    for c in text.upper():
        if c.isspace():
            continue
        phonetic += PHONETIC_MAP.get(c, c) + " "
    return phonetic.strip()

if __name__ == "__main__":
    main()


