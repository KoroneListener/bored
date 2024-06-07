#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long long binomial_coefficient(int n, int k) {
    unsigned long long res = 1;
    if(k > n - k) {
        k = n - k;
    }
    for(int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

unsigned long long g(int n, int m) {
    if ((m + n) % 2 != 0) {
        return 0;
    }
    if (m < 0 || m > n) {
        return 0;
    }

    int k = (n - m) / 2;
    return binomial_coefficient(n, k) - binomial_coefficient(n, k - 1);
}

void generate_sequences(char * seq, int n, int s_count, int x_count, int m, unsigned long long *count) {
    if (s_count + x_count == n) {
        if (s_count - x_count == m) {
            (*count)++;
            printf("%s\n", seq);
        }
        return;
    }

    seq[s_count + x_count] = 'S';
    generate_sequences(seq, n, s_count + 1, x_count, m, count);

    if (x_count < s_count) {
        seq[s_count + x_count] = 'X';
        generate_sequences(seq, n, s_count, x_count + 1, m, count);
    }

}

int main() {
    int n, m;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);

    unsigned long long total_sequences = g(n, m);
    printf("Total number of valid sequences: %llu\n", total_sequences);

    char *sequence = (char *)malloc((n + 1) * sizeof(char));
    if (sequence == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    sequence[n] = '\0';

    unsigned long long count = 0;
    printf("Valid sequences of length %d with %d more S than X:\n", n, m);
    generate_sequences(sequence, n, 0, 0, m, &count);

    printf("Total number of valid sequences: %llu\n", count);

    free(sequence);

    return 0;
}
