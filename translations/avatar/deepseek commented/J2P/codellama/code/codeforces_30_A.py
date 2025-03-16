
import math

def main ( ): 
    # Step 1: Reading Input Values
    A, B, n = map ( int, input ( ).split ( ) ) 

    # Step 2: Handling Special Case A == 0
    if A == 0: 
        if B == 0: 
            print ( 1 ) 
        else: 
            print ( "No solution" ) 
        return 

    # Step 3: Checking Divisibility
    if B % A != 0: 
        print ( "No solution" ) 
        return 

    # Step 4: Normalizing B
    B //= A 
    neg = B < 0 
    if neg and n % 2 == 0: 
        print ( "No solution" ) 
        return 
    if neg: 
        B = - B 

    # Step 5: Iterating to Find Solution
    for x in range ( 0 , B + 1 ): 
        if math.pow ( x , n ) == B: 
            print ( neg * - x or x ) 
            return 

    # Step 6: No Solution Found
    print ( "No solution" ) 



if __name__ == "__main__": 
    main ( ) 



