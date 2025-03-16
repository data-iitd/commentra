public class Main {
    static int[] A = new int[1000000];
    static int n;

    /* 二分探索 */
    static boolean binarySearch(int key) {
        int left = 0;
        int right = n;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if(key == A[mid]) return true; /* keyを発見 */
            if(key > A[mid]) left = mid + 1; /* 後半を探索 */
            else if(key < A[mid]) right = mid; /* 前半を探索 */
        }
        return false;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        for(int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        int sum = 0;
        for(int i = 0; i < q; i++) {
            int k = scanner.nextInt();
            if(binarySearch(k))
                sum++;
        }
        System.out.println(sum);
    }
}
