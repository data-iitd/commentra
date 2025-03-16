import sys ; // Importing the sys module for reading input

def main ( ):
    N = int ( sys.stdin.readline ( ).strip ( ) ) ; // Reading the first integer input, which represents the number of elements in the array W
    L = int ( sys.stdin.readline ( ).strip ( ) ) ; // Reading the first integer parameter, which represents the length of the first segment
    R = int ( sys.stdin.readline ( ).strip ( ) ) ; // Reading the second integer parameter, which represents the length of the second segment
    QL = int ( sys.stdin.readline ( ).strip ( ) ) ; // Reading the first integer query, which represents the length of the first query segment
    QR = int ( sys.stdin.readline ( ).strip ( ) ) ; // Reading the second integer query, which represents the length of the second query segment

    W = [ int ( x ) for x in sys.stdin.readline ( ).strip ( ).split ( " " ) ] ; // Creating an integer array W of size N
    sum = [ 0 ] * ( N + 1 ) ; // Creating an integer array sum of size N+1

    for n in range ( N ) : sum [ n + 1 ] = sum [ n ] + W [ n ] ; // Calculating the sum of all elements from 0 to n+1

    min = 2 ** 63 - 1 ; // Initializing the minimum value to be the maximum long value

    for firstR in range ( N + 1 ) : # Iterating through all possible starting indices for the right segment
        lCount = firstR ; # The length of the left segment is equal to the index of the starting point of the right segment
        rCount = N - lCount ; # The length of the right segment is equal to the total length of the array minus the length of the left segment

        cand = sum [ lCount ] * L + ( sum [ N ] - sum [ lCount ] ) * R ; # Calculating the candidate value for the current combination of left and right segments

        llCount = max ( 0, lCount - rCount - 1 ) ; # Calculating the length of the overlapping part between the left and right segments, if any
        rrCount = max ( 0, rCount - lCount - 1 ) ; # Calculating the length of the overlapping part between the right and left segments, if any

        cand += llCount * QL ; # Adding the contribution of the left overlapping part to the candidate value
        cand += rrCount * QR ; # Adding the contribution of the right overlapping part to the candidate value

        min = min ( cand, min ) ; # Updating the minimum value if the current candidate value is smaller

    print ( min ) ; # Printing the minimum value as the output

if __name__ == '__main__' : main ( )

