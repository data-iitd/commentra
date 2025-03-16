import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a line of input from the user
        String S = sc.nextLine();
        
        // Close the scanner to prevent resource leaks
        sc.close();

        // Check if the length of the string is odd
        if(S.length() % 2 == 1){
            // If odd, remove the last character from the string
            S = S.substring(0, S.length() - 1);
        }
        else{
            // If even, remove the last two characters from the string
            S = S.substring(0, S.length() - 2);
        }

        // Continuously reduce the string by removing the last two characters
        // until the string length is zero or an even string is found
        for(; S.length() > 0; S = S.substring(0, S.length() - 2)){
            // Check if the current string is an even string
            if(isEvenString(S)){
                // If it is, exit the loop
                break;
            }
        }
        
        // Print the length of the remaining string
        System.out.println(S.length());
    }

    // Function to determine if a string of even length is an "even string"
    // An even string is defined as having two equal halves
    static boolean isEvenString(String s){
        // Split the string into two halves
        String a = s.substring(0, s.length()/2);
        String b = s.substring(s.length()/2);
        
        // Check if the two halves are equal
        if(a.equals(b)){
            return true; // Return true if they are equal
        }
        else{
            return false; // Return false if they are not equal
        }
    }
}
