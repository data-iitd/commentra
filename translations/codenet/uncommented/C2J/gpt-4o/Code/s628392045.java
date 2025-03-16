import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] h = new int[100001];
        int max = -1;
        int flag = 0;

        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
            if (max < h[i]) max = h[i];

            if (max - h[i] >= 2) flag = 1;
        }

        if (flag == 1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }

        scanner.close();
    }
}

// <END-OF-CODE>
