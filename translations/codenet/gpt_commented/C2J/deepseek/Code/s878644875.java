public class Main {
    public static void main(String[] args) {
        // Declare two character arrays to hold the input strings
        char[] s = new char[4];
        char[] t = new char[4];
        
        // Read the first string from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String input = scanner.next();
        for (int i = 0; i < 3; i++) {
            s[i] = input.charAt(i);
        }
        
        // Read the second string from user input
        input = scanner.next();
        for (int i = 0; i < 3; i++) {
            t[i] = input.charAt(i);
        }
        
        // Initialize a counter to keep track of matching characters
        int hit = 0;
        
        // Loop through the first three characters of both strings
        for (int i = 0; i < 3; i++) {
            // Check if the characters at the same position in both strings match
            if (s[i] == t[i]) 
                hit++; // Increment the hit counter if there's a match
        }
        
        // Output the total number of matching characters
        System.out.println(hit);
        
        // Return 0 to indicate successful completion of the program
        return;
    }
}
