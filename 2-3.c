// write the function htoi(s) which converts a string of hexidecimal digits into its equivalent integer values.  
// The allowable digits are 0-9, a-f, A-F

#include <stdio.h>
#include <math.h>

int htoi(char s[]);

int main () {
	char hex[4];

	hex[0] = '7';
	hex[1] = 'd';
	hex[2] = 'F';
	hex[3] = '\0';

	int num = htoi(hex);
	printf("%d \n", num);

}

int htoi (char s[]) {
	int i, n, len;
	i = n = len = 0;

	while (s[i] != '\0') {
		i++;
	}

	len = --i;

	while (i >= 0) {

		if (s[i] >= 'a') {
			n += ((s[i] - 'W') * pow(16,(len-i)));
		} else if (s[i] >= 'A') {
			n += ((s[i] - '7') * pow(16,(len-i)));
		} else {
			n += ((s[i] - '0') * pow(16,(len-i)));
		}
		
		i--;
	}

	return n;
}