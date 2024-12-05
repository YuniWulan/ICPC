#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	return(*(int*)a - *(int*)b);
}

int main(){
	int n;
	int i;
	
	scanf("%d", &n);
	
	int *strength = (int *)malloc(3 * n * sizeof(int));
	
	for(i = 0; i < 3*n; i++){
		scanf("%d", &strength[i]);
	}
	
	qsort(strength, 3 * n, sizeof(int), compare);
	
	int team_a = strength[2 * n];
	int team_b = strength[n];
	
	int hasil = 0;
	if(team_a < team_b){
		hasil = team_a;
	} else {
		hasil = team_b;
	}
	
	printf("%d\n", hasil);
	free(strength);
	
	return 0;
}
