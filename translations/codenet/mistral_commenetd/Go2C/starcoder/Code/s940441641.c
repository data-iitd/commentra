#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP_FROM(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define REP_TO(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define RANGE(i, n) REP(i, n)
#define RANGE1(i, n) REP1(i, n)
#define RANGE_FROM(i, m, n) REP_FROM(i, m, n)
#define RANGE_TO(i, m, n) REP_TO(i, m, n)

#define ALL(x) (x).begin(), (x).end()
#define SORT(v) sort((v).begin(), (v).end())
#define UNIQUE(v) SORT(v); (v).erase(unique((v).begin(), (v).end()), (v).end())
#define SZ(v) ((int)(v).size())
#define CONTAINS(v, x) ((v).find(x)!= (v).end())
#define SORT_AND_UNIQUE(v) SORT(v); UNIQUE(v)

#define ERR_IF(cond, msg) do { if (!(cond)) { fprintf(stderr, msg); exit(1); } } while (0)
#define ERR_IF_NOT(cond, msg) do { if ((cond)) { fprintf(stderr, msg); exit(1); } } while (0)
#define ERR_IF_NEG(x) ERR_IF((x) < 0, "Negative value: %d\\n", (x))
#define ERR_IF_NOT_NEG(x) ERR_IF_NOT((x) < 0, "Negative value: %d\\n", (x))
#define ERR_IF_ZERO(x) ERR_IF((x) == 0, "Zero value: %d\\n", (x))
#define ERR_IF_NOT_ZERO(x) ERR_IF_NOT((x) == 0, "Zero value: %d\\n", (x))
#define ERR_IF_NULL(x) ERR_IF((x) == NULL, "Null pointer: %p\\n", (x))
#define ERR_IF_NOT_NULL(x) ERR_IF_NOT((x) == NULL, "Null pointer: %p\\n", (x))
#define ERR_IF_FAIL(x) do { int res = (x); ERR_IF_NEG(res); } while (0)
#define ERR_IF_NOT_FAIL(x) do { int res = (x); ERR_IF_NOT_NEG(res); } while (0)

#define ERR_IF_EQ(x, y) ERR_IF((x) == (y), "Equal: %d == %d\\n", (x), (y))
#define ERR_IF_NOT_EQ(x, y) ERR_IF_NOT((x) == (y), "Equal: %d == %d\\n", (x), (y))
#define ERR_IF_LT(x, y) ERR_IF((x) < (y), "Less than: %d < %d\\n", (x), (y))
#define ERR_IF_NOT_LT(x, y) ERR_IF_NOT((x) < (y), "Less than: %d < %d\\n", (x), (y))
#define ERR_IF_LE(x, y) ERR_IF((x) <= (y), "Less than or equal: %d <= %d\\n", (x), (y))
#define ERR_IF_NOT_LE(x, y) ERR_IF_NOT((x) <= (y), "Less than or equal: %d <= %d\\n", (x), (y))
#define ERR_IF_GT(x, y) ERR_IF((x) > (y), "Greater than: %d > %d\\n", (x), (y))
#define ERR_IF_NOT_GT(x, y) ERR_IF_NOT((x) > (y), "Greater than: %d > %d\\n", (x), (y))
#define ERR_IF_GE(x, y) ERR_IF((x) >= (y), "Greater than or equal: %d >= %d\\n", (x), (y))
#define ERR_IF_NOT_GE(x, y) ERR_IF_NOT((x) >= (y), "Greater than or equal: %d >= %d\\n", (x), (y))

#define ERR_IF_STR_EQ(x, y) ERR_IF(strcmp(x, y) == 0, "Equal: %s == %s\\n", (x), (y))
#define ERR_IF_NOT_STR_EQ(x, y) ERR_IF_NOT(strcmp(x, y) == 0, "Equal: %s == %s\\n", (x), (y))

#define ERR_IF_STR_NOT_BEGINS_WITH(x, y) ERR_IF(strncmp(x, y, strlen(y))!= 0, "Does not begin with: %s does not begin with %s\\n", (x), (y))
#define ERR_IF_NOT_STR_BEGINS_WITH(x, y) ERR_IF_NOT(strncmp(x, y, strlen(y))!= 0, "Does not begin with: %s does not begin with %s\\n", (x), (y))

#define ERR_IF_STR_NOT_ENDS_WITH(x, y) ERR_IF(strcmp(x + strlen(x) - strlen(y), y)!= 0, "Does not end with: %s does not end with %s\\n", (x), (y))
#define ERR_IF_NOT_STR_ENDS_WITH(x, y) ERR_IF_NOT(strcmp(x + strlen(x) - strlen(y), y)!= 0, "Does not end with: %s does not end with %s\\n", (x), (y))

#define ERR_IF_STR_NOT_CONTAINS(x, y) ERR_IF(strstr(x, y) == NULL, "Does not contain: %s does not contain %s\\n", (x), (y))
#define ERR_IF_NOT_STR_CONTAINS(x, y) ERR_IF_NOT(strstr(x, y) == NULL, "Does not contain: %s does not contain %s\\n", (x), (y))

#define ERR_IF_STR_NOT_CONTAINS_ANY(x, y) ERR_IF(strpbrk(x, y) == NULL, "Does not contain any: %s does not contain any %s\\n", (x), (y))
#define ERR_IF_NOT_STR_CONTAINS_ANY(x, y) ERR_IF_NOT(strpbrk(x, y) == NULL, "Does not contain any: %s does not contain any %s\\n", (x), (y))

#define ERR_IF_STR_NOT_CONTAINS_ALL(x, y) do { \
	const char *p = x; \
	const char *q = y; \
	while (*p!= '\0') { \
		if (strchr(q, *p) == NULL) { \
			fprintf(stderr, "Does not contain all: %s does not contain all %s\\n", (x), (y)); \
			exit(1); \
		} \
		p++; \
	} \
} while (0)
#define ERR_IF_NOT_STR_CONTAINS_ALL(x, y) do { \
	const char *p = x; \
	const char *q = y; \
	while (*p!= '\0') { \
		if (strchr(q, *p) == NULL) { \
			fprintf(stderr, "Does not contain all: %s does not contain all %s\\n", (x), (y)); \
			exit(1); \
		} \
		p++; \
	} \
} while (0)

#define ERR_IF_STR_NOT_RE(x, y) ERR_IF(regexec(y, x, 0, NULL, 0)!= 0, "Does not match regex: %s does not match regex %s\\n", (x), (y))
#define ERR_IF_NOT_STR_RE(x, y) ERR_IF_NOT(regexec(y, x, 0, NULL, 0)!= 0, "Does not match regex: %s does not match regex %s\\n", (x), (y))

#define ERR_IF_NOT_FILE(x) ERR_IF_NOT(FILE *f = fopen(x, "r"), "File not found: %s\\n", (x))
#define ERR_IF_FILE(x) ERR_IF(FILE *f = fopen(x, "r"), "File found: %s\\n", (x))

#define ERR_IF_NOT_DIR(x) ERR_IF_NOT(DIR *d = opendir(x), "Directory not found: %s\\n", (x))
#define ERR_IF_DIR(x) ERR_IF(DIR *d = opendir(x), "Directory found: %s\\n", (x))

#define ERR_IF_NOT_EMPTY_FILE(x) do { \
	FILE *f = fopen(x, "r"); \
	ERR_IF_NULL(f); \
	int c = fgetc(f); \
	ERR_IF_NOT_EOF(c); \
	fclose(f); \
} while (0)
#define ERR_IF_EMPTY_FILE(x) do { \
	FILE *f = fopen(x, "r"); \
	ERR_IF_NULL(f); \
	int c = fgetc(f); \
	ERR_IF_NOT_EOF(c); \
	fclose(f); \
} while (0)

#define ERR_IF_NOT_EMPTY_DIR(x) do { \
	DIR *d = opendir(x); \
	ERR_IF_NULL(d); \
	struct dirent *e = readdir(d); \
	ERR_IF_NULL(e); \
	closedir(d); \
} while (0)
#define ERR_IF_EMPTY_DIR(x) do { \
	DIR *d = opendir(x); \
	ERR_IF_NULL(d); \
	struct dirent *e = readdir(d); \
	ERR_IF_NULL(e); \
	closedir(d); \
} while (0)

#define ERR_IF_NOT_EOF(x) ERR_IF((x) == EOF, "Unexpected end of file\\n")
#define ERR_IF_EOF(x) ERR_IF_NOT((x) == EOF, "Unexpected end of file\\n")

#define ERR_IF_NOT_SUCCESS(x) ERR_IF_NOT((x) == 0, "Failed with error code %d\\n", (x))
#define ERR_IF_SUCCESS(x) ERR_IF((x) == 0, "Failed with error code %d\\n", (x))

#define ERR_IF_NOT_NULL(x) ERR_IF((x) == NULL, "Null pointer\\n")
#define ERR_IF_NULL(x) ERR_IF_NOT((x) == NULL, "Null pointer\\n")

#define ERR_IF_NOT_NONNULL(x) ERR_IF((x)!= NULL, "Non-null pointer\\n")
#define ERR_IF_NONNULL(x) ERR_IF_NOT((x)!= NULL, "Non-null pointer\\n")

#define ERR_IF_NOT_TRUE(x) ERR_IF(!(x), "Not true\\n")
#define ERR_IF_TRUE(x) ERR_IF(x, "Not true\\n")

#define ERR_IF_NOT_FALSE(x) ERR_IF((x), "Not false\\n")
#define ERR_IF_FALSE(x) ERR_IF_NOT((x), "Not false\\n")

#define ERR_IF_NOT_ZERO(x) ERR_IF((x) == 0, "Not zero\\n")
#define ERR_IF_ZERO(x) ERR_IF_NOT((x) == 0, "Not zero\\n")

#define ERR_IF_NOT_NOT_ZERO(x) ERR_IF((x)!= 0, "Not not zero\\n")
#define ERR_IF_NOT_ZERO(x) ERR_IF_NOT((x)!= 0, "Not not zero\\n")

#define ERR_IF_NOT_NULL_OR_EMPTY(x) do { \
	ERR_IF_NULL(x); \
	ERR_IF_ZERO(strlen(x)); \
} while (0)
#define ERR_IF_NULL_OR_EMPTY(x) do { \
	ERR_IF_NOT_NULL(x); \
	ERR_IF_NOT_ZERO(strlen(x)); \
} while (0)

#define ERR_IF_NOT_NONNULL_OR_EMPTY(x) do { \
	ERR_IF_NONNULL(x); \
	ERR_IF_NOT_ZERO(strlen(x)); \
} while (0)
#define ERR_IF_NONNULL_OR_EMPTY(x) do { \
	ERR_IF_NOT_NONNULL(x); \
	ERR_IF_NOT_ZERO(strlen(x)); \
} while (0)

#define ERR_IF_NOT_NULL_OR_EMPTY_FILE(x) do { \
	ERR_IF_NOT_FILE(x); \
	ERR_IF_NOT_EMPTY_FILE(x); \
} while (0)
#define ERR_IF_NULL_OR_EMPTY_FILE(x) do { \
	ERR_IF_FILE(x); \
	ERR_IF_EMPTY_FILE(x); \
} while (0)

#define ERR_IF_NOT_NONNULL_OR_EMPTY_FILE(x) do { \
	ERR_IF_NOT_FILE(x); \
	ERR_IF_NOT_EMPTY_FILE(x); \
} while (0)
#define ERR_IF_NONNULL_OR_EMPTY_FILE(x) do { \
	ERR_IF_FILE(x); \
	ERR_IF_EMPTY_FILE(x); \
} while (0)

#define ERR_IF_NOT_NULL_OR_EMPTY_DIR(x) do { \
	ERR_IF_NOT_DIR(x); \
	ERR_IF_NOT_EMPTY_DIR(x); \
} while (0)
#define ERR_IF_NULL_OR_EMPTY_DIR(x) do { \
	ERR_IF_DIR(x); \
	ERR_IF_EMPTY_DIR(x); \
} while (0)

#define ERR_IF_NOT_NONNULL_OR_EMPTY_DIR(x) do { \
	ERR_IF_NOT_DIR(x); \
	ERR_IF_NOT_EMPTY_DIR(x); \
} while (0)
#define ERR_IF_NONNULL_OR_EMPTY_DIR(x) do { \
	ERR_IF_DIR(x); \
	ERR_IF_EMPTY_DIR(x); \
} while (0)

#define ERR_IF_NOT_NULL_OR_EMPTY_STR(x) do { \
	ERR_IF_NULL(x); \
	ERR_IF_ZERO(strlen(x)); \
} while (0)
#define ERR_IF_NULL_OR_EMPTY_STR(x) do { \
	ERR_IF_NOT_NULL(x); \
	ERR_IF_NOT_ZERO(strlen(x)); \
} while (0)

#define ERR_IF_NOT_NONNULL_OR_EMPTY_STR(x) do { \
	ERR_IF_NONNULL(x); \
	ERR_IF_NOT_ZERO(strlen(x)); \
} while (0)
#define ERR_IF_NONNULL_OR_EMPTY_STR(x) do { \
	ERR_IF_NOT_NONNULL(x); \
	ERR_IF_NOT_ZERO(strlen(x)); \
} while (0)

#define ERR_IF_NOT_NULL_OR_EMPTY_FILE_STR(x) do { \
	ERR_IF_NOT_FILE(x); \
	ERR_IF_NOT_EMPTY_FILE(x); \
} while (0)
#define ERR_IF_NULL_OR_EMPTY_FILE_STR(x) do { \
	ERR_IF_FILE(x); \
	ERR_IF_EMPTY_FILE(x); \
} while (0)

#define ERR_IF_NOT_NONNULL_OR_EMPTY_FILE_STR(x) do { \
	ERR_IF_NOT_FILE(x); \
	ERR_IF_NOT_EMPTY_FILE(x); \
} while (0)
#define ERR_IF_NONNULL_OR_EMPTY_FILE_STR(x) do { \
	ERR_IF_FILE(x); \
	ERR_IF_EMPTY_FILE(x); \
} while (0)

#define ERR_IF_NOT_NULL_OR_EMPTY_DIR_STR(x) do { \
	ERR_IF_NOT_DIR(x); \
	ERR_IF_NOT_EMPTY_DIR(x); \
} while (0)
#define ERR_IF_NULL_OR_EMPTY_DIR_STR(x) do { \
	ERR_IF_DIR(x); \
	ERR_IF_EMPTY_DIR(x); \
} while (