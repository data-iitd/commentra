
import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[5];
        for (int i = 0; i < 5; i++) {
            A[i] = sc.nextInt();
        }
        int min = A[0];
        for (int i = 1; i < 5; i++) {
            if (A[i] < min) {
                min = A[i];
            }
        }
        System.out.println((int) Math.ceil((double) N / min) + 4);
    }
}

# Step 1: Import necessary modules for mathematical operations, numerical computations, and data structures.

# Step 2: Read an integer input N which represents some quantity or value.

# Step 3: Read five integer inputs and store them in a list A. This list will be used to determine the minimum value among these integers.

# Step 4: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.

