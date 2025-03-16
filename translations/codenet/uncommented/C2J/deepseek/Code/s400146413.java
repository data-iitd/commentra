public class LinearSearch {
    public static int linearsearch(int[] S, int n, int key) {
        int i = 0;
        int count = 0;
        while (S[i] != key) {
            i++;
            if (i >= n) {
                count = 1;
                return count;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] S = new int[10000];
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        int[] T = new int[10000];
        for (int j = 0; j < q; j++) {
            T[j] = scanner.nextInt();
        }

        int count = 0;
        for (int j = 0; j < q; j++) {
            int key = T[j];
            if (linearsearch(S, n, key) == 0) {
                count++;
            }
        }

        System.out.println(count);
    }
}
