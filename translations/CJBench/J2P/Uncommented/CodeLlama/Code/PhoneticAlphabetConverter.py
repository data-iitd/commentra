
import sys
import string

def text_to_phonetic(text):
    phonetic = ""
    for c in text.upper():
        if c in string.whitespace:
            continue
        phonetic += PHONETIC_MAP.get(c, c) + " "
    return phonetic.strip()

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

if __name__ == "__main__":
    while True:
        input_text = input("Enter text to translate to phonetic alphabet: ").strip()
        if input_text.lower() == "exit":
            print("Exiting...")
            sys.exit()
        if not input_text:
            print("Invalid Input: Input cannot be blank")
            continue
        phonetic_text = text_to_phonetic(input_text)
        print("Phonetic Alphabet:", phonetic_text)

