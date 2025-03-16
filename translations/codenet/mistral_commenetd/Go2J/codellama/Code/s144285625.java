
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ar = new int[3*n];
        for (int i = 0; i < ar.length; i++) {
            ar[i] = sc.nextInt();
        }
        sort(ar);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar[3*n-(i+1)*2];
        }
        System.out.println(sum);
    }

    public static void sort(int[] ar) {
        for (int i = 0; i < ar.length; i++) {
            for (int j = i+1; j < ar.length; j++) {
                if (ar[i] > ar[j]) {
                    int temp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = temp;
                }
            }
        }
    }
}

