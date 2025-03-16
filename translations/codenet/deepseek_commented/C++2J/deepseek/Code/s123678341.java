import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Reading Inputs
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Step 2: Vector Initialization and Input
        List<Long> A = new ArrayList<>();
        List<Long> B = new ArrayList<>();
        List<Long> C = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            A.add(scanner.nextLong());
        }
        for (int i = 0; i < Y; i++) {
            B.add(scanner.nextLong());
        }
        for (int i = 0; i < Z; i++) {
            C.add(scanner.nextLong());
        }
        
        // Step 3: Sorting
        A.sort(Collections.reverseOrder());
        B.sort(Collections.reverseOrder());
        C.sort(Collections.reverseOrder());
        
        // Step 4: Combining A and B
        List<Long> AB = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A.get(i) + B.get(j));
            }
        }
        
        // Step 5: Sorting AB
        AB.sort(Collections.reverseOrder());
        
        // Step 6: Combining AB and C
        List<Long> ABC = new ArrayList<>();
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C.get(j));
            }
        }
        
        // Step 7: Sorting ABC
        ABC.sort(Collections.reverseOrder());
        
        // Step 8: Output
        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
    }
}
