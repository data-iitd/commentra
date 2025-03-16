import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int[][] points = new int[n][d];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = scanner.nextInt();
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isInteger(distance(points[i], points[j]))) {
                    count++;
                }
            }
        }
        
        System.out.println(count);
    }
    
    public static double distance(int[] x, int[] y) {
        double tmp = 0.0;
        for (int i = 0; i < y.length; i++) {
            tmp += Math.pow(x[i] - y[i], 2);
        }
        return Math.sqrt(tmp);
    }
    
    public static boolean isInteger(double value) {
        return value == (int) value;
    }
}
