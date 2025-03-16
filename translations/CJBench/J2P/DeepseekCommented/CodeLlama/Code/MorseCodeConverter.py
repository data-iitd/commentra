
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

def text_to_morse(text):
    morse = ""
    # Split the text into words
    words = text.upper().split(" ")
    for i in range(len(words)):
        for c in words[i]:
            # Append Morse code for each character
            morse += MORSE_MAP.get(c, "") + " "
            if i < len(words) - 1:
                morse += "| "
    return morse.strip()

def morse_to_text(morse):
    text = ""
    # Split the Morse code into words
    words = morse.split(" | ")
    for i in range(len(words)):
        for code in words[i].split(" "):
            # Convert each Morse code symbol back to a character
            text += REVERSE_MAP.get(code, '?')
            if i < len(words) - 1:
                text += " "
    return text.strip()

def main():
    # Read the operation type from the user
    operation = input().strip().lower()
    # Perform the operation based on the user input
    if operation == "text-to-morse":
        # Read the text to be converted to Morse code
        text = input().strip()
        # Convert the text to Morse code
        morse_code = text_to_morse(text)
        # Print the Morse code
        print("Morse Code:", morse_code)
    elif operation == "morse-to-text":
        # Prompt the user to enter Morse code
        print("Enter the Morse code to convert to text: ", end="")
        morse = input().strip()
        # Convert the Morse code to text
        converted_text = morse_to_text(morse)
        # Print the converted text
        print("Text:", converted_text)
    else:
        # Print an error message for invalid operation
        print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")

if __name__ == "__main__":
    main()

