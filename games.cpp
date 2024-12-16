#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int team; // Variabel untuk menyimpan jumlah tim.
    cin >> team; // Input jumlah tim.

    int number(0); // Variabel untuk menghitung jumlah pertandingan khusus.
    vector<int> h(team), a(team); // Dua vektor untuk menyimpan warna seragam kandang (h) dan tandang (a).
    
    for (int i = 0; i < team; ++i) // Loop untuk setiap tim.
    {
        cin >> h[i] >> a[i]; // Input warna seragam kandang dan tandang tim ke-i.
        for (int j = 0; j < i; ++j) // Loop untuk memeriksa semua tim sebelumnya.
        {
            if (h[i] == a[j]) // Jika seragam kandang tim ke-i sama dengan seragam tandang tim ke-j.
            {
                number += 1; // Tambahkan 1 ke counter.
            }
            if (a[i] == h[j]) // Jika seragam tandang tim ke-i sama dengan seragam kandang tim ke-j.
            {
                number += 1; // Tambahkan 1 ke counter.
            }
        }
    }
    cout << number << endl; // Output jumlah pertandingan khusus.
    return 0;
}
