#include <stdio.h>

int main() {
	int edad;
	int* p_edad;
	p_edad = &edad;
	*p_edad = 50;
	printf("%d", edad);
	printf("\n%d", *p_edad);
	
	return 0;
}

