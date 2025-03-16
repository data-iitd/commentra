import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] cookies = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            cookies[i] = Integer.parseInt(input[i]);
        }
        int leftOver = cookies[0] - cookies[2];
        int takahashi = Math.max(0, leftOver);
        if (takahashi > 0) {
            System.out.println(takahashi + " " + (cookies[1] - (leftOver < 0 ? leftOver : 0)));
        } else {
            System.out.println(takahashi + " " + Math.max(0, cookies[1] - Math.abs(leftOver)));
        }
    }
}
