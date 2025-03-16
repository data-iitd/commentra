
import sys ; // For handling standard I/O

class Main:
  # Main method to start the program
  def main ( self ) :
    input = sys.stdin ; # Input stream to read input from standard input
    output = sys.stdout ; # Output stream to write output to standard output
    in = InputReader ( input ) ; # Initialize InputReader
    out = PrintWriter ( output ) ; # Initialize PrintWriter

    solver = CColoringColorfully ( ) ; # Initialize solver object
    solver.solve ( 1, in, out ) ; # Solve the problem and print the output

    out.close ( ) ; # Close the PrintWriter

  # Static inner class to solve the problem
  class CColoringColorfully:
    def solve ( self, testNumber, in, out ) :
      x = in.next ( ) ; # Read the input string
      a = x ; # Create a string 'a' with the same string as 'x'
      b = x ; # Create a string 'b' with the same string as 'x'
      a1 = 0 ; # Initialize counter for number of consecutive '1's in string 'a'
      a2 = 0 ; # Initialize counter for number of consecutive '1's in string 'b'

      # Loop through each character in string 'a' starting from index 1
      for i in range ( 1, len ( x ) ) :
        if ( a [ i ] == a [ i - 1 ] ) : # Check if current character is same as previous character
          if ( a [ i ] == '1' ) : a = a [ 0 : i ] + '0' + a [ i + 1 : ] ; # If '1', change it to '0'
          else : a = a [ 0 : i ] + '1' + a [ i + 1 : ] ; # If not '1', change it to '1'
          a1 += 1 ; # Increment counter for number of consecutive '1's

      # Loop through each character in string 'b' starting from the last character
      for i in range ( len ( x ) - 1, 0, -1 ) :
        if ( b [ i ] == b [ i - 1 ] ) : # Check if current character is same as previous character
          if ( b [ i - 1 ] == '1' ) : b = b [ 0 : i - 1 ] + '0' + b [ i : ] ; # If '1', change it to '0'
          else : b = b [ 0 : i - 1 ] + '1' + b [ i : ] ; # If not '1', change it to '1'
          a2 += 1 ; # Increment counter for number of consecutive '1's

      # Print the minimum number of consecutive '1's in strings 'a' and 'b'
      out.println ( min ( a1, a2 ) ) ;

  # Static inner class to read input
  class InputReader:
    def __init__ ( self, stream ) :
      self.reader = BufferedReader ( stream ) ;
      self.tokenizer = None ;

    def next ( self ) :
      while self.tokenizer == None or not self.tokenizer.hasMoreTokens ( ) :
        try :
          self.tokenizer = StringTokenizer ( self.reader.readLine ( ) ) ;
        except IOException as e :
          raise RuntimeException ( e ) ;
      return self.tokenizer.nextToken ( ) ;

