import java.util.Scanner;

public class Main {
    public static int min(int... nums) {
        int min = nums[0];
        for (int v : nums) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        System.out.println(min(n * a, b));
        scanner.close();
    }
}

// <END-OF-CODE>
