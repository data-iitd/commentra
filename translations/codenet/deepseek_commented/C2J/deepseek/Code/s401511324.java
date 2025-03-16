public class TriangleCount {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[2001];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        java.util.Arrays.sort(l, 0, n);
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (l[i] + l[j] > l[k]) {
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
