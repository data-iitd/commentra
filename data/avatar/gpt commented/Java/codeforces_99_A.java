import java.util.Scanner; 
import java.util.ArrayList; 
import java.util.Arrays; 
import java.math.BigInteger; 

public class Main { 
    public static void main(String[] args) { 
        // Read input from the user and convert it to a character array
        char[] str = new Scanner(System.in).nextLine().toCharArray(); 
        
        // Initialize variable to store the index of the decimal point
        int dotIndex = 0; 
        
        // Find the index of the decimal point in the input
        for (int i = 0; i < str.length; i++) {
            if (str[i] == '.') { 
                dotIndex = i; 
                break; 
            } 
        } 
        
        // Check if the digit before the decimal point is '9'
        if (str[dotIndex - 1] == '9') { 
            // If it is, print a specific message
            System.out.println("GOTO Vasilisa."); 
        } 
        // Check if the digit after the decimal point is greater than 4
        else if (Integer.parseInt(str[dotIndex + 1] + "") > 4) { 
            // If it is, create a new string from the integer part and add 1
            String _str = ""; 
            for (int i = 0; i < dotIndex; i++) 
                _str += str[i]; 
            // Print the incremented value
            System.out.println(new BigInteger(_str).add(new BigInteger("1")).toString()); 
        } 
        // If the digit after the decimal point is 4 or less
        else { 
            // Print the integer part as it is
            for (int i = 0; i < dotIndex; i++) 
                System.out.print(str[i]); 
            System.out.println(); 
        } 
    } 
}
