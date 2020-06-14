#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b,c) (((a) >= (b))?(((a) >= (c))?(a):(c)):((b) >= (c))?(b):(c))

int main(int argc, char ** argv){
	int sum,a,b,c;
	scanf("%d\n%d\n%d",&sum,&a,&b);
	c = sum - a - b;
	printf("%d\n", MAX(a,b,c));
	return 0;
}
