import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] input = scanner.nextLine().split(" ");
        int[] a = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
        
        long ans = 0;
        int pre = Integer.MAX_VALUE;
        
        Arrays.sort(a);
        for (int j = n - 1; j >= 0; j--) {
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        
        System.out.println(ans);
    }
}
