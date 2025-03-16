
import java.util.Scanner;
import java.util.Arrays;

public class s841275808{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reads the number of elements N.
        int N = scanner.nextInt();
        
        // Initializes arrays X and Y to store N integers.
        int[] X = new int[N];
        int[] Y = new int[N];
        
        // Reads N integers into array X and copies them to array Y.
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            Y[i] = X[i];
        }
        
        // Sorts array Y in ascending order.
        Arrays.sort(Y);
        
        // Calculates the two middle values of the sorted array Y.
        int m1 = Y[N / 2 - 1];
        int m2 = Y[N / 2];
        
        // For each element in array X, prints the corresponding median value.
        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                System.out.println(m2);
            } else {
                System.out.println(m1);
            }
        }
        
        // End of code.
        // 