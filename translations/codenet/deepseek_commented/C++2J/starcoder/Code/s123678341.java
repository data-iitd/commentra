import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        // Step 1: Reading Inputs
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();
        int K = sc.nextInt();
        
        // Step 2: Vector Initialization and Input
        int[] A = new int[X];
        int[] B = new int[Y];
        int[] C = new int[Z];
        for(int i=0; i<X; i++)
            A[i] = sc.nextInt();
        for(int i=0; i<Y; i++)
            B[i] = sc.nextInt();
        for(int i=0; i<Z; i++)
            C[i] = sc.nextInt();
        
        // Step 3: Sorting
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        
        // Step 4: Combining A and B
        int[] AB = new int[X*Y];
        for(int i=0; i<X; i++){
            for(int j=0; j<Y; j++){
                AB[i*Y+j] = A[i] + B[j];
            }
        }
        
        // Step 5: Sorting AB
        Arrays.sort(AB);
        
        // Step 6: Combining AB and C
        int[] ABC = new int[K];
        for(int i=0; i<K; i++){
            for(int j=0; j<Z; j++){
                ABC[i] = AB[i] + C[j];
            }
        }
        
        // Step 7: Sorting ABC
        Arrays.sort(ABC);
        
        // Step 8: Output
        for(int i=0; i<K; i++){
            System.out.println(ABC[i]);
        }
    }
}
