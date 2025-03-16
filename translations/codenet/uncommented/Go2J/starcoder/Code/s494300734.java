import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        
        String ans = "No";
        if (s.indexOf("C") < s.lastIndexOf("F")) {
            ans = "Yes";
        }
        if (s.indexOf("C") < 0) {
            ans = "No";
        }
        
        System.out.println(ans);
    }
}
