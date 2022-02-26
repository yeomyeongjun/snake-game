#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 12

struct worm {
	int x;
	int y;
};


void makeMaps(char a[MAX][MAX]) {
	
	int i, j, ranX, ranY;
	
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			a[i][j] = '#';
	
	for (i = 1; i < MAX - 1; i++)
		for (j = 1; j < MAX - 1; j++)
			a[i][j] = ' ';
	
	srand(time(NULL));
	
	for (i = 0; i < 5; i++) {
		
		ranX = rand() % 10 + 1;
		ranY = rand() % 10 + 1;
		
		if (a[ranX][ranY] == ' ')
			a[ranX][ranY] = '*';
		else
			i--;
		
	}
	
}

void printMaps(char a[MAX][MAX]) {
	
	int i, j;

	printf("\n");
	
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}

int inspectNorm(char a[MAX][MAX]) {
	
	int i, j, cnt = 0;
	
	for (i = 1; i < MAX - 1; i++)
		for (j = 1; j < MAX - 1; j++)
			if (a[i][j] == '*')
				cnt++;
	
	return cnt;
	
	
}

void playGames(char a[MAX][MAX]) {
	
	struct worm worm;
	int many;
	char direct;
	
	srand(time(NULL));
	
	while (a[worm.x][worm.y] != ' ') {

		worm.x = rand() % 10 + 1;
		worm.y = rand() % 10 + 1;
	}

	a[worm.x][worm.y] = '@';
	
	while (inspectNorm(a) > 0) {


		printMaps(a);
		printf("Direction? (d, u, l, r) : ");
		scanf("\n%c", &direct);
		printf("How many? : ");
		scanf("%d", &many);
		//printf("\n");

		a[worm.x][worm.y] = ' ';

		if (direct == 'd')
			worm.x += many;

		else if (direct == 'u')
			worm.x -= many;

		else if (direct == 'l')
			worm.y -= many;

		else if (direct == 'r')
			worm.y += many;

		a[worm.x][worm.y] = '@';

	}
}


int main(int argc, char* argv[]) {

	//변수
	
	char a[MAX][MAX];
	
	//지도 생성
	
	makeMaps(a);
	
	//게임 실행
	
	playGames(a);
	
	return 0;
}