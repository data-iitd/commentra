# Import necessary modules
from collections import defaultdict

# Initialize a dictionary named MORSE_MAP to store Morse code mappings for each English alphabet character.
MORSE_MAP = {
    'A': ".-", 'B': "-...", 'C': "-.-.", 'D': "-..", 'E': ".", 'F': "..-.",
    'G': "--.", 'H': "....", 'I': "..", 'J': ".---", 'K': "-.-", 'L': ".-..",
    'M': "--", 'N': "-.", 'O': "---", 'P': ".--.", 'Q': "--.-", 'R': ".-.",
    'S': "...", 'T': "-", 'U': "..-", 'V': "...-", 'W': ".--", 'X': "-..-",
    'Y': "-.--", 'Z': "--.."
}

# Initialize a dictionary named REVERSE_MAP to store the reverse mapping of Morse code to English alphabet characters.
REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

def main():
    # Read user operation from the console.
    operation = input().strip().lower()

    # Switch the user operation and call the corresponding method.
    if operation == "text-to-morse":
        # Read text from the console.
        text = input()

        # Convert text to Morse code and print it to the console.
        morse_code = text_to_morse(text)
        print("Morse Code:", morse_code)
    elif operation == "morse-to-text":
        # Read Morse code from the console.
        morse = input("Enter the Morse code to convert to text: ")

        # Convert Morse code to text and print it to the console.
        converted_text = morse_to_text(morse)
        print("Text:", converted_text)
    else:
        # Print an error message if the user enters an invalid operation.
        print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")

# Convert text to Morse code.
def text_to_morse(text):
    # Initialize a list to store Morse code.
    morse = []

    # Split text into words and iterate through each character in each word.
    words = text.upper().split(" ")
    for i in range(len(words)):
        for c in words[i]:
            # Append Morse code for the character to the list.
            morse.append(MORSE_MAP.get(c, ""))
        
        # Add a separator "| " between words, except for the last word.
        if i < len(words) - 1:
            morse.append("| ")

    # Return the Morse code as a string.
    return " ".join(morse).strip()

# Convert Morse code to text.
def morse_to_text(morse):
    # Initialize a list to store text.
    text = []

    # Split Morse code into words and iterate through each character in each word.
    words = morse.split(" | ")
    for i in range(len(words)):
        for code in words[i].split(" "):
            # Append the English alphabet character corresponding to the Morse code to the list.
            text.append(REVERSE_MAP.get(code, '?'))
        
        # Add a separator " " between words, except for the last word.
        if i < len(words) - 1:
            text.append(" ")

    # Return the text as a string.
    return "".join(text)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>











