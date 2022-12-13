#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct login{
	char username[50];
	char password[10];
	char no_hp[15];
	char email[40];
	char nama[50];
};
struct login user;

struct pesan{
	char id_pemesanan[10];
	char nama[50];
	char no_hp[15];
	int umur;
	char jenis_kelamin[10];
	int kamar;
	int jumlah_kamar;
	int lama_sewa;
	int total;
	int pilih_kamar;
};
struct pesan pesanan;

int jumlah_standard=16;
int jumlah_superior=12;
int jumlah_deluxe=10;
int jumlah_suite=8;
int jumlah_presidential=4;

int standard=450000;
int superior=800000;
int deluxe=1000000;
int suite=1500000;
int presidential=2000000;

char akun[]="akun.txt";

int biaya_admin=50000;

void waktu(){
	time_t pukul;
	struct tm*waktu;
	time(&pukul);
	waktu=localtime(&pukul);
    printf("\tTanggal: %s", asctime(waktu));
}

void hitung_total(){
	if(pesanan.pilih_kamar==1){
		jumlah_standard -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*standard+biaya_admin)*pesanan.jumlah_kamar;
	}else if(pesanan.pilih_kamar==2){
		jumlah_superior -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*superior+biaya_admin)*pesanan.jumlah_kamar;
	}else if(pesanan.pilih_kamar==3){
		jumlah_deluxe -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*deluxe+biaya_admin)*pesanan.jumlah_kamar;
	}else if(pesanan.pilih_kamar==4){
		jumlah_suite -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*suite+biaya_admin)*pesanan.jumlah_kamar;
	}else if(pesanan.pilih_kamar==5){
		jumlah_presidential -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*presidential+biaya_admin)*pesanan.jumlah_kamar;
	} 
}
void pesan_kamar(){
	system("cls");
	FILE *pemesanan;
	pemesanan=fopen("file_pemesanan.txt", "a+");
	printf("\t+=======================================================+\n");
	printf("\t|                  PEMESANAN TIPE KAMAR                 |\n");
	printf("\t=========================================================\n");
	printf("\tMasukan Kode Kamar Yang Ingin Dipesan ->>");
	scanf("%d", &pesanan.pilih_kamar);
	printf("\n\t*********************************************************\n");
	if(pesanan.pilih_kamar>=1 && pesanan.pilih_kamar<=5){
		printf("\tId Pemesanan "); 
		scanf("%s", &pesanan.id_pemesanan);
		printf("\t*********************************************************\n");
		printf("\tMasukan Nama Anda :"); 
		scanf("%s", &pesanan.nama);
		printf("\t*********************************************************\n");
		printf("\tMasukan No_Hp :"); 
		scanf("%s", &pesanan.no_hp);
		printf("\t*********************************************************\n");
		printf("\tMasukan Umur Anda :"); 
		scanf("%d", &pesanan.umur);
		printf("\t*********************************************************\n");
		printf("\tMasukan Jenis Kelamin Anda :"); 
		scanf("%s", &pesanan.jenis_kelamin);
		printf("\t*********************************************************\n");
		printf("\tJumlah Kamar :");
		scanf("%d", &pesanan.jumlah_kamar);
		printf("\t*********************************************************\n");
		printf("\tLama Sewa :");
		scanf("%d", &pesanan.lama_sewa);
		printf("\t==========================================================\n");
		hitung_total();
		printf("Total Harga : %d\n", pesanan.total);
	}else{
		printf("\tMasukan Kode Tipe Kamar Yang Sesuai!!!\n");
		system("pause");
		pesan_kamar();
	}
	fprintf(pemesanan, "================================================================================================================\n");
	fprintf(pemesanan, "| ID |        NAMA       |    No_HP        |     Umur    |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |\n");
	fprintf(pemesanan,"   %s           %s              %s                 %d           %s             %d            %d          %d      \n", pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.umur, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total);
	fclose(pemesanan);
}

void pilih_kamar(){
	system("cls");
	printf("\n");
	printf("\t=======================================================================================================\n");
	printf("\t|========================================Pilih Tipe Kamar Anda========================================|\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t| Kode Kamar |  Jenis Kamar   |               Fasilitas             |   Harga/Malam   |  Jumlah Kamar |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|      1     | Standard Room  | Kamar berada di lantai 1 & 2. Dengan|   Rp 450.000    |      %d       |\n", jumlah_standard);
	printf("\t|            | 6x4            | fasilitas seperti Single Bed, AC, TV|                 |               |\n");
	printf("\t|            |                | Perlengkapan Mandi, WIFI dan Bathtub|                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|      2     | Superior Room  | Kamar berada di lantai 3 & 4. Dengan|   Rp 800.000    |      %d       |\n", jumlah_superior);
	printf("\t|            | 8x4            | fasilitas seperti Twin Bed, AC, TV  |                 |               |\n");
	printf("\t|            |                | Perlengkapan Mandi, WIFI dan Bathtub|                 |               |\n");
	printf("\t|            |                | Kamar Mandi with shower, mini bar,  |                 |               |\n");
	printf("\t|            |                | balcoon                             |                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|      3     | Deluxe Room    | Kamar berada di lantai 5 & 6. Dengan|   Rp 1.000.000  |      %d       |\n", jumlah_deluxe);
	printf("\t|            | 9x4            | fasilitas seperti TwinBed/Double Bed|                 |               |\n");
	printf("\t|            |                | Perlengkapan Mandi, WIFI dan Bathtub|                 |               |\n");
	printf("\t|            |                | Kamar Mandi with shower, mini bar,  |                 |               |\n");
	printf("\t|            |                | balcoon, Ac, Kulkas, TV, Kopi Maker |                 |               |\n");
	printf("\t|            |                | Meja rias.                          |                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|      4     | Suite Room     | Kamar berada di lantai 7 & 8. Dengan|  Rp 1.500.000   |       %d      |\n", jumlah_suite);
	printf("\t|            | 8x4            | fasilitas seperti TwinBed/Double Bed|                 |               |\n");
	printf("\t|            |                | Perlengkapan Mandi, WIFI dan Bathtub|                 |               |\n");
	printf("\t|            |                | Kamar Mandi with shower, mini bar,  |                 |               |\n");
	printf("\t|            |                | balcoon, Ac, Kulkas, TV, Kopi Maker |                 |               |\n");
	printf("\t|            |                | Meja rias.                          |                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|     5      | Presidential   | Kamar berada di lantai 9 & 10.Dengan|   Rp 2.000.000  |       %d      |\n", jumlah_presidential);
	printf("\t|            | Room           | fasilitas seperti TwinBed/Double Bed|                 |               |\n");
	printf("\t|            | 10x8           | Perlengkapan Mandi, Bathtub, dapur  |                 |               |\n");
	printf("\t|            |                | Kamar Mandi with shower, mini bar,  |                 |               |\n");
	printf("\t|            |                | balcoon, Ac, Kulkas, TV, Kopi Maker |                 |               |\n");
	printf("\t|            |                | Meja rias, sofa, ruang tamu terpisah|                 |               |\n");
	printf("\t|            |                | dinning area, meja kerja.           |                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("Mulai Pesan Kamar\n");
	system("pause");
	pesan_kamar();
}

void menu_customer(){
	system("cls");
	int menu;
	printf("\t+=======================================================+\n");
	printf("\t|                      MENU CUSTOMER                    |\n");
	printf("\t=========================================================\n");
	printf("\t|    NO  |    PILIHAN MENU                              |\n");
	printf("\t=========================================================\n");
	printf("\t|    1   |    ABOUT HOTEL                               |\n");
	printf("\t|    2   |    PESAN KAMAR                               |\n");
	printf("\t|    3   |    KELUAR PROGRAM                            |\n");
	printf("\t=========================================================\n");
	printf("\tMasukkan Nomor Menu Yang Di Inginkan [1][2][3] ==> ");
	scanf("%d", &menu);
	switch(menu){
		case 1:
			printf("proses");
			break;
		case 2:
			system("cls");
			pilih_kamar();
			break;
		case 3:
			printf("Terimakasih");
	}
}

void login_user(){
	char username[20];
	char password[20];
	int pilihan;
	FILE *reg;
	reg=fopen(akun, "r");
	waktu();
	printf("\t+=======================================================+\n");
	printf("\t|                      MENU LOGIN                       |\n");
	printf("\t+=======================================================+\n");
	printf("\t|         Masukan Username dan Password Anda!           |\n");
	printf("\t+=======================================================+\n");
	printf("\tUsername :");
	scanf("%s", username);
	printf("\tPassword :");
	scanf("%s", password);
	while(fread(&user, 1, sizeof(user), reg)){
		if(strcmp(username, user.username)==0 && strcmp(password, user.password)==0){
			printf("\t\t\t    +--------------+\n");
			printf("\t\t\t    |Login Berhasil|\n");
			printf("\t\t\t    +--------------+\n");
			system("pause");
			menu_customer();
		}else{
			printf("\t\t\t +----------------------------+\n");
			printf("\t\t\t |Username atau Password Salah|\n");
			printf("\t\t\t +----------------------------+\n");
			system("pause");
			system("cls");
			login_user();
		}
	}
	fclose(reg);
	system("pause");
}

void about_hotel(){
	system("cls");
	FILE *about;
	about=fopen("about_hotel.txt", "r");
	char buffer[300];
	while(fgets(buffer, sizeof(buffer), about)){
		printf("%s\n", buffer);
	}
	fclose(about);
	system("pause");
}

void menu_admin(){
	system("cls");
	int menu;
	printf("\t+=======================================================+\n");
	printf("\t|                      MENU CUSTOMER                    |\n");
	printf("\t=========================================================\n");
	printf("\t|    NO  |    PILIHAN MENU                              |\n");
	printf("\t=========================================================\n");
	printf("\t|    1   |    ABOUT HOTEL                               |\n");
	printf("\t|    2   |    PESAN KAMAR                               |\n");
	printf("\t|    2   |    DATA PESANAN                              |\n");
	printf("\t|    3   |    KELUAR PROGRAM                            |\n");
	printf("\t=========================================================\n");
	printf("\tMasukkan Nomor Menu Yang Di Inginkan [1][2][3] ==> ");
	scanf("%d", &menu);
	switch(menu){
		case 1:
			about_hotel();
			break;
		case 2:
			system("cls");
			pilih_kamar();
			break;
		case 3:
			printf("Terimakasih");
		case 4:
			printf("s");
	}
}

void login_admin(){
	char username_admin[15];
	char password_admin[15];
	int pilihan;
	waktu();
	printf("Masukan Username dan Password Anda\n");
	printf("Username : ");
	scanf("%s", &username_admin);
	printf("Password : ");
	scanf("%s", &password_admin);
	if(strcmp(username_admin, "admin")==0 && strcmp(password_admin, "admin")==0){
		printf("Login Berhasil\n");
		menu_admin();
	}else{
		printf("Masukan Ulang\n");
	}
	system("pause");
}


void form_customer(){
	system("cls");
	int pilihan;
	printf("\t+=========================================================+\n");
	printf("\t|                      FORM CUSTOMER                      |\n");
	printf("\t+=========================================================+\n");
	printf("\t|                    INFORMASI PENTING                    |\n");
	printf("\t|                                                         |\n");
	printf("\t|  1.Pilih Login jika anda sudah punya akun               |\n");
	printf("\t|  2.*Utamakan Pilih Register jika anda belum punya akun* |\n");
	printf("\t|                                                         |\n");
	printf("\t+=========================================================+\n");
	printf("\t||   1   |    REGISTER                                   ||\n");
	printf("\t||   2   |    LOGIN                                      ||\n");
	printf("\t+---------------------------------------------------------+\n");
	printf("\t Masukkan nomor menu yang anda inginkan [1][2] ==> ");
	scanf("%d", &pilihan);
	system("cls");
	if(pilihan==1){
			FILE *reg;
			reg=fopen(akun, "w");
			if(akun==NULL){
				printf("File Not Found!\n");
			}else{
				printf("Silahkan Lengkapi Data Dibawah\n");
				printf("Masukan Nama  :");
				scanf("%s", user.nama);
				printf("Masukan No HP :");
				scanf("%s", user.no_hp);
				printf("Masukan Email Anda :");
				scanf("%s", user.email);
				printf("Masukan Username MAX (8 Karakter) :");
				scanf("%s", user.username);
				printf("Masukan Password MAX (8 Karakter) :");
				scanf("%s", user.password);
				fwrite(&user, 1, sizeof(user), reg);
				fclose(reg);
				printf("\n\nSELAMAT AKUN TELAH BERHASIL DI BUAT\n");
			}
			system("pause");
			form_customer();
	}else if(pilihan==2){
		login_user();
	}else{
		printf("Tidak Valid\n");
		system("pause");
		form_customer();
	}
}

void selamat(){
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|                                                       |\n");	
	printf("\t\t\t\t|     <--  SELAMAT DATANG DI DIAMOND DREAM HOTEL -->    |\n");
	printf("\t\t\t\t|                                                       |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|        Come with a dream leave with the future        |\n");
	printf("\t\t\t\t+=======================================================+\n\n");
	printf("Silahkan Tekan Tombol Apapun Untuk Masuk Ke Program!\n\n");
}

void keluar(){
	printf("\t+--------------------------------------------------------------+\n");
	printf("\t||    TERIMA KASIH TELAH BERKUNJUNG DI DIAMOND DREAM HOTEL    ||\n");
	printf("\t+--------------------------------------------------------------+\n");
}

void menu_masuk(){
	int pilihan;
	printf("\t+=======================================================+\n");
	printf("\t|             MENU PROGRAM DIAMOND DREAM HOTEL          |\n");
	printf("\t=========================================================\n");
	printf("\t|    NO  |                PILIHAN MENU                  |\n");
	printf("\t=========================================================\n");
	printf("\t|    1   |    SEBAGAI ADMIN                             |\n");
	printf("\t|    2   |    SEBAGAI CUSTOMER                          |\n");
	printf("\t|    3   |    KELUAR PROGRAM                            |\n");
	printf("\t+=======================================================+\n");
	printf("\tMasukkan nomor menu yang anda inginkan [1][2][3] ==>| ");
	scanf("%d", &pilihan);
	system("cls");
	switch (pilihan){
		case 1:
			login_admin();
			break;
		case 2:
			form_customer();
			break;
		case 3:
			keluar();
			break;
		default:
			printf("Menu yang anda pilih tidak valid");
	}
}

int main(){
	system ("color 1");;
	selamat();
	system("pause");
	system("cls");
	menu_masuk();
}

