#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define LONGEST 432 /* longest word, sanskrit */

/* count length of words */
int main () {

	int c, state, longest, common, i, counter;
	int lengths[LONGEST];

	state = OUT;
	longest = common = counter = 0;
	for (i = 0; i < LONGEST; i++) {
		lengths[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			
		} else if (c == ' ' || c == '\t' || c == '\n') {
			if (counter >= LONGEST) {

			} else {
				lengths[counter]++;
				if (counter > longest) {
					longest = counter;
				}
				if (lengths[counter] > common) {
					common = lengths[counter];
				}
			}
			state = OUT;
			counter = 0;
		} else {
			counter++;
			state = IN;
		}
	}

	for (i = 1; i <= longest; i++) {
		printf("%3d ", i);
		for (int j = 0; j < lengths[i]; j++) {
			printf("=");
		}
		printf("\n");
	}
}