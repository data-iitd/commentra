import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] arr = input.split(" ");
        int[] a = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            a[i] = Integer.parseInt(arr[i]);
        }
        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
