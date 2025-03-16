import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read input from standard input

        int result = nPairsWithCommonFX(toIntArray(scanner.nextLine().split(" ")));

        System.out.println(result);
    }

    public static int[] toIntArray(String[] strings) {
        int[] intArray = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            intArray[i] = Integer.parseInt(strings[i]);
        }
        return intArray;
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        Map<Integer, Integer> storage = new HashMap<>();

        for (int value : sequence) {
            int fx = f(value);

            storage.put(fx, storage.getOrDefault(fx, 0) + 1);
        }

        int result = 0;
        for (int count : storage.values()) {
            result += count * (count - 1) / 2;
        }

        return result;
    }

    public static int f(int n) {
        int fx = 1;

        while (n != 1) {
            if (n % 2 != 0) {
                fx += 1;
            }
            n /= 2;
        }

        return fx;
    }
}
