import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Initialize input variables
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt(); // Number of elements in vector A
        int Y = scanner.nextInt(); // Number of elements in vector B
        int Z = scanner.nextInt(); // Number of elements in vector C
        int K = scanner.nextInt(); // Limit for output

        // Initialize arrays A, B, and C
        long[] A = new long[X]; // A array of size X
        long[] B = new long[Y]; // B array of size Y
        long[] C = new long[Z]; // C array of size Z

        // Read input values for arrays A, B, and C
        for (int i = 0; i < X; i++) {
            A[i] = scanner.nextLong(); // Read each element of array A
        }
        for (int i = 0; i < Y; i++) {
            B[i] = scanner.nextLong(); // Read each element of array B
        }
        for (int i = 0; i < Z; i++) {
            C[i] = scanner.nextLong(); // Read each element of array C
        }

        // Sort arrays A, B, and C in descending order
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        reverseArray(A);
        reverseArray(B);
        reverseArray(C);

        // Create a new list AB by adding each element of A to each element of B
        List<Long> AB = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A[i] + B[j]); // Add A[i] and B[j] and push the sum into list AB
            }
        }

        // Sort list AB in descending order
        Collections.sort(AB, Collections.reverseOrder());

        // Create a new list ABC by adding each element of AB to each element of C
        List<Long> ABC = new ArrayList<>();
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C[j]); // Add AB[i] and C[j] and push the sum into list ABC
            }
        }

        // Sort list ABC in descending order
        Collections.sort(ABC, Collections.reverseOrder());

        // Print K smallest elements of list ABC
        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i)); // Print each element of list ABC
        }

        // Close the scanner
        scanner.close();
    }

    // Helper method to reverse an array
    private static void reverseArray(long[] array) {
        for (int i = 0; i < array.length / 2; i++) {
            long temp = array[i];
            array[i] = array[array.length - 1 - i];
            array[array.length - 1 - i] = temp;
        }
    }
}

// <END-OF-CODE>
