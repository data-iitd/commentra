public class Main {
    public static void main(String[] args) {
        // Read a string from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        // Initialize variables to keep track of the maximum lengths
        int max_tmp = 0;
        int max = 0;

        // Iterate over each character in the string
        for (int i = 0; i < s.length(); i++) {
            boolean flag = false;
            // Check if the character is one of 'A', 'C', 'T', 'G'
            char c = s.charAt(i);
            if (c == 'A' || c == 'C' || c == 'T' || c == 'G') {
                // Increment the temporary maximum length counter
                max_tmp++;
            } else {
                // Set the flag to true if the character is not 'A', 'C', 'T', 'G'
                flag = true;
            }

            // At the end of the loop, if the flag is true, update the overall maximum length
            if (i == s.length() - 1 || flag) {
                if (max < max_tmp) {
                    max = max_tmp;
                }
                // Reset the temporary maximum length counter
                max_tmp = 0;
            }
        }

        // Print the value of the overall maximum length
        System.out.println(max);
    }
}
