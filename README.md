# big-challange-project
tugas-akhir-pemrog-yey

Anda dimintakan untuk membuat program yang dapat mentransformasi huruf-huruf
dari sebuah kata dalam sebuah file teks menjadi dalam bentuk skor (nilai numerik),
mengubah kata-kata dalam huruf kecil (lower case), menghimpun semua kata dengan
skor yang sama, dan mengurutkan nilai skor kata dari yang paling besar ke yang paling
kecil (descending order based-on score). Hasil pengurutan itu kemudian disimpan
dalam sebuah file binari dengan susunan sebagai berikut:
[skor_terbesar][jumlah_kata_dengan_skor_tersebut][panjang_kata][kata] [panjang_kata]
[kata][panjang_kata][kata] … [skor_kedua_terbesar]
[jumlah_kata_dengan_skor_tersebut][panjang_kata][kata][panjang_kata][kata]
[panjang_kata][kata] … [skor_ketiga_terbesar][jumlah_kata_dengan_skor_tersebut]
[panjang_kata][kata][panjang_kata][kata][panjang_kata][kata] … dstnya sampai dengan
skor terkecil
Dimana:

[skor] bertipe double
[jumlah_kata] bertipe integer
[panjang_kata] bertipe integer
[kata] bertipe string atau array of char

Catatan: Tanda kurung [ ] di atas tidak perlu disimpan, hanya ditulis untuk memisahkan
setiap bagian.

Rumus transformasi untuk membuat skor kata silahkan ditentukan, misal setiap huruf
ditransformasi menjadi nilai desimal pada tabel ASCII yaitu a=97, b=98, c=99, …., y=121,
z=122 atau bentuk transformasi lain, silahkan ditentukan.
Sebagai contoh:

Kata: lokal = 108+111+107+97+108 = 531
Kata: kopi = 107+111+112+105 = 435
Kata: piko = 112+105+107+111 = 435
Anda juga diminta untuk menampilkan maksimum n kata dengan nilai skor terbesar ke
layar monitor. Nilai n diinput oleh user via keyboard. Selain itu, anda juga diminta untuk
mengurutkan kata dari yang terpanjang ke yang terpendek dalam setiap kelompok skor.
Untuk contoh di atas, kata kopi, dan piko sama-sama memiliki skor 435 maka diurutkan
berdasar kata kopi dan piko yang sama-sama berukuran 4 huruf.
