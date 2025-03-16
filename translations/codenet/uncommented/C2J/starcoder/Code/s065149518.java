import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, a, b, x = 10, y = 10;
        boolean[][] fld = new boolean[21][21];
        while(sc.hasNext()) {
            n = sc.nextInt();
            if(n == 0) break;
            m = sc.nextInt();
            for(int i = 0; i < n; i++) {
                a = sc.nextInt();
                b = sc.nextInt();
                fld[b][a] = true;
            }
            while(m-- > 0) {
                char buf = sc.next().charAt(0);
                a = sc.nextInt();
                switch(buf) {
                  case 'N':
                    x -= a;
                    break;
                  case 'E':
                    y += a;
                    break;
                  case 'S':
                    x += a;
                    break;
                  case 'W':
                    y -= a;
                    break;
                }
                while(a-- > 0) {
                    if(fld[y][x]) {
                        fld[y][x] = false;
                        n--;
                    }
                    x % 2? x-- : x++;
                    y % 2? y-- : y++;
                }
            }
            System.out.println(n == 0? "Yes" : "No");
        }
    }
}

