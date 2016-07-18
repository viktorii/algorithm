#include <cstdio>

int N,M,a[1026][1026],s[1026][1026];

// (1,1)부터 (n,n)까지의 합을 구한다.
void init() {
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
}

// (x1,y1)부터 (x2,y2)의 합을 구한다.
int grid_sum(int x1, int y1, int x2, int y2) {
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

int main() {
	scanf("%d %d",&N,&M);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	init();
	for (int i=0; i<M; i++) {
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",grid_sum(x1,y1,x2,y2));
	}
	return 0;
}
