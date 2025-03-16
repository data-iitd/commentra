import sys

def main ( ) :
    N = int ( sys.stdin.readline ( ) )
    M = int ( sys.stdin.readline ( ) )
    B = [ ]

    # Initializing the first box with red color
    B.append ( Box ( 1 , True ) )

    # Initializing the remaining boxes with red color set to false
    for i in range ( 1 , N ) :
        B.append ( Box ( 1 , False ) )

    # Reading the moves from the user and performing them on the boxes
    for i in range ( M ) :
        x = int ( sys.stdin.readline ( ) ) - 1
        y = int ( sys.stdin.readline ( ) ) - 1
        B [ x ].moveTo ( B [ y ] )

    # Counting the number of red boxes
    counter = 0
    for b in B :
        if b.red :
            counter += 1

    # Printing the result
    print ( counter )

class Box :
    def __init__ ( self , n , r ) :
        self.num = n
        self.red = r

    # Method for moving the box to another box
    def moveTo ( self , other ) :
        if self.num == 0 :
            return
        elif self.num == 1 :
            self.num = 0
            other.num += 1
            if self.red :
                other.red = True
            self.red = False
        else :
            self.num -= 1
            other.num += 1
            if self.red :
                other.red = True

if __name__ == "__main__" :
    main ( )

