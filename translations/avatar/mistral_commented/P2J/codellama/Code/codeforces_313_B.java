import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String soz = sc.next();
        int[] a = new int[soz.length() + 1];
        for (int i = 1; i < soz.length(); i++) {
            a[i] = a[i - 1];
            if (soz.charAt(i - 1) == soz.charAt(i)) {
                a[i]++;
            }
        }
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            int l = sc.nextInt();
            arr[i] = a[l - 1] - a[m - 1];
        }
        for (int i : arr) {
            System.out.println(i);
        }
    }
}

