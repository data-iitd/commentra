
import math

def main ( ):
    try:
        n = int ( input ( "Enter a number: " ) )

        # Calculating the square root of the given number
        sqrt = int ( math.sqrt ( n ) )

        # Initializing the answer variable to 0
        answer = 0

        # Checking for prime factors of the given number
        for i in range ( 2 , sqrt + 1 ):
            count = 0
            while ( n % i == 0 ):
                n /= i
                count += 1

            # Calculating the contribution of the current prime factor to the answer
            for j in range ( 1 , count + 1 ):
                count -= j
                answer += 1

        # Checking for the remaining prime factor (if any)
        if ( n > 1 ):
            answer += 1

        # Printing the result
        print ( answer )

    except ValueError:
        print ( "Error: Invalid input" )

if __name__ == "__main__":
    main ( )

