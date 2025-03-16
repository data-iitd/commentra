import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] L = new int[100000];
        int r = 1;
        for (int k : sc.next().split(" ")) {
            for (int i = 0; i < Integer.parseInt(k); i++) {
                L[r] = r;
                r++;
            }
        }
        sc.nextLine();
        for (int j : sc.next().split(" ")) {
            System.out.println(L[Integer.parseInt(j) - 1]);
        }
    }
}
