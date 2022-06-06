#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define vip 1000000
#define stage1 800000
#define stage2 500000
#define stage3 300000

FILE *ptr;
char txt[128];
void add_data()
{
    FILE* f = fopen("data.txt","a");
    printf("Nama\t: ");
    fflush(stdin);fgets(txt,128,stdin);
    fputs(txt,f);
    printf("Stage\t: ");
    fflush(stdin);fgets(txt,128,stdin);
    fputs(txt,f);
    printf("Jumlah\t: ");
    fflush(stdin);fgets(txt,128,stdin);
    fputs(txt,f);
    printf("Biaya\t: ");
    fflush(stdin);fgets(txt,128,stdin);
    fputs(txt,f);
    printf("Kode\t: ");
    fflush(stdin);fgets(txt,128,stdin);
    fputs(txt,f);
    fclose(f);
}

void read_data()
{
    FILE *f = fopen("data.txt","r");
    short c=-1,m=1;
    while(fgets(txt,128,f)!=NULL)
    {
        ++c;
        if(c==0)
        {
            printf("Nama Pembeli ke-%d\n",m);
            printf("Kode\t: %s",txt);
            ++m;
        }
        if(c==1)printf("Nama\t: %s",txt);
        if(c==2)printf("Stage\t: %s",txt);
        if(c==3)printf("Jumlah\t: %s",txt);
        if(c==4){printf("Kode\t: %s",txt);c=-1;}
    }
    fclose(f);
}

struct node
{
  char nama[30];
  int stage;
  int jumlah;
  int biaya;
  int kode;
  struct node *next;
};

typedef struct node tiket;
struct node *head = NULL, *temp, *temp1, *temp2;
int kode = 1;
int total_uang(int pil, int jum)
{
  int total_bayar;
  if(pil==1)
  {
    total_bayar=vip*jum;
  }
  else if(pil==2)
  {
    total_bayar=stage1*jum;
  }
  else if(pil==3)
  {
    total_bayar=stage2*jum;
  }
    if(pil==4)
  {
    total_bayar=stage3*jum;
  }
  return total_bayar;
}

void create_tiket(char nama[])
{
  ptr=fopen("data_tiket.txt", "a");
  int kembalian;
  int bayar;
  struct tm *Sya_T;                                    
  time_t Tval;
  Tval = time(NULL);
  Sya_T = localtime(&Tval);
  int pil, jum;
  temp = (tiket*)malloc(sizeof(tiket));
  temp->next = NULL;
  printf("\n");
     printf("\t=====[ DAFTAR TIKET KONSER  NECK DEEP ]=====\n\n");
     printf("\t____________________________________________\n");
     printf("\t|   Kode Kelas   |    Kelas    |   Harga   |\n");
     printf("\t|       1        |   VIP       | 1.000.000 |\n");
     printf("\t|       2        |   Stage 1   | 800.000   |\n");
     printf("\t|       3        |   Stage 2   | 500.000   |\n");
     printf("\t|       4        |   Stage 3   | 300.000   |\n");
     printf("\t|________________|_____________|_______(Rp)|\n");
     printf("\n");
  printf("\n\tPilih Stage Tiket \t: ");
  scanf("%i", &pil);
  fprintf(ptr,"Stage : %i",pil);
  temp->stage = pil;
  printf("\tJumlah tiket dipesan \t: ");
  scanf("%i", &jum);
  fprintf(ptr,"\nJumlah Tiket : %i\n\n", jum);
  temp->jumlah = jum;
  temp->biaya = total_uang(pil,jum);
  strcpy(temp->nama,nama);
  fclose(ptr);
  temp->kode= kode;
  kode++;
  printf("\tTotal biaya \t\t: Rp. %i ", temp->biaya);
  pill:
  printf("\n\tMasukan Jumblah Pembayaran\t : Rp. ");
  scanf("%d", &bayar);
  kembalian = bayar-temp->biaya;
  if(bayar>= temp->biaya)
  {
      system("cls");
      goto data;
  }
  else
  {
      printf("UANG ANDA KURANG!!!\n");
      goto pill;
  }
  data:
  system("cls");
  printf("\n\n");
  printf("=========================================================\n");
  printf("=================[ DATA PEMBAYARAN TIKET ]===============\n");
  printf("=========================================================\n");
  printf("\n");
  printf("\tNama Pemesan  : %s\n", temp->nama);
  printf("\tDate          : %d/%d/%d\n", Sya_T->tm_mday, Sya_T->tm_mon+1, 1900+Sya_T->tm_year);
  printf("\tTime          : %d:%d:%d\n", Sya_T->tm_hour, Sya_T->tm_min, Sya_T->tm_sec);
  printf("_________________________________________________________\n");
  printf("    | Kelas \t| Jumblah   \t| Subtotal\t\n");
  printf("_________________________________________________________\n");
  printf("\n    | %i\t\t| %i\t    \t| Rp.%d\t\n", temp->stage, temp->jumlah, temp->biaya);
  printf("\n_________________________________________________________\n");
  printf("\n Total Harga\t\t\t\t    | Rp.%i \n", temp->biaya);
  printf("\n Pembayaran\t\t\t\t    | Rp.%d \n", bayar);
  printf("\n Kembalian\t\t\t\t    | Rp.%d \n", kembalian);
  printf("\n_________________________________________________________\n");
}
void pesan_tiket(char nama[])
{
  if(head==NULL)
  {
    create_tiket(nama);
    head=temp;
    temp1=head;
  }
  else
  {
    create_tiket(nama);
    temp->next = head;
    head=temp;
  }
}

void cek_tiket()
{
struct node *curr = head;
    int kode;
    int tru;
    printf("Masukan Kode Tiket: ");
    scanf("%i", &kode);
    while(curr!=NULL)
    {
        if(curr->kode==kode)
        {
            printf("\nKode pesanan \t: %i\n", curr->kode);
            printf("Nama Pemesan \t: %s", curr->nama);
            printf("Stage \t\t: %i\n", curr->stage);
            printf("Jumlah Tiket \t: %i\n", curr->jumlah);
            tru = 1;
        }
         curr = curr->next;
    }
    if(tru!=1)
    {
      printf("Tiket Tidak ditemukan");
    }
}
void display_tiket()
{
    tiket *temp2;
    temp2 = head;
    if(temp2==NULL)
    {
        printf("Belum ada Pesanan :)");
    }
    while(temp2!=NULL)
    {
      printf("\nKode pesanan : %i\n", temp2->kode);
      printf("Nama Pemesan : %s", temp2->nama);
      printf("Stage : %i\n", temp2->stage);
      printf("Jumlah Tiket : %i\n", temp2->jumlah);
      printf("Total biaya : Rp. %i ", temp2->biaya);
      temp2=temp2->next;
    }
}
int main()
{
  int pilihan, pil;
  char nama[30];
  menu:
  system("cls");
  printf("\t=====[ MENU DAFTAR TIKET ]=====\n\n");
  printf("\t1. Pesan Tiket\n\t2. Cari Tiket Anda\n\t3. daftar pesanan\n\t4. keluar\n");
  printf("\t===============================\n");
  printf("\tMasukan Pilihan : ");
  scanf("%i", &pilihan);
  switch (pilihan)
  {
  case 1:
    system("cls");
    fflush(stdin);
    printf("MASUKAN RINCIAN PESANAN\n");
    printf("=========================\n");
    printf("Masukan Nama Anda : ");
    fgets(nama, sizeof(nama), stdin);
    ptr=fopen("data_tiket.txt", "a");
    fprintf(ptr, "Nama : %s", nama);
    fclose(ptr);
    pesan_tiket(nama);
    printf("\nTekan 1 untuk kembali ke menu utama :");
    scanf("%i", &pil);
        if(pil==1)
          goto menu;
    break;
  case 2:
    system("cls");
    cek_tiket();
    printf("\nTekan 1 untuk kembali ke menu utama :");
    scanf("%i", &pil);
        if(pil==1)
          goto menu;
  break;
  case 3:
    system("cls");
    display_tiket();
    printf("\nTekan 1 untuk kembali ke menu utama :");
    scanf("%i", &pil);
        if(pil==1)
          goto menu;
  break;;
  default:
    break;
  }
  return 0;
}
