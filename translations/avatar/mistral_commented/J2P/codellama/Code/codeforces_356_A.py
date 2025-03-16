
import sys
import math

def main ( ) :
    # Initializing FastReader for reading input
    in = FastReader ( )

    n = in.nextInt ( )  # Reading the number of elements in the array

    left = set ( )  # Creating a set to store the indices of elements in the sorted order
    answer = [ -1 ] * n  # Creating an array to store the answer for each index

    # Adding all the indices to the set and initializing the answer array with -1
    for i in range ( n ) :
        left.add ( i )
        answer [ i ] = -1

    q = in.nextInt ( )  # Reading the number of queries

    # Processing each query
    while q > 0 :
        l = in.nextInt ( ) - 1  # Reading the left index of the query range
        r = in.nextInt ( ) - 1  # Reading the right index of the query range
        win = in.nextInt ( )  # Reading the winning index

        # Updating the answer for the winning index and all the indices between the left and right indices
        while left.ceiling ( l ) != None and left.ceiling ( l ) <= r :
            curr = left.ceiling ( l )
            answer [ curr ] = win
            left.remove ( curr )

        # Updating the answer for the winning index in the answer array
        answer [ win - 1 ] = 0

        # Adding the winning index back to the set
        left.add ( win - 1 )

        q -= 1

    ans = ""  # Creating a string to store the answer

    # Printing the answer for each index in the answer array
    for i in range ( n ) :
        ans += str ( answer [ i ] )
        if i != n - 1 :
            ans += " "

    print ( ans )  # Printing the answer as a single line

class FastReader:
    def __init__ ( self ) :
        self.br = sys.stdin

    def next ( self ) :
        while True :
            try :
                st = self.br.readline ( )
                st = st.strip ( )
                st = st.split ( )
                break
            except :
                pass
        return st

    def nextInt ( self ) :
        return int ( self.next ( ) [ 0 ] )

    def nextLong ( self ) :
        return long ( self.next ( ) [ 0 ] )

    def nextDouble ( self ) :
        return float ( self.next ( ) [ 0 ] )

    def nextLine ( self ) :
        st = ""
        while True :
            try :
                st = self.br.readline ( )
                st = st.strip ( )
                break
            except :
                pass
        return st

if __name__ == "__main__" :
    main ( )

