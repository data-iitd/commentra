
import java.util.Scanner;

public class s065149518{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, m;
        while(~(n = scanner.nextInt())) {
            if(n == 0) {
                break;
            }
            char[][] fld = new char[21][21];
            int x = 10, y = 10;
            for(int i = 0; i < n; i++) {
                int a = scanner.nextInt(), b = scanner.nextInt();
                fld[b][a] = '1';
            }
            m = scanner.nextInt();
            for(int i = 0; i < m; i++) {
                String dir = scanner.next();
                int a = scanner.nextInt();
                switch(dir) {
                    case "N":
                        for(int j = 0; j < a; j++) {
                            y--;
                            if(fld[y][x] == '1') {
                                fld[y][x] = '0';
                                n--;
                            }
                        }
                        break;
                    case "E":
                        for(int j = 0; j < a; j++) {
                            x++;
                            if(fld[y][x] == '1') {
                                fld[y][x] = '0';
                                n--;
                            }
                        }
                        break;
                    case "S":
                        for(int j = 0; j < a; j++) {
                            y++;
                            if(fld[y][x] == '1') {
                                fld[y][x] = '0';
                                n--;
                            }
                        }
                        break;
                    case "W":
                        for(int j = 0; j < a; j++) {
                            x--;
                            if(fld[y][x] == '1') {
                                fld[y][x] = '0';
                                n--;
                            }
                        }
                        break;
                }
            }
            System.out.println(n == 0? "Yes" : "No");
        }
    }
}

