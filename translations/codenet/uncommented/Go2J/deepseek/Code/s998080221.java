public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        int maxProfit = 0;
        int maxCnt = 0;
        int maxA = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            int profit = Math.max(0, maxA - A[i]);
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }
            maxA = Math.max(maxA, A[i]);
        }
        System.out.println(maxCnt);
    }
}
