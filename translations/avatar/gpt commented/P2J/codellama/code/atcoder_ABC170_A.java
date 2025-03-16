import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] a = sc.nextLine().split(" ");
        for (int e = 0; e < a.length; e++) {
            if (Integer.parseInt(a[e]) == 0) {
                System.out.println(e + 1);
                break;
            }
        }
    }
}
