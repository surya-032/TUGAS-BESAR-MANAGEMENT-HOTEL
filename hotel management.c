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
	int tglCI;
	int blnCI;
	int thnCI;
	int tglCO;
	int blnCO;
	int thnCO;
	int pilih;
};
struct pesan pesanan;

int jumlah_standard=16;
int jumlah_superior=12;
int jumlah_deluxe=10;
int jumlah_suite=8;
int jumlah_presidential=4;

int add1=100000;
int add2=200000;

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
    printf("\t\t\t\t\t  WAKTU LOGIN : %s", asctime(waktu));
}

void hitung_total(){
	if(pesanan.pilih_kamar==1 && pesanan.pilih==1){
		jumlah_standard -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*standard+biaya_admin)*pesanan.jumlah_kamar+add1;
	}else if(pesanan.pilih_kamar==1 && pesanan.pilih==2){
		jumlah_standard -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*standard+biaya_admin)*pesanan.jumlah_kamar+add2;
	}else if(pesanan.pilih_kamar==1){
		jumlah_standard -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*standard+biaya_admin)*pesanan.jumlah_kamar;
		
	}else if(pesanan.pilih_kamar==2 && pesanan.pilih==1){
		jumlah_superior -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*superior+biaya_admin)*pesanan.jumlah_kamar+add1;
	}else if(pesanan.pilih_kamar==2 && pesanan.pilih==2){
		jumlah_superior -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*superior+biaya_admin)*pesanan.jumlah_kamar+add2;
	}else if(pesanan.pilih_kamar==2){
		jumlah_superior -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*superior+biaya_admin)*pesanan.jumlah_kamar;
		
	}else if(pesanan.pilih_kamar==3 && pesanan.pilih==1){
		jumlah_deluxe -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*deluxe+biaya_admin)*pesanan.jumlah_kamar+add1;
	}else if(pesanan.pilih_kamar==3 && pesanan.pilih==2){
		jumlah_deluxe -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*deluxe+biaya_admin)*pesanan.jumlah_kamar+add2;
	}else if(pesanan.pilih_kamar==3){
		jumlah_deluxe -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*deluxe+biaya_admin)*pesanan.jumlah_kamar;
		
	}else if(pesanan.pilih_kamar==4 && pesanan.pilih==1){
		jumlah_suite -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*suite+biaya_admin)*pesanan.jumlah_kamar+add1;
	}else if(pesanan.pilih_kamar==4 && pesanan.pilih==2){
		jumlah_suite -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*suite+biaya_admin)*pesanan.jumlah_kamar+add2;
	}else if(pesanan.pilih_kamar==4){
		jumlah_suite -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*suite+biaya_admin)*pesanan.jumlah_kamar+add1;
		
	}else if(pesanan.pilih_kamar==5 && pesanan.pilih==1){
		jumlah_presidential -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*presidential+biaya_admin)*pesanan.jumlah_kamar+add1;
	}else if(pesanan.pilih_kamar==5 && pesanan.pilih==2){
		jumlah_presidential -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*presidential+biaya_admin)*pesanan.jumlah_kamar+add2;
	}else if(pesanan.pilih_kamar==5){
		jumlah_presidential -= pesanan.jumlah_kamar;
		pesanan.total = (pesanan.lama_sewa*presidential+biaya_admin)*pesanan.jumlah_kamar;
	} 
}
void selamat(){
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|                                                       |\n");	
	printf("\t\t\t\t|     <-----  SELAMAT DATANG DI DIAMOND HOTEL ----->    |\n");
	printf("\t\t\t\t|                                                       |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|        Come with a dream leave with the future        |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t||                                                     ||\n");
	printf("\t\t\t\t||-----------------------------------------------------||\n");
	printf("\t\t\t\t||                           *                         ||\n");
	printf("\t\t\t\t||                          ***                        ||\n");
	printf("\t\t\t\t||                         *****                       ||\n");
	printf("\t\t\t\t||                        *******                      ||\n");
	printf("\t\t\t\t||                       *********                     ||\n");
	printf("\t\t\t\t||                      ***********                    ||\n");
	printf("\t\t\t\t||                     *************                   ||\n");
	printf("\t\t\t\t||                     *************                   ||\n");
	printf("\t\t\t\t||                      ***********                    ||\n");
	printf("\t\t\t\t||                       *********                     ||\n");
	printf("\t\t\t\t||                        *******                      ||\n");
	printf("\t\t\t\t||                         *****                       ||\n");
	printf("\t\t\t\t||                          ***                        ||\n");
	printf("\t\t\t\t||                           *                         ||\n");
	printf("\t\t\t\t||                                                     ||\n");
	printf("\t\t\t\t+-------------------------------------------------------+\n");
	printf("\t\t\t\t| Silahkan Tekan Tombol Apapun Untuk Masuk Ke Program!! |\n");
	printf("\t\t\t\t+=======================================================+\n");
}

void keluar(){
	printf("\t\t\t\t+--------------------------------------------------------------+\n");
	printf("\t\t\t\t||       TERIMA KASIH TELAH BERKUNJUNG DI DIAMOND HOTEL       ||\n");
	printf("\t\t\t\t+--------------------------------------------------------------+\n");
	printf("\t\t\t\t+--------------------------------------------------------------+\n");
	printf("\t\t\t\t||Program Creator : Komang Bayu Lobi Hartawan_2205551032      ||\n");
	printf("\t\t\t\t||                  I Putu Gede Surya Pratama_2205551025      ||\n");
	printf("\t\t\t\t+--------------------------------------------------------------+\n");
	system("pause");
	system("cls");
	main();
}


void billing(){
	system("cls");
	printf("\t+=======================================================+\n");
	printf("\t|                  DIAMOND HOTEL's BILING               |\n");
	printf("\t=========================================================\n");
	printf("\tNIK Pemesan	: %s\n", pesanan.id_pemesanan);
	printf("\t---------------------------------------------------------\n");
	printf("\tNama		: %s\n", pesanan.nama);
	printf("\t---------------------------------------------------------\n");
	printf("\tNo_Hp		: %s\n", pesanan.no_hp);
	printf("\t---------------------------------------------------------\n");
	printf("\tUmur		: %d\n", pesanan.umur);
	printf("\t---------------------------------------------------------\n");
	printf("\tjenis Kelamin	: %s\n", pesanan.jenis_kelamin);
	printf("\t---------------------------------------------------------\n");
	printf("\tJumlah Kamar	: %d\n", pesanan.jumlah_kamar);
	printf("\t---------------------------------------------------------\n");
	printf("\tLama Inap	: %d Hari\n", pesanan.lama_sewa);
	printf("\t=========================================================\n");
	printf("\tTanggal Check In	: %d/%d/%d\n", pesanan.tglCI, pesanan.blnCI, pesanan.thnCI);
	printf("\tTanggal Check Out	: %d/%d/%d\n", pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
	printf("\tTotal Harga		: Rp. %d\n\n", pesanan.total);
	printf("\t+=======================================================+\n");
	printf("\t|               TERIMA KASIH TELAH MEMESAN              |\n");
	printf("\t|                    HOTEL DIAMOND                      |\n");
	printf("\t+=======================================================+\n");
	printf("\t     +--------------------------------------------+\n");
	printf("\t     |     Tekan Tombol Apapun Untuk Mencetak     |\n");
	printf("\t     +--------------------------------------------+\n\n\n");
	
}
void tambah_kamar(){
	char pilihan;
	system("cls");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|           Penambahan Fasilitas Ekstra Bed             |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    NO  |    Jenis Bed       |        Harga Bed        |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    1   |    Single Bed      |      -Rp 100.000        |\n");
	printf("\t\t\t\t|    2   |    Double Bed      |      -Rp 200.000        |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Penambahan Fasilitas Ekstra Bed Yang Di Inginkan [1][2][3][4] ==> ");
	printf ("\tApakah anda ingin menambah Ekstra Bed[y][t] ?");
	fflush(stdin);
	scanf (" %c", &pilihan);
	if(pilihan=='y'){
		printf("Masukan Nomor Bed Yang Ingin Di Request [max 1]");
		scanf("%d", &pesanan.pilih);
		if(pesanan.pilih==1){
			printf("Anda Memilih Single Bed dengan Harga Rp 100.000");
		}else if(pesanan.pilih==2){
			printf("Anda Memilih Double Bed dengan Harga Rp 200.000");
		}else{
			printf("angka tidak valid");
			tambah_kamar();
		}
	}else if(pilihan=='t'){
		printf("\n");
	}
	
}

void pesan_kamar(){
	system("cls");
	FILE *pemesanan;
	pemesanan=fopen("file_pemesanan.txt", "a+");
	printf("\t+=======================================================+\n");
	printf("\t| KODE KAMAR |       JENIS KAMAR        |  HARGA/MALAM  |\n");
	printf("\t=========================================================\n");
	printf("\t|     1      |       Standard Room      |  Rp 450.000   |\n");
	printf("\t=========================================================\n");
	printf("\t|     2      |       Superior Room      |  Rp 800.000   |\n");
	printf("\t=========================================================\n");
	printf("\t|     3      |       Deluxe Room        |  Rp 1.000.000 |\n");
	printf("\t=========================================================\n");
	printf("\t|     4      |     Presidential Room    |  Rp 2.000.000 |\n");
	printf("\t=========================================================\n\n");

	printf("\t+=======================================================+\n");
	printf("\t|                  PEMESANAN TIPE KAMAR                 |\n");
	printf("\t=========================================================\n");
	printf("\tMasukan Kode Kamar Yang Ingin Dipesan ->>");
	scanf("%d", &pesanan.pilih_kamar);
	printf("\t=========================================================\n\n");
	printf("\n\t*********************************************************\n");
	if(pesanan.pilih_kamar>=1 && pesanan.pilih_kamar<=5){
		printf("\tNIK Pemesanan	:"); 
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
		printf("\tMasukan Jenis Kelamin Anda:"); 
		scanf("%s", &pesanan.jenis_kelamin);
		printf("\t*********************************************************\n");
		printf("\tJumlah Kamar :");
		scanf("%d", &pesanan.jumlah_kamar);
		printf("\t*********************************************************\n");
		printf("\tLama Sewa :");
		scanf("%d", &pesanan.lama_sewa);
		printf("\t*********************************************************\n");
		printf("\tMasukan Tanggal Check in (dd/mm/yy)	:");
		scanf("%d/%d/%d", &pesanan.tglCI, &pesanan.blnCI, &pesanan.thnCO);
		printf("\t==========================================================\n\n");
		printf("\tMasukan Tanggal Check Out (dd/mm/yy)	:");
		scanf("%d/%d/%d", &pesanan.tglCO, &pesanan.blnCO, &pesanan.thnCO);
		printf("\t==========================================================\n\n");
		printf("\t\t\t\t==================================\n");
		tambah_kamar();
		hitung_total();
		printf("\t\t\t\tTotal Harga	: %d\n", pesanan.total);
		printf("\t\t\t\t==================================\n");
		system("pause");
		billing();
	}else{
		printf("\tMasukan Kode Tipe Kamar Yang Sesuai!!!\n");
		system("pause");
		pesan_kamar();
	}
	fprintf(pemesanan, "=============================================================================================================================================\n");
	fprintf(pemesanan, "| ID |        NAMA       |    No_HP        |     Umur    |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
	fprintf(pemesanan,"   %s           %s              %s                 %d           %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.umur, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
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
	printf("\t\t\t\t\t\tMulai Pesan Kamar\n");
	printf("\t\t\t\t\t\t\t\t\t\t|-----------------------------|\n");
	printf("\t\t\t\t\t\t\t\t\t\t|     Tekan Tombol Apapun     |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n\n");
	system("pause");
	pesan_kamar();
}

void data_pemesanan(){
	system("cls");
	char buffer[300];
	FILE *pesan;
	pesan=fopen("file_pemesanan.txt", "r");
	while(fgets(buffer, sizeof(buffer), pesan)){
		printf("%s", buffer);
	}
	system("pause");
	fclose(pesan);
}

void menu_admin(){
	system("cls");
	int menu;
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|                      MENU ADMIN                       |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    NO  |    PILIHAN MENU                              |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    1   |    ABOUT HOTEL                               |\n");
	printf("\t\t\t\t|    2   |    PESAN KAMAR                               |\n");
	printf("\t\t\t\t|    3   |    DATA PESANAN                              |\n");
	printf("\t\t\t\t|    4   |    KELUAR PROGRAM                            |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Nomor Menu Yang Di Inginkan [1][2][3] ==> ");
	scanf("%d", &menu);
	fflush(stdin);
	switch(menu){
		case 1:
			system("cls");
			FILE *about;
			about=fopen("about_hotel.txt", "r");
			char buffer[1000];
			while(fgets(buffer, sizeof(buffer), about)){
				printf("%s\n", buffer);
			}
			fclose(about);
			system("pause");
			menu_admin();
			break;
		case 2:
			system("cls");
			pilih_kamar();
			break;
		case 3:
			data_pemesanan();
		case 4:
			system("cls");
			keluar();
		default :
			system("cls");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			printf("\t\t\t\t|           Menu yang anda pilih tidak valid              |\n");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			system("pause");
			menu_admin();
			break;
			
			
			
	}
}
void menu_customer(){
	system("cls");
	int menu;
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|                      MENU CUSTOMER                    |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    NO  |    PILIHAN MENU                              |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    1   |    ABOUT HOTEL                               |\n");
	printf("\t\t\t\t|    2   |    PESAN KAMAR                               |\n");
	printf("\t\t\t\t|    3   |    KELUAR PROGRAM                            |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tMasukkan Nomor Menu Yang Di Inginkan [1][2][3] ==> ");
	fflush(stdin);
	scanf("%d", &menu);
	switch(menu){
		case 1:
			system("cls");
			FILE *about;
			about=fopen("about_hotel.txt", "r");
			char buffer[1000];
			while(fgets(buffer, sizeof(buffer), about)){
				printf("%s\n", buffer);
			}
			fclose(about);
			system("pause");
			menu_admin();
			break;
		case 2:
			system("cls");
			pilih_kamar();
			break;
		case 3:
			system("cls");
			keluar();
		default :
			system("cls");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			printf("\t\t\t\t|           Menu yang anda pilih tidak valid              |\n");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			system("pause");
			menu_customer();
			break;
	}
}

void login_user(){
	char username[20];
	char password[20];
	int pilihan;
	FILE *reg;
	reg=fopen(akun, "r");
	waktu();
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|                      MENU LOGIN                       |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|         Masukan Username dan Password Anda!           |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\tUsername :");
	scanf("%s", username);
	printf("\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\tPassword :");
	scanf("%s", password);
	printf("\t\t\t\t+=======================================================+\n");
	while(fread(&user, 1, sizeof(user), reg)){
		if(strcmp(username, user.username)==0 && strcmp(password, user.password)==0){
			printf("\t\t\t\t\t\t    +--------------+\n");
			printf("\t\t\t\t\t\t    |Login Berhasil|\n");
			printf("\t\t\t\t\t\t    +--------------+\n");
			system("pause");
			menu_customer();
		}else{
			printf("\t\t\t\t\t      +----------------------------+\n");
			printf("\t\t\t\t\t      |Username atau Password Salah|\n");
			printf("\t\t\t\t\t      +----------------------------+\n");
			system("pause");
			system("cls");
			login_user();
		}
	}
	fclose(reg);
	system("pause");
}


void login_admin(){
	char username_admin[15];
	char password_admin[15];
	int pilihan;
	printf("\t\t\t\t+=======================================================+\n");
	waktu();
	printf("\t\t\t\t+=======================================================+\n\n\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|              MASUKAN USERNAME & PASSWORD              |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\tUSERNAME : ");
	scanf("%s", &username_admin);
	printf("\t\t\t\t---------------------------------------------------------\n");
	printf("\t\t\t\tPASSWORD : ");
	scanf("%s", &password_admin);
	printf("\t\t\t\t+=======================================================+\n\n");
	if(strcmp(username_admin, "admin")==0 && strcmp(password_admin, "admin")==0){
			printf("\t\t\t\t\t\t   + -------------- +\n");
			printf("\t\t\t\t\t\t   | LOGIN BERHASIL |\n");
			printf("\t\t\t\t\t\t   + -------------- +\n");
		system("pause");
		menu_admin();
	}else{
		printf("\t\t\t\t\t     + --------------------------- +\n");
		printf("\t\t\t\t\t     | USERNAME DAN PASSWORD SALAH |\n");
		printf("\t\t\t\t\t     + --------------------------- +\n\n");
		system("cls");
		printf("\t\t\t\t\t  + -------------------------------- +\n");
		printf("\t\t\t\t\t  | Masukan Ulang Username & Password|\n");
		printf("\t\t\t\t\t  + -------------------------------- +\n");
		system("pause");
		system("cls");
		login_admin();
	}

}

void form_customer(){
	system("cls");
	int pilihan;
	printf("\t\t\t\t+=========================================================+\n");
	printf("\t\t\t\t|                      FORM CUSTOMER                      |\n");
	printf("\t\t\t\t+=========================================================+\n");
	printf("\t\t\t\t|                    INFORMASI PENTING                    |\n");
	printf("\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t|  1.Pilih Login jika anda sudah punya akun               |\n");
	printf("\t\t\t\t|  2.*Utamakan Pilih Register jika anda belum punya akun* |\n");
	printf("\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t+=========================================================+\n");
	printf("\t\t\t\t||   1   |    REGISTER                                   ||\n");
	printf("\t\t\t\t||   2   |    LOGIN                                      ||\n");
	printf("\t\t\t\t||   3   |    KELUAR PROGRAM                             ||\n");
	printf("\t\t\t\t+---------------------------------------------------------+\n");
	printf("\t\t\t\t Masukkan nomor menu yang anda inginkan [1][2][3] ==> ");
	fflush(stdin);
	scanf("%d", &pilihan);
	system("cls");
	if(pilihan==1){
			FILE *reg;
			reg=fopen(akun, "w");
			if(akun==NULL){
				printf("File Not Found!\n");
			}else{
				printf("\t\t\t\t+=========================================================+\n");
				printf("\t\t\t\t|         SILAHKAN LENGKAPI DATA KETENTUAN DIBAWAH        |\n");
				printf("\t\t\t\t+=========================================================+\n");
				printf("\t\t\t\tMasukan Nama  : ");
				scanf(" %s", user.nama);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				printf("\t\t\t\tMasukan No HP :");
				scanf("%s", user.no_hp);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				printf("\t\t\t\tMasukan Email Anda :");
				scanf("%s", user.email);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				printf("\t\t\t\tMasukan Username MAX (8 Karakter) :");
				scanf("%s", user.username);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				printf("\t\t\t\tMasukan Password MAX (8 Karakter) :");
				scanf("%s", user.password);
				fwrite(&user, 1, sizeof(user), reg);
				fclose(reg);
				fflush(stdin);
				printf("\t\t\t\t=========================================================\n");
				printf("\t\t\t\t\t\t   + -------------------- +\n");
				printf("\t\t\t\t\t\t   | AKUN BERHASIL DIBUAT |\n");
				printf("\t\t\t\t\t\t   + -------------------- +\n");
				printf("\t\t\t\t+---------------------------------------------------------+\n");
				printf("\t\t\t\t|         SILAHKAN SEKARANG PILIH MENU LOGIN              |\n");
				printf("\t\t\t\t+---------------------------------------------------------+\n");
			}
			system("pause");
			form_customer();
	}else if(pilihan==2){
		login_user();
	}else if(pilihan==3){
		keluar();
	}else{
		system("cls");
		printf("\t\t\t\t+---------------------------------------------------------+\n");
		printf("\t\t\t\t|           Menu yang anda pilih tidak valid              |\n");
		printf("\t\t\t\t+---------------------------------------------------------+\n");
		system("pause");
		form_customer();
	}
}


void menu_masuk(){
	int pilihan;
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|             MENU PROGRAM DIAMOND DREAM HOTEL          |\n");
	printf("\t\t\t\t========================================================\n");
	printf("\t\t\t\t|    NO  |                PILIHAN MENU                  |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    1   |    SEBAGAI ADMIN                             |\n");
	printf("\t\t\t\t|    2   |    SEBAGAI CUSTOMER                          |\n");
	printf("\t\t\t\t|    3   |    KELUAR PROGRAM                            |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\tMasukkan nomor menu yang anda inginkan [1][2][3] ==>| ");
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
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			printf("\t\t\t\t|           Menu yang anda pilih tidak valid              |\n");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			system("pause");
			fflush(stdin);
			system("cls");
			menu_masuk();
			
	}
}

int main(){
	system ("color 1");;
    selamat();
	system("pause");
	system("cls");
	menu_masuk();
}
