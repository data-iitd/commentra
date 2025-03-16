

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
	ull cnt[3], pcnt = 0;
	ull x[3005][3005];
	ull gin[N_MAX];
	ull a[N_MAX + 5];
	ull b[N_MAX + 5];
	ull c[N_MAX + 5];
	ull d[N_MAX + 5];
	ull e[N_MAX * 4];
	ull table[3005][3005];
	ull table2[3005][3005];
	ull table3[3005][3005];
	ull table4[3005][3005];
	ull table5[3005][3005];
	ull table6[3005][3005];
	ull table7[3005][3005];
	ull table8[3005][3005];
	ull table9[3005][3005];
	ull table10[3005][3005];
	ull table11[3005][3005];
	ull table12[3005][3005];
	ull table13[3005][3005];
	ull table14[3005][3005];
	ull table15[3005][3005];
	ull table16[3005][3005];
	ull table17[3005][3005];
	ull table18[3005][3005];
	ull table19[3005][3005];
	ull table20[3005][3005];
	ull table21[3005][3005];
	ull table22[3005][3005];
	ull table23[3005][3005];
	ull table24[3005][3005];
	ull table25[3005][3005];
	ull table26[3005][3005];
	ull table27[3005][3005];
	ull table28[3005][3005];
	ull table29[3005][3005];
	ull table30[3005][3005];
	ull table31[3005][3005];
	ull table32[3005][3005];
	ull table33[3005][3005];
	ull table34[3005][3005];
	ull table35[3005][3005];
	ull table36[3005][3005];
	ull table37[3005][3005];
	ull table38[3005][3005];
	ull table39[3005][3005];
	ull table40[3005][3005];
	ull table41[3005][3005];
	ull table42[3005][3005];
	ull table43[3005][3005];
	ull table44[3005][3005];
	ull table45[3005][3005];
	ull table46[3005][3005];
	ull table47[3005][3005];
	ull table48[3005][3005];
	ull table49[3005][3005];
	ull table50[3005][3005];
	ull table51[3005][3005];
	ull table52[3005][3005];
	ull table53[3005][3005];
	ull table54[3005][3005];
	ull table55[3005][3005];
	ull table56[3005][3005];
	ull table57[3005][3005];
	ull table58[3005][3005];
	ull table59[3005][3005];
	ull table60[3005][3005];
	ull table61[3005][3005];
	ull table62[3005][3005];
	ull table63[3005][3005];
	ull table64[3005][3005];
	ull table65[3005][3005];
	ull table66[3005][3005];
	ull table67[3005][3005];
	ull table68[3005][3005];
	ull table69[3005][3005];
	ull table70[3005][3005];
	ull table71[3005][3005];
	ull table72[3005][3005];
	ull table73[3005][3005];
	ull table74[3005][3005];
	ull table75[3005][3005];
	ull table76[3005][3005];
	ull table77[3005][3005];
	ull table78[3005][3005];
	ull table79[3005][3005];
	ull table80[3005][3005];
	ull table81[3005][3005];
	ull table82[3005][3005];
	ull table83[3005][3005];
	ull table84[3005][3005];
	ull table85[3005];
	ull table86[3005][3005];
	ull table87[3005][3005];
	ull table88[3005][3005];
	ull table89[3005][3005];
	ull table90[3005][3005];
	ull table91[3005][3005];
	ull table92[3005][3005];
	ull table93
	ull table94[3005][3005];
	ull table95[3005][3005];
	ull table96[3005][3005];
	ull table97[3005][3005];
	ull table98[3005][3005];
	ull table99[3005][3005];
	ull table10005][3005];
	ull table101[3005][3005];
	ull table102[3005][3005];
	ull table103[3005][3005];
	ull table104[3005][3005];
	ull table105[3005][3005];
	ull table106[3005][3005];
	ull table107[3005][3005];
	ull table108[3005][3005];
	ull table109[3005][3005];
	ull table110[3005][3005];
	ull table111[3005][3005];
	ull table112[3005][3005];
	ull table113[3005][3005];
	ull table14[3005][3005];
	ull table15[3005][3005];
	ull table16[3005][3005];
	ull table17[3005][3005];
	ull table18[3005][3005];
	ull table19[3005][3005];
	ull table190[3005][3005];
	ull table191[3005][3005];
	ull table192[3005][3005];
	ull table193
	ull table1940[3005][3005];
	ull table195005][3005];
	ull table196

	ull table197
	ull table198[3005][3005];
	ull table199
	ull table2005][3005];
	ull table201

	ull table202[3005][3005];
	ull table2005][3005];
	ull table2101
	ull table202[3005][3005];
	ull table2101
	ull table2102
	ull table2101
	ull table202102
	ull table203
	ull table20401
	ull table202
	ull table203005
	ull table20401
	ull table202
	ull table21005
	ull table201005][3005];
	ull table20005
	ull table201005
	ull table202005
	ull table20102
	ull table2005
	ull table21005
	ull table201
	ull table202005
	ull table201
	ull table202005
	ull table21
	ull table20005
	ull table201
	ull table2005
	ull table201
	ull table2005
	ull table20
	ull table21005
	ull table201
	ull table202
	ull table21
	ull table2005
	ull table201
	ull table21
	ull table2005
	ull table21
	ull table2005
	ull table21
	ull table2005
	ull table201
	ull table2021
	ull table203005
	ull table21
	ull table2005
	ull table1
	ull table201
	ull table21
	ull table2005;
	ull table2005;
	ull table21
	ull table2005;
	ull table2005;
	ull table21
	ull table2005;
	ull table2101;
	ull table2005;
	ull table21
	ull table20005;
	ull table21
	ull table2005;
	ull table2005;
	ull table21
	ull table2005
	ull table201
	ull table2102005;
	ull table201
	ull table2102
	ull table201
	ull table21
	ull table202
	ull table21
	ull table2005;
	ull table21
	ull table2005;
	ull table201
	ull table21
	ull table202
	ull table2101
	ull table2005;
	ull table201
	ull table2021;
	ull table2005;
	ull table201
	ull table2005;
	ull table21
	ull table2005;
	ull table21
	