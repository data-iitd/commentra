   import java.util.*;
     
    public class Main{
    	static int n,m,l,r,vi,fa[100005],v[200005];
     
    	static int get(int x){
    		if(x==fa[x])return x;
    		int f=get(fa[x]);
    		v[x]+=v[fa[x]];
    		return fa[x]=f;
    	}
     
    	public static void main(String[] args){
    		Scanner cin=new Scanner(System.in);
    		n=cin.nextInt();m=cin.nextInt();
    		for(int i=1;i<=n;i++)fa[i]=i;
    		for(int i=1;i<=m;i++){
    			l=cin.nextInt();r=cin.nextInt();vi=cin.nextInt();
    			int li=get(l),ri=get(r);
    			if(li!=ri){
    				v[ri]=vi-v[r]+v[l];
    				fa[ri]=li;
    			}else{
    				if(v[r]-v[l]!=vi){
    					System.out.println("No");
    					return;
    				}
    			}
    		}
    		System.out.println("Yes");
    	}
    }
    