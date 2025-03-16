public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        int N = readInt(scanner);
        int[] X = new int[N];
        int[] Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = readInt(scanner);
            Y[i] = X[i];
        }
        
        java.util.Arrays.sort(Y);
        int m1 = Y[N / 2 - 1];
        int m2 = Y[N / 2];
        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                System.out.println(m2);
            } else {
                System.out.println(m1);
            }
        }
    }
    
    private static int readInt(java.util.Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }
    
    private static double readDouble(java.util.Scanner scanner) {
        return Double.parseDouble(scanner.next());
    }
    
    private static String readString(java.util.Scanner scanner) {
        return scanner.next();
    }
    
    private static int max(int a, int b) {
        return a < b ? b : a;
    }
    
    private static int min(int a, int b) {
        return a > b ? b : a;
    }
    
    private static int abs(int a) {
        return a < 0 ? -a : a;
    }
}
