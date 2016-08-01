#include <stdio.h>
int N,M,K;
long long A[1000005],D[4000005];

long long init(int start, int end, int node) {
	if (start==end) {
		return D[node]=A[start];
	}
	int mid=(start+end)/2;
	return D[node]=init(start,mid,node*2)+init(mid+1,end,node*2+1);
}

long long query(int start, int end, int node, int i, int j) {
	if (end<i || start>j) return 0;
	if (i<=start && end<=j) return D[node];

	int mid=(start+end)/2;
	return query(start,mid,node*2,i,j)+query(mid+1,end,node*2+1,i,j);
}

void update(int start, int end, int node, int target, long long diff) {
	if (end<target || start>target) return;
	D[node]=D[node]+diff;
	if (start!=end) {
		int mid=(start+end)/2;
		update(start,mid,node*2,target,diff);
		update(mid+1,end,node*2+1,target,diff);
	}
}

int main() {
	scanf("%d %d %d",&N,&M,&K);
	for (int i=1; i<=N; i++) {
		scanf("%lld",&A[i]);
	}
	init(1,N,1);
	for (int i=0; i<M+K; i++) {
		int q;
		scanf("%d",&q);
		if (q==1) {
			int t2;
			long long t3; 
      		scanf("%d %lld",&t2,&t3); 
			long long diff = t3-A[t2];
			A[t2]=t3;
			update(1,N,1,t2,diff);
		} else {
			int t2,t3; 
			scanf("%d %d",&t2,&t3); 
      		printf("%lld\n",query(1,N,1,t2,t3)); 
		}
	}
	return 0;
}
