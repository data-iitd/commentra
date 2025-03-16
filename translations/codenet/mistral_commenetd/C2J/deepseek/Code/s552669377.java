import java.util.Scanner;

public class MinMaxSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, tmp;
        long min = 1000000, max = -1000000, sum = 0;

        n = scanner.nextInt();
        System.out.println("Enter the number of integers: ");
        for (int i = 0; i < n; i++) {
            tmp = scanner.nextInt();
            if (min > tmp) min = tmp;
            if (max < tmp) max = tmp;
            sum += tmp;
        }

        System.out.println(min + " " + max + " " + sum);
    }
}
