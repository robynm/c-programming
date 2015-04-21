#include <stdio.h>
#define LENGTH 6;
int binsearch(int i, int j[], int q);

int main () {
	int x, n, i;
	x = 3;
	n = LENGTH;
	int v[n];

	for (i = 0; i < n; i++) {
		v[i] = i + 1;
		printf("%d \n", v[i]);
	}

	printf("index: %d \n", binsearch(x,v,n));
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;
	low = 0;
	high = n-1;
	mid = (low + high) / 2;

	while (low <= high && x != v[mid]) {
		if (x < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	if (x == v[mid]) {
		return mid;
	} else {
		return -1;
	}
}