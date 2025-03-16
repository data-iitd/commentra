import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n, m, s, f
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int s = scanner.nextInt();
        int f = scanner.nextInt();
        
        int d;
        char c;
        if (s < f) {
            d = 1;
            c = 'R';
        } else {
            d = -1;
            c = 'L';
        }
        
        StringBuilder res = new StringBuilder();
        int i = 1;
        int j = s;
        int t, l, r;
        int k = 1;
        
        t = scanner.nextInt();
        l = scanner.nextInt();
        r = scanner.nextInt();
        
        while (j != f) {
            if (i > t && k < m) {
                t = scanner.nextInt();
                l = scanner.nextInt();
                r = scanner.nextInt();
                k++;
            }
            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                res.append('X');
            } else {
                res.append(c);
                j += d;
            }
            i++;
        }
        
        System.out.println(res.toString());
        scanner.close();
    }
}

// <END-OF-CODE>
