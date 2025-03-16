
import java.util.* ; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program is run
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream

        Integer n = Integer.valueOf ( sc.nextLine ( ) ) ; // Reading the first line of input which is an integer representing the number of elements in the arrays
        String vStr = sc.nextLine ( ) ; // Reading the second line of input which is a string representing the values array
        Map<Integer, Integer> vList = str2List(vStr) ; // Converting the string representation of the values array to a Map using the str2List method

        String cStr = sc.nextLine ( ) ; // Reading the third line of input which is a string representing the costs array
        Map<Integer, Integer> cList = str2List(cStr) ; // Converting the string representation of the costs array to a Map using the str2List method

        Integer max = 0 ; // Initializing the variable max to 0

        for ( Integer i = 0 ; i < n ; i ++ ) { // Iterating through each element in the arrays using a for loop
            Integer profit = vList.get(i) - cList.get(i) ; // Calculating the profit for the current element by subtracting the cost from the value
            if ( profit > 0 ) { // Checking if the profit is positive
                max += profit ; // If the profit is positive, adding it to the max variable
            }
        }

        System.out.println(max) ; // Printing the maximum profit to the standard output stream
    }

    static Map<Integer, Integer> str2List(String str) { // Defining the str2List method that converts a string representation of an array to a Map
        String[] vArrStr = str.split(" ") ; // Splitting the string into an array of strings using the space character as a delimiter
        Map<Integer, Integer> ret = new HashMap<>() ; // Creating an empty HashMap to store the key-value pairs
        Integer key = 0 ; // Initializing the key variable to 0

        for ( String val : vArrStr ) { // Iterating through each string in the array using an enhanced for loop
            ret.put(key, Integer.valueOf(val)) ; // Adding each string to the HashMap as a key-value pair, where the key is an integer and the value is the integer value of the string
            key++ ; // Incrementing the key variable for the next iteration
        }

        return ret ; // Returning the HashMap
    }
}

