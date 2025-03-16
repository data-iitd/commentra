public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        int[][] point = new int[n + 1][d + 1];
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= d; j++) {
                point[i][j] = scanner.nextInt();
            }
        }
        
        int count = 0;
        
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = 0;
                for (int k = 1; k <= d; k++) {
                    sum += Math.pow(point[i][k] - point[j][k], 2);
                }
                double kyori = Math.sqrt(sum);
                
                if (Math.ceil(kyori) == Math.floor(kyori)) {
                    count++;
                }
            }
        }
        
        System.out.println(count);
    }
}
