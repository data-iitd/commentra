import sys ; // Importing the sys module for reading the input

class Box: # Defining the Box class
    def __init__ ( self, n, r ): # Constructor for initializing the Box object
        self.num = n ;
        self.red = r ;

    # Method for moving the box to another box
    def moveTo ( self, other ):
        if ( self.num ==0 ): # If the current box is empty
            return ; # Do nothing
        elif ( self.num == 1 ): # If the current box has only one item
            self.num = 0 ; # Setting the current box to be empty
            other.num += 1 ; # Incrementing the number of items in the other box
            if ( self.red ): # If the current box was red
                other.red = True ; # Setting the other box to be red
            self.red = False ; # Setting the current box to be empty and not red
        else: # If the current box has more than one item
            self.num -= 1 ; # Decrementing the number of items in the current box
            other.num += 1 ; # Incrementing the number of items in the other box
            if ( self.red ): # If the current box was red
                other.red = True ; # Setting the other box to be red

def main ( ): # Defining the main function
    N = int ( sys.stdin.readline ( ) ) # Reading the first integer input from the user (number of boxes)
    M = int ( sys.stdin.readline ( ) ) # Reading the second integer input from the user (number of moves)
    B = [ ] ; # Creating an empty array of Box objects

    # Initializing the first box with red color
    B.append ( Box ( 1, True ) )

    # Initializing the remaining boxes with red color set to false
    for i in range ( 1, N ):
        B.append ( Box ( 1, False ) )

    # Reading the moves from the user and performing them on the boxes
    for i in range ( 0, M ):
        x = int ( sys.stdin.readline ( ) ) - 1 # Reading the x-coordinate of the source box
        y = int ( sys.stdin.readline ( ) ) - 1 # Reading the y-coordinate of the destination box
        B [ x ].moveTo ( B [ y ] ) # Moving the box at index x to the box at index y

    # Counting the number of red boxes
    counter = 0 ;
    for b in B: # Iterating through all the boxes in the array
        if ( b.red ): # If the current box has red color
            counter += 1 ; # Increment the counter

    # Printing the result
    print ( counter ) ;

if __name__ == "__main__": # Checking if the file is being run directly
    main ( ) ;

