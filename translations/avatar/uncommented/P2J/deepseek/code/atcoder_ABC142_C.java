import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String[] input = scanner.nextLine().split(" ");
        
        List<Pair> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(new Pair(i + 1, Integer.parseInt(input[i])));
        }
        
        Collections.sort(A, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return Integer.compare(p1.value, p2.value);
            }
        });
        
        List<Integer> A__ = new ArrayList<>();
        for (Pair p : A) {
            A__.add(p.index);
        }
        
        for (int i = 0; i < A__.size() - 1; i++) {
            System.out.print(A__.get(i) + " ");
        }
        System.out.println(A__.get(A__.size() - 1));
    }
    
    static class Pair {
        int index;
        int value;
        
        Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}
