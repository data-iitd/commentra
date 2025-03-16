import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the sizes of the three arrays and the number K
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();

        // Declare vectors to hold the input values
        List<Long> A = new ArrayList<>();
        List<Long> B = new ArrayList<>();
        List<Long> C = new ArrayList<>();

        // Read values into vector A
        for (int i = 0; i < X; i++) {
            A.add(scanner.nextLong());
        }

        // Read values into vector B
        for (int i = 0; i < Y; i++) {
            B.add(scanner.nextLong());
        }

        // Read values into vector C
        for (int i = 0; i < Z; i++) {
            C.add(scanner.nextLong());
        }

        // Sort the vectors in descending order to facilitate maximum sum calculations
        A.sort(Collections.reverseOrder());
        B.sort(Collections.reverseOrder());
        C.sort(Collections.reverseOrder());

        // Create a list to store the sums of elements from A and B
        List<Long> AB = new ArrayList<>();

        // Calculate all possible sums of elements from A and B
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A.get(i) + B.get(j));
            }
        }

        // Sort the sums in descending order
        AB.sort(Collections.reverseOrder());

        // Create a list to store the final sums including elements from C
        List<Long> ABC = new ArrayList<>();

        // Calculate sums of the top K elements from AB with each element from C
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C.get(j));
            }
        }

        // Sort the final sums in descending order
        ABC.sort(Collections.reverseOrder());

        // Output the top K sums from the final list
        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
    }
}
