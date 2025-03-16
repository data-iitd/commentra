
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

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
        Set<Integer> setX = new HashSet<>();
        Set<Integer> setY = new HashSet<>();
        for (int i = 0; i < max_level; i++) {
            setX.add(x[i]);
            setY.add(y[i]);
        }
        if (setX.contains(0) && setY.contains(0)) {
            setX.remove(0);
            setY.remove(0);
        }
        if (setX.size() != max_level || setY.size() != max_level) {
            System.out.println("Oh, my keyboard!");
        } else {
            System.out.println("I become the guy.");
        }
    }
}

