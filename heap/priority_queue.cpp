#include <cstdio>
#define MAX 100

int heap[MAX], cnt;

/*
	마지막 노드부터 위치를 찾아간다.
	부모노드의 값보다 작으면 cur 위치를 부모와 바꾸고, 아니면 cur 위치에 값을 넣는다. 
*/
void push(int x) {
	int cur=cnt++;
	while (cur>1) {
		int parent=cur/2;
		// 부모노드의 값이 자식노드 값보다 작으면 빠져나온다.
		if (heap[parent]<=x) break;
		
		// 부모노드의 값을 자식노드로 넣는다.
		heap[cur]=heap[parent];
		cur=parent;
	}
	heap[cur]=x;
}

/*
	루트노드의 값을 리턴한다.
	마지막 노드를 루트로 보내고, 위치를 찾아간다.
*/
int pop() {
	int ret=heap[0];
	int x=heap[cnt--];

	int cur=0;
	
	// 자식이 존재하는 경우에만 while문 수행한다.
	while(cur*2<=cnt) {
		// 자식들 중에 작은값을 추출한다.
		int a=cur*2, b=cur*2+1;
		if (b<=cnt && heap[b]<heap[a]) a=b;

		// 자식의 값이 더 크면 중단한다.
		if (heap[a]>=x) break;
		
		heap[cur]=heap[a];
		cur=a;
	}
	heap[cur]=x;

	return ret;
}
