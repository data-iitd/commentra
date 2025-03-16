import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line (usually empty)
        int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(a);
        System.out.println(s(a));
    }

    public static String s(int[] a) {
        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                return "YES";
            }
        }
        return "NO";
    }
}
