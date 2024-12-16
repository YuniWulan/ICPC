#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string a, b; // Deklarasi dua string `a` dan `b`
    cin >> a >> b; // Membaca input string `a` dan `b`
    reverse(b.begin(), b.end()); // Membalik string `b` (menggunakan fungsi `reverse`)
    if (a == b) // Memeriksa apakah string `a` sama dengan string `b` setelah dibalik
    {
        cout << "YES" << endl; // Jika sama, cetak "YES"
    }
    else
    {
        cout << "NO" << endl; // Jika tidak sama, cetak "NO"
    }

    return 0;
}
