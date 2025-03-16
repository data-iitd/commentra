import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int sum = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                sum += arr[i];
            } else {
                odd++;
            }
        }
        int even = n - odd;
        int[] sorted = new int[n];
        for (int i = 0; i < n; i++) {
            sorted[i] = arr[i];
        }
        Arrays.sort(sorted);
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (sorted[i] % 2 == 0) {
                sum += sorted[i];
                even--;
            } else {
                if (even > 0) {
                    sum += sorted[i];
                    even--;
                } else {
                    j++;
                }
            }
        }
        System.out.println(sum);
    }
}

