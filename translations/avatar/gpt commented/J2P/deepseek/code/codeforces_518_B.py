import sys

def reverse(ch):
    if ch.islower():
        return ch.upper()
    else:
        return ch.lower()

def main():
    # Read the first string and initialize a list with it
    s = list(input().strip())
    
    # Read the second string
    t = input().strip()
    
    # Initialize counters for unique characters replaced (ura) and reversed characters (opa)
    ura = 0
    opa = 0
    
    # Create a dictionary to count occurrences of each character in string t
    tmap = {}
    
    # Populate the character frequency dictionary for string t
    for ch in t:
        if ch not in tmap:
            tmap[ch] = 1
        else:
            tmap[ch] += 1
    
    # First pass: Replace characters in s with 'Я' and update the frequency dictionary
    for i in range(len(s)):
        ch = s[i]
        if ch in tmap:
            num = tmap[ch]
            del tmap[ch]
            s[i] = 'Я'
            ura += 1
    
    # Second pass: Check for reversed characters and update the frequency dictionary
    for i in range(len(s)):
        ch = s[i]
        rch = reverse(ch)
        if rch in tmap:
            num = tmap[rch]
            del tmap[rch]
            opa += 1
    
    # Output the counts of unique character replacements and reversed characters
    print(ura, opa)

if __name__ == "__main__":
    main()
