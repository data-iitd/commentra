
import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, q, i, j, count = 0;
        int[] S = new int[10000];
        int[] T = new int[10000];

        System.out.print("Enter the size of the array S: ");
        n = sc.nextInt();

        System.out.print("Enter " + n + " integers for array S:\n");
        for (i = 0; i < n; i++) {
            System.out.print("Enter integer S[" + i + "]: ");
            S[i] = sc.nextInt();
        }

        System.out.print("Enter the number of queries: ");
        q = sc.nextInt();

        System.out.print("Enter " + q + " integers for array T:\n");
        for (j = 0; j < q; j++) {
            System.out.print("Enter integer T[" + j + "]: ");
            T[j] = sc.nextInt();
        }

        for (j = 0; j < q; j++) {
            int key = T[j];
            if (linearsearch(S, n, key) == 1) {
                count++;
            }
        }

        System.out.print("Number of integers in array S that are not present in array T: " + count + "\n");
    }

    public static int linearsearch(int[] S, int n, int key) {
        int i = 0;
        int count = 0;
        while (S[i]!= key) {
            i++;
            if (i >= n) {
                count = 1;
                return count;
            }
        }
        return 0;
    }
}

