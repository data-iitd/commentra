import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line of input
        System.out.println(nPairsWithCommonFX(Arrays.stream(scanner.nextLine().split(" "))
                .mapToInt(Integer::parseInt).toArray()));
        scanner.close();
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        Map<Integer, List<Integer>> storage = new HashMap<>();
        List<Integer> FXs = new ArrayList<>();

        for (int value : sequence) {
            int y = f(value);
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>(Arrays.asList(value)));
                FXs.add(y);
            } else {
                storage.get(y).add(value);
            }
        }

        int totalPairs = 0;
        for (int y : FXs) {
            int count = storage.get(y).size();
            totalPairs += count * count;
        }

        int totalSingleCounts = FXs.stream().mapToInt(y -> storage.get(y).size()).sum();
        return (totalPairs - totalSingleCounts) / 2;
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
}
