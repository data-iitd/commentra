import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements (n) from standard input
        int n = scanner.nextInt();
        // Read the threshold value (x) from standard input
        int x = scanner.nextInt();
        
        // Initialize a list to hold the integers (l)
        ArrayList<Integer> l = new ArrayList<>();
        
        // Loop to read n integers from standard input and add them to the list l
        for (int i = 0; i < n; i++) {
            int tmpL = scanner.nextInt();
            l.add(tmpL);
        }
        
        // Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
        int tmpSum = 0;
        int rs = 0;
        
        // Loop through the list l to calculate the cumulative sum and determine the result
        for (int i = 0; i < n; i++) {
            // Add the current value to the cumulative sum
            tmpSum += l.get(i);
            
            // If the cumulative sum is less than or equal to x, update the result
            if (tmpSum <= x) {
                rs = i + 2; // Update result to the current index + 2
            } else {
                break; // Exit the loop if the cumulative sum exceeds x
            }
        }
        
        // Print the final result
        System.out.println(rs);
    }
}
