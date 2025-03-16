import java.util.Scanner;

public class ThreeLargest {
    public static void main(String[] args) {
        int[] s = new int[11];
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            s[i] = sc.nextInt();
        }

        for (int i = 9; i > 6; i--) {
            System.out.println(s[i]);
        }
    }
}

