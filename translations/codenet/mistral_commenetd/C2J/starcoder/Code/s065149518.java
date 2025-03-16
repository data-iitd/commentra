
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, x, y;
        char[][] fld = new char[21][21];
        while(true) {
            n = sc.nextInt();
            if(n < 0) break;
            x = y = 10;
            for(int i = 0; i < 21; i++) Arrays.fill(fld[i], (char)0);
            while(n-- > 0) {
                int a = sc.nextInt(), b = sc.nextInt();
                fld[b][a] = 1;
            }
            m = sc.nextInt();
            while(m-- > 0) {
                char buf[] = sc.next().toCharArray();
                int a = sc.nextInt();
                switch(buf[0]) {
                    case 'N': d = 0; break;
                    case 'E': d = 1; break;
                    case 'S': d = 2; break;
                    case 'W': d = 3; break;
                }
                while(a-- > 0) {
                    if(d % 2) {
                        d % 2? x-- : x++;
                    } else {
                        d? y-- : y++;
                        x += d / 2;
                    }
                    if(fld[y][x]) {
                        fld[y][x] = 0;
                        n--;
                    }
                }
            }
            System.out.println(n == 0? "Yes" : "No");
        }
    }
}

