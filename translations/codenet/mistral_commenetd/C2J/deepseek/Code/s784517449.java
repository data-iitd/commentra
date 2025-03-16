public class BinarySearch {
    static int[] A = new int[1000000];
    static int n;

    public static int binarySearch(int key) {
        int left = 0;
        int right = n;
        int mid;

        while (left < right) {
            mid = (left + right) / 2;
            if (key == A[mid]) {
                return 1;
            }
            if (key > A[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int sum = 0;
        for (int i = 0; i < q; i++) {
            int k = scanner.nextInt();
            if (binarySearch(k) == 1) {
                sum++;
            }
        }
        System.out.println(sum);
    }
}
