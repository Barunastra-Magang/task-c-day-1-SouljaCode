//  SOAL LATIHAN MODUL 1 

/* 
 * Soal 1: Cek apakah bilangan 0-999 merupakan bilangan Armstrong.
 *          (153 = 1^3 + 5^3 + 3^3 = 153)
 *          Input : 153
 *          Output: Merupakan Bilangan Armstrong
 * 
*/

#include <stdio.h>

int main() {
    int n, asli, ratusan, puluhan, satuan, jumlah; // deklarasi variabel
    scanf("%d", &n); // minta input angka
    asli = n; // simpan nilai asli
    ratusan = n / 100; // ambil angka ratusan dengan pembagian int
    puluhan = (n / 10) % 10; // ambil angka puluhan dengan pembagian int dan modulus 10
    satuan = n % 10; // ambil angka satuan dengan modulus 10
    jumlah = ratusan * ratusan * ratusan + puluhan * puluhan * puluhan + satuan * satuan * satuan; // rumus angka armstrong yaitu ratusan^3 + puluhan^3 + satuan^3
    
    if (jumlah == asli) // mengecek apakah bilangan armstrong atau tidak dengan membandingkan hasil perhitungan dengan angka input
        printf("Merupakan Bilangan Armstrong\n");
    else
        printf("Bukan Bilangan Armstrong\n");
    
    return 0;
}

/* 
 * Soal 2: Cetak terbilang dari angka 0-999.
 *          Input : 979
 *          Output: Sembilan ratus tujuh puluh sembilan
 *
*/
 
#include <stdio.h>
#include <string.h>   // untuk strcpy, strcat
#include <ctype.h>    // untuk toupper

// Mengubah angka 0-9 menjadi kata satuan
const char* satuan(int n) {
    switch(n) {
        case 0: return "nol";
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        default: return "";
    }
}

// Mengubah angka 0-9 menjadi kata belasan (10-19)
const char* belasan(int n) {   // n mewakili digit terakhir 0..9 untuk 10..19
    switch(n) {
        case 0: return "sepuluh";
        case 1: return "sebelas";
        case 2: return "dua belas";
        case 3: return "tiga belas";
        case 4: return "empat belas";
        case 5: return "lima belas";
        case 6: return "enam belas";
        case 7: return "tujuh belas";
        case 8: return "delapan belas";
        case 9: return "sembilan belas";
        default: return "";
    }
}

// Mengubah angka puluhan (2-9) menjadi kata puluhan
const char* puluhan(int n) {
    switch(n) {
        case 2: return "dua puluh";
        case 3: return "tiga puluh";
        case 4: return "empat puluh";
        case 5: return "lima puluh";
        case 6: return "enam puluh";
        case 7: return "tujuh puluh";
        case 8: return "delapan puluh";
        case 9: return "sembilan puluh";
        default: return "";
    }
}

int main() {
    int n;
    scanf("%d", &n);   // mmeminta input angka 0-999

    char hasil[100] = "";   // buffer untuk menyusun kata terbilang

    // jika angka 0
    if (n == 0) {
        strcpy(hasil, "nol");
    }
    // 1 - 9
    else if (n < 10) {
        strcpy(hasil, satuan(n));
    }
    // 10 - 19
    else if (n < 20) {
        strcpy(hasil, belasan(n - 10));   // indeks 0 untuk 10, 1 untuk 11, dst
    }
    // 20 - 99
    else if (n < 100) {
        int puluh = n / 10;       // digit puluhan
        int satu = n % 10;         // digit satuan
        strcpy(hasil, puluhan(puluh));   // tulis kata puluhannya
        if (satu != 0) {                   // jika ada satuan, m3nammbahkan
            strcat(hasil, " ");
            strcat(hasil, satuan(satu));
        }
    }
    // 100 - 999
    else {
        int ratus = n / 100;       // digit ratusan
        int sisa = n % 100;         // dua digit terakhir

        // Bagian ratusan
        if (ratus == 1) {
            strcpy(hasil, "seratus");   // khusus 100
        } else {
            strcpy(hasil, satuan(ratus));
            strcat(hasil, " ratus");
        }

        // Bagian sisa (jika ada)
        if (sisa > 0) {
            strcat(hasil, " ");
            if (sisa < 10) {                    // 1-9
                strcat(hasil, satuan(sisa));
            } else if (sisa < 20) {              // 10-19
                strcat(hasil, belasan(sisa - 10));
            } else {                              // 20-99
                int puluh = sisa / 10;
                int satu = sisa % 10;
                strcat(hasil, puluhan(puluh));
                if (satu != 0) {
                    strcat(hasil, " ");
                    strcat(hasil, satuan(satu));
                }
            }
        }
    }

    // Kapitalisasi huruf pertama
    hasil[0] = toupper(hasil[0]);

    // Cetak hasil
    printf("%s\n", hasil);

    return 0;
}

/* 
 *  Soal 3: 7-segment display. Input 4 bit (I1 I2 I3 I4) sebagai
 *          notasi biner, output 7 sinyal A-G (1=menyala, 0=mati).
 *          Input : 0 0 0 0
 *          Output: 1 1 1 1 1 1 0
*/

#include <stdio.h>

int main() {
    int i1, i2, i3, i4;
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4); // minta input angka
    
    // Hitung nilai desimal dari 4 bit (I1 sebagai MSB)
    int angka = i1 * 8 + i2 * 4 + i3 * 2 + i4;
    
    // Variabel untuk menyimpan status segmen A-G
    int a, b, c, d, e, f, g;
    
    // Switch-case untuk menentukan pola berdasarkan digit 0-9
    switch (angka) {
        case 0:
            a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 0;
            break;
        case 1:
            a = 0; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;
            break;
        case 2:
            a = 1; b = 1; c = 0; d = 1; e = 1; f = 0; g = 1;
            break;
        case 3:
            a = 1; b = 1; c = 1; d = 1; e = 0; f = 0; g = 1;
            break;
        case 4:
            a = 0; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1;
            break;
        case 5:
            a = 1; b = 0; c = 1; d = 1; e = 0; f = 1; g = 1;
            break;
        case 6:
            a = 1; b = 0; c = 1; d = 1; e = 1; f = 1; g = 1;
            break;
        case 7:
            a = 1; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;
            break;
        case 8:
            a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 1;
            break;
        case 9:
            a = 1; b = 1; c = 1; d = 1; e = 0; f = 1; g = 1;
            break;
        default: // Untuk nilai di luar 0-9, semua segmen mati
            a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; g = 0;
    }
    
    // Cetak hasil
    printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
    
    return 0;
}
 