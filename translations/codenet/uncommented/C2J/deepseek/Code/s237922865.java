public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int cnt4 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            int wk = scanner.nextInt();
            if (wk % 4 == 0) {
                cnt4++;
            } else if (wk % 2 == 0) {
                cnt2++;
            }
        }

        if (cnt4 + cnt2 / 2 >= n / 2) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
