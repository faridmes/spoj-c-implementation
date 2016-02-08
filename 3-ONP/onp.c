#include <stdio.h>
#define MAX_NUM_OF_LINES 100
#define EXPR_MAX_SIZE 401
#define NUM_OF_OPERATOR 5

void convertToRpn(char *);
int isParenthesis(char);
int isOperator(char);
void pr(char *);

int main(void) {

	int numOfLine;
	char lines[MAX_NUM_OF_LINES][EXPR_MAX_SIZE];

	scanf("%d\n", &numOfLine);
	
	for (int i = 0; i < numOfLine; i++) {
		fgets(lines[i], EXPR_MAX_SIZE, stdin);
	}

	for (int d = 0; d < numOfLine; d++) {
		convertToRpn(lines[d]);
	}

	return 0;
}

void convertToRpn(char *expr) {
	char charStack[EXPR_MAX_SIZE] = {'\0'};
	int stackIndex = 0;
	int count = 0;
	char temp[EXPR_MAX_SIZE] = {'\0'};
	int tempIndex = 0;
	int parenthesisNum = 0;
	int total = 0;

	for (int i = EXPR_MAX_SIZE - 1; i >= 0; i--) {
		if (expr[i] == ')') {
			parenthesisNum++;
			count = 0;
		} else if (expr[i] == '(') {
			parenthesisNum--;
		} else 

		if (expr[i] == '\0' || expr[i] == '\n' || isParenthesis(expr[i])) {
			//do nothing
		} else if (isOperator(expr[i])) {
			int ref = (parenthesisNum == 1) ? total : count;
	
			for (int j = 0; j < ref; j++) {
				temp[tempIndex++] = charStack[--stackIndex];
				count--;
				total--;
			}

			charStack[stackIndex++] = expr[i];
			count++;
			total++;
			
			while (tempIndex > 0) {
				charStack[stackIndex++] = temp[--tempIndex];
				count++;
				total++;
			}
		} else {
			charStack[stackIndex++] = expr[i];
			count++;
			total++;
		}
	}
	
	pr (charStack);
}

void pr(char *p) {

	for (int z = EXPR_MAX_SIZE - 1; z >= 0; z--) {
		printf("%c", p[z]);
	}
	printf("\n");
}

int isParenthesis(char c) {
	return c == '(' || c == ')';
}

int isOperator(char c) {
	char operators[NUM_OF_OPERATOR] = {'+', '-', '*', '/', '^'};

	for (int i = 0; i < NUM_OF_OPERATOR; i++) {
		if (c == operators[i])
			return 1;
	}

	return 0;
}

