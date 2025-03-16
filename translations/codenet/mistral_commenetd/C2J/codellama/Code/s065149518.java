
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, x, y, m;
        char[][] fld = new char[21][21];
        while(true) {
            n = sc.nextInt();
            if(n <= 0) {
                break;
            }
            x = y = 10;
            for(int i = 0; i < n; i++) {
                fld[sc.nextInt()][sc.nextInt()] = 1;
            }
            m = sc.nextInt();
            for(int i = 0; i < m; i++) {
                char dir = sc.next().charAt(0);
                int steps = sc.nextInt();
                switch(dir) {
                    case 'N':
                        y -= steps;
                        break;
                    case 'E':
                        x += steps;
                        break;
                    case 'S':
                        y += steps;
                        break;
                    case 'W':
                        x -= steps;
                        break;
                }
                if(fld[y][x] == 1) {
                    fld[y][x] = 0;
                    n--;
                }
            }
            System.out.println(n == 0 ? "Yes" : "No");
        }
    }
}

