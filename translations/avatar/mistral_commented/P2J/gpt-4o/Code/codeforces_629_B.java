import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Initializing the arrays m and f with zeros for all indices up to N
        int N = 368;
        int[] m = new int[N];
        int[] f = new int[N];

        // Reading the number of operations
        int operations = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Processing each operation
        for (int i = 0; i < operations; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            String x = parts[0];
            int a = Integer.parseInt(parts[1]);
            int b = Integer.parseInt(parts[2]) + 1;

            // If the operation is 'M', updating the m array accordingly
            if (x.equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            } 
            // If the operation is 'F', updating the f array accordingly
            else {
                f[a] += 2;
                f[b] -= 2;
            }
        }

        // Initializing three variables a, b, and c with zeros
        int aSum = 0, bSum = 0, c = 0;

        // Calculating the prefix sums of m and f arrays
        for (int i = 0; i < N; i++) {
            // Updating the variables aSum and bSum with the sum of m and f arrays respectively
            aSum += m[i];
            bSum += f[i];
            // Finding the minimum of aSum and bSum and updating the variable c if the minimum is greater than the current value of c
            if (Math.min(aSum, bSum) > c) {
                c = Math.min(aSum, bSum);
            }
        }

        // Printing the result, which is the minimum of the prefix sums of m and f arrays
        System.out.println(c);
        
        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
