#include <stdio.h>
#include <stdlib.h>


void compute_sequence(int n, unsigned long long *b) {
	if (n == 0) {
		b[0] = 1;
		return;
	}

	b[0] = 1;
	if ( n >= 1) {
		b[1] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		b[i] = (3 * (2 * i - 3) * b[i - 1] - (i - 3) * b[i - 2]) / i;
	}
}

int main() {
	int n;
	printf("Enter the number of terms to compute (n): ");
	scanf("%d", &n);

	unsigned long long *b =(unsigned long long *)malloc((n+1) * sizeof(unsigned long long));
	if (b == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}

	compute_sequence(n,b);

	printf("The sequence b_n for the first %d terms is:\n", n);
	for (int i = 0; i <= n; ++i) {
		printf("b_%d = %llu\n", i, b[i]);
	}

	free(b);

	return 0;
}

