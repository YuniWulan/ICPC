#include<stdio.h>
#include<string.h>

// Untuk mengubah string sesuai dengan kententuan 
void pengubahan(char *kata, char *ubah){
	int k = 0; // Index untuk iterasi input string kata
	int m = 0; // Index untuk karakter pada string output
	
	 // Iterasi seluruh karakter pada string kata
	while( k < strlen(kata)){
			// Jika ditemukan 'ch' akan diubah ke 'c'
			if(kata[k] == 'c' && kata[k + 1] == 'h'){
				ubah[m++] = 'c';
				k += 2; // Lompat ke karakter setelah 'ch' karena telah diubah
			  // Jika ditemukan 'c' tanpa 'h' maka periksa karakter selanjutnya 	
			} else if(kata[k] == 'c'){
				if(k+1 < strlen(kata)){ // Memastikan tidak melebihi batas string
					char next = kata[k+1]; // Karakter setelah 'c'

					// Menentukan perubahan berdasarkan huruf selanjutnya
					if(next == 'a' || next == 'o' || next == 'u'){
						ubah[m++] = 'k'; // Jika vokal 'a', 'o', atau 'u', ubah ke 'k'
					} else if (next == 'e' || next == 'i' || next == 'y'){
						ubah [m++] = 's'; // Jika vokal 'e', 'i', atau 'y', ubah ke 's'
					} else {
						ubah[m++] = 'k'; // Jika huruf lain maka ubah ke 'k'
					}
				} else {
					ubah[m++] = 'k'; // Jika 'c' ada di akhir string maka ubah ke 'k'
				}
				k++; // Lanjut ke karakter selanjutnya
				} else { // Jika bukan 'c', langsung salin karakter ke output
					ubah[m++] = kata[k++];
				}	
			}
	ubah[m] = '\0'; // Tambahkan null-terminator untuk mengakhiri string output
	
}

int main(){
	
	int n; // Jumlah string yang ingin diinputkan 
	scanf("%d", &n); // Read jumlah string
	
	char kata[100][101]; // Array untuk menyimpan input string
	char ubah[100][101]; // Array untuk menyimpan hasil perubahan
	
	int i;
	// Loop untuk membaca n string dan melakukan perubahan
	for(i = 0; i < n; i++){
		scanf("%s", kata[i]); // Membaca string dari input
		pengubahan(kata[i], ubah[i]); // Memanggil fungsi pengubahan
	}
	
	printf("\n");
	
	// Loop untuk print hasil perubahan
	for(i = 0; i < n; i++){
		printf("%s\n", ubah[i]); // Print output string hasil pengubahan
	}
	
	return 0;
}
