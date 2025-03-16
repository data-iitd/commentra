# Import necessary modules
from collections import defaultdict

# Define the Morse code mappings
MORSE_MAP = {
    'A': ".-", 'B': "-...", 'C': "-.-.", 'D': "-..", 'E': ".", 'F': "..-.",
    'G': "--.", 'H': "....", 'I': "..", 'J': ".---", 'K': "-.-", 'L': ".-..",
    'M': "--", 'N': "-.", 'O': "---", 'P': ".--.", 'Q': "--.-", 'R': ".-.",
    'S': "...", 'T': "-", 'U': "..-", 'V': "...-", 'W': ".--", 'X': "-..-",
    'Y': "-.--", 'Z': "--.."
}

# Create a reverse mapping for Morse code to characters
REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

def text_to_morse(text):
    morse = []
    # Split the input text into words
    words = text.upper().split(" ")
    # Iterate through each word
    for i, word in enumerate(words):
        # Iterate through each character in the word
        for c in word:
            # Append the Morse code for the character, or an empty string if not found
            morse.append(MORSE_MAP.get(c, ""))
        # Append a separator for words, except for the last word
        if i < len(words) - 1:
            morse.append("|")
    # Return the Morse code as a joined string
    return " ".join(morse).strip()

def morse_to_text(morse):
    text = []
    # Split the Morse code into words based on the separator
    words = morse.split(" | ")
    # Iterate through each Morse code word
    for i, word in enumerate(words):
        # Iterate through each Morse code character in the word
        for code in word.split(" "):
            # Append the corresponding character, or '?' if not found
            text.append(REVERSE_MAP.get(code, '?'))
        # Append a space between words, except for the last word
        if i < len(words) - 1:
            text.append(" ")
    # Return the converted text
    return "".join(text)

def main():
    # Read the operation type (text-to-morse or morse-to-text)
    operation = input().strip().lower()
    
    # Determine the operation based on user input
    if operation == "text-to-morse":
        # Read the text input to convert to Morse code
        text = input()
        # Convert the text to Morse code
        morse_code = text_to_morse(text)
        # Output the resulting Morse code
        print("Morse Code:", morse_code)
    elif operation == "morse-to-text":
        # Prompt user for Morse code input
        morse = input("Enter the Morse code to convert to text: ")
        # Convert the Morse code to text
        converted_text = morse_to_text(morse)
        # Output the resulting text
        print("Text:", converted_text)
    else:
        # Handle invalid operation input
        print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
