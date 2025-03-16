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
                if (isIntegerDistance(points[i], points[j], d)) {
                    count++;
                }
            }
        }
        
        System.out.println(count);
        scanner.close();
    }
    
    private static boolean isIntegerDistance(int[] x, int[] y, int d) {
        double tmp = 0.0;
        for (int i = 0; i < d; i++) {
            tmp += Math.pow(x[i] - y[i], 2);
        }
        double distance = Math.sqrt(tmp);
        return distance == Math.floor(distance);
    }
}

// <END-OF-CODE>
