
import sys
import math

def main ( ):
    # Create a FastReader object to read input
    fast_reader = FastReader ( )
    # Create a PrintWriter object to write output
    print_writer = PrintWriter ( sys.stdout )

    # Read an integer input
    x = fast_reader.nextInt ( )
    # Initialize a counter to keep track of the number of iterations
    count = 0
    # Store the initial value of x in a temporary variable
    tmp = x

    # Initialize x to 0 to start the loop
    x = 0

    # Loop until x becomes 360
    while x != 360:
        # Increment x by tmp
        x = x + tmp
        # If x exceeds 360, adjust it by subtracting 360
        if x > 360:
            x = x - 360
        # Increment the counter
        count += 1

    # Print the final count
    print_writer.println ( count )

    # Close the PrintWriter object
    print_writer.close ( )

class FastReader:
    def __init__ ( self ):
        self.br = BufferedReader ( InputStreamReader ( System.in ) )

    def next ( self ):
        while self.st == None or not self.st.hasMoreElements ( ):
            try:
                self.st = StringTokenizer ( self.br.readLine ( ) )
            except IOException as e:
                e.printStackTrace ( )

        return self.st.nextToken ( )

    def nextInt ( self ):
        return int ( self.next ( ) )

    def nextLong ( self ):
        return long ( self.next ( ) )

    def nextDouble ( self ):
        return float ( self.next ( ) )

    def nextLine ( self ):
        str = ""
        try:
            str = self.br.readLine ( )
        except IOException as e:
            e.printStackTrace ( )

        return str

class PrintWriter:
    def __init__ ( self, out ):
        self.out = out

    def println ( self, data ):
        self.out.write ( str ( data ) + "\n" )

    def close ( self ):
        self.out.close ( )

if __name__ == "__main__":
    main ( )

