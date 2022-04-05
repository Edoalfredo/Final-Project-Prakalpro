#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{ 
  awal:
     printf("\n");
     printf("\t=====[ DAFTAR TIKET KONSER BLINK-182 ]=====\n\n");
     printf("\t____________________________________________\n");
     printf("\t|   Kode Kelas   |    Kelas    |   Harga   |\n");
     printf("\t|       1        |   VVIP      | 1.000.000 |\n");
     printf("\t|       2        |   VIP       | 800.000   |\n");
     printf("\t|       3        |   D-PANGUNG | 500.000   |\n");
     printf("\t|       4        |   BIASA     | 300.000   |\n");
     printf("\t|________________|_____________|_______(Rp)|\n");
     printf("\n");
     printf("\n\tMasukan Nama Pembeli   : ");
     scanf("%d", &nama);
     printf("/tMasukan Banyak Kelas : ");
     scanf("%d", n);
     printf("\n\t________________________\n");
     for(i=1; i<=n; i++){
         printf("\n\tpembelian Tiket ke-%d\n\n", i);
         kode:
         printf("\tkode kelas\t: ");
         scanf("%d",&kode[i]);
  return 0;
}

