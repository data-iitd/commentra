import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of test cases
        int n = sc.nextInt();
        
        // Define a string of characters corresponding to the keys on a mobile keypad
        String[] s = ".,!? :abc:def:ghi:jkl:mno:pqrs:tuv:wxyz".split(":");
        
        // Create a 2D array to hold the characters for each key
        char[][] k = new char[9][];
        
        // Populate the 2D array with characters from the string
        for (int i = 0; i < 9; i++) {
            k[i] = s[i].toCharArray();
        }
        
        // Process each test case
        while (n-- > 0) {
            // Read the input as a character array
            char[] c = sc.next().toCharArray();
            
            // Initialize variables to track the current key and character position
            int l = -1, a = 0;
            
            // Iterate through each character in the input
            for (int i = 0; i < c.length; i++) {
                // If the character is not '0', determine the key pressed
                if (c[i] != '0') {
                    a = c[i] - '1'; // Convert character to corresponding key index
                    l = (l + 1) % k[a].length; // Move to the next character in the key
                } 
                // If the character is '0' and we have a valid character position
                else if (l >= 0) {
                    // Print the character corresponding to the current key and position
                    System.out.print(k[a][l]);
                    l = -1; // Reset position for the next character
                }
            }
            // Print a newline after processing each test case
            System.out.println();
        }
    }
}
