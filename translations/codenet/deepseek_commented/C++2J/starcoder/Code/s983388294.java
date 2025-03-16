import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        /*
         * Step 2: Define main function
         * The main function is the entry point of the program. It initializes variables and processes the input.
         */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int[] a = new int[n];
        int i;
        for(i=0; i<n; i++) {
            /*
             * Step 3: Read input
             * The program reads an integer `n` which represents the number of elements in the array.
             * It then reads `n` integers and stores them in a vector `a`.
             */
            a[i] = in.nextInt();
        }
        int curr=0;
        for(i=0; i<n; i++) {
            /*
             * Step 4: Process the array
             * The program initializes a variable `curr` to 0.
             * It iterates through the array `a` and updates `curr` based on the condition `a[i] == curr + 1`.
             */
            if(a[i]==curr+1) curr++;
        }
        if(curr>0) {
            /*
             * Step 5: Output the result
             * If `curr` is greater than 0, it prints the number of elements that need to be removed to make the sequence continuous, which is `n - curr`.
             * If `curr` is 0, it prints `-1` indicating that it's not possible to make the sequence continuous.
             */
            System.out.println(n-curr);
        }
        else {
            System.out.println("-1");
        }

        /*
         * Step 6: Return 0
         * The main function returns 0 to indicate successful execution.
         */
    }
}
