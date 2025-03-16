import java.util.Scanner; 

public class Main { 
    // Declare a static Scanner object for input
    static Scanner scanner; 
    
    public static void main(String[] args) { 
        // Initialize the Scanner object to read input from the console
        scanner = new Scanner(System.in); 
        
        // Read an integer N from the user
        int N = gi(); 
        
        // Initialize a long variable i starting from 357
        long i = 357; 
        
        // Initialize a counter to keep track of valid numbers
        int c = 0; 
        
        // Loop until i exceeds N
        while (i <= N) { 
            // Convert the current number i to a String
            String s = String.valueOf(i); 
            
            // Check if the string contains '3', '5', and '7'
            if (s.contains("3") && s.contains("5") && s.contains("7")) 
                c++; // Increment the counter if all digits are present
            
            // Create a StringBuilder to construct a new number
            StringBuilder sb = new StringBuilder(); 
            boolean f = false; // Flag to indicate if a replacement has occurred
            
            // Iterate through the digits of the number in reverse order
            for (int j = 0; j < s.length(); j++) { 
                char a = s.charAt(s.length() - 1 - j); // Get the current digit
                
                // If a replacement has occurred, append the digit as is
                if (f) { 
                    sb.append(a); 
                } else { 
                    // Replace '3' with '5' and set the flag
                    if (a == '3') { 
                        sb.append('5'); 
                        f = true; 
                    } 
                    // Replace '5' with '7' and set the flag
                    else if (a == '5') { 
                        sb.append('7'); 
                        f = true; 
                    } 
                    // If it's neither, append '3'
                    else { 
                        sb.append('3'); 
                    } 
                } 
            } 
            
            // If no replacement occurred, append '3' to the StringBuilder
            if (!f) 
                sb.append(3); 
            
            // Reverse the constructed number and parse it back to long
            StringBuffer sb2 = new StringBuffer(sb); 
            i = Long.parseLong(sb2.reverse().toString()); 
        } 
        
        // Print the total count of valid numbers found
        System.out.println(c); 
    } 
    
    // Method to read a String input from the user
    public static String gs() { 
        return scanner.next(); 
    } 
    
    // Method to read an integer input from the user
    public static int gi() { 
        return Integer.parseInt(scanner.next()); 
    } 
    
    // Method to read a long input from the user
    public static long gl() { 
        return Long.parseLong(scanner.next()); 
    } 
    
    // Method to read a double input from the user
    public static double gd() { 
        return Double.parseDouble(scanner.next()); 
    } 
}
