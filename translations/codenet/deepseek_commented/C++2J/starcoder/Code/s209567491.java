
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        /*
        1. Include necessary headers: The code starts by including several headers, including standard libraries for input/output operations, string manipulation, mathematical operations, and container classes.
        */
        Scanner in = new Scanner(System.in);
        int N, D, X;
        int num_of_chocolate;
        int counter;
        int days;
        int A[] = new int[101];
        
        /*
        2. Main function: The main function is defined to execute the program. It initializes variables and processes input to compute the number of chocolates needed.
        */
        N = in.nextInt();
        D = in.nextInt();
        X = in.nextInt();
        
        /*
        3. Input reading: The program reads three integers N, D, and X from the standard input.
        */
        
        /*
        4. Array initialization: An array A of size 101 is declared to store the values of A[i] for each i from 0 to N-1.
        */
        
        /*
        5. Reading values into array A: The program reads N values into the array A.
        */
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }
        
        /*
        6. Calculating the number of chocolates: The program calculates the number of chocolates needed by iterating through each value in A and counting how many days it takes to consume all chocolates for each A[i].
        */
        num_of_chocolate = 0;
        for (int i = 0; i < N; i++) {
            days = 0;
            counter = 0;
            for (int j = 0;; j++) {
                days = j * A[i] + 1;
                if (days <= D) {
                    counter++;
                }
                else {
                    break;
                }
            }
            num_of_chocolate = num_of_chocolate + counter;
        }
        
        /*
        7. Adding extra chocolates: The program adds the number of extra chocolates X to the total number of chocolates calculated.
        */
        num_of_chocolate = num_of_chocolate + X;
        
        /*
        8. Output the result: Finally, the program prints the total number of chocolates to the standard output.
        */
        System.out.println(num_of_chocolate);
    }
}

