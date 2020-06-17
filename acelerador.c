#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned long distance_traveled, rem;

	scanf("%lu", &distance_traveled);

	rem = (distance_traveled-3)%8;

	printf("%d", rem-2);

	return 0;
}
