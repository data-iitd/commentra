
import java.util.Optional;
import java.util.Scanner;
public final class BoyerMoore {
    private BoyerMoore() {
    }
    public static Optional<Integer> findMajorityElement(int[] array) {
        if (array == null || array.length == 0) {
            return Optional.empty();
        }
        int candidate = findCandidate(array);
        int count = countOccurrences(candidate, array);
        if (isMajority(count, array.length)) {
            return Optional.of(candidate);
        }
        return Optional.empty();
    }
    private static int findCandidate(final int[] array) {
        int count = 0;
        int candidate = -1;
        for (int value : array) {
            if (count == 0) {
                candidate = value;
            }
            count += (value == candidate) ? 1 : -1;
        }
        return candidate;
    }
    private static int countOccurrences(final int candidate, final int[] array) {
        int count = 0;
        for (int value : array) {
            if (value == candidate) {
                count++;
            }
        }
        return count;
    }
    private static boolean isMajority(int count, int totalCount) {
        return 2 * count > totalCount;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        Optional<Integer> majorityElement = findMajorityElement(array);
        if (majorityElement.isPresent()) {
            System.out.println(majorityElement.get());
        } else {
            System.out.println("No majority element");
        }
        scanner.close();
    }
}
