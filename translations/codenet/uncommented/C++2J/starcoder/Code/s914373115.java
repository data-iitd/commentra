import java.util.*;
public class Main{
    public static void main(String[] args){
        B();
    }
    static void B(){
        long x,sum;
        Scanner sc=new Scanner(System.in);
        x=sc.nextLong();
        sum=100;
        int i;
        for(i=0;sum<x;++i){
            sum+=sum/100;
        }
        System.out.println(i);
    }
}
