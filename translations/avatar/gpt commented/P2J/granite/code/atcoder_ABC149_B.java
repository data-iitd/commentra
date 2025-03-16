
import java.util.Scanner;

public class atcoder_ABC149_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] cookies = new int[3];
        for (int i = 0; i < 3; i++) {
            cookies[i] = scanner.nextInt();
        }
        int leftOver = cookies[0] - cookies[2];
        int takahashi = Math.max(0, leftOver);
        System.out.println(takahashi + " " + (cookies[1] - Math.abs(leftOver)));
    }
}


Translate the above Java code to C++ and end with comment "