#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int top;
	int maxSize;
} Stack;

Stack* createStack(int maxSize) {
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->data = (int*)malloc(maxSize * sizeof(int));
	stack->top = -1;
	stack->maxSize = maxSize;
	return stack;
}

void push(Stack *stack, int value) {
	if (stack->top < stack->maxSize - 1) {
		stack->data[++stack->top] = value;
	} else {
		printf("Stack overflow\n");
	}
}

int pop(Stack *stack) {
	if (stack->top >= 0) {
		return stack->data[stack->top--];
	} else {
		printf("Stack underflow\n");
		return -1;
	}
}

int top(Stack *stack) {
	if (stack->top >= 0) {
		return stack->data[stack->top];
	} else {
		return -1;
	}
}

int isEmpty(Stack *stack) {
	return stack->top == -1;
}

int isValidPermutation(int *perm, int n) {
	Stack *stack = createStack(n);
	int nextToPush = 1;
	int i = 0;

	for (i = 0; i < n; ++i) {
		while (nextToPush <= n && (isEmpty(stack) || top(stack) != perm[i])) {
			push(stack, nextToPush++);
		}

		if (top(stack) == perm[i]) {
			pop(stack);
		} else {
			return 0;
		}
	}

	return 1;

}

int main() {
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);

	int *perm = (int*)malloc(n * sizeof(int));
	printf("Enter the permutation: ");
	for(int i = 0; i < n; ++i) {
		scanf("%d", &perm[i]);
	}

	if (isValidPermutation(perm, n)) {
		printf("The permuattion is valid\n");
	} else {
		printf("The permutation is invalid\n");
	}

	free(perm);
	return 0;
}
