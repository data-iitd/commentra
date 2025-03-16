#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	FILE *wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	int cnt = 0;

	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2;
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	char *saveptr = NULL;
	int k, x;

	while ((read = getline(&line, &len, fp))!= -1) {
		token = strtok_r(line, " ", &saveptr);
		k = atoi(token);
		token = strtok_r(NULL, " ", &saveptr);
		x = atoi(token);

		if (k*500 >= x) {
			fprintf(wfp, "Yes\n");
		} else {
			fprintf(wfp, "No\n");
		}
	}
	for (int i = 0; i < cnt; i++) {
		fprintf(wfp, "-----------------------------------\n");
		while ((read = getline(&line, &len, fp))!= -1) {
			token = strtok_r(line, " ", &saveptr);
			k = atoi(token);
			token = strtok_r(NULL, " ", &saveptr);
			x = atoi(token);

			if (k*500 >= x) {
				fprintf(wfp, "Yes\n");
			} else {
				fprintf(wfp, "No\n");
			}
		}
	}
	free(line);
	fclose(fp);
	fclose(wfp);
}

