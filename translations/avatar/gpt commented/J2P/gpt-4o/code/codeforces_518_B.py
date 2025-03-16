def reverse(ch):
    # If the character is lowercase, convert it to uppercase
    if ch.islower():
        return ch.upper()
    else:
        # If it's uppercase, convert it to lowercase
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
    
    # Populate the character frequency map for string t
    for ch in t:
        if ch not in tmap:
            tmap[ch] = 1
        else:
            tmap[ch] += 1
    
    # Get the length of the list for iteration
    length = len(s)
    
    # First pass: Replace characters in s with 'Я' and update the frequency map
    for i in range(length):
        ch = s[i]
        num = tmap.get(ch)
        # If the character is not in the map, skip it
        if num is None:
            continue
        inum = num
        # If the count is 1, remove it from the map; otherwise, decrement the count
        if inum == 1:
            del tmap[ch]
        else:
            tmap[ch] = inum - 1
        # Replace the character in the list with 'Я'
        s[i] = 'Я'
        # Increment the unique character replacement counter
        ura += 1
    
    # Second pass: Check for reversed characters and update the frequency map
    for i in range(length):
        ch = s[i]
        # Get the reversed character
        rch = reverse(ch)
        num = tmap.get(rch)
        # If the reversed character is not in the map, skip it
        if num is None:
            continue
        inum = num
        # If the count is 1, remove it from the map; otherwise, decrement the count
        if inum == 1:
            del tmap[rch]
        else:
            tmap[rch] = inum - 1
        # Increment the reversed character counter
        opa += 1
    
    # Output the counts of unique character replacements and reversed characters
    print(ura, opa)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
