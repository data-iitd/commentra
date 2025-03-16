
import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string from the user input
        String s = sc.next();
        
        // Extract the last character of the string and convert it to an integer
        int n = Integer.parseInt(s.substring(s.length()-1,s.length()));
        
        // Check the value of n and print the corresponding string based on the rules
        if (n == 3)
            System.out.println("bon");
        else if (n == 0 || n == 1 || n == 6 || n == 8)
            System.out.println("pon");
        else
            System.out.println("hon");
        
        // Close the Scanner object to free up resources
        sc.close();
    }
}

