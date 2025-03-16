import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long sum = 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
            int m = in.nextInt();
            sum += m;
            if(min > m){
                min = m;
            }
            if(max < m){
                max = m;
            }
        }
        System.out.println(min + " " + max + " " + sum);
    }
}
