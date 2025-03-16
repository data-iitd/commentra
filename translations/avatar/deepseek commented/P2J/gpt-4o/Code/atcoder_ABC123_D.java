import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking four integer inputs: x, y, z, and k
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Reading list a of integers
        int[] a = new int[x];
        for (int i = 0; i < x; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Reading list b of integers
        int[] b = new int[y];
        for (int i = 0; i < y; i++) {
            b[i] = scanner.nextInt();
        }
        
        // Reading list c of integers
        int[] c = new int[z];
        for (int i = 0; i < z; i++) {
            c[i] = scanner.nextInt();
        }
        
        // Initializing an empty list ab to store sums of elements from a and b
        List<Integer> ab = new ArrayList<>();
        
        // Populating list ab with sums of elements from a and b
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a[i] + b[j]);
            }
        }
        
        // Sorting list ab in descending order
        Collections.sort(ab, Collections.reverseOrder());
        
        // Initializing an empty list abc to store sums of elements from ab and c
        List<Integer> abc = new ArrayList<>();
        
        // Populating list abc with sums of elements from ab and c, limited by k
        for (int i = 0; i < Math.min(k, ab.size()); i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c[j]);
            }
        }
        
        // Sorting list abc in descending order
        Collections.sort(abc, Collections.reverseOrder());
        
        // Printing the first k elements of abc in descending order
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
