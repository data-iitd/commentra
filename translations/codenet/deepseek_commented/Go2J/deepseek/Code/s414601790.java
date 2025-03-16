public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of characters in the string
        String s = scanner.next(); // Read the input string

        int max = 0; // Initialize max to 0, this will store the maximum value of cnt
        int cnt = 0; // Initialize cnt to 0, this will keep track of the count of 'I' minus 'D'
        for (int i = 0; i < n; i++) { // Loop through each character in the string s
            char r = s.charAt(i); // Get the character at position i in the string s
            if (r == 'I') { // If the character is 'I'
                cnt++; // Increment cnt
            } else { // If the character is 'D'
                cnt--; // Decrement cnt
            }

            if (cnt > max) { // Check if the current cnt is greater than max
                max = cnt; // Update max to be equal to cnt
            }
        }

        System.out.println(max); // Print the maximum value of cnt encountered
    }
}
