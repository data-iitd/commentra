import java.util.Arrays;
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
        
        Arrays.sort(numbers);
        
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += numbers[i];
        }
        
        System.out.println(sum);
    }
}
