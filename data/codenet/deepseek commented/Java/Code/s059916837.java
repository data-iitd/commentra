import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the first string S from the user
        String S = scanner.nextLine();
        
        // Read the second string T from the user
        String T = scanner.nextLine();
        
        // Initialize min to the maximum possible integer value
        int min = Integer.MAX_VALUE;
        
        // Loop through possible substrings of S that are of the same length as T
        for(int i = 0; i <= S.length() - T.length(); i++) {
            // Calculate the number of differences between the substring and T
            // and update min with the minimum number of differences found
            min = Math.min(min, find(S.substring(i, i + T.length()), T));
        }
        
        // Check if a match was found and print the minimum number of differences
        if(min != Integer.MAX_VALUE) {
            System.out.println(min);
        } else {
            // If no match is found, print the length of T
            System.out.println(T.length());
        }
    }

    // Method to calculate the number of differences between two strings
    public static int find(String a, String b) {
        // Initialize calc to 0 to count the number of differences
        int calc = 0;
        
        // Loop through the characters of the strings and count differences
        for(int x = 0; x < a.length(); x++) {
            if(a.charAt(x) != b.charAt(x)) {
                calc++;
            }
        }
        
        // Return the number of differences found
        return calc;
    }
}