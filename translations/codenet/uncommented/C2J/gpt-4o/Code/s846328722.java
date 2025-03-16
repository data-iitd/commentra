import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] s = new int[100000];
        
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        int count = 0;

        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt();
            if (linearSearch(s, n, t)) {
                count++;
            }
        }
        System.out.println(count);
        scanner.close();
    }

    public static boolean linearSearch(int[] a, int n, int key) {
        int i = 0;
        a[n] = key; // This line is not necessary in Java, but kept for direct translation

        while (a[i] != key) {
            i++;
        }
        return i != n;
    }
}

// <END-OF-CODE>
