s, t = input ( ), input ( )
freqs = make ( map ( func ( ) string { return string ( ) }, s ) )
freqt = make ( map ( func ( ) string { return string ( ) }, t ) )
yay, whoops = 0, 0
for letra in s :
    freqs [ letra ] += 1
for letra in t :
    freqt [ letra ] += 1
for letra in freqs :
    while ( freqs [ letra ] > 0 and letra in freqt and freqt [ letra ] > 0 ) :
        yay += 1
        freqs [ letra ] -= 1
        freqt [ letra ] -= 1
for letra in freqs :
    while ( freqs [ letra ] > 0 ) :
        if letra.islower ( ) and letra.upper ( ) in freqt and freqt [ letra.upper ( ) ] > 0 :
            whoops += 1
            freqs [ letra ] -= 1
            freqt [ letra.upper ( ) ] -= 1
        elif letra.isupper ( ) and letra.lower ( ) in freqt and freqt [ letra.lower ( ) ] > 0 :
            whoops += 1
            freqs [ letra ] -= 1
            freqt [ letra.lower ( ) ] -= 1
        else :
            break ;
print ( yay, whoops )

