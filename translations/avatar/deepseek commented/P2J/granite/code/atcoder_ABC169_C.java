

import java.io.*;
import java.util.*;

public class atcoder_ABC169_C{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] ab = br.readLine().split(" ");
        int a = Integer.parseInt(ab[0]);
        double b = Double.parseDouble(ab[1]);
        int c = (int)Math.round(b * 100);
        System.out.println(a * c / 100);
    }
}

Translate the above Java code to C++ and end with comment "