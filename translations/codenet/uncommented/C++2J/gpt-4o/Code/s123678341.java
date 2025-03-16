import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();
        
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
        
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        
        // Reverse the arrays to sort in descending order
        reverseArray(A);
        reverseArray(B);
        reverseArray(C);
        
        List<Long> AB = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A[i] + B[j]);
            }
        }
        
        Collections.sort(AB, Collections.reverseOrder());
        
        List<Long> ABC = new ArrayList<>();
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C[j]);
            }
        }
        
        Collections.sort(ABC, Collections.reverseOrder());
        
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
