import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input: four integers x, y, z, and k
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Initialize lists a, b, and c
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        
        // Read x * y integers for list a
        for (int i = 0; i < x * y; i++) {
            a.add(scanner.nextInt());
        }
        
        // Read y * z integers for list b
        for (int i = 0; i < y * z; i++) {
            b.add(scanner.nextInt());
        }
        
        // Read x * z integers for list c
        for (int i = 0; i < x * z; i++) {
            c.add(scanner.nextInt());
        }
        
        // Initialize an empty list ab to store the sum of each element from list a with each element from list b
        List<Integer> ab = new ArrayList<>();
        
        // Iterate through each element in list a for i, and for each element in list b for j, append their sum to list ab
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a.get(i) + b.get(j));
            }
        }
        
        // Sort list ab in descending order
        ab.sort(Collections.reverseOrder());
        
        // Initialize an empty list abc to store the sum of each element from list ab with each element from list c
        List<Integer> abc = new ArrayList<>();
        
        // Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
        for (int i = 0; i < Math.min(k, x * y); i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c.get(j));
            }
        }
        
        // Sort list abc in descending order
        abc.sort(Collections.reverseOrder());
        
        // Iterate through the first k elements of list abc and print each element
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
    }
}
