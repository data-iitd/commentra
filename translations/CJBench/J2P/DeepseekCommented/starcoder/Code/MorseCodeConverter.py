import re

# Morse code map for character to Morse code conversion
MORSE_MAP = {
    'A': ".-",
    'B': "-...",
    'C': "-.-.",
    'D': "-..",
    'E': ".",
    'F': "..-.",
    'G': "--.",
    'H': "....",
    'I': "..",
    'J': ".---",
    'K': "-.-",
    'L': ".-..",
    'M': "--",
    'N': "-.",
    'O': "---",
    'P': ".--.",
    'Q': "--.-",
    'R': ".-.",
    'S': "...",
    'T': "-",
    'U': "..-",
    'V': "...-",
    'W': ".--",
    'X': "-..-",
    'Y': "-.--",
    'Z': "--.."
}

# Reverse map for Morse code to character conversion
REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

# Main method to run the program
def main():
    # Read the operation type from the user
    operation = input("Enter the operation type (text-to-morse or morse-to-text): ").strip().lower()
    # Perform the operation based on the user input
    if operation == "text-to-morse":
        # Read the text to be converted to Morse code
        text = input("Enter the text to convert to Morse code: ").strip()
        # Convert the text to Morse code
        morse_code = text_to_morse(text)
        # Print the Morse code
        print("Morse Code: " + morse_code)
    elif operation == "morse-to-text":
        # Prompt the user to enter Morse code
        morse = input("Enter the Morse code to convert to text: ").strip()
        # Convert the Morse code to text
        converted_text = morse_to_text(morse)
        # Print the converted text
        print("Text: " + converted_text)
    else:
        # Print an error message for invalid operation
        print("Invalid operation. Please enter 'text-to-morse' or'morse-to-text'.")

# Method to convert text to Morse code
def text_to_morse(text):
    morse = []
    # Split the text into words
    words = re.split(r"\s+", text.upper())
    for word in words:
        for c in word:
            # Append Morse code for each character
            morse.append(MORSE_MAP.get(c, " "))
        morse.append("| ")
    return "".join(morse).strip()

# Method to convert Morse code to text
def morse_to_text(morse):
    text = []
    # Split the Morse code into words
    words = re.split(r"\s+\|\s+", morse)
    for word in words:
        for code in re.split(r"\s+", word):
            # Convert each Morse code symbol back to a character
            text.append(REVERSE_MAP.get(code, "?"))
        text.append(" ")
    return "".join(text).strip()

# Run the program
if __name__ == "__main__":
    main()

