
import java.util.*;
import java.io.*;

class s970719454 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        
        while(true){
            line = br.readLine();
            String[] str = line.split(" ");
            int n = Integer.parseInt(str[0]);
            int m = Integer.parseInt(str[1]);
            
            if(n == 0) break;
            
            int[] here = new int[100001];
            int[] dp1 = new int[100001];
            int[] dp2 = new int[100001];
            
            boolean dpflg = false;
            
            for(int i = 0; i < m; i++){
                int a = Integer.parseInt(br.readLine());
                if(a == 0) dpflg = true;
                here[a] = 1;
            }
            
            int maxi1 = 0;
            int maxi2 = 0;
            
            for(int i = 1; i <= n; i++){
                if(here[i] == 1) dp1[i] = dp1[i - 1] + 1;
                maxi1 = Math.max(dp1[i], maxi1);
            }
            
            for(int i = 1; i <= n; i++){
                if(here[i] == 1) dp2[i] = dp2[i - 1] + 1;
                else dp2[i] = dp1[i - 1] + 1;
                maxi2 = Math.max(dp2[i], maxi2);
            }
            
            if(!dpflg){
                System.out.println(maxi1);
            } else {
                System.out.println(maxi2);
            }
        }
    }
}

