#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int pilihan,n=0;

struct tanggallahir{
	int tanggal;
	char bulan[50];
	int tahun;
	char cari;
}; typedef struct tanggallahir tgl;

struct wali{
	char alamat[50];
	char wali[50];
}; typedef struct wali wali;

struct siswa{
	char nomor_induk[50];
	char nama_siswa[50];
	
	char gender[50];
	wali walifl;
	tgl tglfl; 
}; typedef struct siswa fl;
fl a[50];

void menu_utama();
void tambah_data();
void view_data();
void cari_data();
void ubah_data();
void urutkan_data();

int main(){
	system("color 6");
	menu_utama();	
	return 0;
}

void menu_utama(){
	do{
		menu:
		printf("\n\t ==========================================");
		printf("\n\t|              SELAMAT DATANG              |");    
		printf("\n\t|===============SDN KAYEN I================|"); 
		printf("\n\t|  1. Daftarkan siswa                      |");
		printf("\n\t|  2. Tampilkan siswa terdaftar            |");
		printf("\n\t|  3. Cari siswa                           |");
		printf("\n\t|  4. Edit siswa                           |");
		printf("\n\t|  5. Urutkan siswa                        |");
		printf("\n\t|  6. Keluar                               |");
		printf("\n\t|==========================================|");
		printf("\n\tMasukkan pilihan menu (1-6)= ");
		scanf("%d", &pilihan);
		system("cls");
		
		switch(pilihan){
		case 1 :
		{
			system("cls");
			tambah_data();
			break;
		}
		case 2 :
		{
			system("cls");
			view_data();
			break;
		}
		case 3 :
		{
			system("cls");
			cari_data();
			break;
		}
		case 4 :
		{
			system("cls");
			ubah_data();
			break;
		}
		case 5 :
		{
			system("cls");
			urutkan_data();
			break;
		}
		case 6 :
		{
			printf("             T E R I M A  K A S I H                 ");
			exit(0);
			break;
		}
		default :
		{
			printf("\n\n[Keterangan] :");
			printf("\n ======================================================");
			printf("\n| Pilihan menu tidak ditemukan...                      |");
			printf("\n|======================================================|");
			printf("\nPress [ANY KEY] to back to menu\n");
			getch();
			system("cls");
			menu_utama();
		}
	}
	}while(pilihan>=1 && pilihan<=6);
}

void input(int i){
	printf("[siswa ke-%d] \n", i+1);
	printf("Masukan Nomor Induk      : "); fflush (stdin); gets(a[i].nomor_induk);
	printf("Masukan Nama Siswa       : "); fflush (stdin); gets(a[i].nama_siswa);
	printf("Masukan Jenis Kelamin    : "); fflush (stdin); gets(a[i].gender);
	printf("Masukan Orang Tua/Wali   : "); fflush (stdin); gets(a[i].walifl.wali);
	printf("Masukan Alamat           : "); fflush (stdin); gets(a[i].walifl.alamat);
	printf("Masukan Tanggal Lahir    : "); fflush (stdin); scanf("%d",&a[i].tglfl.tanggal);
	printf("Masukan Bulan Lahir      : "); fflush (stdin); gets(a[i].tglfl.bulan);
	printf("Masukan Tahun Lahir      : "); fflush (stdin); scanf("%d",&a[i].tglfl.tahun);
}

void view(int i){
	printf("\n[siswa ke-%d]", i+1);
	printf("\nNomor Induk       : %s", a[i].nomor_induk);
	printf("\nNama Siswa        : %s", a[i].nama_siswa);
	printf("\nJenis Kelamin     : %s", a[i].gender);
	printf("\nOrang Tua/Wali    : %s", a[i].walifl.wali);
	printf("\nAlamat            : %s", a[i].walifl.alamat);
	printf("\nTanggal Lahir     : %d", a[i].tglfl.tanggal);
	printf("\nBulan Lahir       : %s", a[i].tglfl.bulan);
	printf("\nTahun Lahir       : %d", a[i].tglfl.tahun);
	printf("\n");
}

void updatesiswa(int i){
	printf("\n[siswa ke-%d] \n", i+1);
	printf("Ganti Nama         	 : "); fflush (stdin); gets(a[i].nama_siswa);
	printf("Ganti Jenis Kelamin  : "); fflush (stdin); gets(a[i].gender);
	printf("Ganti Orang Tua/Wali : "); fflush (stdin); gets(a[i].walifl.wali);
	printf("Ganti Alamat    	 : "); fflush (stdin); gets(a[i].walifl.alamat);
	printf("Ganti Tanggal Lahir  : "); fflush (stdin); scanf("%d",&a[i].tglfl.tanggal);
	printf("Ganti Bulan Lahir	 : "); fflush (stdin); gets(a[i].tglfl.bulan);
	printf("Ganti Tahun Lahir	 : "); fflush (stdin); scanf("%d",&a[i].tglfl.tahun);
}

int binary_search(fl arr[], char cari[], int n)
{
    int t, hasil;
    int k = n - 1;
    int l = 0;
  
    while ( l <= k )
    {
        t = (l + k) / 2;
        hasil = strcmp(arr[t].nomor_induk, cari);

        if (hasil == -1)
            l = t + 1;
        else if (hasil == 1)
            k = t - 1;
        else
            return t;
    }       
    return -1;  
}

void InsertionSort(fl arr[], int n) // id
{
    int i, j;
    fl key;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; (j >= 0) && (strcmp(arr[j+1].nomor_induk, arr[j].nomor_induk)<0); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void tambah_data(){
	system("cls");
	printf("\n--- Input data siswa ---\n\n");
	input(n);
	n++;
	printf("\n\n[Keterangan] :");
	printf("\n ====================================================== ");
	printf("\n| Data berhasil ditambahkan...                         |");
	printf("\n========================================================");
	printf("\n>> Press [ANY KEY] to back to menu\n");
	getch();
	system("cls");
}

void view_data(){
	int i;
	system("cls");
	printf("\n--- data siswa terdaftar ---\n");
	if(n==0){
		printf("\n\n[Keterangan] :");
		printf("\n ====================================================== ");
		printf("\n| Masukan data terlebih dahulu...                      |");
		printf("\n========================================================");
		printf("\n>> Press [ANY KEY] to back to menu\n");
		getch();
		system("cls");
	}
	else{
		for(i=0;i<n;i++){
			view(i);					
		}
		printf("\n\n[Keterangan] :");
		printf("\n ====================================================== ");
		printf("\n| Data berhasil ditampilkan...                         |");
		printf("\n========================================================");
		printf("\n>> Press [ANY KEY] to back to menu\n");
		getch();
		system("cls");
	}
}

void cari_data(){
		int i, hasil;
				system("cls");
				printf("\n--- Cari nomor induk siswa ---\n");
				char cariid[50];
				if(n==0){
					printf("\n\n[Keterangan] :");
					printf("\n ______________________________________________________ ");
					printf("\n| Masukan data terlebih dahulu...                      |");
					printf("\n|______________________________________________________|");
					printf("\n>> Press [ANY KEY] to back to menu\n");
					getch();
					system("cls");
					cari_data();
				}
				else{
					InsertionSort(a,n);
					printf("\n\n<--------------------------------->");
					printf("\n Data yang terdaftar :");
					printf("\n<--------------------------------->\n");
					for(i=0; i<n; i++){
						view(i);								
					}
					printf("\n\n<--------------------------------->");
					printf("\nCari nomor induk siswa : ");fflush(stdin);gets(cariid);
					printf("<--------------------------------->\n\n");
					//hasil=binary_search1(a,n,cariid);
					hasil = binary_search(a,cariid,n);
					if(hasil==-1){
						printf("[Keterangan] :");
						printf("\n ================================================ ");
						printf("\n| Tidak ditemukan ID siswa %s                    |",cariid);
						printf("\n==================================================");
	   					printf("\n>> Press [ANY KEY] to back to menu\n");
	   					getch();
						system("cls");
						cari_data();
	   				}
					else{
						printf("[Hasil Pencarian] :\n");
	              		for(i=hasil; i<=hasil; i++){
							view(i);	
						}
						printf("\n[Keterangan] :");
						printf("\n ======================== ");
						printf("\n| Data Ditemukan...      |");
						printf("\n==========================");
						printf("\n>> Press [ANY KEY] to back to menu\n");
						printf("\n\n");
						getch();
						system("cls");
						menu_utama();
					}
				}
	
}

void ubah_data(){
	int i;
	system("cls");
	if(n==0){
		printf("\n\n[Keterangan] :");
		printf("\n ====================================================== ");
		printf("\n| Masukan data terlebih dahulu...                      |");
		printf("\n========================================================");
		printf("\n>> Press [ANY KEY] to back to menu\n");
		getch();
		system("cls");
	}
	else{
		printf("\n\n<--------------------------------->");
		printf("\n Data siswa sebelum dirubah");
		printf("\n<--------------------------------->\n");
		for(i=0;i<n;i++){
			view(i);
		}
		int flag = 0;
		printf("\n--- Ubah data siswa ---\n");
		printf("Masukan nomor induk siswa yang ingin diubah : ");
		char cariID[10];
		fflush(stdin); gets(cariID);
		for(i=0;i<n;i++){
			if(!strcmp(a[i].nomor_induk, cariID)){
				printf("\n\n<--------------------------------->");
				printf("\n Data siswa yang ingin dirubah");
				printf("\n<--------------------------------->\n");
				updatesiswa(i);

				printf("\n\n<--------------------------------->");
				printf("\n Hasil ubah data siswa");
				printf("\n<--------------------------------->\n");
				view(i);

				printf("\n\n[Keterangan] :");
				printf("\n ==================================================== ");
				printf("\n| Ubah data siswa berhasil...                        |");
				printf("\n=======================================================");
				printf("\n>> Press [ANY KEY] to back to menu\n");
				getch();
				system("cls");
				flag++;
				break;
			}
		}
		if(flag == 0){
			printf("[Keterangan] :");
			printf("\n ================================================ ");
			printf("\n| Tidak ditemukan Nama siswa %s                  |",cariID);
			printf("\n==================================================");
	   		printf("\n>> Press [ANY KEY] to back to menu\n");
	   		getch();
			system("cls");
		}	
	}
}

void urutkan_data(){
	int i;
				system("cls");
				printf("\n--- Pengurutan Berdasarkan Nomor Induk ---\n");
				if(n==0){
					printf("\n\n[Keterangan] :");
					printf("\n ====================================================== ");
					printf("\n| Masukan data siswa terlebih dahulu...                |");
					printf("\n========================================================");
					printf("\n>> Press [ANY KEY] to back to menu\n");
					getch();
					system("cls");
					urutkan_data();
				}
				else{
					for(i=0; i<n; i++){
					InsertionSort(a,n);									
				}
					
					printf("\n\n<--------------------------------->");
					printf("\n Data setelah diurutkan");
					printf("\n<--------------------------------->\n");
					for(i=0; i<n; i++){					
						view(i);								
					}
					getch();
					system("cls");
					menu_utama();
				
			}
}
