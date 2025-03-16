
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        // Initialize minimum value of array A to a large number
        int minA = (int) Math.pow(10, 9) + 1;
        int num = 0;

        // Read number of elements and time t from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();

        // Create a vector A of size n to store the input elements
        Vector<Integer> A = new Vector<Integer>(n);

        // Read each element of vector A from the standard input
        for (int i = 0; i < n; i++) {
            A.add(sc.nextInt());
            // Check if the current element is smaller than the minimum value
            if (minA > A.get(i)) {
                // Update the minimum value of array A
                minA = A.get(i);
            } else {
                // Calculate the difference between the current element and the minimum value
                int diff = A.get(i) - minA;

                // If the difference is equal to the previous difference, increment the count of similar differences
                if (f == diff) num++;
                // If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
                else if (f < diff) {
                    num = 1;
                    f = diff;
                }
            }
        }

        // Print the count of similar differences on the standard output
        System.out.println(num);
    }
}

