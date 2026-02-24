// --- SOAL LATIHAN MODUL 3 ---

/*
 * Soal 1: Fungsi rekursif untuk N! (N faktorial).
 *          Input : 5
 *          Output: 120
*/

#include <stdio.h>

// Set fungsi Faktorial
int faktorial(int n);

// Definisi fungsi faktorial secara rekursif
int faktorial(int n) {
    if (n == 0) {               // BASE CASE: 0! = 1
        return 1;
    } else {                     // RECURSIVE CASE: n! = n * (n-1)!
        return n * faktorial(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);           // Meminta input N

    int hasil = faktorial(n);  // Panggil fungsi rekursif
    printf("%d\n", hasil);     // Mencetak hasil

    return 0;
}


/*
 *  Soal 2: Deret 1, 5, 14, 30, ... Fungsi rekursif untuk
 *          menentukan bilangan ke-n.
 *          Input : 2
 *          Output: 5
*/

#include <stdio.h>

// Set fungsi deret
int deret(int n);

// Fungsi rekursif untuk menghitung bilangan ke-n pada deret
// Deret: 1, 5, 14, 30, ... = deret dengan beda yaitu kuadrat setiap bilangan
int deret(int n) {
    if (n == 1) {               // Base case: suku pertama = 1
        return 1;
    } else {                    // Rekursif: suku ke-n = suku ke-(n-1) + n^2
        return deret(n - 1) + n * n;
    }
}

int main() {
    int n;
    scanf("%d", &n);           // Meminta input bilangan ke n
    printf("%d\n", deret(n));  // Mencetak hasil
    
    return 0;
}

/*
 *  Soal 3: Fungsi untuk mencari nilai terbesar dan terkecil
 *          dari array A dengan N bilangan.
 *          Input : 5 / 1 2 3 4 5
 *          Output: max: 5, min: 1
 */

#include <stdio.h>

// Prototipe fungsi
int cariMax(int arr[], int n);
int cariMin(int arr[], int n);

// Fungsi untuk mencari nilai terbesar dalam array
int cariMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Fungsi untuk mencari nilai terkecil dalam array
int cariMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n, i;
    scanf("%d", &n);           // Memintq jumlah bilangan

    int arr[n];                // Array untuk menyimpan n bilangan
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Memintq bilangan yang akan dimasukan ke dalam array
    }

    int max = cariMax(arr, n); // Memanggil fungsi cariMax
    int min = cariMin(arr, n); // Memanggil fungsi cariMin

    printf("max: %d, min: %d\n", max, min);
    return 0;
}


