// --- SOAL LATIHAN MODUL 2 ---
 
/*
*  Soal 1: Cetak "Ganjil"/"Genap" untuk setiap input.
*/

#include <stdio.h>

int main() {
    int n;  // Variabel untuk menyimpan bilangan yang diinput

    // Membaca bilangan bulat satu per satu hingga akhir input (EOF)
    while (scanf("%d", &n) != EOF) {
        // Mengecek apakah bilangan tersebut genap
        // n % 2 == 0 berarti sisa bagi 0, maka genap
        if (n % 2 == 0) {
            printf("Genap\n");   // Output jika genap
        } else {
            printf("Ganjil\n");  // Output jika ganjil
        }
    }

    return 0; 
}

/* 
*  Soal 2: Cetak '*' untuk angka genap, nilai asli untuk ganjil,
 *          dari 1 sampai n.
 *          Input : 6
 *          Output: 1 * 3 * 5 *
*/

#include <stdio.h>

int main() {
    int n, i;  // n = batas atas, i = penghitung

    // Meminta input bilangan bulat n
    scanf("%d", &n);

    // Loop dari 1 hingga n
    for (i = 1; i <= n; i++) {
        // Cetak spasi sebelum elemen kecuali untuk elemen pertama
        if (i > 1) {
            printf(" ");
        }

        // Cek apakah i genap
        if (i % 2 == 0) {
            printf("*");       // genap: cetak bintang
        } else {
            printf("%d", i);   // ganjil: cetak angka
        }
    }

    printf("\n");  // baris baru setelah selesai
    return 0;
}

/*
*  Soal 3: Cetak '*' untuk bilangan prima, nilai asli untuk non-prima,
 *          dari 2 sampai n.
 *          Input : 10
 *          Output: * * 4 * 6 * 8 9 10
*/

#include <stdio.h>

int main() {
    int n, i, j, prima;
    scanf("%d", &n);  // Membaca batas atas n

    // Loop dari 2 sampai n
    for (i = 2; i <= n; i++) {
        // Cek apakah i bilangan prima
        prima = 1;  // Anggap prima
        for (j = 2; j * j <= i; j++) {  // Cek pembagi hingga akar i
            if (i % j == 0) {
                prima = 0;  // Bukan prima
                break;
            }
        }

        // Cetak dengan spasi antar elemen (kecuali elemen pertama)
        if (i > 2) {
            printf(" ");
        }

        if (prima) {
            printf("*");       // Prima: cetak bintang
        } else {
            printf("%d", i);   // Bukan prima: cetak angka
        }
    }
    printf("\n");  // Baris baru di akhir
    return 0;
}

/*
*  Soal 4: Cetak N angka input secara terbalik.
 *          Input : 5 / 1 4 3 2 9
 *          Output: 9 2 3 4 1
*/

#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);  // Meminta jumlah angka

    int arr[n];  // Array untuk menyimpan n angka

    // Membaca n angka ke dalam array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Mencetak angka secara terbalik
    for (i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf(" ");  // Spasi antar angka, kecuali setelah yang terakhir
        }
    }
    printf("\n");  // Baris baru di akhir

    return 0;
}

/* 
*  Soal 5: Hitung jumlah tiap vokal (A/a, I/i, U/u, E/e, O/o)
 *          dalam string S.
*/

#include <stdio.h>
#include <string.h>  // untuk strlen
#include <ctype.h>   // untuk tolower

int main() {
    char S[1000];            // Array untuk menyimpan string input
    int i;                    // Penghitung loop
    int countA = 0, countI = 0, countU = 0, countE = 0, countO = 0; // Penghitung vokal

    // Membaca string (bisa mengandung spasi) menggunakan fgets
    fgets(S, sizeof(S), stdin);

    // Menghilangkan karakter newline ('\n') jika ada di akhir string
    S[strcspn(S, "\n")] = 0;

    // Loop sepanjang string
    for (i = 0; i < strlen(S); i++) {
        char c = tolower(S[i]); // Ubah ke huruf kecil agar tidak case sensitive

        // Cek vokal dan tambah hitungan
        if (c == 'a') {
            countA++;
        } else if (c == 'i') {
            countI++;
        } else if (c == 'u') {
            countU++;
        } else if (c == 'e') {
            countE++;
        } else if (c == 'o') {
            countO++;
        }
    }

    // Cetak hasil
    printf("A:%d I:%d U:%d E:%d O:%d\n", countA, countI, countU, countE, countO);

    return 0;
}

/*
 *  Soal 6: Konversi snake_case ke camelCase.
 *          Input : player_score
 *          Output: playerScore
*/

#include <stdio.h>
#include <string.h>  // untuk strcspn
#include <ctype.h>   // untuk toupper

int main() {
    char input[1000];   // Menyimpan string input (snake_case)
    char output[1000];  // Menyimpan hasil konversi (camelCase)
    int i, j = 0;       // i untuk indeks input, j untuk indeks output
    int next_capital = 0; // Flag: 1 jika karakter berikutnya harus kapital

    // Meminta string (bisa mengandung spasi, tapi snake_case biasanya tanpa spasi)
    fgets(input, sizeof(input), stdin);
    // Menghapus karakter newline ('\n') jika ada
    input[strcspn(input, "\n")] = 0;

    // Memproses setiap karakter dalam string input
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '_') {
            // Jika menemukan underscore, set flag agar karakter berikutnya dikapital
            next_capital = 1;
        } else {
            if (next_capital) {
                // Ubah huruf menjadi kapital dan simpan ke output
                output[j++] = toupper(input[i]);
                next_capital = 0; // Reset flag
            } else {
                // Salin karakter biasa
                output[j++] = input[i];
            }
        }
    }
    output[j] = '\0'; // Akhiri string output

    // Cetak hasil konversi
    printf("%s\n", output);

    return 0;
}