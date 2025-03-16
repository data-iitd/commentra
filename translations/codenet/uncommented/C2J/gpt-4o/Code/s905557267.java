import java.util.Scanner;

public class Main {
    
    public static int min(int a, int b) {
        return (a <= b) ? a : b;
    }

    public static int chain(int[] b, int n) {
        int[] a = new int[10000];
        System.arraycopy(b, 0, a, 0, n);
        
        for (int i = 0; i < n - 4; i++) {
            if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
                int count = 0;
                int color = a[i];
                
                for (int j = i; a[j] == color; j++) {
                    a[j] = 0;
                    count++;
                }
                
                for (int j = 0; i + j + count < 10000; j++) {
                    a[i + j] = a[i + j + count];
                    a[i + j + count] = 0;
                }
                
                i = -1; // Reset i to -1 because it will be incremented to 0 in the next iteration
            }
        }
        
        int count = 0;
        while (count < n && a[count] != 0) {
            count++;
        }
        
        if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
            return 0;
        }
        
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int[] a = new int[10000];
            int n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            int ans = n;
            
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }
            
            for (int i = 0; i < n - 4; i++) {
                int[] count = new int[3];
                for (int j = i; j < i + 4; j++) {
                    if (a[j] - 1 >= 0) {
                        count[a[j] - 1]++;
                    }
                }
                
                int color = 0;
                for (int j = 0; j < 3; j++) {
                    if (count[j] >= 3) {
                        color = j + 1;
                        break;
                    }
                }
                
                if (color != 0) {
                    for (int j = i; j < i + 4; j++) {
                        int buf = a[j];
                        a[j] = color;
                        ans = min(ans, chain(a, n));
                        a[j] = buf;
                    }
                }
            }
            
            System.out.println(ans);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
