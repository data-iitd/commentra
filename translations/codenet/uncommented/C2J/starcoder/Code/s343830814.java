import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int len = line.length();
        System.out.println(line.charAt(0) + (len-3) + line.charAt(len-2));
    }
}
