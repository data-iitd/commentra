public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();
        
        // Declare variables to store the positions of 'A' and 'Z'
        int a = -1, z = -1;
        
        // Loop through the string to find the first occurrence of 'A'
        for(int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                a = i; // Store the index of 'A'
                break; // Exit the loop once 'A' is found
            }
        }
        
        // Loop through the string in reverse to find the last occurrence of 'Z'
        for(int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == 'Z') {
                z = i; // Store the index of 'Z'
                break; // Exit the loop once 'Z' is found
            }
        }
        
        // Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
        System.out.println(z - a + 1);
    }
}
