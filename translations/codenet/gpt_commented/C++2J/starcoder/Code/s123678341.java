import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Input the sizes of the three arrays and the number K
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();
        int K = sc.nextInt();

        // Declare vectors to hold the input values
        Vector<Integer> A = new Vector<Integer>(X);
        Vector<Integer> B = new Vector<Integer>(Y);
        Vector<Integer> C = new Vector<Integer>(Z);

        // Read values into vector A
        for(int i = 0; i < X; i++) {
            A.add(sc.nextInt());
        }

        // Read values into vector B
        for(int i = 0; i < Y; i++) {
            B.add(sc.nextInt());
        }

        // Read values into vector C
        for(int i = 0; i < Z; i++) {
            C.add(sc.nextInt());
        }

        // Sort the vectors in descending order to facilitate maximum sum calculations
        Collections.sort(A, Collections.reverseOrder());
        Collections.sort(B, Collections.reverseOrder());
        Collections.sort(C, Collections.reverseOrder());

        // Create a vector to store the sums of elements from A and B
        Vector<Integer> AB = new Vector<Integer>();

        // Calculate all possible sums of elements from A and B
        for(int i = 0; i < X; i++) {
            for(int j = 0; j < Y; j++) {
                AB.add(A.get(i) + B.get(j));
            }
        }

        // Sort the sums in descending order
        Collections.sort(AB, Collections.reverseOrder());

        // Create a vector to store the final sums including elements from C
        Vector<Integer> ABC = new Vector<Integer>();

        // Calculate sums of the top K elements from AB with each element from C
        for(int i = 0; i < Math.min(K, AB.size()); i++) {
            for(int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C.get(j));
            }
        }

        // Sort the final sums in descending order
        Collections.sort(ABC, Collections.reverseOrder());

        // Output the top K sums from the final vector
        for(int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
    }
}

