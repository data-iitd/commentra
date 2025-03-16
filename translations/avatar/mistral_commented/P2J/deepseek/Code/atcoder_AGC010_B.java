import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Check if the sum of the elements in the array is divisible by the formula
        if (sum(a) % (n * (n + 1) / 2) != 0) {
            System.out.println("NO");
            return;
        }

        // Calculate the average of the elements in the array
        double k = (double) sum(a) / (n * (n + 1) / 2);

        // Add the first element to the end of the array for simplification
        int[] a2 = new int[n + 1];
        System.arraycopy(a, 0, a2, 0, n);
        a2[n] = a[0];

        // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
        if (sumDifferences(a2, k, n) != 0 || sumRatios(a2, k, n) != n) {
            System.out.println("NO");
            return;
        }

        // If all checks pass, print YES
        System.out.println("YES");
    }

    // Helper method to calculate the sum of an array
    private static int sum(int[] array) {
        int sum = 0;
        for (int num : array) {
            sum += num;
        }
        return sum;
    }

    // Helper method to calculate the sum of differences (modulo n)
    private static int sumDifferences(int[] array, double k, int n) {
        int sum = 0;
        for (int i = 1; i < array.length; i++) {
            sum += (int) ((k - array[i - 1] + array[i]) % n);
        }
        return sum;
    }

    // Helper method to calculate the sum of ratios (modulo n)
    private static int sumRatios(int[] array, double k, int n) {
        int sum = 0;
        for (int i = 1; i < array.length; i++) {
            if ((k - array[i - 1] + array[i]) / n >= 0) {
                sum++;
            }
        }
        return sum;
    }
}
