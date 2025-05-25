#include <stdio.h>
#include <time.h> //saya akan menggunakan waktu lama pengerjaan jadi pakai library ini

int main() {
    //pertanyaan, cara: saya dapat ketika projek matkul Pengantar Komputasi
    char pertanyaan[][500] = {
        "Apa yang harus kita lakukan jika ingin membuat robot mengikuti perintah?", 
        "Saat ingin menyelesaikan masalah, langkah pertama yang harus dilakukan adalah?",
        "Jika kita ingin menemukan pola dalam sesuatu, kita sedang menggunakan teknik?",
        "Apa yang disebut sebagai instruksi berurutan dalam komputer?",
        "Mengapa komputer menggunakan bahasa pemrograman untuk bekerja?"
    };

    char pilihan[][4][100] = {
        {"a. Membelinya", "b. Memberi perintah acak", "c. Membuat algoritma", "d. Menunggu saja"},
        {"a. Langsung menjawab", "b. Membuat pertanyaan baru", "c. Memecah masalah menjadi bagian kecil", "d. Mengabaikannya"},
        {"a. Dekompisi", "b. Abstraksi", "c. Pengenalan pola", "d. Algoritma"},
        {"a. Program", "b. Algoritma", "c. Variabel", "d. Debugging"},
        {"a. Karena bahasa manusia sulit dipahami oleh komputer", "b. Karena komputer suka belajar sendiri", "c. Karena komputer hanya mengerti gambar", "d. Karena komputer tidak membutuhkan bahasa"}
    };

    char jawabanBenar[] = {'c', 'c', 'c', 'b', 'a'};

    char trivia[][200] = { //pengetahuan tambahan. agar anak yg menjawab salah tetap mengerti
        "Trivia: Robot membutuhkan algoritma untuk mengikuti perintah dengan benar!",
        "Trivia: Memecah masalah menjadi bagian kecil disebut 'dekomposisi' dalam Computational Thinking.",
        "Trivia: Pengenalan pola membantu kita menemukan kesamaan dalam data dan menyederhanakan solusi!",
        "Trivia: Algoritma adalah langkah-langkah yang harus dilakukan secara berurutan untuk menyelesaikan tugas.",
        "Trivia: Komputer hanya mengerti kode pemrograman karena bahasa manusia terlalu kompleks!"
    };

    int skor = 0; //untuk nyimpen, mulai nya dari 0 nanti buat condisional
    char jawaban; //menyimpan jawaban nanti, variabel
    clock_t mulai, selesai; //salah satu yg ada dilibrary time.h dan fungsinya menyimpan waktu pemprosesan
    int jumlahSoal = 5; //1 soal 20 poin

    printf("===================================\n"); //:) biar sesuai rikwes
    printf("            QUIZ TEKA TEKI          \n");
    printf("       COMPUTATIONAL THINKINNG      \n");
    printf("===================================\n\n");

    printf("Pilih jawaban (A/B/C/D)\n");
    printf("Jika jawaban yang diinput selain opsi tersebut maka sistem akan terus meminta input opsi yang benar! \n\n");

    for (int i = 0; i < jumlahSoal; i++) {
        mulai = clock(); //mencatat waktu mulai
        printf("--------------------------------\n"); //batas tiap nomer
        printf("%d. %s\n", i + 1, pertanyaan[i]); //i+1 untuk sistem tau pertanyaan mulai dari 1, kalo hanya i nanti dari 0
        for (int j = 0; j < 4; j++) {
            printf("   %s\n", pilihan[i][j]); //i = jawaban yg sedang diakses, j=opsinya. pake [] soalnya array
        }

        //untuk mengecek input penjawab
        do {
            printf("Jawaban: ");
            scanf(" %c", &jawaban);
            if (jawaban != 'a' && jawaban != 'b' && jawaban != 'c' && jawaban != 'd') {
                printf("tolong input kembali dan masukan jawaban sesuai opsi!\n");
            }
        } while (jawaban != 'a' && jawaban != 'b' && jawaban != 'c' && jawaban != 'd');

        selesai = clock(); //waktu berakhir. saya belum bisa pakai batas waktu, mungkin perlu mempelajari lebih dalam
        double waktuJawab = (double)(selesai - mulai) / CLOCKS_PER_SEC; //menghitung waktu jawab, dan per detik diitung

        // Mengecek jawaban benar atau salah
       if (jawaban == jawabanBenar[i]) {
        printf("Yeayy Benar! Kamu dapat 20 poin!\n");
        printf("Selamat ya!\n");
        skor += 20; // Tambah 20 poin setiap jawaban benar
       } else {
        printf("Yahh Salah! Jawaban benarnya adalah %c.\n", jawabanBenar[i]);
        printf("Terus semangat dan jangan putus asa!\n");
       }
    

        printf("%s\n", trivia[i]);
        printf("Waktu menjawab: %.2f detik\n\n", waktuJawab);
    }

    printf("===================================\n"); //pembatas soal ke poin
    printf("Skor akhir Anda: %d/100\n", skor); //nampilin skor

    // Menampilkan hasil akhir berdasarkan skor
    printf("Kuis selesai! Skor akhir Anda: %d/100\n", skor);
    if (skor == 100) {
        printf("🎉 Nilai sempurna! Kamu luar biasa! Selamat! 🎉\n");
    } else if (skor >= 70) {
        printf("Bagus! Tingkatkan lagi yaa!\n");
    } else if (skor >= 51) {
        printf("Yahh Remedial, belajar lebih giat lagi ya! Kurangi scroll sosmed terlalu sering\n");
    } else {
        printf("Jangan HP terus! Belajar!\n");
    }

    return 0;
}