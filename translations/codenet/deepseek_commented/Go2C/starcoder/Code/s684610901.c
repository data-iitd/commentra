#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000000
#define INF 1000000000

typedef struct {
	int64_t index;
	int64_t p1, p2;
} pair;

typedef struct {
	pair *data;
	int64_t size;
	int64_t capacity;
} pairs;

typedef struct {
	int64_t *data;
	int64_t size;
	int64_t capacity;
} Int64Slice;

pair* pair_new(int64_t index, int64_t p1, int64_t p2) {
	pair *p = (pair*)malloc(sizeof(pair));
	p->index = index;
	p->p1 = p1;
	p->p2 = p2;
	return p;
}

void pair_free(pair *p) {
	free(p);
}

pairs* pairs_new(int64_t capacity) {
	pairs *p = (pairs*)malloc(sizeof(pairs));
	p->data = (pair*)malloc(sizeof(pair) * capacity);
	p->size = 0;
	p->capacity = capacity;
	return p;
}

void pairs_free(pairs *p) {
	for (int64_t i = 0; i < p->size; i++) {
		pair_free(p->data[i]);
	}
	free(p->data);
	free(p);
}

void pairs_add(pairs *p, pair *data) {
	if (p->size == p->capacity) {
		p->capacity *= 2;
		p->data = (pair*)realloc(p->data, sizeof(pair) * p->capacity);
	}
	p->data[p->size] = *data;
	p->size++;
}

int64_t pairs_get_index(pairs *p, int64_t i) {
	return p->data[i].index;
}

int64_t pairs_get_p1(pairs *p, int64_t i) {
	return p->data[i].p1;
}

int64_t pairs_get_p2(pairs *p, int64_t i) {
	return p->data[i].p2;
}

bool pairs_less(pairs *p, int64_t i, int64_t j) {
	return p->data[i].index < p->data[j].index;
}

void pairs_swap(pairs *p, int64_t i, int64_t j) {
	pair tmp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = tmp;
}

void pairs_sort(pairs *p) {
	qsort(p->data, p->size, sizeof(pair), (int (*)(const void *, const void *))pairs_less);
}

Int64Slice* Int64Slice_new(int64_t capacity) {
	Int64Slice *p = (Int64Slice*)malloc(sizeof(Int64Slice));
	p->data = (int64_t*)malloc(sizeof(int64_t) * capacity);
	p->size = 0;
	p->capacity = capacity;
	return p;
}

void Int64Slice_free(Int64Slice *p) {
	free(p->data);
	free(p);
}

void Int64Slice_add(Int64Slice *p, int64_t data) {
	if (p->size == p->capacity) {
		p->capacity *= 2;
		p->data = (int64_t*)realloc(p->data, sizeof(int64_t) * p->capacity);
	}
	p->data[p->size] = data;
	p->size++;
}

int64_t Int64Slice_get(Int64Slice *p, int64_t i) {
	return p->data[i];
}

bool Int64Slice_less(Int64Slice *p, int64_t i, int64_t j) {
	return p->data[i] < p->data[j];
}

void Int64Slice_swap(Int64Slice *p, int64_t i, int64_t j) {
	int64_t tmp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = tmp;
}

void Int64Slice_sort(Int64Slice *p) {
	qsort(p->data, p->size, sizeof(int64_t), (int (*)(const void *, const void *))Int64Slice_less);
}

bool Int64Slice_are_sorted(Int64Slice *p) {
	for (int64_t i = 1; i < p->size; i++) {
		if (p->data[i] < p->data[i-1]) {
			return false;
		}
	}
	return true;
}

int64_t* double_ary_new(int64_t h, int64_t w, int64_t init) {
	int64_t **res = (int64_t**)malloc(sizeof(int64_t*) * h);
	for (int64_t i = 0; i < h; i++) {
		res[i] = (int64_t*)malloc(sizeof(int64_t) * w);
		for (int64_t j = 0; j < w; j++) {
			res[i][j] = init;
		}
	}
	return res;
}

void double_ary_free(int64_t **res, int64_t h, int64_t w) {
	for (int64_t i = 0; i < h; i++) {
		free(res[i]);
	}
	free(res);
}

bool ary_eq(int64_t *a, int64_t *b, int64_t n) {
	for (int64_t i = 0; i < n; i++) {
		if (a[i]!= b[i]) {
			return false;
		}
	}
	return true;
}

int64_t* clone(int64_t *n, int64_t n_size) {
	int64_t *r = (int64_t*)malloc(sizeof(int64_t) * n_size);
	for (int64_t i = 0; i < n_size; i++) {
		r[i] = n[i];
	}
	return r;
}

void write(char *s) {
	fputs(s, stdout);
}

void print() {
	fflush(stdout);
}

char* read_line() {
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	return line;
}

int64_t read_int() {
	char *line = read_line();
	int64_t val = strtol(line, NULL, 10);
	free(line);
	return val;
}

double read_float() {
	char *line = read_line();
	double val = strtod(line, NULL);
	free(line);
	return val;
}

int64_t* read_runes() {
	char *line = read_line();
	int64_t *runes = (int64_t*)malloc(sizeof(int64_t) * strlen(line));
	for (int64_t i = 0; i < strlen(line); i++) {
		runes[i] = line[i];
	}
	free(line);
	return runes;
}

char* read_string() {
	char *line = read_line();
	return line;
}

char** read_strings() {
	char *line = read_line();
	char **strs = (char**)malloc(sizeof(char*) * strlen(line));
	for (int64_t i = 0; i < strlen(line); i++) {
		strs[i] = (char*)malloc(sizeof(char) * 2);
		strs[i][0] = line[i];
		strs[i][1] = '\0';
	}
	free(line);
	return strs;
}

int64_t s2i(char *s) {
	int64_t val = strtol(s, NULL, 10);
	return val;
}

char* i2s(int64_t i) {
	char *s = (char*)malloc(sizeof(char) * 20);
	sprintf(s, "%ld", i);
	return s;
}

double s2f(char *s) {
	double val = strtod(s, NULL);
	return val;
}

int64_t abs(int64_t i) {
	return (i < 0)? -i : i;
}

int64_t max(int64_t a, int64_t b) {
	return (a > b)? a : b;
}

int64_t min(int64_t a, int64_t b) {
	return (a < b)? a : b;
}

int64_t sum(int64_t *i, int64_t i_size) {
	int64_t sum = 0;
	for (int64_t i = 0; i < i_size; i++) {
		sum += i[i];
	}
	return sum;
}

char** split(char *s) {
	char **strs = NULL;
	int64_t strs_size = 0;
	char *token = strtok(s, " ");
	while (token!= NULL) {
		strs = (char**)realloc(strs, sizeof(char*) * (strs_size + 1));
		strs[strs_size] = (char*)malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(strs[strs_size], token);
		strs_size++;
		token = strtok(NULL, " ");
	}
	return strs;
}

int64_t* str_ary2int_ary(char **strs, int64_t strs_size) {
	int64_t *ret = (int64_t*)malloc(sizeof(int64_t) * strs_size);
	for (int64_t i = 0; i < strs_size; i++) {
		ret[i] = s2i(strs[i]);
	}
	return ret;
}

char** int_ary2str_ary(int64_t *nums, int64_t nums_size) {
	char **ret = (char**)malloc(sizeof(char*) * nums_size);
	for (int64_t i = 0; i < nums_size; i++) {
		ret[i] = i2s(nums[i]);
	}
	return ret;
}

char* ary2str(char **strs, int64_t strs_size) {
	char *ret = (char*)malloc(sizeof(char) * (strs_size + 1));
	for (int64_t i = 0; i < strs_size; i++) {
		strcat(ret, strs[i]);
		if (i!= strs_size - 1) {
			strcat(ret, " ");
		}
	}
	return ret;
}

void reverse(int64_t *res, int64_t res_size) {
	for (int64_t i = 0; i < res_size / 2; i++) {
		int64_t tmp = res[i];
		res[i] = res[res_size - i - 1];
		res[res_size - i - 1] = tmp;
	}
}

void reverse_str(char **res, int64_t res_size) {
	for (int64_t i = 0; i < res_size / 2; i++) {
		char *tmp = res[i];
		res[i] = res[res_size - i - 1];
		res[res_size - i - 1] = tmp;
	}
}

void ini(int64_t *res, int64_t res_size, int64_t init) {
	if (res_size == 0) {
		return;
	}
	res[0] = init;
	for (int64_t i = 0; i < res_size; i++) {
		memcpy(res + i, res, sizeof(int64_t) * i);
	}
}

int main() {
	int64_t A, B, C;
	scanf("%ld %ld %ld", &A, &B, &C);
	if (C >= A && C <= B) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}

