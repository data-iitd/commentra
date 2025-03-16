import java.util.Scanner;

public class Main {
    // Function to calculate 2 raised to the power of a given number
    static int pow2(int a) {
        int ret = 1; // Initialize result to 1
        for (int i = 0; i < a; i++) ret *= 2; // Multiply result by 2 for each iteration of the loop
        return ret; // Return the final result
    }

    // Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
    static int count(int[][] hw, int a, int b) {
        int sum = 0; // Initialize sum to 0
        for (int i = 0; i < hw.length; i++) { // Iterate through each row of the 2D grid
            for (int j = 0; j < hw[0].length; j++) { // Iterate through each column of the current row
                if ((a & (1 << i)) != 0 && (b & (1 << j)) != 0 && hw[i][j] == 1) {
                    sum++; // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
                }
            }
        }
        return sum; // Return the final sum
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt(); // Read height
        int w = scanner.nextInt(); // Read width
        int k = scanner.nextInt(); // Read target count
        int[][] hw = new int[h][w]; // Initialize 2D grid with zeroes

        for (int i = 0; i < h; i++) { // Iterate through each row of the 2D grid
            String row = scanner.next(); // Read the current row as a string
            for (int j = 0; j < w; j++) { // Iterate through each column of the current row
                if (row.charAt(j) == '#') hw[i][j] = 1; // If the character is '#', set the corresponding cell in the grid to 1
            }
        }

        int sum = 0; // Initialize sum to 0
        for (int i = 0; i < pow2(h); i++) { // Iterate through all possible binary combinations of height
            for (int j = 0; j < pow2(w); j++) { // Iterate through all possible binary combinations of width
                if (count(hw, i, j) == k) sum++; // If the number of 1's in the current combination matches the target count, increment sum
            }
        }
        System.out.println(sum); // Output the final sum to standard output
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
