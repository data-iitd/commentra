# We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
freqs = dict ()
freqt = dict ()

# We read the two strings s and t from the user input
s, t = input (), input ()

# We iterate through each character in the string s and update the frequency count in the freqs dictionary
for letra in s:
    if letra in freqs:
        freqs [letra] += 1
    else:
        freqs [letra] = 1

# We iterate through each character in the string t and update the frequency count in the freqt dictionary
for letra in t:
    if letra in freqt:
        freqt [letra] += 1
    else:
        freqt [letra] = 1

# We initialize two counters, yay and whoops, to zero
yay, whoops = 0, 0

# We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
for letra in freqs.keys ():
    while (freqs [letra] > 0 and letra in freqt and freqt [letra] > 0):
        yay += 1
        freqs [letra] -= 1
        freqt [letra] -= 1

# We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
for letra in freqs.keys ():
    while (freqs [letra] > 0):
        if letra.islower () and letra.upper () in freqt.keys () and freqt [letra.upper ()] > 0:
            whoops += 1
            freqs [letra] -= 1
            freqt [letra.upper ()] -= 1
        elif letra.isupper () and letra.lower () in freqt.keys () and freqt [letra.lower ()] > 0:
            whoops += 1
            freqs [letra] -= 1
            freqt [letra.lower ()] -= 1
        else:
            break ;

# Finally, we print the values of yay and whoops
print (yay, whoops)
