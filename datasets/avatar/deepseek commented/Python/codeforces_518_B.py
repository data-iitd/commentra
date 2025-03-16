s , t = input ( ) , input ( )  # Taking two input strings
freqs = dict ( )  # Dictionary to store frequency of characters in s
freqt = dict ( )  # Dictionary to store frequency of characters in t
yay , whoops = 0 , 0  # Initializing counters for yay and whoops

# Populating the frequency dictionaries
for letra in s :
    if letra in freqs :
        freqs [ letra ] += 1  # Incrementing the count if character is already in dictionary
    else :
        freqs [ letra ] = 1  # Initializing the count if character is not in dictionary

for letra in t :
    if letra in freqt :
        freqt [ letra ] += 1  # Incrementing the count if character is already in dictionary
    else :
        freqt [ letra ] = 1  # Initializing the count if character is not in dictionary

# Counting yay by matching characters in freqs and freqt
for letra in freqs.keys ( ) :
    while ( freqs [ letra ] > 0 and letra in freqt and freqt [ letra ] > 0 ) :
        yay += 1  # Incrementing yay if characters match
        freqs [ letra ] -= 1  # Decrementing the count in freqs
        freqt [ letra ] -= 1  # Decrementing the count in freqt

# Counting whoops by transforming characters to match
for letra in freqs.keys ( ) :
    while ( freqs [ letra ] > 0 ) :
        if letra.islower ( ) and letra.upper ( ) in freqt.keys ( ) and freqt [ letra.upper ( ) ] > 0 :
            whoops += 1  # Incrementing whoops if transformation is possible
            freqs [ letra ] -= 1  # Decrementing the count in freqs
            freqt [ letra.upper ( ) ] -= 1  # Decrementing the count in freqt
        elif letra.isupper ( ) and letra.lower ( ) in freqt.keys ( ) and freqt [ letra.lower ( ) ] > 0 :
            whoops += 1  # Incrementing whoops if transformation is possible
            freqs [ letra ] -= 1  # Decrementing the count in freqs
            freqt [ letra.lower ( ) ] -= 1  # Decrementing the count in freqt
        else :
            break ;  # Breaking the loop if no more transformations are possible

print ( yay , whoops )  # Printing the final counts of yay and whoops
