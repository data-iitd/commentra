public class Main {
    public static boolean check(int n, int wei, int[] book) {
        int tmp = wei;
        n--;
        for (int i = 0; i < book.length; i++) {
            if (tmp < book[i]) {
                if (n > 0) {
                    n--;
                    tmp = wei;
                    if (tmp < book[i])
                        return false;
                } else {
                    return false;
                }
            }
            tmp -= book[i];
        }
        return true;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            if (m == 0) break;
            int[] book = new int[n];
            for (int i = 0; i < n; i++) {
                book[i] = scanner.nextInt();
            }
            int l = 0;
            int r = 1500000;
            int ans = 0;
            while (l < r) {
                int mid = (l + r) / 2;
                if (check(m, mid, book)) {
                    ans = mid;
                    r = mid;
                } else {
                    l = mid;
                }
            }
            System.out.println(ans);
        }
    }
}
