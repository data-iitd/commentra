

import sys

# Step 1: Read the input string `s` and the target string `t`.
s = input()
t = input()

# Initialize counters for the number of replacements
ura = 0 # Counter for replacements in step 3
opa = 0 # Counter for replacements in step 4

# Step 2: Create a frequency map `tmap` for characters in `t`.
tmap = {}
for ch in t:
    if ch not in tmap:
        tmap[ch] = 1
    else:
        tmap[ch] += 1

# Step 3: Iterate through `s` and replace characters that are in `t` with 'Я'.
length = len(s)
for i in range(length):
    ch = s[i]
    num = tmap.get(ch)
    if num == None: continue
    inum = num
    if inum == 1:
        tmap.pop(ch)
    else:
        tmap[ch] = inum - 1
    s = s[:i] + 'Я' + s[i+1:]
    ura += 1

# Step 4: Iterate through `s` again and replace characters that are the reverse of characters in `t` with their reverse.
for i in range(length):
    ch = s[i]
    rch = ch[::-1]
    num = tmap.get(rch)
    if num == None: continue
    inum = num
    if inum == 1:
        tmap.pop(rch)
    else:
        tmap[rch] = inum - 1
    opa += 1

# Step 5: Print the results `ura` and `opa`.
print(ura, opa)

