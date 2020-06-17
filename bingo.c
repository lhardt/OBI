#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int i,j,k;
	int n_sheets, n_numbers, max_num;
	int ** sheets;
	int * taken;
	int * remaining;
	bool bingo = false;

	scanf("%d %d %d", &n_sheets, &n_numbers, &max_num);

	sheets = (int**)calloc(n_sheets, sizeof(int*));
	remaining = (int *) calloc(n_sheets, sizeof(int));
	for(i = 0; i < n_sheets; ++i){
		sheets[i] = (int*) calloc(n_numbers, sizeof(int));
		for(j = 0; j < n_numbers; ++j){
			scanf("%d", &sheets[i][j]);
		}
		remaining[i] = n_numbers;
	}
	taken = (int*) calloc(max_num, sizeof(int));
	for(i = 0; !bingo && (i < max_num); ++i){
		scanf("%d", &taken[i]);

		for(j = 0; j < n_sheets; ++j){
			for(k = 0; k < n_numbers; ++k){
				if(sheets[j][k] == taken[i]){
					sheets[j][k] = -1;
					--remaining[j];

					if(remaining[j] == 0){
						printf("%d ", j+1);
						bingo = true;
					}
				}
			}
		}
	}



	// printf("Printing sheets:\n");
	//
	// for(i = 0; i < n_sheets; ++i){
	// 	for(j = 0; j < n_numbers; ++j){
	// 		printf("%d ", sheets[i][j]);
	// 	}
	// 	printf("\n");
	// }
	//
	// printf("Printing sheets:\n");
	//
	// for(i = 0; i < max_num; ++i){
	// 	printf("%d ", taken[i]);
	// }

	return 0;
}
