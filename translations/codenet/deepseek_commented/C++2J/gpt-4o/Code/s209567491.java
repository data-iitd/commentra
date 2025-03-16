import java.util.Scanner;

public class ChocolateCalculator {
    public static void main(String[] args) {
        /*
        1. Main function: The main function is defined to execute the program. It initializes variables and processes input to compute the number of chocolates needed.
        */
        Scanner scanner = new Scanner(System.in);
        
        /*
        2. Input reading: The program reads three integers N, D, and X from the standard input.
        */
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        int X = scanner.nextInt();
        
        /*
        3. Array initialization: An array A of size 101 is declared to store the values of A[i] for each i from 0 to N-1.
        */
        int[] A = new int[101];
        
        /*
        4. Reading values into array A: The program reads N values into the array A.
        */
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        /*
        5. Calculating the number of chocolates: The program calculates the number of chocolates needed by iterating through each value in A and counting how many days it takes to consume all chocolates for each A[i].
        */
        int num_of_chocolate = 0;
        for (int i = 0; i < N; i++) {
            int days = 0;
            int counter = 0;
            for (int j = 0;; j++) {
                days = j * A[i] + 1;
                if (days <= D) {
                    counter++;
                } else {
                    break;
                }
            }
            num_of_chocolate += counter;
        }
        
        /*
        6. Adding extra chocolates: The program adds the number of extra chocolates X to the total number of chocolates calculated.
        */
        num_of_chocolate += X;
        
        /*
        7. Output the result: Finally, the program prints the total number of chocolates to the standard output.
        */
        System.out.println(num_of_chocolate);
        
        scanner.close();
    }
}

/* <END-OF-CODE> */
