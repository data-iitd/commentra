import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Integer> l = new ArrayList<>();
        String[] strs = br.readLine().split(" ");
        for (String s : strs) {
            l.add(Integer.parseInt(s));
        }
        Collections.sort(l);
        int c = 0;
        for (int i : l) {
            if (i > c) {
                c += 1;
            }
        }
        System.out.println(c + 1);
    }
}
