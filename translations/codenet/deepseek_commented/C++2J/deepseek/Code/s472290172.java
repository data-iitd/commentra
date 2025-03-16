public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.nextLine(); // Read the input string from the standard input.

        int max = 0, cnt = 0;
        // Initialize max and cnt to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence, respectively.

        for (char sc : str.toCharArray()) {
            // Iterate over each character in the string.
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                // Check if the character is one of 'A', 'C', 'G', or 'T'.
                cnt++; // If it is, increment the cnt variable.
            } else {
                cnt = 0; // If not, reset cnt to 0.
            }
            max = Math.max(max, cnt); // After each character, update max to be the maximum of max and cnt.
        }

        System.out.println(max); // Print the value of max to the standard output.
    }
}
