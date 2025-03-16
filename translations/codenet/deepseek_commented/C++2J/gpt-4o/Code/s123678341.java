import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Step 1: Reading Inputs
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Step 2: Vector Initialization and Input
        long[] A = new long[X];
        long[] B = new long[Y];
        long[] C = new long[Z];
        
        for (int i = 0; i < X; i++) {
            A[i] = scanner.nextLong();
        }
        for (int i = 0; i < Y; i++) {
            B[i] = scanner.nextLong();
        }
        for (int i = 0; i < Z; i++) {
            C[i] = scanner.nextLong();
        }
        
        // Step 3: Sorting
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        
        // Reverse the arrays to sort in descending order
        reverseArray(A);
        reverseArray(B);
        reverseArray(C);
        
        // Step 4: Combining A and B
        List<Long> AB = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A[i] + B[j]);
            }
        }
        
        // Step 5: Sorting AB
        Collections.sort(AB, Collections.reverseOrder());
        
        // Step 6: Combining AB and C
        List<Long> ABC = new ArrayList<>();
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C[j]);
            }
        }
        
        // Step 7: Sorting ABC
        Collections.sort(ABC, Collections.reverseOrder());
        
        // Step 8: Output
        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
        
        scanner.close();
    }
    
    private static void reverseArray(long[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            long temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
    }
}

// <END-OF-CODE>
