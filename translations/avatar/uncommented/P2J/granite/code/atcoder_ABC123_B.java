
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int[][] menu = new int[5][2];
        for(int i=0; i<5; i++){
            String m = sc.next();
            int e = Integer.parseInt(m.substring(m.length()-1));
            if(e==0) e=10;
            menu[i][0] = Integer.parseInt(m);
            menu[i][1] = e;
        }
        Arrays.sort(menu, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[1]-b[1];
            }
        });
        int ans = 0;
        for(int i=1; i<5; i++){
            ans += (int)Math.ceil(menu[i][0]/10.0)*10;
        }
        ans += menu[0][0];
        System.out.println(ans);
    }
}

