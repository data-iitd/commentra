import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int[] numbers = Arrays.stream(scanner.nextLine().split(" "))
                              .mapToInt(Integer::parseInt)
                              .toArray();
        Arrays.sort(numbers);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += numbers[i];
        }
        System.out.println(sum);
    }
}
