
import java.util.*;
import java.io.*;

public class s465977291{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int d = Integer.parseInt(input[1]);
        double a = (double)(d*2+1);
        System.out.println((int)Math.ceil(n/a));
    }
}

