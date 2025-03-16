
import java.util.ArrayList; # Importing ArrayList class from java.util package
import java.util.LinkedList; # Importing LinkedList class from java.util package
import java.util.Scanner; # Importing Scanner class from java.util package

public class Main:
    public static void main(String[] args):
        Scanner sc = new Scanner(System.in); # Creating a Scanner object to read input from the standard input stream
        long a = sc.nextLong(); # Reading a long integer 'a' from the input
        String b = sc.next(); # Reading a string 'b' from the input
        
        char[] bChar = b.toCharArray(); # Converting the string 'b' to a character array
        int length = bChar.length; # Getting the length of the character array
        String bStr = ""; # Initializing an empty string to store the filtered characters of 'b'
        
        # Looping through the character array 'bChar' to build the string 'bStr' without periods
        for i in range(length):
            if bChar[i] != '.':
                bStr += bChar[i]; # Appending non-period characters to 'bStr'
        
        int bInt = Integer.parseInt(bStr); # Parsing 'bStr' as an integer
        long result = (a * bInt) / 100; # Calculating the result of (a * bInt) / 100
        System.out.println(result); # Printing the result to the standard output

