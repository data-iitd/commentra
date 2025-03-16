
import java.util.*;

public class s123678341{
    public static void main(String[] args) {
        // Input the sizes of the three arrays and the number K
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();

        // Declare lists to hold the input values
        List<Long> A = new ArrayList<>();
        List<Long> B = new ArrayList<>();
        List<Long> C = new ArrayList<>();

        // Read values into list A
        for(int i = 0; i < X; i++) {
            long a = scanner.nextLong();
            A.add(a);
        }

        // Read values into list B
        for(int i = 0; i < Y; i++) {
            long b = scanner.nextLong();
            B.add(b);
        }

        // Read values into list C
        for(int i = 0; i < Z; i++) {
            long c = scanner.nextLong();
            C.add(c);
        }

        // Sort the lists in descending order to facilitate maximum sum calculations
        Collections.sort(A, Collections.reverseOrder());
        Collections.sort(B, Collections.reverseOrder());
        Collections.sort(C, Collections.reverseOrder());

        // Create a list to store the sums of elements from A and B
        List<Long> AB = new ArrayList<>();

        // Calculate all possible sums of elements from A and B
        for(long a : A) {
            for(long b : B) {
                AB.add(a + b);
            }
        }

        // Sort the sums in descending order
        Collections.sort(AB, Collections.reverseOrder());

        // Create a list to store the final sums including elements from C
        List<Long> ABC = new ArrayList<>();

        // Calculate sums of the top K elements from AB with each element from C
        for(int i = 0; i < Math.min(K, AB.size()); i++) {
            for(long c : C) {
                ABC.add(AB.get(i) + c);
            }
        }

        // Sort the final sums in descending order
        Collections.sort(ABC, Collections.reverseOrder());

        // Output the top K sums from the final list
        for(int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
    }
}

