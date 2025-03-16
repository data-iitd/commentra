n , L , R , QL , QR = map ( int , input ( ).split ( ) )  # Reading inputs for n, L, R, QL, QR
W = list ( map ( int , input ( ).split ( ) ) )  # Reading the list of weights W

# Calculating the prefix sum of the weights
sum_el = [ 0 ]
for i in range ( 1 , n + 1 ) :
    sum_el.append ( W [ i - 1 ] + sum_el [ i - 1 ] )

# Initial answer calculation based on the formula
answer = QR * ( n - 1 ) + sum_el [ n ] * R

# Loop to calculate energy for each possible split point
for i in range ( 1 , n + 1 ) :
    energy = L * sum_el [ i ] + R * ( sum_el [ n ] - sum_el [ i ] )  # Energy calculation
    if i > ( n - i ) :  # If the left side is heavier
        energy = energy + ( i - ( n - i ) - 1 ) * QL  # Adding QL if needed
    elif ( n - i ) > i :  # If the right side is heavier
        energy = energy + ( ( n - i ) - i - 1 ) * QR  # Adding QR if needed
    if energy < answer :  # Updating the answer if a new minimum energy is found
        answer = energy

print ( answer )  # Output the minimum energy
