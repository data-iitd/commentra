public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        while (true) {
            int n = scanner.nextInt();
            int r = scanner.nextInt();
            
            if (n == 0 && r == 0) break;
            
            int[] a = new int[100];
            int[] b = new int[100];
            
            for (int i = 0; i < n; i++) {
                a[i] = n - i;
            }
            
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < n; j++) {
                    b[j] = a[j];
                }
                
                int p = scanner.nextInt();
                int c = scanner.nextInt();
                
                for (int j = 0; j < c; j++) {
                    a[j] = b[p - 1 + j];
                }
                
                for (int j = c; j < c + p - 1; j++) {
                    a[j] = b[j - c];
                }
            }
            
            System.out.println(a[0]);
        }
        
        scanner.close();
    }
}
