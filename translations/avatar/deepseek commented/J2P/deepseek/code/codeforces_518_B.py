import sys
from collections import Counter

def reverse(ch):
    return ch.swapcase() if ch.isalpha() else ch

# Read the input string `s` and the target string `t`.
s = input().strip()
t = input().strip()

# Initialize counters for the number of replacements
ura = 0
opa = 0

# Create a frequency map `tmap` for characters in `t`.
tmap = Counter(t)

# Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
for i in range(len(s)):
    ch = s[i]
    if tmap[ch] > 0:
        tmap[ch] -= 1
        s = s[:i] + 'Я' + s[i+1:]
        ura += 1

# Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
for i in range(len(s)):
    ch = s[i]
    rch = reverse(ch)
    if tmap[rch] > 0:
        tmap[rch] -= 1
        s = s[:i] + rch + s[i+1:]
        opa += 1

# Step 5: Print the results `ura` and `opa`.
print(ura, opa)
