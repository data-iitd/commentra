import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, a, b, x = 10, y = 10;
        boolean[][] fld = new boolean[21][21];
        while(~(n = sc.nextInt())) {
            for(int i = 0; i < n; i++) {
                a = sc.nextInt();
                b = sc.nextInt();
                fld[b][a] = true;
            }
            m = sc.nextInt();
            while(m-- > 0) {
                char buf[] = sc.next().toCharArray();
                a = sc.nextInt();
                switch(buf[0]) {
                    case 'N':
                        y -= a;
                        break;
                    case 'E':
                        x += a;
                        break;
                    case 'S':
                        y += a;
                        break;
                    case 'W':
                        x -= a;
                        break;
                }
                if(fld[y][x]) {
                    fld[y][x] = false;
                    n--;
                }
            }
            System.out.println(n == 0? "Yes" : "No");
        }
    }
}

