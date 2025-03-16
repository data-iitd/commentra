import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        /*
         * Step 1: Create a Scanner object for input
         * The program starts by creating a Scanner object to read input from the console.
         */
        Scanner scanner = new Scanner(System.in);
        
        /*
         * Step 2: Read input
         * The program reads an integer `n` which represents the number of elements in the array.
         * It then reads `n` integers and stores them in an ArrayList `a`.
         */
        int n = scanner.nextInt();
        ArrayList<Integer> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }
        
        int curr = 0;
        /*
         * Step 3: Process the array
         * The program initializes a variable `curr` to 0.
         * It iterates through the array `a` and updates `curr` based on the condition `a[i] == curr + 1`.
         */
        for (int i = 0; i < n; i++) {
            if (a.get(i) == curr + 1) {
                curr++;
            }
        }
        
        /*
         * Step 4: Output the result
         * If `curr` is greater than 0, it prints the number of elements that need to be removed to make the sequence continuous, which is `n - curr`.
         * If `curr` is 0, it prints `-1` indicating that it's not possible to make the sequence continuous.
         */
        if (curr > 0) {
            System.out.println(n - curr);
        } else {
            System.out.println("-1");
        }
        
        /*
         * Step 5: Close the scanner
         * The scanner is closed to prevent resource leaks.
         */
        scanner.close();
    }
}

/*
 * Step 6: End of the code
 * The main function returns 0 to indicate successful execution.
 */
