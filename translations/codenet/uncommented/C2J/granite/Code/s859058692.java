
import java.util.Scanner;
public class s859058692{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum = 0;
        int min = 0;
        int max = 0;
        for(int i=0; i<n; i++){
            int m = sc.nextInt();
            sum += m;
            if(i == 0){
                min = m;
                max = m;
            }
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
//END-OF-CODE