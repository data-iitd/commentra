
# Importing the Java Utility Package
import java.util.* ;

# Defining the Main class
class Main:
    # Main method to start the program
    def main ( self ) :
        sc = Scanner ( System.in ) ;  # Creating a Scanner object to read input from the console

        n = sc.nextInt ( ) ;  # Reading the number of test cases from the console

        map = TreeMap ( ) ;  # Creating an empty TreeMap to store the frequency of each number

        while ( n -- > 0 ) :  # Loop through each test case
            num = sc.nextInt ( ) ;  # Reading the number from the console

            if ( map.lowerKey ( num ) == None ) :  # If the number is not present in the TreeMap
                val = map.getOrDefault ( num, 0 ) ;  # Get the initial value of the number from the TreeMap or set it to 0 if not present
                map.put ( num, val + 1 ) ;  # Increment the value of the number in the TreeMap
            else :  # If the number is already present in the TreeMap
                key = map.lowerKey ( num ) ;  # Get the key (previous number) from the TreeMap
                val = map.get ( key ) ;  # Get the value (frequency) of the previous number from the TreeMap

                if ( val == 1 ) :  # If the frequency of the previous number is 1
                    map.remove ( key ) ;  # Remove the previous number from the TreeMap
                else :  # If the frequency of the previous number is greater than 1
                    map.put ( key, val - 1 ) ;  # Decrement the frequency of the previous number in the TreeMap

                val = map.getOrDefault ( num, 0 ) ;  # Get the initial value of the current number from the TreeMap or set it to 0 if not present
                map.put ( num, val + 1 ) ;  # Increment the value of the current number in the TreeMap

        ans = 0 ;  # Initializing the answer variable to 0

        for key in map.keySet ( ) :  # Iterating through each key (number) in the TreeMap
            val = map.get ( key ) ;  # Getting the value (frequency) of the current number from the TreeMap
            ans += val ;  # Adding the frequency of the current number to the answer

        print ( ans ) ;  # Printing the answer to the console

# 