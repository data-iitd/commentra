class MorseCodeConverter:
    MORSE_MAP = {
        'A': ".-", 'B': "-...", 'C': "-.-.", 'D': "-..", 'E': ".", 'F': "..-.",
        'G': "--.", 'H': "....", 'I': "..", 'J': ".---", 'K': "-.-", 'L': ".-..",
        'M': "--", 'N': "-.", 'O': "---", 'P': ".--.", 'Q': "--.-", 'R': ".-.",
        'S': "...", 'T': "-", 'U': "..-", 'V': "...-", 'W': ".--", 'X': "-..-",
        'Y': "-.--", 'Z': "--.."
    }
    REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

    @staticmethod
    def text_to_morse(text):
        morse = []
        words = text.upper().split(" ")
        for i, word in enumerate(words):
            for c in word:
                morse.append(MorseCodeConverter.MORSE_MAP.get(c, ""))
            if i < len(words) - 1:
                morse.append("|")
        return " ".join(morse).strip()

    @staticmethod
    def morse_to_text(morse):
        text = []
        words = morse.split(" | ")
        for i, word in enumerate(words):
            for code in word.split(" "):
                text.append(MorseCodeConverter.REVERSE_MAP.get(code, '?'))
            if i < len(words) - 1:
                text.append(" ")
        return "".join(text)

def main():
    operation = input().strip().lower()
    if operation == "text-to-morse":
        text = input()
        morse_code = MorseCodeConverter.text_to_morse(text)
        print("Morse Code:", morse_code)
    elif operation == "morse-to-text":
        morse = input("Enter the Morse code to convert to text: ")
        converted_text = MorseCodeConverter.morse_to_text(morse)
        print("Text:", converted_text)
    else:
        print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
