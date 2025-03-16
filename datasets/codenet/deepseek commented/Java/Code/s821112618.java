import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Initialize Scanner to read input
        Scanner sc = new Scanner(System.in);
        // Read the number of test cases
        int n = sc.nextInt();
        // Define the string array and split it using colon as delimiter
        String[] s = ".,!? :abc:def:ghi:jkl:mno:pqrs:tuv:wxyz".split(":");
        // Initialize a 2D character array to store the sequences
        char[][] k = new char[9][];
        // Fill the 2D array with character sequences
        for (int i = 0; i < 9; i++) {
            k[i] = s[i].toCharArray();
        }
        // Start processing each test case
        while (n-- > 0) {
            // Read the input string and convert it to a character array
            char[] c = sc.next().toCharArray();
            // Initialize variables to track the current position and key index
            int l = -1, a = 0;
            // Iterate over each character in the input array
            for (int i = 0; i < c.length; i++) {
                // If the character is not '0'
                if (c[i] != '0') {
                    // Update the key index and calculate the new position
                    a = c[i] - '1';
                    l = (l + 1) % k[a].length;
                } else if (l >= 0) { // If the character is '0' and l is not -1
                    // Print the current character and reset l
                    System.out.print(k[a][l]);
                    l = -1;
                }
            }
            // Print a newline character after processing each test case
            System.out.println();
        }
        // Close the Scanner to free up resources
        sc.close();
    }
}
