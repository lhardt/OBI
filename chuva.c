#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void rain_horizontal(char **wall, int m, int i ){
	bool change = false;
	int j = 0;
	change = true;
	while(change){
		change = false;
		for(j = 1; j < m-1; ++j){
			if(wall[i][j] == 'o'){
				if(wall[i][j+1] != 'o' && wall[i+1][j] == '#'){
					wall[i][j+1] = 'o';
					change=true;
				}
				if(wall[i][j-1] != 'o' && wall[i+1][j] == '#'){
					wall[i][j-1] = 'o';
					change = true;
				}
			}
		}
	}
}

void rain_vertical(char **wall, int m, int i){
	int j = 0;

	for(j = 0; j < m; ++j){
		if(wall[i][j] == 'o' && wall[i+1][j] == '.'){
			wall[i+1][j] = 'o';
		}
	}
}

int main(){
	int m, n, i, j;
	char ** wall;

	scanf("%d %d", &n, &m);


	wall = (char**) calloc(n, sizeof(char*));
	for(i = 0; i < n; ++i){
		wall[i] = (char*) calloc(1 + m, sizeof(char));

		for(j = 0; j <= m; ++j){
			wall[i][j] = '\0';
		}
		scanf("%s", wall[i]);
	}

	for(i = 0; i < n -1; ++i){
		rain_horizontal(wall, m,i);
		rain_vertical(wall, m,i);
	}
	for(i = 0; i < n; ++i){
		printf("%s\n", wall[i]);
	}
	return 0;
}
