
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // Initialize input variables
        int X, Y, Z, K; // Number of elements in vectors A, B, C and the limit for output
        Scanner sc = new Scanner(System.in); // Create a new scanner object
        X = sc.nextInt(); // Read input value for X from standard input
        Y = sc.nextInt(); // Read input value for Y from standard input
        Z = sc.nextInt(); // Read input value for Z from standard input
        K = sc.nextInt(); // Read input value for K from standard input

        // Initialize vectors A, B, and C
        int[] A = new int[X]; // A vector of size X, initialized with zeroes
        int[] B = new int[Y]; // B vector of size Y, initialized with zeroes
        int[] C = new int[Z]; // C vector of size Z, initialized with zeroes

        // Read input values for vectors A, B, and C from standard input
        for(int i=0; i<X; i++){
            A[i] = sc.nextInt(); // Read each element of vector A
        }
        for(int i=0; i<Y; i++){
            B[i] = sc.nextInt(); // Read each element of vector B
        }
        for(int i=0; i<Z; i++){
            C[i] = sc.nextInt(); // Read each element of vector C
        }

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
        for(int i=0; i<min(K, AB.length); i++){
            for(int j=0; j<Z; j++){
                ABC[i*Z+j] = AB[i] + C[j]; // Add AB[i] and C[j] and push the sum into vector ABC
            }
        }

        // Sort vector ABC in descending order
        Arrays.sort(ABC);

        // Print K smallest elements of vector ABC
        for(int i=0; i<K; i++){
            System.out.println(ABC[i]); // Print each element of vector ABC
        }

        // Main function ends here
    }
}

