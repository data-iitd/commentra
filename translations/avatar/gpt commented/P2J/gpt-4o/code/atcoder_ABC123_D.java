import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read integers x, y, z, and k from input
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read list a of size x from input
        int[] a = new int[x];
        for (int i = 0; i < x; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Read list b of size y from input
        int[] b = new int[y];
        for (int i = 0; i < y; i++) {
            b[i] = scanner.nextInt();
        }
        
        // Read list c of size z from input
        int[] c = new int[z];
        for (int i = 0; i < z; i++) {
            c[i] = scanner.nextInt();
        }
        
        // Initialize a list to store the sums of elements from lists a and b
        List<Integer> ab = new ArrayList<>();
        
        // Calculate all possible sums of elements from list a and list b
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a[i] + b[j]);
            }
        }
        
        // Sort the list of sums in descending order
        Collections.sort(ab, Collections.reverseOrder());
        
        // Initialize a list to store the sums of the top k elements from ab and elements from list c
        List<Integer> abc = new ArrayList<>();
        
        // Calculate sums of the top k elements from ab with each element in c
        for (int i = 0; i < Math.min(k, ab.size()); i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c[j]);
            }
        }
        
        // Sort the resulting sums in descending order
        Collections.sort(abc, Collections.reverseOrder());
        
        // Print the top k sums from the final list abc
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
