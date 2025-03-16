public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        int[][] matrix = new int[N][D];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        int k = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int m = 0;
                for (int n = 0; n < D; n++) {
                    m += Math.pow(matrix[i][n] - matrix[j][n], 2);
                }
                double l = Math.sqrt(m);
                if (Math.ceil(l) == Math.floor(l)) k++;
            }
        }
        System.out.println(k);
        scanner.close();
    }
}
