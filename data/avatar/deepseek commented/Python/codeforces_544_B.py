
n , k = map ( int , input ( ).split ( ) )  # Read input for n and k
x = 0  # Initialize x to 0

# Check if k is within the feasible range for placing 'L' characters
if k <= max ( n ** 2 // 2 , n ** 2 - ( n ** 2 // 2 ) ) :
    print ( 'YES' )  # Print 'YES' if k is feasible
    for i in range ( n ) :  # Loop through each row
        for j in range ( n ) :  # Loop through each column
            if i % 2 == j % 2 and x < k :  # Check if the cell should be 'L'
                print ( 'L' , end = '' )  # Print 'L'
                x += 1  # Increment x
            else : print ( 'S' , end = '' )  # Print 'S' otherwise
        print ( )  # Move to the next line after each row
else : print ( 'NO' )  # Print 'NO' if k is not feasible

