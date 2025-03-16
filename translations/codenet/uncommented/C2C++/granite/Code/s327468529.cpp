

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <array>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define BEGCMP(NAME) int32_t NAME (const void *left, const void *right)
#define DEFLR(TYPE) TYPE l=*(TYPE*)left,r=*(TYPE*)right
#define CMPRET(L, R) if((L)<(R))return-1;if((L)>(R))return+1

// int32_t pullcomp (const void *left, const void *right) {
// 	ull l = *(ull*)left;
// 	ull r = *(ull*)right;
// 	if (l < r) {
// 		return -1;
// 	}
// 	if (l > r) {
// 		return +1;
// 	}
// 	return 0;
// }
BEGCMP(pullcomp){
	DEFLR(ull);
	CMPRET(l, r);
	return 0;
}
BEGCMP(prevcomp){
	DEFLR(sll);
	CMPRET(r, l);
	return 0;
}
BEGCMP(psllcomp){
	DEFLR(sll);
	CMPRET(l, r);
	return 0;
}
BEGCMP(pcharcomp){
	DEFLR(char);
	CMPRET(l, r);
	return 0;
}
BEGCMP(pdoublecomp){
	DEFLR(double);
	CMPRET(l, r);
	return 0;
}

int32_t pstrcomp (const void *left, const void *right) {
	char* l = *(char**)left;
	char* r = *(char**)right;

	return strcmp(l, r);
}

BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}
BEGCMP(phwllREVcomp){
	DEFLR(hwll);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	return 0;
}
BEGCMP(ptriplecomp){
	DEFLR(hwllc);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}
BEGCMP(ptripleREVcomp){
	DEFLR(hwllc);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	return 0;
}
BEGCMP(ptripleCABcomp){
	DEFLR(hwllc);
	CMPRET(l.c, r.c);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}
BEGCMP(phwrealcomp){
	DEFLR(hwreal);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

int32_t pquadcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}
int32_t pfracomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	ull result = 0;
	ull maybe = 0;
	ull sum = 0;
	ull cnt[3] = {0};
	ull pcnt = 0;
	ull *dpcell;

	ull ncr (sll n, sll r) {
	ull invf[N_MAX * 3];
	ull a[N_MAX + 5];
	ull b[N_MAX + 5];
	ull c[N_MAX + 5];
	ull d[N_MAX + 5];
	ull e[N_MAX * 4];
	ull table[3001][3001];
	ull gin[N_MAX];
	ull x[3001][3001];
	ull *dpcell;
	ull *dpcell2;
	ull *dpcell3;
	ull *dpcell4;
	ull *dpcell5;
	ull *dpcell6;
	ull *dpcell7;
	ull *dpcell8;
	ull *dpcell9;
	ull *dpcell10;
	ull *dpcell11;
	ull *dpcell12;
	ull *dpcell13;
	ull *dpcell14;
	ull *dpcell15;
	ull *dpcell16;
	ull *dpcell17;
	ull *dpcell18;
	ull *dpcell19;
	ull *dpcell20;
	ull *dpcell21;
	ull *dpcell22;
	ull *dpcell23;
	ull *dpcell24;
	ull *dpcell25;
	ull *dpcell26;
	ull *dpcell27;
	ull *dpcell28;
	ull *dpcell29;
	ull *dpcell30;
	ull *dpcell31;
	ull *dpcell32;
	ull *dpcell33;
	ull *dpcell34;
	ull *dpcell35;
	ull *dpcell36;
	ull *dpcell37;
	ull *dpcell38;
	ull *dpcell39;
	ull *dpcell40;
	ull *dpcell41;
	ull *dpcell42;
	ull *dpcell43;
	ull *dpcell44;
	ull *dpcell45;
	ull *dpcell46;
	ull *dpcell47;
	ull *dpcell48;
	ull *dpcell49;
	ull *dpcell50;
	ull *dpcell51;
	ull *dpcell52;
	ull *dpcell53;
	ull *dpcell54;
	ull *dpcell55;
	ull *dpcell56;
	ull *dpcell57;
	ull *dpcell58;
	ull *dpcell59;
	ull *dpcell60;
	ull *dpcell61;
	ull *dpcell62;
	ull *dpcell63;
	ull *dpcell64;
	ull *dpcell65;
	ull *dpcell66;
	ull *dpcell67;
	ull *dpcell68;
	ull *dpcell69;
	ull *dpcell70;
	ull *dpcell71;
	ull *dpcell72;
	ull *dpcell73;
	ull *dpcell74;
	ull *dpcell75;
	ull *dpcell76;
	ull *dpcell77;
	ull *dpcell78;
	ull *dpcell79;
	ull *dpcell80;
	ull *dpcell81;
	ull *dpcell82;
	ull *dpcell83;
	ull *dpcell84;
	ull *dpcell85;
	ull *dpcell86;
	ull *dpcell87;
	ull *dpcell88;
	ull *dpcell89;
	ull *dpcell90;
	ull *dpcell91;
	ull *dpcell92;
	ull *dpcell93;
	ull *dpcell94;
	ull *dpcell95;
	ull *dpcell96;
	ull *dpcell97;
	ull *dpcell98;
	ull *dpcell99;
	ull *dpcell100;
	ull *dpcell101;
	ull *dpcell102;
	ull *dpcell103;
	ull *dpcell104;
	ull *dpcell105;
	ull *dpcell106;
	ull *dpcell107;
	ull *dpcell108;
	ull *dpcell109;
	ull *dpcell110;
	ull *dpcell111;
	ull *dpcell112;
	ull *dpcell113;
	ull *dpcell114;
	ull *dpcell115;
	ull *dpcell116;
	ull *dpcell117;
	ull *dpcell118;
	ull *dpcell119;
	ull *dpcell120;
	ull *dpcell121;
	ull *dpcell122;
	ull *dpcell123;
	ull *dpcell124;
	ull *dpcell125;
	ull *dpcell126;
	ull *dpcell127;
	ull *dpcell128;
	ull *dpcell129;
	ull *dpcell130;
	ull *dpcell131;
	ull *dpcell132;
	ull *dpcell133;
	ull *dpcell134;
	ull *dpcell135;
	ull *dpcell136;
	ull *dpcell137;
	ull *dpcell138;
	ull *dpcell139;
	ull *dpcell140;
	ull *dpcell141;
	ull *dpcell142;
	ull *dpcell143;
	ull *dpcell144;
	ull *dpcell145;
	ull *dpcell146;
	ull *dpcell147;
	ull *dpcell148;
	ull *dpcell149;
	ull *dpcell150;
	ull *dpcell151;
	ull *dpcell152;
	ull *dpcell153;
	ull *dpcell154;
	ull *dpcell155;
	ull *dpcell156;
	ull *dpcell157;
	ull *dpcell158;
	ull *dpcell159;
	ull *dpcell160;
	ull *dpcell161;
	ull *dpcell162;
	ull *dpcell163;
	ull *dpcell164;
	ull *dpcell165;
	ull *dpcell166;
	ull *dpcell167;
	ull *dpcell168;
	ull *dpcell169;
	ull *dpcell170;
	ull *dpcell171;
	ull *dpcell172;
	ull *dpcell173;
	ull *dpcell174;
	ull *dpcell175;
	ull *dpcell176;
	ull *dpcell177;
	ull *dpcell178;
	ull *dpcell179;
	ull *dpcell180;
	ull *dpcell181;
	ull *dpcell182;
	ull *dpcell183;
	ull *dpcell184;
	ull *dpcell185;
	ull *dpcell186;
	ull *dpcell187;
	ull *dpcell188;
	ull *dpcell189;
	ull *dpcell190;
	ull *dpcell191;
	ull *dpcell192;
	ull *dpcell193;
	ull *dpcell194;
	ull *dpcell195;
	ull *dpcell196

	ull *dpcell197;
	ull *dpcell198;
	ull *dpcell199;
	ull *dpcell1910;
	ull *dpcell192;
	ull *dpcell193;
	ull *dpcell194;
	ull *dpcell195;
	ull *dpcell196;
	ull *dpcell197;
	ull *dpcell198;
	ull *dpcell199;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell190;
	ull *dpcell191;
	ull *dpcell1920;
	ull *dpcell1930;
	ull *dpcell1940;
	ull *dpcell1950;
	ull *dpcell1960;
	ull *dpcell1970;
	ull *dpcell190;
	ull *dpcell191920;
	ull *dpcell1930;
	ull *dpcell1940;
	ull *dpcell1910;
	ull *dpcell192;
	ull *dpcell193;
	ull *dpcell194;
	ull *dpcell1950;
	ull *dpcell1960;
	ull *dpcell1970;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19
	ull *dpcell19;
	ull *dpcell1940;
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *dpcell19;
	ull *d