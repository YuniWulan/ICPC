#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur data 'Pair' yang menyimpan pasangan key-value.
typedef struct {
    int key;
    int value;
} Pair;

// Mendefinisikan struktur data 'Map' yang menyimpan array of 'Pair' dan atribut ukuran dan kapasitas map.
typedef struct {
    Pair *pairs;
    int ukuran;    // Menyimpan jumlah pasangan yang ada dalam map
    int kapasitas; // Menyimpan kapasitas maksimal yang tersedia untuk map
} Map;

// Fungsi untuk menginisialisasi map dengan ukuran 0 dan kapasitas 10.
void initMap(Map *map) {
    map->ukuran = 0;
    map->kapasitas = 10;
    map->pairs = (Pair *)malloc(map->kapasitas * sizeof(Pair));  // Alokasi memori untuk pasangan key-value
}

// Fungsi untuk menambahkan key ke dalam map, atau memperbarui nilai jika key sudah ada.
void addToMap(Map *map, int key) {
    int i;
    for (i = 0; i < map->ukuran; i++) {
        if (map->pairs[i].key == key) {  // Jika key sudah ada, tambah nilai
            map->pairs[i].value++;
            return;
        }
    }

    // Jika kapasitas penuh, perbesar kapasitas map
    if (map->ukuran == map->kapasitas) {
        map->kapasitas *= 2;
        map->pairs = (Pair *)realloc(map->pairs, map->kapasitas * sizeof(Pair)); // Mengalokasi ulang memori
    }

    // Tambahkan pasangan key-value baru
    map->pairs[map->ukuran].key = key;
    map->pairs[map->ukuran].value = 1;  // Nilai awal adalah 1
    map->ukuran++;  // Tingkatkan ukuran map
}

// Fungsi untuk mendapatkan frekuensi maksimum dari pasangan dalam map
int getMaxFrequency(Map *map) {
    int maxFreq = 0;
    int i;
    for (i = 0; i < map->ukuran; i++) {
        if (map->pairs[i].value > maxFreq) { // Cek jika nilai pasangan lebih besar dari frekuensi maksimum
            maxFreq = map->pairs[i].value;
        }
    }
    return maxFreq;  // Kembalikan frekuensi maksimum
}

int main() {
    int n;
    scanf("%d", &n);  // Input jumlah elemen dalam array kacang

    // Alokasi memori untuk array kacang
    int *kacang = (int *)malloc(n * sizeof(int)); 
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &kacang[i]);  // Input nilai-nilai kacang
    }

    // Alokasi memori untuk array jumlah dan inisialisasi nilai pertama menjadi 0
    int *jumlah = (int *)malloc(n * sizeof(int)); 
    jumlah[0] = 0;

    // Perhitungan jumlah pasangan kacang berurutan
    int j;
    for (j = 0; j < n - 1; j++) {
        int total = kacang[j] + kacang[j + 1];  // Jumlahkan dua kacang berurutan
        if (jumlah[j] != total) {
            jumlah[j + 1] = total;  // Jika tidak sama, simpan jumlah
        } else {
            jumlah[j + 1] = 0;  // Jika sama, set jumlah ke 0
        }
    }

    // Inisialisasi map untuk menyimpan frekuensi jumlah yang dihitung
    Map freq;
    initMap(&freq);

    // Menambahkan nilai-nilai yang tidak 0 ke dalam map untuk menghitung frekuensi
    int l;
    for (l = 0; l < n; l++) {
        if (jumlah[l] != 0) {
            addToMap(&freq, jumlah[l]);  // Menambahkan nilai jumlah ke dalam map
        }
    }

    // Mendapatkan frekuensi maksimum dari nilai-nilai jumlah
    int maxFreq = getMaxFrequency(&freq); 
    printf("%d\n", maxFreq);  // Outputkan frekuensi maksimum

    // Membebaskan memori yang dialokasikan
    free(kacang);
    free(jumlah);
    free(freq.pairs);

    return 0;  // Mengakhiri program
}
