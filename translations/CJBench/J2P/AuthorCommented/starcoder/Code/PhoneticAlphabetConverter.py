
import re

PHONETIC_MAP = {
    'A': 'Alpha',
    'B': 'Bravo',
    'C': 'Charlie',
    'D': 'Delta',
    'E': 'Echo',
    'F': 'Foxtrot',
    'G': 'Golf',
    'H': 'Hotel',
    'I': 'India',
    'J': 'Juliett',
    'K': 'Kilo',
    'L': 'Lima',
    'M': 'Mike',
    'N': 'November',
    'O': 'Oscar',
    'P': 'Papa',
    'Q': 'Quebec',
    'R': 'Romeo',
    'S': 'Sierra',
    'T': 'Tango',
    'U': 'Uniform',
    'V': 'Victor',
    'W': 'Whiskey',
    'X': 'X-ray',
    'Y': 'Yankee',
    'Z': 'Zulu',
    '0': 'Zero',
    '1': 'One',
    '2': 'Two',
    '3': 'Three',
    '4': 'Four',
    '5': 'Five',
    '6': 'Six',
    '7': 'Seven',
    '8': 'Eight',
    '9': 'Nine',
}


def text_to_phonetic(text):
    result = []
    for c in text.upper():
        if c in PHONETIC_MAP:
            result.append(PHONETIC_MAP[c])
        else:
            result.append(c)
    return''.join(result)


if __name__ == '__main__':
    while True:
        text = input('Enter text to convert to NATO phonetic alphabet: ')
        if text.lower() == 'exit':
            print('Exiting...')
            break
        if not text:
            print('Invalid Input: Input cannot be blank')
            continue
        print('Phonetic Alphabet:'+ text_to_phonetic(text))

