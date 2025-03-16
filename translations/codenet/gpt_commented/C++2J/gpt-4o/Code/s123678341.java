import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the sizes of the three arrays and the number K
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();

        // Declare lists to hold the input values
        List<Long> A = new ArrayList<>(X);
        List<Long> B = new ArrayList<>(Y);
        List<Long> C = new ArrayList<>(Z);

        // Read values into list A
        for (int i = 0; i < X; i++) {
            A.add(scanner.nextLong());
        }

        // Read values into list B
        for (int i = 0; i < Y; i++) {
            B.add(scanner.nextLong());
        }

        // Read values into list C
        for (int i = 0; i < Z; i++) {
            C.add(scanner.nextLong());
        }

        // Sort the lists in descending order to facilitate maximum sum calculations
        Collections.sort(A, Collections.reverseOrder());
        Collections.sort(B, Collections.reverseOrder());
        Collections.sort(C, Collections.reverseOrder());

        // Create a list to store the sums of elements from A and B
        List<Long> AB = new ArrayList<>();

        // Calculate all possible sums of elements from A and B
        for (long a : A) {
            for (long b : B) {
                AB.add(a + b);
            }
        }

        // Sort the sums in descending order
        Collections.sort(AB, Collections.reverseOrder());

        // Create a list to store the final sums including elements from C
        List<Long> ABC = new ArrayList<>();

        // Calculate sums of the top K elements from AB with each element from C
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (long c : C) {
                ABC.add(AB.get(i) + c);
            }
        }

        // Sort the final sums in descending order
        Collections.sort(ABC, Collections.reverseOrder());

        // Output the top K sums from the final list
        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }

        scanner.close();
    }
}

// <END-OF-CODE>
