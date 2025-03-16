public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int xt = 0, yt = 0;
        int[][] a = {
            {1, 3, 5, 7, 8, 10, 12},
            {4, 6, 9, 11},
            {2}
        };
        for (int i = 0; i < a.length; i++) {
            for (int n : a[i]) {
                if (x == n) {
                    xt = i;
                }
                if (y == n) {
                    yt = i;
                }
            }
        }
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
