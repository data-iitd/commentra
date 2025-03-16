import java.util.Arrays;
import java.util.Scanner;

class Data implements Comparable<Data> {
    String X;

    @Override
    public int compareTo(Data other) {
        return this.X.compareTo(other.X);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        Data[] s = new Data[N];

        for (int i = 0; i < N; i++) {
            s[i] = new Data();
            s[i].X = scanner.next();
        }

        Arrays.sort(s);

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < N; i++) {
            ans.append(s[i].X);
        }
        System.out.println(ans.toString());
    }
}
