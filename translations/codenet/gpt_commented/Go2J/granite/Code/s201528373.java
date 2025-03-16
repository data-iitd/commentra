
import java.util.Scanner;

public class s201528373{
    public static void main(String[] args) {
        // Declare variables for the number of elements (n), the threshold value (x), and a list to hold the integers (l)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        List<Integer> l = new ArrayList<>();
        
        // Loop to read n integers from standard input and add them to the list l
        for (int i = 0; i < n; i++) {
            int tmpL = scanner.nextInt();
            l.add(tmpL);
        }
        
        // Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
        int tmpSum = 0;
        int rs = 0;
        
        // Loop through the list l to calculate the cumulative sum and determine the result
        for (int i = 0; i < l.size(); i++) {
            // Add the current value to the cumulative sum
            tmpSum += l.get(i);
            
            // Check if the index exceeds the number of elements
            if (i >= n) {
                rs = n; // Set result to n if index exceeds n
                break;
            }
            
            // If the cumulative sum is less than or equal to x, update the result
            if (tmpSum <= x) {
                rs = i + 2; // Update result to the current index + 2
            } else if (tmpSum > x) {
                break; // Exit the loop if the cumulative sum exceeds x
            }
        }
        
        // Print the final result
        System.out.println(rs);
    }
}
