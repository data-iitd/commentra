import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int minA = (int)Math.pow(10,9) + 1;
        int num = 0;
        int f = 0;
        ArrayList<Integer> A = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            A.add(sc.nextInt());
        }
        for(int i = 0; i < n; i++){
            if(minA > A.get(i)){
                minA = A.get(i);
            }else{
                if(f == A.get(i) - minA)num++;
                else if(f < A.get(i) - minA){
                    num = 1;
                    f = A.get(i) - minA;
                }
            }
        }
        System.out.println(num);
    }
}

