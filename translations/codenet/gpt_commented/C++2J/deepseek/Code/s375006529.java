public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();
        
        // Get the size of the input string
        int n = s.length();
        
        // Initialize an array to count occurrences of each character (a-z)
        int[] v = new int[26];
        
        // Count the frequency of each character in the string
        for (int i = 0; i < n; i++) {
            v[s.charAt(i) - 'a']++; // Increment the count for the corresponding character
        }
        
        // Assume the answer is "Yes" initially
        String ans = "Yes";
        
        // Check if each character's count is even
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 != 0) { // If any character has an odd count
                ans = "No"; // Set answer to "No"
                break; // Exit the loop early as we found an odd count
            }
        }
        
        // Output the result
        System.out.println(ans);
    }
}
