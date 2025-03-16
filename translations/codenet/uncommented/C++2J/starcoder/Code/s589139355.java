
import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a,t=0,h=0,lt,lh,tt,hh,l;
        a = in.nextInt();
        for(int i=0; i<a; ++i){
            String taro = in.next();
            String hana = in.next();
            lt= taro.length();
            lh= hana.length();
            if(lt>lh){
                l=lt;
            }
            else{
                l=lh;
            }
            tt=0;
            hh=0;

            if(taro.compareTo(hana)>0){
                t=t+3;
            }
            else if(hana.compareTo(taro)>0){
                h=h+3;
            }
            else if(hana.compareTo(taro)==0){
                h=h+1;
                t=t+1;
            }
        }
        System.out.println(t+" "+h);
    }
}
