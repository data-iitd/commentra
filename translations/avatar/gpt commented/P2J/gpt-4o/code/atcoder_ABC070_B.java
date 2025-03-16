import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of input, split it into components, and convert each component to an integer, storing them in an array A
        int[] A = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();

        // Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
        if (A[1] <= A[2] || A[3] <= A[0]) {
            // If the condition is true, print 0
            System.out.println(0);
        } else {
            // If the condition is false, sort the array A in ascending order
            Arrays.sort(A);
            // Calculate the difference between the largest and the second largest elements in the sorted array and print the result
            System.out.println(A[2] - A[1]);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
