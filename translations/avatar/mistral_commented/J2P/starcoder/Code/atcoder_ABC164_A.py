import java.util.* ;  # Importing the Java utility package for Scanner class

def main ( ):  # Main method definition
    scan = Scanner ( System.in ) ;  # Creating a new Scanner object to read input from the console
    scList = ArrayList ( ) ;  # Creating an empty ArrayList to store the input lines

    # The following for loop reads input lines from the console and stores them in the ArrayList
    for i in range ( 0, -1 ):
        try:
            scList.add ( scan.nextLine ( ) ) ;  # Reading the next line from the console and adding it to the ArrayList
        except Exception as e:
            break ;  # Exiting the loop if an exception occurs during input reading

    # The following line extracts the first line of the input (which contains the number of sheep and wolves)
    numlist = scList.get ( 0 ).split ( " " ) ;

    # The following two lines parse the first two elements of the numlist array as integers representing the number of sheep and wolves
    Sheep = int ( numlist [ 0 ] ) ;
    Wolve = int ( numlist [ 1 ] ) ;

    # The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
    # If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
    if ( Wolve >= Sheep ) :
        print ( "unsafe" ) ;  # Printing the message "unsafe" to the console
    else:
        print ( "safe" ) ;  # Printing the message "safe" to the console

main ( ) ;  # Calling the main method

