import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int max_level = sc.nextInt();
        int[] x = new int[max_level];
        int[] y = new int[max_level];
        for (int i = 0; i < max_level; i++) {
            x[i] = sc.nextInt();
        }
        for (int i = 0; i < max_level; i++) {
            y[i] = sc.nextInt();
        }
        Set<Integer> z = new HashSet<Integer>();
        for (int i = 0; i < max_level; i++) {
            z.add(x[i]);
        }
        for (int i = 0; i < max_level; i++) {
            z.add(y[i]);
        }
        if (z.size()!= max_level) {
            System.out.println("Oh, my keyboard!");
        } else {
            System.out.println("I become the guy.");
        }
    }
}
