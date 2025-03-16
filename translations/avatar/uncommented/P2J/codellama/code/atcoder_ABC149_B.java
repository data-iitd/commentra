
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] cookies = new int[3];
        for (int i = 0; i < cookies.length; i++) {
            cookies[i] = sc.nextInt();
        }
        int leftOver = cookies[0] - cookies[2];
        int takahashi = Math.max(0, leftOver);
        System.out.print(takahashi + " ");
        if (takahashi > 0) {
            System.out.print(cookies[1]);
        } else {
            System.out.print(Math.max(0, cookies[1] - Math.abs(leftOver)));
        }
        sc.close();
    }
}

