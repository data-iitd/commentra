import java.util.*;
public class HelloWorld {

    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc=new Scanner(System.in);
        int a,b,x,w;
        while(sc.hasNextInt())
        {
            a=sc.nextInt();
            b=sc.nextInt();
            x=a+b;
            w=0;
            while(x!=0)
            {
                w++;
                x/=10;
            }
            System.out.println(w);
        }
    }
}
