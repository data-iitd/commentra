public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[100000];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int cnt = 1;
        boolean isup = a[0] < a[1];
        boolean issame = a[0] == a[1];
        for (int i = 1; i < n - 1; i++) {
            if (issame) {
                if (a[i] != a[i + 1]) {
                    issame = false;
                    isup = a[i] < a[i + 1];
                }
            } else {
                if (isup && a[i] <= a[i + 1]) {
                    // do nothing
                } else if (!isup && a[i] >= a[i + 1]) {
                    // do nothing
                } else {
                    if (i + 2 < n) {
                        isup = a[i + 1] < a[i + 2];
                        if (a[i + 1] == a[i + 2]) {
                            issame = true;
                        } else {
                            issame = false;
                        }
                        cnt++;
                    } else {
                        cnt++;
                        break;
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
