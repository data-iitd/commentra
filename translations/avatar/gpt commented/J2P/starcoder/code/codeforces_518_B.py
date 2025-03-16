
# Create a Scanner object to read input from the console
scan = Scanner(sys.stdin)

# Read the first string and initialize a StringBuilder with it
s = StringBuilder(scan.next())

# Read the second string
t = scan.next()

# Initialize counters for unique characters replaced (ura) and reversed characters (opa)
ura = 0
opa = 0

# Create a map to count occurrences of each character in string t
tmap = {}

# Populate the character frequency map for string t
for i in range(len(t)):
    ch = t[i]
    # If the character is not already in the map, add it with a count of 1
    if ch not in tmap:
        tmap[ch] = 1
    else
        # If it exists, increment its count
        tmap[ch] += 1

# Get the length of the StringBuilder for iteration
length = len(s)

# First pass: Replace characters in s with 'Я' and update the frequency map
for i in range(length):
    ch = s[i]
    num = tmap.get(ch)
    # If the character is not in the map, skip it
    if num == None: continue
    inum = num
    # If the count is 1, remove it from the map; otherwise, decrement the count
    if inum == 1:
        del tmap[ch]
    else:
        tmap[ch] = inum - 1
    # Replace the character in the StringBuilder with 'Я'
    s[i] = 'Я'
    # Increment the unique character replacement counter
    ura += 1

# Second pass: Check for reversed characters and update the frequency map
for i in range(length):
    ch = s[i]
    # Get the reversed character (lowercase to uppercase or vice versa)
    rch = reverse(ch)
    num = tmap.get(rch)
    # If the reversed character is not in the map, skip it
    if num == None: continue
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

# 