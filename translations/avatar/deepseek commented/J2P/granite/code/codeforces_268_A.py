

n = int ( input ( ) ) 
h = [ ] 
g = [ ] 

for i in range ( n ) : 
    h_i, g_i = map ( int, input ( ).split ( ) ) 
    h. append ( h_i ) 
    g. append ( g_i ) 

result = 0 

for i in range ( n ) : 
    for j in range ( n ) : 
        if ( h [ i ] == g [ j ] ) : 
            result += 1 

print ( result ) 
