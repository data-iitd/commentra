import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[sc.nextInt()];
        for (int i = 0; i < a.length; i++) {
            a[i] = sc.nextInt();
        }
        for (int e = 0; e < a.length; e++) {
            if (a[e] == 0) {
                System.out.println(e + 1);
                break;
            }
        }
    }
}
