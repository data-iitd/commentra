
import java.util.*;
class s914373115{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        long long x,sum;
        x=sc.nextLong();
        int i;
        sum=100;
        for(i=0;sum<x;++i){
            sum+=sum/100;
        }
        System.out.println(i);
    }
}

