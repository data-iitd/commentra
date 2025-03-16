import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long h = sc.nextLong();
        long w = sc.nextLong();
        String target = "snuke";
        
        for (long i = 0; i < h; i++) {
            for (long j = 0; j < w; j++) {
                String t = sc.next();
                if (target.equals(t)) {
                    char c = (char) ('A' + j);
                    System.out.println(c + "" + (i + 1));
                    return;
                }
            }
        }
        
        sc.close();
    }
}

/* <END-OF-CODE> */
