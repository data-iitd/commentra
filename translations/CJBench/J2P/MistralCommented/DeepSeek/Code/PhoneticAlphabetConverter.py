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

def text_to_phonetic(text):
    phonetic = []
    for c in text.upper():
        if c.isspace():
            continue
        phonetic.append(PHONETIC_MAP.get(c, c))
    return ' '.join(phonetic).strip()

def main():
    while True:
        user_input = input().strip()
        if user_input.lower() == 'exit':
            print("Exiting...")
            break
        if not user_input:
            print("Invalid Input: Input cannot be blank")
            continue
        result = text_to_phonetic(user_input)
        print("Phonetic Alphabet:", result)

if __name__ == "__main__":
    main()
