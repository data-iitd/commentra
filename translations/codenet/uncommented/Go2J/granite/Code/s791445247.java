
// by syu
import java.io.*;
import java.util.*;

class s791445247 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        if (n % k == 0) {
            System.out.println(0);
        } else {
            System.out.println(1);
        }
    }
}

class Scanner {
    BufferedReader r;
    StreamTokenizer st;

    public Scanner(InputStream in) {
        r = new BufferedReader(new InputStreamReader(in));
        st = new StreamTokenizer(r);
    }

    int nextInt() {
        try {
            st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return (int) st.nval;
    }
}

