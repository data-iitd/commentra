
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Initialize input variables
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();
        int K = sc.nextInt();

        // Initialize vectors A, B, and C
        int[] A = new int[X];
        int[] B = new int[Y];
        int[] C = new int[Z];

        // Read input values for vectors A, B, and C from standard input
        for(int i=0; i<X; i++)
            A[i] = sc.nextInt();
        for(int i=0; i<Y; i++)
            B[i] = sc.nextInt();
        for(int i=0; i<Z; i++)
            C[i] = sc.nextInt();

        // Sort vectors A, B, and C in descending order
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);

        // Create a new vector AB by adding each element of A to each element of B
        int[] AB = new int[X*Y];
        for(int i=0; i<X; i++){
            for(int j=0; j<Y; j++){
                AB[i*Y+j] = A[i] + B[j]; // Add A[i] and B[j] and push the sum into vector AB
            }
        }

        // Sort vector AB in descending order
        Arrays.sort(AB);

        // Create a new vector ABC by adding each element of AB to each element of C
        int[] ABC = new int[K];
        for(int i=0; i<K; i++){
            for(int j=0; j<Z; j++){
                ABC[i] = AB[i] + C[j]; // Add AB[i] and C[j] and push the sum into vector ABC
            }
        }

        // Sort vector ABC in descending order
        Arrays.sort(ABC);

        // Print K smallest elements of vector ABC
        for(int i=0; i<K; i++){
            System.out.println(ABC[i]); // Print each element of vector ABC
        }
    }
}

