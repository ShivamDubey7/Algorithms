#include <bits/stdc++.h>
#define wLim 500
#define nLim 100
int x[wLim][nLim],w[nLim],v[nLim],n,W,enable=1,choice[nLim];
void print(int t){
	for(int i=0;i<t;i++){
		printf("\t");
	}
	printf("|-->");
}
int best(int num,int weight,int t){
	if(enable){
		print(t);
		printf("Called for case(%d,%d)\n",num,weight);
	}
	if(num==0 || weight==0){
		if(enable){print(t);printf("Base Case calculated directly as 0\n");}
		return 0;
	}
	if(x[weight][num]!=0){
		if(enable){print(t);printf("memoization utilised for calculating case(%d,%d)\n",weight,num);}
		return x[weight][num];
	}
	if(w[num]>weight){
		x[weight][num]= best(num-1,weight,t+1);
		if(enable){print(t);printf("Calulated for case(%d,%d) as %d\n",num,weight,x[weight][num]);}
		return x[weight][num];
	}
	int ans1 = best(num-1,weight-w[num],t+1);
	int ans2 = best(num-1,weight,t+1);
	x[weight][num] = v[num]+ans1>ans2 ? v[num]+ans1:ans2;
	if (enable){print(t);printf("Calulated for case(%d,%d) as %d\n",num,weight,x[weight][num]);}
	return x[weight][num];
}
int main(){
	printf("Want to see the path?\n");
	scanf("%d",&enable);
	printf("numberOfEements knapsackCapacity-\n");
	scanf("%d %d",&n,&W);
	printf("Weight value for all elements-\n");
	for(int i=1;i<=n;i++){
		scanf("%d %d",&w[i],&v[i]);
	}
	printf("The maximum of total value possible to grab is %d\n",best(n,W,0));
	int cW=W;
	for(int i=n;i>=1;i--){
		if ( x[cW-w[i]][i-1] + v[i]  == x[cW][i] ){
			choice[i] = 1;
			cW -= w[i];
		}

	}
	printf("By chosing :\n");
	for(int i=1;i<=n;i++){
		printf("%d ",choice[i]);
	}
	return 0;}
