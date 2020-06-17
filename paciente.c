#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int i, j, tmp;

	int n_people, n_chains, chain_sz, chain_starter;
	bool * can_be_zero; // indexed by pacient id;

	scanf("%d %d", &n_people, &n_chains);

	can_be_zero = calloc(n_people, sizeof(bool));
	for(i = 0; i < n_people; ++i){
		can_be_zero[i] = true;
	}
	/* No chain can be onger */
	for(i = 0; i < n_chains; ++i){
		scanf("%d%d", &chain_starter, &chain_sz);
		for(j = 0; j < chain_sz; ++j){
			scanf("%d", &tmp);
			/* Person ids start at 1 */
			can_be_zero[tmp-1] = false;
 		}
	}

	for(i = 0; i < n_people; ++i){
		if(can_be_zero[i]){
			/* Person ids start at 1 */
			printf("%d\n", i+1);
		}
	}
	free(can_be_zero);
}
