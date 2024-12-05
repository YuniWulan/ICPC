#include<stdio.h>
#include<string.h>

void pengubahan(char *kata, char *ubah){
	int k = 0;
	int m = 0;
	
	while( k < strlen(kata)){
			if(kata[k] == 'c' && kata[k + 1] == 'h'){
				ubah[m++] = 'c';
				k += 2;
				
			} else if(kata[k] == 'c'){
				if(k+1 < strlen(kata)){
					char next = kata[k+1];
					
					if(next == 'a' || next == 'o' || next == 'u'){
						ubah[m++] = 'k';
					} else if (next == 'e' || next == 'i' || next == 'y'){
						ubah [m++] = 's';
					} else {
						ubah[m++] = 'k';
					}
				} else {
					ubah[m++] = 'k';
				}
				k++;
				} else {
					ubah[m++] = kata[k++];
				}	
			}
	ubah[m] = '\0';
	
}

int main(){
	
	int n;
	scanf("%d", &n);
	
	char kata[100][101];
	char ubah[100][101];
	
	int i;
	for(i = 0; i < n; i++){
		scanf("%s", kata[i]);
		pengubahan(kata[i], ubah[i]);
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++){
		printf("%s\n", ubah[i]);
	}
	
	return 0;
}
