
import java.util.*;
public class HelloWorld {

    public static void main(String[] args) {
        // your code goes here
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        int d=sc.nextInt();
        int i=a*b;
        int j=c*d;
        if(i>j){
            System.out.println(i);
        }
        else{
            System.out.println(j);
        }
    }
}
