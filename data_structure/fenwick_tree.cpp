#include <stdio.h>

int N,M,K;
long long a[1000005],tree[1000005];

long long sum(int i) {
	long long ans=0;
	while(i>0) {
		ans+=tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, long long diff) {
	while(i<=N) {
		tree[i]+=diff;
		i += (i&-i);
	}
}

int main() {
	scanf("%d %d %d",&N,&M,&K);
	for (int i=1; i<=N; i++) {
		scanf("%lld",&a[i]);
		update(i, a[i]);
	}
	for (int i=0; i<M+K; i++) {
		int q;
		scanf("%d",&q);
		if (q==1) {
			int t2;
			long long t3;
			scanf("%d %lld",&t2,&t3);
			long long diff = t3-a[t2];
			a[t2]=t3;
			update(t2,diff);
		} else {
			int t2,t3;
			scanf("%d %d",&t2,&t3);
			printf("%lld\n",sum(t3)-sum(t2-1));
		}
	}
	return 0;
}
