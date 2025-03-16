public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[] foods = new int[m];

        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();

            for (int j = 0; j < k; j++) {
                int temp = scanner.nextInt();
                temp--;

                foods[temp]++;
            }
        }

        int ans = 0;
        for (int elem : foods) {
            if (elem == n) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}
