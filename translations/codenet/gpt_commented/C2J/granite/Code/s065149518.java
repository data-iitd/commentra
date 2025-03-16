
import java.util.Scanner;

public class s065149518{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, x, y;
        char[][] fld;
        int m;
        while(~(n = scanner.nextInt())) {
            init(n);
            m = scanner.nextInt();
            move(m);
            System.out.println(n? "No" : "Yes");
        }
    }

    public static void init(int i) {
        int a, b;
        x = y = 10;
        fld = new char[i][i];
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < i; k++) {
                fld[j][k] = '0';
            }
        }
        while(i-- > 0) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = '1';
        }
    }

    public static void move(int i) {
        int a, d;
        char buf[] = new char[2];
        while(i-- > 0) {
            buf = scanner.next().toCharArray();
            a = scanner.nextInt();
            switch(buf[0]) {
                case 'N':
                    d = 0;
                    break;
                case 'E':
                    d = 1;
                    break;
                case 'S':
                    d = 2;
                    break;
                case 'W':
                    d = 3;
                    break;
            }
            while(a-- > 0) {
                d % 2 == 0? ~-d? x-- : x++ : d == 0? y-- : y++;
                if(fld[y][x] == '1') {
                    fld[y][x] = '0';
                    n--;
                }
            }
        }
    }
}

