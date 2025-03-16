import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the first string S from the input
        String S = scanner.nextLine();
        
        // Read the second string T from the input
        String T = scanner.nextLine();
        
        // Initialize min to the maximum possible integer value
        int min = Integer.MAX_VALUE;
        
        // Loop through the string S to find all substrings of length equal to T
        for(int i = 0; i <= S.length() - T.length(); i++) {
            // Calculate the minimum number of character differences between the substring of S and T
            min = Math.min(min, find(S.substring(i, i + T.length()), T));
        }
        
        // Check if min was updated; if so, print the minimum differences found
        if(min != Integer.MAX_VALUE) {
            System.out.println(min);
        } else {
            // If no valid substring was found, print the length of T
            System.out.println(T.length());
        }
    }

    // Method to calculate the number of differing characters between two strings of equal length
    public static int find(String a, String b) {
        int calc = 0;
        
        // Loop through each character of the strings a and b
        for(int x = 0; x < a.length(); x++) {
            // Increment calc for each differing character
            if(a.charAt(x) != b.charAt(x)) {
                calc++;
            }
        }
        
        // Return the total count of differing characters
        return calc;
    }
}
