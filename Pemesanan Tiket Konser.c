#include <stdio.h>
#include <string.h>
#include <time.h>

void pemesanan(int kode[10], char kls[100], int harga[100], int n, int i, int j){
    for( i=1; i<=n; i++){
        printf("\n\tpembelian Tiket ke-%d\n\n", i);
         kode:
         printf("\tkode kelas\t: ");
         scanf("%d",&kode[i]);
         if (kode[i]==1)
         {
             strcpy(kls[i],"VVIP");
             harga[i]=1000000;
         }
         else if (kode[i]==2)
         {
             strcpy(kls[i],"VIP");
             harga[i]=800000;
         }
         else if (kode[i]==3)
         {
             strcpy(kls[i],"D-PANGGUNG");
             harga[i]=500000;
         }
         else if (kode[i]==2)
         {
             strcpy(kls[i],"BIASA");
             harga[i]=300000;
         }
         else
         {
             printf("\n\tIMPUTAN SALAH!!!!\n");
             goto kode;
         }
     printf("\tjumblah tiket\t: ");
     scanf("%d", &j[i]);
     printf("\t_____________________");
         
    }
}


int main()
{ 
  struct tm *Sya_T;                                       
    time_t Tval;
    Tval = time(NULL);
    Sya_T = localtime(&Tval);
    int i, bayar, n, kembalian, pilih;
    int j[100], th[100], harga[100], tsh=0, kode[10];
    char kls[100][30], nama[50];
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
  
     pemesanan(kode, kls, harga, n, i, j);
  return 0;
}

