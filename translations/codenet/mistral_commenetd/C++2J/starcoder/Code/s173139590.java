
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of contest results from the standard input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Read each contest result and update the corresponding counter
        int ac_count = 0; // number of AC (Accepted) results
        int wa_count = 0; // number of WA (Wrong Answer) results
        int tle_count = 0; // number of TLE (Time Limit Exceeded) results
        int re_count = 0; // number of RE (Runtime Error) results
        for (int i = 0; i < n; ++i){
            String s = sc.next();
            if (s.equals("AC")){ // if the contest result is AC
                ac_count+=1; // increment the number of AC results
            }else if(s.equals("WA")){ // if the contest result is WA
                wa_count+=1; // increment the number of WA results
            }else if(s.equals("TLE")){ // if the contest result is TLE
                tle_count+=1; // increment the number of TLE results
            }else if(s.equals("RE")){ // if the contest result is RE
                re_count+=1; // increment the number of RE results
            }
        }

        // Print the number of each contest result to the standard output
        System.out.println("AC x " + ac_count);
        System.out.println("WA x " + wa_count);
        System.out.println("TLE x " + tle_count);
        System.out.println("RE x " + re_count);
    }
}

