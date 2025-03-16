import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int s = Integer.parseInt(input[2]);
        int f = Integer.parseInt(input[3]);

        int d = s < f ? 1 : -1;
        String c = s < f ? "R" : "L";
        StringBuilder res = new StringBuilder();
        int i = 1;
        int j = s;
        while (j != f) {
            if (i > t && k < m) {
                input = scanner.nextLine().split(" ");
                t = Integer.parseInt(input[0]);
                l = Integer.parseInt(input[1]);
                r = Integer.parseInt(input[2]);
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
    }
}
