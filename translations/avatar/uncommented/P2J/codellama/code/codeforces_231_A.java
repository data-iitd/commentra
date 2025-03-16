import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = 0;
        for (int i = 0; i < n; i++) {
            int[] l1 = new int[n];
            for (int j = 0; j < n; j++) {
                l1[j] = sc.nextInt();
            }
            if (sum(l1) > 1) {
                c++;
            }
        }
        System.out.println(c);
    }

    public static int sum(int[] l1) {
        int sum = 0;
        for (int i = 0; i < l1.length; i++) {
            sum += l1[i];
        }
        return sum;
    }
}

