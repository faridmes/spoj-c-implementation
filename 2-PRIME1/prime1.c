#include <stdio.h>
#include <math.h>

int isPrime(int);

int main(void) {

	int numberOfCases;

	scanf("%d", &numberOfCases);

	for (int i = 0; i < numberOfCases; i++) {
		int min, max;

		scanf("%d %d", &min, &max);

		for (int j = min; j <= max; j++) {

			if (isPrime(j))
				printf("%d\n", j);
		}

		printf("\n");
	}

	return 0;
}

int isPrime(int number) {
	if (number == 1)
		return 0;
	
	if (number == 2)
		return 1;

	int sqrtOfNumber = ceil(sqrt(number));

	for (int n = 2; n <= sqrtOfNumber; n++) {
		if (number % n == 0)
			return 0;
	}
	
	return 1;
}
