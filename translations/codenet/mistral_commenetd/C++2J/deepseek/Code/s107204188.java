import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int minA = (int) Math.pow(10, 9) + 1;
        int num = 0;

        // Read number of elements and time t from the standard input
        int n = scanner.nextInt();
        int t = scanner.nextInt();

        // Create an ArrayList A to store the input elements
        ArrayList<Integer> A = new ArrayList<>();

        // Read each element of ArrayList A from the standard input
        for (int i = 0; i < n; i++) {
            A.add(scanner.nextInt());
            // Check if the current element is smaller than the minimum value
            if (minA > A.get(i)) {
                // Update the minimum value of array A
                minA = A.get(i);
            } else {
                // Calculate the difference between the current element and the minimum value
                int diff = A.get(i) - minA;

                // If the difference is equal to the previous difference, increment the count of similar differences
                if (num == diff) num++;
                // If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
                else if (num < diff) {
                    num = 1;
                    num = diff;
                }
            }
        }

        // Print the count of similar differences on the standard output
        System.out.println(num);
    }
}
