import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    // Function to calculate 2 raised to the power of a given number
    public static int pow2(int a) {
        int ret = 1; // Initialize result to 1
        for (int i = 0; i < a; i++) ret *= 2; // Multiply result by 2 for each iteration of the loop
        return ret; // Return the final result
    }

    // Function to count the number of 1's in the given 2D grid that match the binary representation of a and b
    public static int count(List<List<Integer>> hw, int a, int b) {
        int sum = 0; // Initialize sum to 0
        for (int i = 0; i < hw.size(); i++) { // Iterate through each row of the 2D grid
            for (int j = 0; j < hw.get(0).size(); j++) { // Iterate through each column of the current row
                if ((a & (1 << i)) != 0 && (b & (1 << j)) != 0 && hw.get(i).get(j) == 1) sum++; // If the bits at the corresponding positions in a and b are set and the corresponding cell in the grid is 1, increment sum
            }
        }
        return sum; // Return the final sum
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt(); // Read input value for height from standard input
        int w = scanner.nextInt(); // Read input value for width from standard input
        int k = scanner.nextInt(); // Read input value for target count from standard input
        List<List<Integer>> hw = new ArrayList<>(); // Initialize 2D grid
        for (int i = 0; i < h; i++) { // Iterate through each row of the 2D grid
            List<Integer> row = new ArrayList<>(); // Initialize a row
            for (int j = 0; j < w; j++) { // Iterate through each column of the current row
                char c = scanner.next().charAt(0); // Read the character from standard input
                if (c == '#') row.add(1); // If the character is '#', add 1 to the row
                else row.add(0); // Otherwise, add 0 to the row
            }
            hw.add(row); // Add the row to the grid
        }
        int sum = 0; // Initialize sum to 0
        for (int i = 0; i < pow2(h); i++) { // Iterate through all possible binary combinations of height
            for (int j = 0; j < pow2(w); j++) { // Iterate through all possible binary combinations of width
                if (count(hw, i, j) == k) sum++; // If the number of 1's in the current combination matches the target count, increment sum
            }
        }
        System.out.println(sum); // Output the final sum to standard output
    }
}
