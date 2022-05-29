#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define vip 100000
#define stage1 75000
#define stage2 50000
#define stage3 25000

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
void create_tiket(char nama[])
{
  int pil, jum;
  temp = (tiket*)malloc(sizeof(tiket));
  temp->next = NULL;
  printf("\nStage Tiket\n1. VIP\n2. Stage 1\n3. Stage 2\n4. Stage 3\n");
  printf("\nPilih Stage Tiket : ");
  scanf("%i", &pil);
  temp->stage = pil;
  printf("Jumlah tiket yang ingin dipesan : ");
  scanf("%i", &jum);
  temp->jumlah = jum;
  temp->biaya = total_uang(pil,jum);
  strcpy(temp->nama,nama);
  temp->kode= kode;
  kode++;
  system("cls");
  printf("===========================================\n");
  printf("\tPesanan Berhasil Dibuat!!!\n");
  printf("===========================================\n");
  printf("Rincian Pesanan\n");
      printf("\nKode pesanan \t: %i\n", temp->kode);
      printf("Nama Pemesan \t: %s", temp->nama);
      printf("Stage \t\t: %i\n", temp->stage);
      printf("Jumlah Tiket \t: %i\n", temp->jumlah);
      printf("Total biaya \t: Rp. %i ", temp->biaya);

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


int main()
{ 
int pilihan, pil;
  char nama[30];
  menu:
  system("cls");
  printf("1. Pesan Tiket\n2. Cari Tiket Anda\n3. daftar pesanan\n4. keluar\n");
  printf("Masukan Pilihan : ");
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
    pesan_tiket(nama);
    printf("\nTekan 1 untuk kembali ke menu utama :");
    scanf("%i", &pil);
        if(pil==1)
          goto menu;
    break;
  default:
    break;
  }
  return 0;
}

