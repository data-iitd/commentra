import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] sequence = new int[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = scanner.nextInt();
        }
        System.out.println(nPairsWithCommonFX(sequence));
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        Map<Integer, Integer> storage = new HashMap<>();
        int[] FXs = new int[sequence.length];
        int index = 0;
        for (int value : sequence) {
            int y = f(value);
            if (!storage.containsKey(y)) {
                storage.put(y, 1);
                FXs[index++] = y;
            } else {
                storage.put(y, storage.get(y) + 1);
            }
        }
        int result = 0;
        for (int y : FXs) {
            if (storage.get(y) > 1) {
                result += storage.get(y) * storage.get(y);
            }
        }
        return (result - index) / 2;
    }

    public static int f(int n) {
        int y = 1;
        while (n != 1) {
            if (n % 2 != 0) {
                y += 1;
            }
            n /= 2;
        }
        return y;
    }
}
