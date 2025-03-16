import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input: four integers x, y, z, and k
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the lists a, b, and c
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
        
        // Initialize a list to store the sum of each element from list a with each element from list b
        List<Integer> ab = new ArrayList<>();
        
        // Calculate sums of a[i] + b[j]
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a[i] + b[j]);
            }
        }
        
        // Sort list ab in descending order
        Collections.sort(ab, Collections.reverseOrder());
        
        // Initialize a list to store the sum of each element from list ab with each element from list c
        List<Integer> abc = new ArrayList<>();
        
        // Calculate sums of ab[i] + c[j]
        for (int i = 0; i < Math.min(k, ab.size()); i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c[j]);
            }
        }
        
        // Sort list abc in descending order
        Collections.sort(abc, Collections.reverseOrder());
        
        // Print the first k elements of list abc
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
