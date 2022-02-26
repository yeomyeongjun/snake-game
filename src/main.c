#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 12

struct worm {
	int x;
	int y;
};



void makeMaps(char a[MAX][MAX], int x, int y) {
	
	int i, j, ranX, ranY, norm;
	
	
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			a[i][j] = '#';
	
	for (i = 1; i < x - 1; i++)
		for (j = 1; j < y - 1; j++)
			a[i][j] = ' ';
	
	srand(time(NULL));
	
	printf("norm: ");
	scanf("%d", &norm);
	
	for (i = 0; i < norm; i++) {
		
		ranX = rand() % (x - 2) + 1;
		ranY = rand() % (y - 2) + 1;
		
		if (a[ranX][ranY] == ' ')
			a[ranX][ranY] = '*';
		else
			i--;
		
	}
}

void printMaps(char a[MAX][MAX], int x, int y) {
	
	int i, j;

	printf("\n");
	
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}

int inspectNorm(char a[MAX][MAX], int x, int y) {
	
	int i, j, cnt = 0;
	
	for (i = 1; i < x - 1; i++)
		for (j = 1; j < y - 1; j++)
			if (a[i][j] == '*')
				cnt++;
	
	return cnt;
	
	
}

void playGames(char a[MAX][MAX], int x, int y) {
	
	struct worm worm;
	int i, many;
	char direct;
	
	srand(time(NULL));
	
	while (a[worm.x][worm.y] != ' ') {

		worm.x = rand() % 10 + 1;
		worm.y = rand() % 10 + 1;
	}

	a[worm.x][worm.y] = '@';
	
	while (inspectNorm(a, x, y) > 0) {


		printMaps(a, x, y);
		printf("Direction? (d, u, l, r) : ");
		scanf("\n%c", &direct);
		printf("How many? : ");
		scanf("%d", &many);
		//printf("\n");

		a[worm.x][worm.y] = ' ';

		if (direct == 'd')
			for (i = 0; i < many; i++) {
				worm.x += 1; 
				if (a[worm.x][worm.y] == '#')
					break;
			}

		else if (direct == 'u') 
			for (i = 0; i < many; i++) {
				worm.x -= 1;
				if (a[worm.x][worm.y] == '#')
					break;
			}
			
		else if (direct == 'l') 
			for (i = 0; i < many; i++) {
				worm.y -= 1;
				if (a[worm.x][worm.y] == '#')
					break;
			}

		else if (direct == 'r') 
			for (i = 0; i < many; i++) {
				worm.y += 1;
				if (a[worm.x][worm.y] == '#')
					break;
			}

		a[worm.x][worm.y] = '@';

	}
}


int main(int argc, char* argv[]) {
	
	int x, y;
	char a[MAX][MAX];
	
	printf("====SNAKE GAME====\n");
	printf("row: ");
	scanf("\n%d", &x);
	printf("column: ");
	scanf("%d", &y);
	
	//지도 생성
	
	makeMaps(a, x, y);
	
	//게임 실행
	
	playGames(a, x, y);
	
	return 0;
}