
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] x = new int[10000];
        int i = 0;
        Scanner sc = new Scanner(System.in);
        x[i] = sc.nextInt();
        while (x[i] != 0) {
            i++;
            x[i] = sc.nextInt();
        }
        for (int j = 0; j < i; j++) {
            System.out.println("Case " + (j + 1) + ": " + x[j]);
        }
    }
}

