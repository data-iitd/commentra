import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read x, y, z, k
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read arrays a, b, c
        int[] a = new int[x];
        int[] b = new int[y];
        int[] c = new int[z];
        
        for (int i = 0; i < x; i++) {
            a[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < y; i++) {
            b[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < z; i++) {
            c[i] = scanner.nextInt();
        }
        
        // Calculate all possible sums of a[i] + b[j]
        List<Integer> ab = new ArrayList<>();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a[i] + b[j]);
            }
        }
        
        // Sort ab in descending order
        Collections.sort(ab, Collections.reverseOrder());
        
        // Calculate all possible sums of ab[i] + c[j]
        List<Integer> abc = new ArrayList<>();
        for (int i = 0; i < Math.min(k, ab.size()); i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c[j]);
            }
        }
        
        // Sort abc in descending order
        Collections.sort(abc, Collections.reverseOrder());
        
        // Print the top k elements
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
