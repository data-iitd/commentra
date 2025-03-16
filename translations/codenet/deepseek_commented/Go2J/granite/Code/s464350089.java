

import java.util.Scanner;

public class s464350089{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int n = sc.nextInt();
        int a = 0;
        for (int i = 0; i < n; i++) {
            a += sc.nextInt();
        }
        if (h > a) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
