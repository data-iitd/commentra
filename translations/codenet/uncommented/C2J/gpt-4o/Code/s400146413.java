import java.util.Scanner;

public class LinearSearch {
    public static int linearSearch(int[] S, int n, int key) {
        int i = 0;
        while (i < n && S[i] != key) {
            i++;
        }
        return (i >= n) ? 1 : 0; // Return 1 if not found, 0 if found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] S = new int[n];
        
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        int[] T = new int[q];
        
        for (int j = 0; j < q; j++) {
            T[j] = scanner.nextInt();
        }

        int count = 0;
        for (int j = 0; j < q; j++) {
            int key = T[j];
            if (linearSearch(S, n, key) == 1) {
                count++;
            }
        }

        System.out.println(count);
        scanner.close();
    }
}

// <END-OF-CODE>
