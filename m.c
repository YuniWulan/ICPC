#include<stdio.h>
#include<stdlib.h>

// Fungsi untuk membandingkan dua elemen saat melakukan sorting dengan menggunakan qsort
int compare(const void *a, const void *b){
	return(*(int*)a - *(int*)b); // Mengembalikan perbedaan nilai antar dua elemen
}

int main(){
	int n; // Jumlah tim
	int i; // Variable untuk iterasi
	
	scanf("%d", &n); // Read jumlah tim

	// Alokasi memori untuk menyimpan kekuatan dari anggota
	int *strength = (int *)malloc(3 * n * sizeof(int));
	
	// Untuk memastikan alokasi berhasil
	for(i = 0; i < 3*n; i++){
		scanf("%d", &strength[i]);
	}
	
	// Untuk melakukan sorting kekuatan anggota secara ascending dengan menggunakan qsort
	qsort(strength, 3 * n, sizeof(int), compare);
	
	// Untuk mendapatkan kekuatan tim A dan tim B
	int team_a = strength[2 * n]; // Nilai indeks tim A
	int team_b = strength[n]; // Nilai indeks tim B
	
	int hasil = 0; // Untuk simpan hasil
	// Untuk memilih nilai minimum antara kekuatan tim A dan tim B
	if(team_a < team_b){
		hasil = team_a;
	} else {
		hasil = team_b;
	}
	
	// Untuk cetak hasil kekuatan terkecil antara tim A dan tim B
	printf("%d\n", hasil);
	free(strength); // Membebaskan memori yang telah dialokasikan
	
	return 0;
}
