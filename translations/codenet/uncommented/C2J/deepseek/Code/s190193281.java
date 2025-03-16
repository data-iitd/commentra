public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] S = new int[n];
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int[] T = new int[q];
        for (int i = 0; i < q; i++) {
            T[i] = scanner.nextInt();
        }
        int c = 0;
        for (int i = 0; i < q; i++) {
            if (binarySearch(S, T[i], n) == 1) {
                c++;
            }
        }
        System.out.println(c);
    }

    public static int binarySearch(int[] S, int key, int n) {
        int left = 0, right = n, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (S[mid] == key) {
                return 1;
            } else if (key < S[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
}
