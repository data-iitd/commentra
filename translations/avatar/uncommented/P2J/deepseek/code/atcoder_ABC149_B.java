import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] cookieInput = scanner.nextLine().split(" ");
        int[] cookies = new int[cookieInput.length];
        for (int i = 0; i < cookieInput.length; i++) {
            cookies[i] = Integer.parseInt(cookieInput[i]);
        }

        int leftOver = cookies[0] - cookies[2];
        int takahashi = Math.max(0, leftOver);

        if (takahashi > 0) {
            System.out.println(takahashi + " " + (cookies[1] - takahashi));
        } else {
            System.out.println(takahashi + " " + Math.max(0, cookies[1] - Math.abs(leftOver)));
        }
    }
}
