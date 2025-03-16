import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input from the user
        int N = scanner.nextInt();
        
        // Read 5 integer inputs from the user and store them in an array A
        int[] A = new int[5];
        for (int i = 0; i < 5; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Calculate the minimum value from the array A, divide N by this minimum value,
        // take the ceiling of the result, and add 4 to it before printing the final result
        int minA = A[0];
        for (int i = 1; i < 5; i++) {
            if (A[i] < minA) {
                minA = A[i];
            }
        }
        
        int result = (int) Math.ceil((double) N / minA) + 4;
        System.out.println(result);
    }
}
