import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read integers x, y, z, and k from input
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = scanner.nextInt();
        int k = scanner.nextInt();

        // Read list a of size x from input
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < x; i++) {
            a.add(scanner.nextInt());
        }

        // Read list b of size y from input
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < y; i++) {
            b.add(scanner.nextInt());
        }

        // Read list c of size z from input
        List<Integer> c = new ArrayList<>();
        for (int i = 0; i < z; i++) {
            c.add(scanner.nextInt());
        }

        // Initialize an empty list to store the sums of elements from lists a and b
        List<Integer> ab = new ArrayList<>();

        // Calculate all possible sums of elements from list a and list b
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                ab.add(a.get(i) + b.get(j));
            }
        }

        // Sort the list of sums in descending order
        ab.sort(Collections.reverseOrder());

        // Initialize an empty list to store the sums of the top k elements from ab and elements from list c
        List<Integer> abc = new ArrayList<>();

        // Calculate sums of the top k elements from ab with each element in c
        int limit = Math.min(k, ab.size());
        for (int i = 0; i < limit; i++) {
            for (int j = 0; j < z; j++) {
                abc.add(ab.get(i) + c.get(j));
            }
        }

        // Sort the resulting sums in descending order
        abc.sort(Collections.reverseOrder());

        // Print the top k sums from the final list abc
        for (int i = 0; i < k; i++) {
            System.out.println(abc.get(i));
        }
    }
}
