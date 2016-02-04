#include <stdio.h>
#define EXPR_MAX_SIZE 400
#define NUM_OF_OPERATOR 5

void convertToRpn(char *, char *);
int isParenthesis(char);
int isOperator(char);
void pr(char, char *, int);

int main(void) {

	int numOfLine;

	scanf("%d\n", &numOfLine);
	
	for (int i = 0; i < numOfLine; i++) {
		char expr[EXPR_MAX_SIZE] = {'\0'};
		char rpn[10];
			
		fgets(expr, EXPR_MAX_SIZE, stdin);
		convertToRpn(expr, rpn);
	}

	return 0;
}

void convertToRpn(char *expr, char *rpn) {
	char charStack[EXPR_MAX_SIZE] = {'\0'};;
	int stackIndex = 0;
	int count = 0;
	char temp[EXPR_MAX_SIZE] = {'\0'};
	int tempIndex = 0;
	//int parenthesisNum = 0;
	//int countTwo = 0;

	for (int i = EXPR_MAX_SIZE - 1; i >= 0; i--) {
		/*		
		if (expr[i] == ')') {
			parenthesisNum++;
		} else if (expr[i] == '(') {
			parenthesisNum--;
			countTwo = 0;
		} else 
		*/

		if (expr[i] == ')') {
			count = 0;
		}

		if (expr[i] == '\0' || expr[i] == '\n' || isParenthesis(expr[i])) {
			//do nothing
		} else if (isOperator(expr[i])) {
			//int ref = parenthesisNum ? countTwo : count;	
			int ref = count;
	
			for (int j = 0; j < ref; j++) {
				temp[tempIndex++] = charStack[--stackIndex];
				count--;
			}

			charStack[stackIndex++] = expr[i];
			count++;
			
			while (tempIndex > 0) {
				charStack[stackIndex++] = temp[--tempIndex];
				count++;
			}
		} else {
			charStack[stackIndex++] = expr[i];
			count++;
		}
 
		printf("\n");
	}
	
	pr ('s', charStack, stackIndex);
	
	rpn[0] = 'a';
}

//TODO delete that it's just for dev
void pr(char c, char *p, int ind) {

	for (int z = EXPR_MAX_SIZE - 1; z >= 0; z--) {
		printf("%c", p[z]);
	}
	c = c;
	ind = ind;	
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

