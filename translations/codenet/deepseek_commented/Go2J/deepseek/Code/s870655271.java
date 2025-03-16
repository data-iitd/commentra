public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int ans = 0;

        // If both N and M are 1, there is only one cell, so the answer is 1.
        if (N == 1 && M == 1) {
            ans = 1;
        } else if (N > 1 && M > 1) {
            // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
            ans = (N - 2) * (M - 2);
        } else {
            // If either N or M is 1, the number of cells is (N*M) - 2.
            ans = (N * M) - 2;
        }

        System.out.println(ans);
    }
}

