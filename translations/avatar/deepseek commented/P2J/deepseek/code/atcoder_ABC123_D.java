import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Reading list a of integers
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < x; i++) {
            a.add(scanner.nextInt());
        }
        
        // Reading list b of integers
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < y; i++) {
            b.add(scanner.nextInt());
        }
        
        // Reading list c of integers
        List<Integer> c = new ArrayList<>();
        for (int i = 0; i < z; i++) {
            c.add(scanner.nextInt());
        }
        
        // Initializing an empty list ab to store sums of elements from a and b
        List<Integer> ab = new ArrayList<>();
        
        // Populating list ab with sums of elements from a and b
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a.get(i) + b.get(j));
            }
        }
        
        // Sorting list ab in descending order
        ab.sort(Collections.reverseOrder());
        
        // Initializing an empty list abc to store sums of elements from ab and c
        List<Integer> abc = new ArrayList<>();
        
        // Populating list abc with sums of elements from ab and c, limited by k
        int limit = Math.min(k, ab.size() * z);
        for (int i = 0; i < limit; i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c.get(j));
            }
        }
        
        // Sorting list abc in descending order
        abc.sort(Collections.reverseOrder());
        
        // Printing the first k elements of abc in descending order
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
    }
}
