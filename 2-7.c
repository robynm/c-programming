// write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
// (ie 1 changed to 0), leaving the others unchanged
#include <stdio.h>

int invert(int x, int p, int n);

int main () {
	int x = 45;
	int p = 4;
	int n = 4;
	int r = invert(x, p, n);
	printf("%d \n", r);
}


int invert(int x, int p, int n) {
	int xor = 0;

	while (n > 0) {
		xor += 1<<p;
		n--;
		p++;
	}

	x = x ^ xor;
	return x;
}