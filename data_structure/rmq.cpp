#include <cstdio>
#define INF 1000000001

using namespace std;
int N,M;
int d[400000],a[100005];

int min(int a, int b) {
	return a<b?a:b;
}

int init(int node, int start, int end) {
	if (start==end) {
		return d[node]=a[start];
	} else {
		int mid=(start+end)/2;
		int l=init(node*2,start,mid);
		int r=init(node*2+1,mid+1,end);
		return d[node]=min(l,r);
	}
}

int query(int node, int start, int end, int i, int j) {
	if (i>end || j<start) return INF;
	if (i<=start && end<=j) return d[node];
	int mid=(start+end)/2;
	return min(query(node*2,start,mid,i,j),query(node*2+1,mid+1,end,i,j));
}

int main() {
	scanf("%d %d",&N,&M);
	for (int i=1; i<=N; i++) {
		scanf("%d",a+i);
	}
	init(1,1,N);
	for (int i=0; i<M; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query(1,1,N,a,b));
	}
	return 0;
}
