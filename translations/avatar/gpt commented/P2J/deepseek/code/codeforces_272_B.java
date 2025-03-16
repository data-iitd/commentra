import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println(main());
    }

    public static int main() {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read input from the user (not stored, just consumed)
        String[] input = scanner.nextLine().split(" ");
        int[] sequence = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            sequence[i] = Integer.parseInt(input[i]);
        }
        return nPairsWithCommonFX(sequence);
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        Map<Integer, Integer> storage = new HashMap<>();
        int[] FXs = new int[sequence.length];
        int fxIndex = 0;

        for (int value : sequence) {
            int y = f(value);
            if (!storage.containsKey(y)) {
                storage.put(y, value);
                FXs[fxIndex++] = y;
            } else {
                storage.put(y, storage.get(y) + 1);
            }
        }

        int pairCount = 0;
        for (int y : FXs) {
            if (storage.containsKey(y)) {
                int count = storage.get(y);
                pairCount += (count * count);
            }
        }

        return (pairCount - sumOfCounts(FXs, storage)) / 2;
    }

    public static int f(int n) {
        int y = 1;
        while (n != 1) {
            if (n % 2 != 0) {
                y++;
            }
            n /= 2;
        }
        return y;
    }

    private static int sumOfCounts(int[] FXs, Map<Integer, Integer> storage) {
        int sum = 0;
        for (int y : FXs) {
            if (storage.containsKey(y)) {
                sum += storage.get(y);
            }
        }
        return sum;
    }
}
