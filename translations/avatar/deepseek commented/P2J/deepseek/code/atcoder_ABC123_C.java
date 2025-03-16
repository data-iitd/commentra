import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Read an integer input N which represents some quantity or value.
        int N = scanner.nextInt();
        
        // Step 2: Read five integer inputs and store them in an array A. This array will be used to determine the minimum value among these integers.
        int[] A = new int[5];
        for (int i = 0; i < 5; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Step 3: Find the minimum value in the array A.
        int minA = Arrays.stream(A).min().getAsInt();
        
        // Step 4: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.
        int result = (int) Math.ceil((double) N / minA) + 4;
        System.out.println(result);
    }
}

