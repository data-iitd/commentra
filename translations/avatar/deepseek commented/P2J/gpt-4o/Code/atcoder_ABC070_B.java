import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input from the user and converting it into an array of integers
        int[] A = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        // Checking if the second element is less than or equal to the third element 
        // or if the fourth element is less than or equal to the first element
        if (A[1] <= A[2] || A[3] <= A[0]) {
            System.out.println(0);  // If either condition is true, print 0
        } else {
            Arrays.sort(A);  // Sorting the array
            System.out.println(A[2] - A[1]);  // Printing the difference between the third and second elements
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
