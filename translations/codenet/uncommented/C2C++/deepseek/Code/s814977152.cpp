#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int miyukiti(const void* asumisu, const void* mizuhasu) {
	int isihasu = *(const int*)asumisu, matukisu = *(const int*)mizuhasu;
	return isihasu < matukisu ? -1 : isihasu > matukisu;
}

int N;
int A[114514];

int yukinnko;
int tomatu[114514];

int mikakosi[114514];

int sumipe(int hayaminn) {
	int satorina = 0, zaasan = yukinnko - 1;
	while (satorina <= zaasan) {
		int yukati = satorina + (zaasan - satorina) / 2;
		if (tomatu[yukati] == hayaminn) return yukati;
		else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
		else zaasan = yukati - 1;
	}
	return 114513;
}

int main(void) {
	int inorinn;
	int emirinn = 0;
	cin >> N;
	for (inorinn = 0; inorinn < N; inorinn++) {
		cin >> A[inorinn];
		tomatu[inorinn] = A[inorinn];
	}
	sort(tomatu, tomatu + N, miyukiti);
	yukinnko = 1;
	for (inorinn = 1; inorinn < N; inorinn++) {
		if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
			tomatu[yukinnko++] = tomatu[inorinn];
		}
	}
	for (inorinn = 0; inorinn < N; inorinn++) {
		int kugyu = sumipe(A[inorinn]);
		mikakosi[kugyu] = !mikakosi[kugyu];
	}
	for (inorinn = 0; inorinn < yukinnko; inorinn++) {
		if (mikakosi[inorinn]) emirinn++;
	}
	cout << emirinn << endl;
	return 0;
}

