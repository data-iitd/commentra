import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] list = new int[n];
        for (int i = 0; i < n; i++) {
            list[i] = sc.nextInt() % 2;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += list[i];
        }
        if (sum == 1) {
            System.out.println("The first number with remainder 1 is: " + (list.indexOf(1) + 1));
        } else {
            System.out.println("The first number with remainder 0 is: " + (list.indexOf(0) + 1));
        }
    }
}
