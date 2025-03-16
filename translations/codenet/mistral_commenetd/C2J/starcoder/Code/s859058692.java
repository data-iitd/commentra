import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long sum = 0;
        int n, m, i, min, max;
        
        n = sc.nextInt();
        
        for(i=0; i<n; i++){
            m = sc.nextInt();
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
