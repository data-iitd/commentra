public class Main {
    public static void main(String[] args) {
        String LUCKY = "abcd";
        // Define a string LUCKY containing the characters "abcd"

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        // Take an integer input n from the user

        StringBuilder s = new StringBuilder();
        // Initialize a StringBuilder s to store the result

        for (int i = 0; i < n; i++) {
            // Loop n times to construct the string s
            s.append(LUCKY.charAt(i % 4));
            // Append a character from LUCKY to s based on the index i modulo 4
        }

        System.out.println(s.toString());
        // Print the final string s
    }
}
