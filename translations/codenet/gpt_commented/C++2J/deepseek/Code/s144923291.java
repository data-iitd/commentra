public class Main {
    public static void main(String[] args) {
        // Read height and width of the grid
        int h, w;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        h = scanner.nextInt();
        w = scanner.nextInt();

        // Initialize a temporary character array and the target string
        char[] t = new char[10];
        char[] s = "snuke".toCharArray();

        // Iterate through the grid to find the target string
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // Read the current string from input
                scanner.next(t);
                // Check if the current string matches the target string
                if (java.util.Arrays.equals(s, t)) {
                    // If found, calculate the position and print it
                    char c = (char) ('A' + j); // Convert column index to character
                    System.out.println(c + "" + (i + 1)); // Output the position in the required format
                    return; // Exit the program after finding the target
                }
            }
        }

        // Return 0 to indicate successful execution
    }
}
