import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] s = new int[11];
        for (int i = 0; i < 10; i++) {
            s[i] = sc.nextInt();
        }
        for (int i = 9; i > 6; i--) {
            System.out.println(s[i]);
        }
    }
}
