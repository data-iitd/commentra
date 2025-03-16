
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int e = sc.nextInt();
        int[] al = {a, b, c, d, e};
        for (int i = 0; i < al.length; i++) {
            if (al[i] == 0) {
                System.out.println(i + 1);
                break;
            }
        }
    }
}

