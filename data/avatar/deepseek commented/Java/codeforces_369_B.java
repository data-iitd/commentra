import java.util.Arrays; // Importing necessary classes for array operations and input handling
import java.util.Scanner; // Importing necessary classes for input handling

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Initializing a Scanner object to read input from the user
        int n = scan.nextInt(); // Reading the number of elements
        int k = scan.nextInt(); // Reading the number of elements in the first group
        int l = scan.nextInt(); // Reading the lower bound for the points
        int r = scan.nextInt(); // Reading the upper bound for the points
        int sAll = scan.nextInt(); // Reading the total sum of points
        int sk = scan.nextInt(); // Reading the sum of points for the first group
        
        int[] ans = getPoints(n, k, l, r, sAll, sk); // Calling the getPoints method to compute the result
        
        for (int num : ans) { // Iterating through the result array to print each element
            System.out.print(num + " "); // Printing each element followed by a space
        }
    }

    public static int[] getPoints(int n, int k, int l, int r, int sAll, int sk) {
        int[] ans = new int[n]; // Initializing an array to store the result
        Arrays.fill(ans, l); // Filling the array with the lower bound value 'l'
        
        // Subtracting the initial points for the first group and the remaining elements
        sAll -= sk + (n - k) * l;
        sk -= k * l;
        
        // Distributing the remaining points to the first group until sk is zero
        while (sk > 0) {
            int idx = n - 1; // Starting from the last element in the array
            while (sk > 0 && idx >= n - k) {
                ans[idx--]++; // Incrementing the points and moving to the previous element
                sk--; // Decrementing the remaining points to distribute
            }
        }
        
        // Distributing the remaining points to the remaining elements until sAll is zero
        while (sAll > 0) {
            int idx = 0; // Starting from the first element in the array
            while (sAll > 0 && idx < n - k) {
                ans[idx++]++; // Incrementing the points and moving to the next element
                sAll--; // Decrementing the remaining points to distribute
            }
        }
        
        return ans; // Returning the result array
    }
}
