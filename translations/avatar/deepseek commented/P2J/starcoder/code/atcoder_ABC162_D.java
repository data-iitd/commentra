import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        String S = sc.next();
        
        calculate(N, S);
    }
    
    public static void calculate(int n, String s) {
        char[] arr = s.toCharArray();
        
        int rNum = 0;
        int gNum = 0;
        int bNum = 0;
        
        for (char c : arr) {
            if (c == 'R') {
                rNum++;
            } else if (c == 'G') {
                gNum++;
            } else if (c == 'B') {
                bNum++;
            }
        }
        
        int sum = 0;
        
        for (int step = 1; step <= Math.ceil(n / 2.0) + 1; step++) {
            for (int i = 0; i < n - 2 * step; i++) {
                String sub = "" + arr[i] + arr[i + step] + arr[i + step * 2];
                
                if (sub.equals("RGB") || sub.equals("RBG") || sub.equals("BGR") || sub.equals("BRG") || sub.equals("GBR") || sub.equals("GRB")) {
                    sum++;
                }
            }
        }
        
        System.out.println(rNum * gNum * bNum - sum);
    }
}

