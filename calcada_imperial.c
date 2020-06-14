#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_bi_choice_score(int * list, int n, int choice_a, int choice_b){
	int selected_last = -1;
	int i, score = 0;
	for(i = 0; i < n; ++i){
		if(selected_last != choice_b && list[i] == choice_b){
			++score;
			selected_last = choice_b;
		} else if(selected_last != choice_a && list[i] == choice_a){
			++score;
			selected_last = choice_a;
		}
	}
	return score;
}



int get_choice_score(int * list, int n, int choice){
	int score = 0, max_score = 0, i;
	/* just need to check when i < choice. the for in main guarantees*/
	for(i = 0; i < choice; ++i){
		score = get_bi_choice_score(list, n, choice, i);
		if(score > max_score){
			max_score = score;
		}
		score = get_bi_choice_score(list, n, choice, -1);
		if(score > max_score){
			max_score = score;
		}
	}

	return max_score;
}

int main(int argc, char ** argv){
	int i, n, *list, score, max_score = -1;

	scanf("%d", &n);

	list = calloc(n, sizeof(int));
	for(i = 0; i < n; ++i){
		scanf("%d", &list[i]);
	}
	if(n == 0){
		printf("0");
	} else if(n < 3){
		printf("1");
	} else {
		for(i = 0; i < n; ++i){
			score = get_choice_score(list, n, i);
			if(score > max_score){
				max_score = score;
			}
		}
		printf("%d\n", max_score);
	}

	free(list);

	return 0;
}
