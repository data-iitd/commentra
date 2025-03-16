public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = sc.nextInt();
        }
        boolean allSame = true;
        for (int i = 1; i < n; i++) {
            if (elems[i] != elems[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            System.out.println(0);
            return;
        }
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        if (!allSame(elems, k - 1, n - 1)) {
            System.out.println(-1);
            return;
        }
        int target = elems[n - 1];
        int toDelete = 0;
        for (int i = 0; i < k - 1; i++) {
            if (elems[i] == target) {
                toDelete++;
            }
        }
        System.out.println(toDelete);
    }

    public static boolean allSame(int[] elems, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            if (elems[i] != elems[start]) {
                return false;
            }
        }
        return true;
    }
}
