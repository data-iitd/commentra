import java.util.Scanner;

public class Main {
    static final int N = 1000000;
    static final int Q = 50000;
    static int n;
    static int[] S = new int[N];
    static int[] T = new int[Q];

    public static int binarySearch(int key) {
        int left = 0, right = n, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (S[mid] == key) return 1;
            else if (key < S[mid]) right = mid;
            else left = mid + 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }
        
        int q = scanner.nextInt();
        int c = 0;
        for (int i = 0; i < q; i++) {
            T[i] = scanner.nextInt();
            if (binarySearch(T[i]) == 1) c++;
        }
        
        System.out.println(c);
        
        scanner.close();
    }
}

// <END-OF-CODE>
