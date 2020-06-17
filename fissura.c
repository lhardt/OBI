#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// NOTE  -1 means lava.


bool lava_iter(int ** map, int sz, int force){
	int i, j;
	bool differ = false;

	for(i = 0; i < sz; ++i){
		for(j = 0; j < sz; ++j){
			if(map[i][j] == -1){
				/* four possibilities. By hand is faster */
				if(i < sz-1 && map[i+1][j] != -1 && map[i+1][j] <= force){
					map[i+1][j] = -1;
					differ = true;
				}
				if(i > 0 && map[i-1][j] != -1 && map[i-1][j] <= force){
					map[i-1][j] = -1;
					differ = true;
				}
				if(j < sz-1 && map[i][j+1] != -1 && map[i][j+1] <= force){
					map[i][j+1] = -1;
					differ = true;
				}
				if(j > 0 && map[i][j-1] != -1 && map[i][j-1] <= force){
					map[i][j-1] = -1;
					differ = true;
				}
			}
		}
	}
	return differ;
}

int main(){
	int sz, force;
	int ** map;
	int i, j;
	char * temp;
	bool differ;

	scanf("%d %d", &sz, &force);

	map = (int**) calloc(sz, sizeof(int*));
	temp = calloc(sz+1, sizeof(char));
	for(i = 0; i < sz; ++i){
		map[i] = (int*) calloc(sz, sizeof(int));
		scanf("%s", temp);
		for(j = 0; j < sz; ++j){
			map[i][j] = temp[j] - '0';
		}
	}

	// Allowed because N>=1
	if(map[0][0] <= force){
		map[0][0] = -1;

		differ = true;
		while(differ){
			differ = lava_iter(map,sz,force);
		}
	}
	
	for(i = 0; i < sz; ++i){
		for(j = 0; j < sz; ++j){
			if(map[i][j] == -1){
				printf("*");
			} else {
				printf("%d", map[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
