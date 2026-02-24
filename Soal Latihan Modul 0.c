// --- SOAL LATIHAN MODUL 0 ---

/*
 *  Soal 1: Hitung umur dari tahun lahir dan tahun sekarang.
 *          Input : 2002 2023
 *          Output: 21
 */

#include <stdio.h> // library untuk printf dan scanf

int main() {
    int tahun_lahir, tahun_sekarang, umur; // deklarasi variabel untuk rumus

    // Ambil input tahun lahir dan tahun sekarang
    scanf("%d %d", &tahun_lahir, &tahun_sekarang);

    // Rumus umur
    umur = tahun_sekarang - tahun_lahir;

    // Menampilkan hasil
    printf("%d\n", umur);

    return 0;
}

/*
 *  Soal 2: Bagi P potongan pizza ke N teman sama rata.
 *          Sisa dimakan Ghifari.
 *          Input : 11 3
 *          Output: Teman mendapat 3 potong, Ghifari mendapat 2 potong
 *
*/

#include <stdio.h>

int main() {
    int P, N; // deklarasi P dan N variabel
    
    scanf("%d %d", &P, &N); // minta input P dan N
    int bagian_teman = P / N; // Rumus untuk menghitung berapa potong yang teman dapat, dengan deklarasi perhitungan dalam int
    int sisa = P % N; // Rumus untuk menghitung sisa untuk Ghifari
    printf("Teman mendapat %d potong, Ghifari mendapat %d potong\n", bagian_teman, sisa); // menampilkan hasil bagian_teman dan sisa
    return 0;
}

/*
Soal 3: Hitung (a+b)/c dengan 2 angka di belakang koma.
 *          Input : 5 6 3
 *          Output: 3.67
*/

#include <stdio.h>

int main() {
    int a, b, c; // deklarasi a b c sebagai variabel
    scanf("%d %d %d", &a, &b, &c);// minta input a b c
    
    float hasil = (a + b) / (float) c; // rumus untuk hitung (a+b)/c, menggunakan double didepan dan pada depan c agar keduanya dilihat sebagai angka berkoma
    printf("%.2f\n", hasil); // menampilkan hasil, dengan .2lf menunjukan hasil harus diikutkan 2 angka belakang koma
    // menggunakan double agar hasil lebih akurat daripada float
    return 0;
}

/*
Soal 4: Hitung jumlah dan rata-rata dari 5 bilangan A B C D E.
 *          Input : 6 9 4 20 7
 *          Output: 46 9.2
*/

#include <stdio.h>

int main() {
    int a, b, c, d, e; // deklarasi variabel sebagai angka
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e); // minta input
    
    int jumlah = a + b + c + d + e; // rumus jumlah
    double rata_rata = jumlah / 5.0; // rumus rata - rata, menggunakan double untuk angka koma
    
    printf("%d %.1f\n", jumlah, rata_rata); // menampilkan hasil, menggunakan .1f agar 1 angka belakang koma
    
    return 0;
}