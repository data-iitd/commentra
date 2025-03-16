#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables initialization
int mod = 1000000007;
int INF = 1000000007;

// Function to calculate minimum of two integers
int min(int a, int b) {
	return (a < b)? a : b;
}

// Function to calculate minimum cost of visiting all cities in a single tour
int minCost(int **costs, int n, int *rs, int R) {
	// Generating all permutations of starting points
	int **perms = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		perms[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			perms[i][j] = rs[j];
		}
	}
	int **tmp = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp[i][j] = rs[j];
		}
	}
	int **tmp2 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp2[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp2[i][j] = rs[j];
		}
	}
	int **tmp3 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp3[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp3[i][j] = rs[j];
		}
	}
	int **tmp4 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp4[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp4[i][j] = rs[j];
		}
	}
	int **tmp5 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp5[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp5[i][j] = rs[j];
		}
	}
	int **tmp6 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp6[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp6[i][j] = rs[j];
		}
	}
	int **tmp7 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp7[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp7[i][j] = rs[j];
		}
	}
	int **tmp8 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp8[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp8[i][j] = rs[j];
		}
	}
	int **tmp9 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp9[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp9[i][j] = rs[j];
		}
	}
	int **tmp10 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp10[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp10[i][j] = rs[j];
		}
	}
	int **tmp11 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp11[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp11[i][j] = rs[j];
		}
	}
	int **tmp12 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp12[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp12[i][j] = rs[j];
		}
	}
	int **tmp13 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp13[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp13[i][j] = rs[j];
		}
	}
	int **tmp14 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp14[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp14[i][j] = rs[j];
		}
	}
	int **tmp15 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp15[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp15[i][j] = rs[j];
		}
	}
	int **tmp16 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp16[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp16[i][j] = rs[j];
		}
	}
	int **tmp17 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp17[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp17[i][j] = rs[j];
		}
	}
	int **tmp18 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp18[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp18[i][j] = rs[j];
		}
	}
	int **tmp19 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp19[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp19[i][j] = rs[j];
		}
	}
	int **tmp20 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp20[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp20[i][j] = rs[j];
		}
	}
	int **tmp21 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp21[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp21[i][j] = rs[j];
		}
	}
	int **tmp22 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp22[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp22[i][j] = rs[j];
		}
	}
	int **tmp23 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp23[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp23[i][j] = rs[j];
		}
	}
	int **tmp24 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp24[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp24[i][j] = rs[j];
		}
	}
	int **tmp25 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp25[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp25[i][j] = rs[j];
		}
	}
	int **tmp26 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp26[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp26[i][j] = rs[j];
		}
	}
	int **tmp27 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp27[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp27[i][j] = rs[j];
		}
	}
	int **tmp28 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp28[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp28[i][j] = rs[j];
		}
	}
	int **tmp29 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp29[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp29[i][j] = rs[j];
		}
	}
	int **tmp30 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp30[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp30[i][j] = rs[j];
		}
	}
	int **tmp31 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp31[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp31[i][j] = rs[j];
		}
	}
	int **tmp32 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp32[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp32[i][j] = rs[j];
		}
	}
	int **tmp33 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp33[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp33[i][j] = rs[j];
		}
	}
	int **tmp34 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp34[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp34[i][j] = rs[j];
		}
	}
	int **tmp35 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp35[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp35[i][j] = rs[j];
		}
	}
	int **tmp36 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp36[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp36[i][j] = rs[j];
		}
	}
	int **tmp37 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp37[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp37[i][j] = rs[j];
		}
	}
	int **tmp38 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp38[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp38[i][j] = rs[j];
		}
	}
	int **tmp39 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp39[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp39[i][j] = rs[j];
		}
	}
	int **tmp40 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp40[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp40[i][j] = rs[j];
		}
	}
	int **tmp41 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp41[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp41[i][j] = rs[j];
		}
	}
	int **tmp42 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp42[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp42[i][j] = rs[j];
		}
	}
	int **tmp43 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp43[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp43[i][j] = rs[j];
		}
	}
	int **tmp44 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp44[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp44[i][j] = rs[j];
		}
	}
	int **tmp45 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp45[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp45[i][j] = rs[j];
		}
	}
	int **tmp46 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp46[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp46[i][j] = rs[j];
		}
	}
	int **tmp47 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp47[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp47[i][j] = rs[j];
		}
	}
	int **tmp48 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp48[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp48[i][j] = rs[j];
		}
	}
	int **tmp49 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp49[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			tmp49[i][j] = rs[j];
		}
	}
	int **tmp50 = (int **)malloc(sizeof(int *) * R);
	for (int i = 0; i < R; i++) {
		tmp50[i] = (int *)malloc(sizeof(int) * R);
		for (int j = 0; j < R; j++) {
			