import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = nextInt();
        int L = nextInt();
        Data[] s = new Data[N];

        for (int i = 0; i < N; i++) {
            s[i] = new Data();
            s[i].X = nextString();
        }

        out(N, L, s);
        Arrays.sort(s, Comparator.comparing(data -> data.X));
        out(s);

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < N; i++) {
            ans.append(s[i].X);
        }
        System.out.println(ans.toString());
    }

    static int nextInt() {
        return sc.nextInt();
    }

    static String nextString() {
        return sc.next();
    }

    static void out(Object... x) {
        // System.out.println(Arrays.toString(x));
    }

    static class Data {
        String X;
    }
}

// <END-OF-CODE>
