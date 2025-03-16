
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        int[] sortedNumbers = new int[n];
        for (int i = 0; i < n; i++) {
            sortedNumbers[i] = numbers[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (sortedNumbers[j] > sortedNumbers[j + 1]) {
                    int temp = sortedNumbers[j];
                    sortedNumbers[j] = sortedNumbers[j + 1];
                    sortedNumbers[j + 1] = temp;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < k; i++) {
            result += sortedNumbers[i];
        }
        System.out.println(result);
    }
}

