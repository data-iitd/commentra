#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
#define sig(x) (fabs(x)<1e-8?0:(x)<0?-1:1)
#define btw(x,a,b) (sig((x).x-(a).x)*sig((x).y-(a).y))
#define dis(a,b) sqrt((a).x-(b).x)*(a).x-(b).x)
#define dot(a,b) ((a).x*(b).x+(a).y*(b).y)
#define cross(a,b) ((a).x*(b).y-(a).y*(b).x)
#define cos(o,a,b) (dot(o,a,b)/dis(o,a)/dis(o,b))
typedef struct Point{
	double x,y;
	double k;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	void set(double x,double y){
		this->x=x;
		this->y=y;
	}
	double mod(){
		return sqrt(x*x+y*y);
	}
	double mod_pow(){
		return x*x+y*y;
	}
	void output(){
		printf("x = %f, y = %f\n",x,y);
	}
	bool operator < (const Point &p) const {
		return sig(x-p.x)!=0?x<p.x:sig(y-p.y)<0;
	}
}P[110];
int ch[110];
double ang[110],ans[110];
int main(){
	int n,xx,yy;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&xx,&yy);
		P[i].set(xx,yy);
	}
	if(n==2){
		printf("0.5\n");
		printf("0.5\n");
	}else{
		int m=jarvis(P,n,ch);
		double sum=0;
		if(m==2){
			ans[ch[0]]=0.5;
			ans[ch[1]]=0.5;
		}else{
			for(int i=0;i<m;i++){
				ang[ch[i]]=PI-acos(cos(P[ch[i]],P[ch[(i-1+m)%m]],P[ch[(i+1)%m]]));
			}
			for(int i=0;i<n;i++){
				ans[i]=ang[i]/2./PI;
			}
		}
		for(int i=0;i<n;i++){
			printf("%.20f\n",ans[i]);
		}
	}
	return 0;
}

