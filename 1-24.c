#include <stdio.h>

#define IN 1 /* inside a comment */
#define OUT 0 /* outside a comment */
#define CHARS 128 /* characters to count */
#define MAXLINE 1000

int getInput(char input[]);
void removeComments(char input[]);
void removeQuotes(char input[], char c);
void removeEscapedChars(char input[]);
void countChars(char input[], char count[], int l);
void printWarnings(char s[]);

/* count frequency of characters */
int main () {
	int length, i;
	char chars[CHARS];
	char input[MAXLINE];

	for (i = 0; i < CHARS; i++) {
		chars[i] = 0;
	}

	for (i = 0; i < MAXLINE; i++) {
		input[i] = 0;
	}

	length = getInput(input);
	removeComments(input);
	removeQuotes(input, '"');
	removeQuotes(input, '\'');
	removeEscapedChars(input);
	printf("%s \n", input);
	countChars(input, chars, length);
	printWarnings(chars);
}

int getInput(char input[]) {
	int i;
	i = 0;

	while ((input[i] = getchar()) != EOF) {
		i++;
	}
	input[i] = '\0';
	return i;
}

void removeQuotes(char input[], char c) {
	int state, i;
	state = OUT;

	i = 0;

	while (input[i] != '\0') {
		if (input[i] == c && state == OUT) {
			state = IN;
		} else if (input[i] == c && state == IN) {
			state = OUT;
		} else if (state == IN) {
			input[i] = ' '; 
		} 
		i++;
	}
}

void removeComments(char input[]) {
	int state, i;
	state = OUT;

	i = 0;

	while (input[i] != '\0') {
		if (input[i] == '/' && input[i+1] == '*') {
			state = IN;
			i++;
		} else if (input[i] == '*' && input[i+1] == '/') {
			state = OUT;
			i++;
		} else if (state == IN) {
			input[i] = ' '; 
		} 
		i++;
	}
}

void removeEscapedChars(char input[]) {
	int i;
	i = 0;
	
	while (input[i] != '\0') {
		if (input[i] == '\\') {
			i++;
			input[i] = ' ';
		} else {
			i++;
		}
	}
}

void countChars(char input[], char count[], int len) {
	int i;

	for (i = 0; i < len; i++) {
			count[input[i]]++;
	}
}

void printWarnings(char chars[]) {

	if (chars[40] != chars[41]) {
		printf("warning: ( and ) do not match\n");
	}

	if (chars[123] != chars[125]) {
		printf("warning: { and } do not match\n");
	}

	if (chars[91] != chars[93]) {
		printf("warning: [ and ] do not match\n");
	}

	if (chars[34] % 2 != 0) {
		printf("warning: \" and \" do not match\n");
	}

	if (chars[39] % 2 != 0) {
		printf("warning: \' and \' do not match\n");
	}
}