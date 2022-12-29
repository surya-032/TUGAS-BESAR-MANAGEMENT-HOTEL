//CREATOR PROGRAM MANAGEMENT PEMESANAN HOTEL
//Nama	: Komang Bayu Lobi Hartawan_2205551025
//Nama	: I Putu Gede Surya Pratama_2205551032
//Program Studi : Teknologi Informasi

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
	int id_pemesanan;
	char nama[50];
	int no_hp;
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
	int nokamar;
	char room[20];
};
struct pesan pesanan;

int jumlah_standard=9;
int jumlah_superior=8;
int jumlah_deluxe=7;
int jumlah_suite=6;
int jumlah_presidential=4;

int add1=100000;
int add2=200000;
int hari1;
int standard=450000;
int superior=800000;
int deluxe=1000000;
int suite=1500000;
int presidential=2000000;

char akun[]="akun.txt";

int biaya_admin=50000;
void menu_masuk();
void form_customer();
void rooms();
void menu_admin();
void waktu(){
	time_t pukul;
	struct tm*waktu;
	time(&pukul);
	waktu=localtime(&pukul);
    printf("\t\t\t\t\t  Tanggal : %s", asctime(waktu));
}

void valid(int *var){
	char buffer[1000];
	fgets(buffer, sizeof(buffer), stdin);
	while(sscanf(buffer, "%d",var)!=1){
		printf("\t\t\t\tInput hanya berupa angka\n");
		printf("\t\t\t\tMasukan Lagi : ");
		fgets(buffer, sizeof(buffer), stdin);
	}
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
	printf("\t\t\t\t||           *              *              *           ||\n");
	printf("\t\t\t\t||          ***            ***            ***          ||\n");
	printf("\t\t\t\t||         *****          *****          *****         ||\n");
	printf("\t\t\t\t||        *******        *******        *******        ||\n");
	printf("\t\t\t\t||       *********      *********      *********       ||\n");
	printf("\t\t\t\t||      ***********    ***********    ***********      ||\n");
	printf("\t\t\t\t||     *************  *************  *************     ||\n");
	printf("\t\t\t\t||     *************  *************  *************     ||\n");
	printf("\t\t\t\t||      ***********    ***********    ***********      ||\n");
	printf("\t\t\t\t||       *********      *********      *********       ||\n");
	printf("\t\t\t\t||        *******        *******        *******        ||\n");
	printf("\t\t\t\t||         *****          *****          *****         ||\n");
	printf("\t\t\t\t||          ***            ***            ***          ||\n");
	printf("\t\t\t\t||           *              *              *           ||\n");
	printf("\t\t\t\t||                                                     ||\n");
	printf("\t\t\t\t+-------------------------------------------------------+\n");
	printf("\t\t\t\t| Silahkan Tekan Tombol Apapun Untuk Masuk Ke Program!! |\n");
	printf("\t\t\t\t+=======================================================+\n");
}

void keluar(){
	printf("\t\t\t\t+==============================================================+\n");
	printf("\t\t\t\t||       TERIMA KASIH TELAH BERKUNJUNG DI DIAMOND HOTEL       ||\n");
	printf("\t\t\t\t+==============================================================+\n");
	waktu();
	printf("\t\t\t\t+==============================================================+\n");
	printf("\t\t\t\t||                       PROGRAM CREATOR :                    ||\n");
	printf("\t\t\t\t||                                                            ||\n");
	printf("\t\t\t\t|| Komang Bayu Lobi Hartawan_2205551032                       ||\n");
	printf("\t\t\t\t|| I Putu Gede Surya Pratama_2205551025                       ||\n");
	printf("\t\t\t\t||                                                            ||\n");
	printf("\t\t\t\t||                      Teknologi Informasi                   ||\n");
	printf("\t\t\t\t||                        Fakultas Teknik                     ||\n");
	printf("\t\t\t\t||                      Universitas Udayana                   ||\n");
	printf("\t\t\t\t+==============================================================+\n");
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
		fflush(stdin);
		printf("Masukan Nomor Bed Yang Ingin Di Request [max 1]");
		valid(&pesanan.pilih);
		fflush(stdin);
		if(pesanan.pilih==1){
			printf("Anda Memilih Single Bed dengan Harga Rp 100.000");
		}else if(pesanan.pilih==2){
			fflush(stdin);
			printf("Anda Memilih Double Bed dengan Harga Rp 200.000");
		}else{
			printf("angka tidak valid");
			tambah_kamar();
		}
	}else if(pilihan=='t'){
		printf("\n");
	}else if(pilihan!='y' && pilihan != 't'){
		printf("Masukan Ulang\n");
		system("pause");
		tambah_kamar();
	}
	
}

void hari (){
	switch (hari1){
		case 1 : printf ("\t\t\tSENIN"); break ;
		case 2 : printf ("\t\t\tSELASA"); break ;
		case 3 : printf ("\t\t\tRABU"); break ;
		case 4 : printf ("\t\t\tKAMIS"); break ;
		case 5 : printf ("\t\t\tJUMAT"); break ;
		case 6 : printf ("\t\t\tSABTU"); break ;
		case 7 : printf ("\t\t\tMINGGU"); break ;
	}
}

int BknFeb (int thn, int bln){
	thn = pesanan.thnCI;
	bln = pesanan.blnCI;
	
	if ((pesanan.blnCI==1) || (pesanan.blnCI==3) || (pesanan.blnCI==5) || (pesanan.blnCI==7) || (pesanan.blnCI==8) || (pesanan.blnCI==10) || (pesanan.blnCI==12)){
		return 31 ;
	}
	else { 
		return 30 ;
	}
}

int Februari (int thn){
	thn = pesanan.thnCI;
	if ((pesanan.thnCI % 100 != 0) && (pesanan.thnCI % 4 == 0)||(pesanan.thnCI % 400 == 0)){ 
		return 29 ; 
	}
	else {
		return 28 ;
	}		
}


void kalenderuntukCO (){
	
	pesanan.tglCO;
	pesanan.blnCO;
	pesanan.thnCO;
	//menggunakan do while 
	do {
		if (pesanan.lama_sewa <= 31) 
		{
			if (pesanan.blnCI == 2) 
				pesanan.tglCO = Februari (pesanan.thnCI);
			else 
				pesanan.tglCO = BknFeb (pesanan.thnCI,pesanan.blnCI);
				
			if (pesanan.tglCI + pesanan.lama_sewa > pesanan.tglCO) 
			{
				pesanan.blnCO = pesanan.blnCI + 1 ;
				if (pesanan.blnCO>12){
					pesanan.thnCO=pesanan.thnCI+1;
					pesanan.blnCO=1;
				}
				else
				pesanan.thnCO = pesanan.thnCI ;
				pesanan.tglCO = pesanan.tglCI + pesanan.lama_sewa - pesanan.tglCO ;

			}
			else 
			{
				pesanan.tglCO= pesanan.tglCI+pesanan.lama_sewa;
				pesanan.blnCO=pesanan.blnCI;
				pesanan.thnCO=pesanan.thnCI;
			}
		
		}
		else 
		{
			if (pesanan.blnCI == 2) 
				pesanan.tglCO = Februari (pesanan.blnCI);
			else 
				pesanan.tglCO = BknFeb (pesanan.thnCI,pesanan.blnCI);
				pesanan.lama_sewa = pesanan.lama_sewa - pesanan.tglCO;
			if (pesanan.blnCI == 12)
			{
				pesanan.blnCI = 1 ; 
				pesanan.thnCI = pesanan.thnCI + 1 ;
			}
			else
				pesanan.blnCI = pesanan.blnCI + 1 ;
		}
	}
	while (pesanan.thnCO== 0); 
}

void loading(){
	printf("\t\t\t\t\t\t+-----------------------+\n");
	printf("\t\t\t\t\t\t|       LOADING...      |\n");
	printf("\t\t\t\t\t\t+-----------------------+\n");
	sleep(2);
	system("cls");
	
}

void biling(){
		system("cls");
		waktu();
		printf("\t+=======================================================+\n");
		printf("\t|                  DIAMOND HOTEL's BILLING              |\n");
		printf("\t=========================================================\n");
		printf("\tNIK Pemesan	: %d\n", pesanan.id_pemesanan);
		printf("\t---------------------------------------------------------\n");
		printf("\tNama		: %s\n", pesanan.nama);
		printf("\t---------------------------------------------------------\n");
		printf("\tNo_Hp		: %d\n", pesanan.no_hp);
		printf("\t---------------------------------------------------------\n");
		printf("\tjenis Kelamin	: %s\n", pesanan.jenis_kelamin);
		printf("\t---------------------------------------------------------\n");
		printf("\tJumlah Kamar	: %d\n", pesanan.jumlah_kamar);
		printf("\t---------------------------------------------------------\n");
		printf("\tNomor Kamar	: %s\n", pesanan.room);
		printf("\t---------------------------------------------------------\n");
		printf("\tLama Inap	: %d Hari\n", pesanan.lama_sewa);
		printf("\t=========================================================\n");
		printf("\tTanggal Check In	: ", pesanan.tglCI, pesanan.blnCI, pesanan.thnCI); 
		hari (); 
		printf("\%d/%d/%d\n", pesanan.tglCI, pesanan.blnCI, pesanan.thnCI); 
		kalenderuntukCO (); 
		hari1=hari1+(pesanan.lama_sewa%7);
		while(hari1>7)
			hari1=hari1%7;	
			printf ("\tCheck Out  :");
			hari();
			printf ("%d/%d/%d\n", pesanan.tglCO,pesanan.blnCO, pesanan.thnCO) ;
		printf("\tTotal Harga		: Rp. %d\n\n", pesanan.total);
		printf("\t+=======================================================+\n");
		printf("\t|               TERIMA KASIH TELAH MEMESAN              |\n");
		printf("\t|                    HOTEL DIAMOND                      |\n");
		printf("\t+=======================================================+\n");

}

void jumlahstd(){ 
    FILE *file;
	  char filename[]="roomstd.txt";
	  file = fopen(filename, "r");
	  if (file == NULL){
	    printf("Error opening file.\n");
	  }
	  int current_line = 0;
	  char c;
	  do {
	    c = fgetc(file);
	    if (c == '\n') current_line++;
	  } while (c != EOF);
	  fclose(file);
	  printf("Jumlah Kamar Yang Tersedia: %d\n", current_line);
	FILE* view;
    view = fopen("roomstd.txt","r");
    printf("\tKamar Yang Tersedia:\n");
    while(fscanf(view,"%s",pesanan.room) != -1){	
    printf("\t%s \n",pesanan.room);
    }
    fclose(view);
}
void jumlahsuper(){
	 FILE *file;
	  char filename[]="roomsuper.txt";
	  file = fopen(filename, "r");
	  if (file == NULL){
	    printf("Error opening file.\n");
	  }
	  int current_line = 0;
	  char c;
	  do {
	    c = fgetc(file);
	    if (c == '\n') current_line++;
	  } while (c != EOF);
	  fclose(file);
	  printf("Jumlah Kamar Yang Tersedia: %d\n", current_line);
	FILE* view;
    view = fopen("roomsuper.txt","r");
    printf("\tKamar Yang Tersedia:\n");
    while(fscanf(view,"%s",pesanan.room) != -1){	
    printf("\t%s \n",pesanan.room);
    }
    fclose(view);
}

void jumlahdel(){
	 FILE *file;
	  char filename[]="roomdel.txt";
	  file = fopen(filename, "r");
	  if (file == NULL){
	    printf("Error opening file.\n");
	  }
	  int current_line = 0;
	  char c;
	  do {
	    c = fgetc(file);
	    if (c == '\n') current_line++;
	  } while (c != EOF);
	  fclose(file);
	  printf("Jumlah Kamar Yang Tersedia: %d\n", current_line);
	FILE* view;
    view = fopen("roomdel.txt","r");
    printf("\tKamar Yang Tersedia:\n");
    while(fscanf(view,"%s",pesanan.room) != -1){	
    printf("\t%s \n",pesanan.room);
    }
    fclose(view);
}

void jumlahsuit(){
	 FILE *file;
	  char filename[]="roomsuit.txt";
	  file = fopen(filename, "r");
	  if (file == NULL){
	    printf("Error opening file.\n");
	  }
	  int current_line = 0;
	  char c;
	  do {
	    c = fgetc(file);
	    if (c == '\n') current_line++;
	  } while (c != EOF);
	  fclose(file);
	  printf("Jumlah Kamar Yang Tersedia: %d\n", current_line);
	FILE* view;
    view = fopen("roomsuit.txt","r");
    printf("\tKamar Yang Tersedia:\n");
    while(fscanf(view,"%s",pesanan.room) != -1){	
    printf("\t%s \n",pesanan.room);
    }
    fclose(view);
}

void jumlahpres(){
	 FILE *file;
	  char filename[]="roompres.txt";
	  file = fopen(filename, "r");
	  if (file == NULL){
	    printf("Error opening file.\n");
	  }
	  int current_line = 0;
	  char c;
	  do {
	    c = fgetc(file);
	    if (c == '\n') current_line++;
	  } while (c != EOF);
	  fclose(file);
	  printf("Jumlah Kamar Yang Tersedia: %d\n", current_line);
	FILE* view;
    view = fopen("roompres.txt","r");
    printf("\tKamar Yang Tersedia:\n");
    while(fscanf(view,"%s",pesanan.room) != -1){	
    printf("\t%s \n",pesanan.room);
    }
    fclose(view);
}

void sstandard(){ 

    FILE *tmp1; 
    FILE *tmp2;
    FILE *fp;
    FILE *enter;
    FILE *view;
    
    //entering guests
    fp = fopen("hotelnew.txt","a");

    if( fp == NULL){
        printf("\nFile Tidak DItemukan");
        exit(1);
    }
    else{
        fprintf(fp, "=============================================================================================================================\n");
		fprintf(fp, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
		fprintf(fp,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
    }
    fprintf(fp,"\n");

  
    char remove_guest[20];
    strcpy(remove_guest,pesanan.nama);
    char remove_room[20];
    strcpy(remove_room,pesanan.room);


    tmp1 = fopen("tmp1.txt","a");
    enter = fopen("file_pemesanan.txt","r");
 
    while(fscanf(enter,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO) != -1){
            fgetc(enter);	
		    fgets(pesanan.nama, 1000, (FILE*)enter);
			    if(strcmp(pesanan.nama,remove_guest) != 0){
                    fprintf(tmp1, "=============================================================================================================================\n");
					fprintf(tmp1, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
					fprintf(tmp1,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
                }
        }
    fclose(enter);
    fclose(tmp1);
    remove("file_pemesanan.txt");
    rename("tmp1.txt","file_pemesanan.txt");
    fclose(fp);

    //removing room
    tmp2 = fopen("tmp2.txt","a");
    view = fopen("roomstd.txt","r");

    
    while(fscanf(view,"%s",pesanan.room) != -1){
			    if(strcmp(pesanan.room,remove_room) != 0){
                    fprintf(tmp2,"%s",pesanan.room);
                    fprintf(tmp2,"\n");
                }
        }
    fclose(view);
    fclose(tmp2);
    remove("roomstd.txt");
    rename("tmp2.txt","roomstd.txt");

    fclose(fp);
}

void ssuperior(){ 

    FILE *tmp1; 
    FILE *tmp2;
    FILE *fp;
    FILE *enter;
    FILE *view;
    
    //entering guests
    fp = fopen("hotelnew.txt","a");

    if( fp == NULL){
        printf("\nFile Tidak DItemukan");
        exit(1);
    }
    else{
        fprintf(fp, "=============================================================================================================================\n");
		fprintf(fp, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
		fprintf(fp,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
    }
    fprintf(fp,"\n");

    //
    char remove_guest[20];
    strcpy(remove_guest,pesanan.nama);
    char remove_room[20];
    strcpy(remove_room,pesanan.room);

    //removing booking
    tmp1 = fopen("tmp1.txt","a");
    enter = fopen("file_pemesanan.txt","r");
 
    while(fscanf(enter,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO) != -1){
            fgetc(enter);	
		    fgets(pesanan.nama, 1000, (FILE*)enter);
			    if(strcmp(pesanan.nama,remove_guest) != 0){
                    fprintf(tmp1, "=============================================================================================================================\n");
					fprintf(tmp1, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
					fprintf(tmp1,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
                }
        }
    fclose(enter);
    fclose(tmp1);
    remove("file_pemesanan.txt");
    rename("tmp1.txt","file_pemesanan.txt");
    fclose(fp);

    //removing room
    tmp2 = fopen("tmp2.txt","a");
    view = fopen("roomsuper.txt","r");

    
    while(fscanf(view,"%s",pesanan.room) != -1){
			    if(strcmp(pesanan.room,remove_room) != 0){
                    fprintf(tmp2,"%s",pesanan.room);
                    fprintf(tmp2,"\n");
                }
        }
    fclose(view);
    fclose(tmp2);
    remove("roomsuper.txt");
    rename("tmp2.txt","roomsuper.txt");

    fclose(fp);
}

void ddeluxe(){ 

    FILE *tmp1; 
    FILE *tmp2;
    FILE *fp;
    FILE *enter;
    FILE *view;
    
    //entering guests
    fp = fopen("hotelnew.txt","a");

    if( fp == NULL){
        printf("\nFile Tidak DItemukan");
        exit(1);
    }
    else{
        fprintf(fp, "=============================================================================================================================\n");
		fprintf(fp, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
		fprintf(fp,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
    }
    fprintf(fp,"\n");

    //
    char remove_guest[20];
    strcpy(remove_guest,pesanan.nama);
    char remove_room[20];
    strcpy(remove_room,pesanan.room);

    //removing booking
    tmp1 = fopen("tmp1.txt","a");
    enter = fopen("file_pemesanan.txt","r");
 
    while(fscanf(enter,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO) != -1){
            fgetc(enter);	
		    fgets(pesanan.nama, 1000, (FILE*)enter);
			    if(strcmp(pesanan.nama,remove_guest) != 0){
                    fprintf(tmp1, "=============================================================================================================================\n");
					fprintf(tmp1, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
					fprintf(tmp1,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
                }
        }
    fclose(enter);
    fclose(tmp1);
    remove("file_pemesanan.txt");
    rename("tmp1.txt","file_pemesanan.txt");
    fclose(fp);

    //removing room
    tmp2 = fopen("tmp2.txt","a");
    view = fopen("roomdel.txt","r");

    
    while(fscanf(view,"%s",pesanan.room) != -1){
			    if(strcmp(pesanan.room,remove_room) != 0){
                    fprintf(tmp2,"%s",pesanan.room);
                    fprintf(tmp2,"\n");
                }
        }
    fclose(view);
    fclose(tmp2);
    remove("roomdel.txt");
    rename("tmp2.txt","roomdel.txt");

    fclose(fp);
}

void ssuite(){ 

    FILE *tmp1; 
    FILE *tmp2;
    FILE *fp;
    FILE *enter;
    FILE *view;
    
    //entering guests
    fp = fopen("hotelnew.txt","a");

    if( fp == NULL){
        printf("\nFile Tidak DItemukan");
        exit(1);
    }
    else{
        fprintf(fp, "=============================================================================================================================\n");
		fprintf(fp, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
		fprintf(fp,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
    }
    fprintf(fp,"\n");

    //
    char remove_guest[20];
    strcpy(remove_guest,pesanan.nama);
    char remove_room[20];
    strcpy(remove_room,pesanan.room);

    //removing booking
    tmp1 = fopen("tmp1.txt","a");
    enter = fopen("file_pemesanan.txt","r");
 
    while(fscanf(enter,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO) != -1){
            fgetc(enter);	
		    fgets(pesanan.nama, 1000, (FILE*)enter);
			    if(strcmp(pesanan.nama,remove_guest) != 0){
                    fprintf(tmp1, "=============================================================================================================================\n");
					fprintf(tmp1, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
					fprintf(tmp1,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
                }
        }
    fclose(enter);
    fclose(tmp1);
    remove("file_pemesanan.txt");
    rename("tmp1.txt","file_pemesanan.txt");
    fclose(fp);

    //removing room
    tmp2 = fopen("tmp2.txt","a");
    view = fopen("roomsuit.txt","r");

    
    while(fscanf(view,"%s",pesanan.room) != -1){
			    if(strcmp(pesanan.room,remove_room) != 0){
                    fprintf(tmp2,"%s",pesanan.room);
                    fprintf(tmp2,"\n");
                }
        }
    fclose(view);
    fclose(tmp2);
    remove("roomsuit.txt");
    rename("tmp2.txt","roomsuit.txt");

    fclose(fp);
}

void ppresidential(){ 

    FILE *tmp1; 
    FILE *tmp2;
    FILE *fp;
    FILE *enter;
    FILE *view;
    
    //entering guests
    fp = fopen("hotelnew.txt","a");

    if( fp == NULL){
        printf("\nFile Tidak DItemukan");
        exit(1);
    }
    else{
        fprintf(fp, "=============================================================================================================================\n");
		fprintf(fp, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
		fprintf(fp,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
    }
    fprintf(fp,"\n");


    char remove_guest[20];
    strcpy(remove_guest,pesanan.nama);
    char remove_room[20];
    strcpy(remove_room,pesanan.room);

    //removing booking
    tmp1 = fopen("tmp1.txt","a");
    enter = fopen("file_pemesanan.txt","r");
 
    while(fscanf(enter,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO) != -1){
            fgetc(enter);	
		    fgets(pesanan.nama, 1000, (FILE*)enter);
			    if(strcmp(pesanan.nama,remove_guest) != 0){
                    fprintf(tmp1, "=============================================================================================================================\n");
					fprintf(tmp1, "|Nomor Kamar| ID |        NAMA       |    No_HP      |Jenis Kelamin | Jumlah Kamar | Lama Sewa |   Total   |   Check in   |  Check out  |\n");
					fprintf(tmp1,"      %s       %d           %s              %d              %s             %d            %d          %d         %d/%d/%d   |   %d/%d/%d  | \n", pesanan.room,pesanan.id_pemesanan, pesanan.nama, pesanan.no_hp, pesanan.jenis_kelamin, pesanan.jumlah_kamar,pesanan.lama_sewa, pesanan.total, pesanan.tglCI, pesanan.blnCI, pesanan.thnCI, pesanan.tglCO, pesanan.blnCO, pesanan.thnCO);
                }
        }
    fclose(enter);
    fclose(tmp1);
    remove("file_pemesanan.txt");
    rename("tmp1.txt","file_pemesanan.txt");
    fclose(fp);

    //removing room
    tmp2 = fopen("tmp2.txt","a");
    view = fopen("roompres.txt","r");

    
    while(fscanf(view,"%s",pesanan.room) != -1){
			    if(strcmp(pesanan.room,remove_room) != 0){
                    fprintf(tmp2,"%s",pesanan.room);
                    fprintf(tmp2,"\n");
                }
        }
    fclose(view);
    fclose(tmp2);
    remove("roompres.txt");
    rename("tmp2.txt","roompres.txt");

    fclose(fp);
}

void data_pemilihan(){
		fflush(stdin);
		printf("\t+=======================================================+\n");
		printf("\t|                   MASUKAN NOMOR KAMAR                 |\n");
		printf("\t=========================================================\n");
		printf("\t----->>[example : 1/2/3 dst...]");
		scanf("%s", pesanan.room);
		fflush(stdin);
		printf("\tMasukan NIK anda	:"); 
		valid(&pesanan.id_pemesanan);
		printf("\t*********************************************************\n");
		printf("\tMasukan Nama Anda :"); 
		scanf("%s", &pesanan.nama);
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\tMasukan No_Hp :"); 
		valid(&pesanan.no_hp);
		printf("\t*********************************************************\n");
		printf("\tMasukan Jenis Kelamin Anda:"); 
		scanf("%s", &pesanan.jenis_kelamin);
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\tLama Sewa (Masukan angka):");
		valid(&pesanan.lama_sewa);
		printf("\t*********************************************************\n");
		printf("\tMasukan Hari Dalam Angka	:");
		scanf("%d", &hari1);
		printf("\t*********************************************************\n");
		printf("\tMasukan Tanggal Check in (dd/mm/yy)	:");
		scanf("%d/%d/%d", &pesanan.tglCI, &pesanan.blnCI, &pesanan.thnCI);
		printf("\t==========================================================\n\n");
		printf("\t==========================================================\n\n");
		printf("\t\t\t\t==================================\n");
		tambah_kamar();
		hitung_total();
		printf("\t\t\t\tTotal Harga	: %d\n", pesanan.total);
		printf("\t\t\t\t==================================\n");
		fflush(stdin);
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
	printf("\t|     4      |       Suite Room         |  Rp 1.500.000 |\n");
	printf("\t=========================================================\n");
	printf("\t|     5      |     Presidential Room    |  Rp 2.000.000 |\n");
	printf("\t=========================================================\n\n");

	printf("\t+=======================================================+\n");
	printf("\t|                  PEMESANAN TIPE KAMAR                 |\n");
	printf("\t=========================================================\n");
	printf("\tMasukan Kode Kamar Yang Ingin Dipesan ->>");
	scanf("%d", &pesanan.pilih_kamar);
	printf("\t=========================================================\n\n");
	printf("\n\t*********************************************************\n");
	if(pesanan.pilih_kamar==1){
		fflush(stdin);
		ch:
		printf("\tJumlah Kamar [Max 1] :");
		valid(&pesanan.jumlah_kamar);
		if (pesanan.jumlah_kamar >1 || pesanan.jumlah_kamar <1){
			printf("\tJika ingin memesan lebih dari 1 kamar silahkan lakukan pemesanan lagi!!!\n");
			goto ch;
		}
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\t+=======================================================+\n");
		printf("\t|                NOMOR KAMAR YANG TERSEDIA              |\n");
		printf("\t=========================================================\n");
		jumlahstd();
		data_pemilihan();
		biling();
		sstandard();
	}else if(pesanan.pilih_kamar==2){
		fflush(stdin);
		printf("\tJumlah Kamar :");
		valid(&pesanan.jumlah_kamar);
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\t+=======================================================+\n");
		printf("\t|                NOMOR KAMAR YANG TERSEDIA              |\n");
		printf("\t=========================================================\n");
		jumlahsuper();
		data_pemilihan();
		biling();
		ssuperior();
	}else if(pesanan.pilih_kamar==3){
		fflush(stdin);
		printf("\tJumlah Kamar :");
		valid(&pesanan.jumlah_kamar);
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\t+=======================================================+\n");
		printf("\t|                NOMOR KAMAR YANG TERSEDIA              |\n");
		printf("\t=========================================================\n");
		jumlahdel();
		data_pemilihan();
		biling();
		ddeluxe();
	}else if(pesanan.pilih_kamar==4){
		fflush(stdin);
		printf("\tJumlah Kamar :");
		valid(&pesanan.jumlah_kamar);
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\t+=======================================================+\n");
		printf("\t|                NOMOR KAMAR YANG TERSEDIA              |\n");
		printf("\t=========================================================\n");
		jumlahsuit();
		data_pemilihan();
		biling();
		ssuite();
	}else if(pesanan.pilih_kamar==5){
		fflush(stdin);
		printf("\tJumlah Kamar :");
		valid(&pesanan.jumlah_kamar);
		printf("\t*********************************************************\n");
		fflush(stdin);
		printf("\t+=======================================================+\n");
		printf("\t|                NOMOR KAMAR YANG TERSEDIA              |\n");
		printf("\t=========================================================\n");
		jumlahpres();
		data_pemilihan();
		biling();
		ppresidential();
	}
	else{
		printf("\t+=======================================================+\n");
		printf("\t|       MASUKAN KODE TIPE KAMAR YANG SESUAI!!!          |\n");
		printf("\t=========================================================\n");
		system("pause");
		pesan_kamar();
	}
	
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
	printf("\t|      3     | Deluxe Room    | Kamar berada di lantai 5 & 6. Dengan|  Rp 1.000.000   |      %d       |\n", jumlah_deluxe);
	printf("\t|            | 9x4            | fasilitas seperti TwinBed/Double Bed|                 |               |\n");
	printf("\t|            |                | Perlengkapan Mandi, WIFI dan Bathtub|                 |               |\n");
	printf("\t|            |                | Kamar Mandi with shower, mini bar,  |                 |               |\n");
	printf("\t|            |                | balcoon, Ac, Kulkas, TV, Kopi Maker |                 |               |\n");
	printf("\t|            |                | Meja rias.                          |                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|      4     | Suite Room     | Kamar berada di lantai 7 & 8. Dengan| Rp 1.500.000    |       %d      |\n", jumlah_suite);
	printf("\t|            | 8x4            | fasilitas seperti TwinBed/Double Bed|                 |               |\n");
	printf("\t|            |                | Perlengkapan Mandi, WIFI dan Bathtub|                 |               |\n");
	printf("\t|            |                | Kamar Mandi with shower, mini bar,  |                 |               |\n");
	printf("\t|            |                | balcoon, Ac, Kulkas, TV, Kopi Maker |                 |               |\n");
	printf("\t|            |                | Meja rias.                          |                 |               |\n");
	printf("\t|-----------------------------------------------------------------------------------------------------|\n");
	printf("\t|     5      | Presidential   | Kamar berada di lantai 9 & 10.Dengan|  Rp 2.000.000   |       %d      |\n", jumlah_presidential);
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
	char buffer[10000];
	FILE *pesan;
	pesan=fopen("hotelnew.txt", "r");
	if(pesan==NULL){
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|                  DATA FILE TIDAK ADA                  |\n");
	printf("\t\t\t\t=========================================================\n");
		exit(0);
	}
	while(fgets(buffer, sizeof(buffer), pesan)){
		printf("%s", buffer);
	}
	system("pause");
	fclose(pesan);
}


void hapus(){
	FILE *fp1, *fp2;
	struct pesan pesanan;
	char id;
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|          Apakah anda yakin menghapus data             |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|         y [yes]          |            n [no]          |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\tPilihan Anda :");
	scanf("\t\t\t\t%c", &id);
	
	fp1=fopen("hotelnew.txt", "r+");
	fp2=fopen("Temp_Data.txt", "a+");
	if(fp1==NULL){
		fprintf(stderr, "\n\t\t\t\t\t\tDATA TIDAK DITEMUKAN\n");
	}
	while(fread(&pesanan, sizeof(struct pesan),1,fp1)){
		if(pesanan.id_pemesanan!=id){
			fwrite(&pesanan, sizeof(struct pesan), 1,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("hotelnew.txt");
	rename("Data_Temp.txt", "hotelnew");
	printf("\t\t\t\t\t+-------------------------------------+\n");
	printf("\t\t\t\t\t|          SUKSES HAPUS DATA          |\n");
	printf("\t\t\t\t\t+-------------------------------------+\n");
}
void rooms(){
	int pil;
	system("cls");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\t|      MASUKAN PILIHAN KATEGORI KAMAR YANG DI CEK       |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    NO  |    KATEGORI KAMAR                            |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    1   |    STANDARD ROOM                             |\n");
	printf("\t\t\t\t|    2   |    SUPERIOR ROOM                             |\n");
	printf("\t\t\t\t|    3   |    DELUXE ROOM                               |\n");
	printf("\t\t\t\t|    4   |    SUITE ROOM                                |\n");
	printf("\t\t\t\t|    5   |    PRESEDENTIAL ROOM                         |\n");
	printf("\t\t\t\t|    6   |    KELUAR                                    |\n");
	printf("\t\t\t\t=========================================================\n");
		printf("\t\t\t\t1. Pilih Kamar/Room Yang Mau Di Cek[1][2][3][4][5]:");
			scanf("%d", &pil);
			if(pil==1){
				system("cls");
				jumlahstd();
				system("pause");
				rooms();
			}else if(pil==2){
				system("cls");
				jumlahsuper();
				system("pause");
				rooms();
			}else if(pil==3){
				system("cls");
				jumlahdel();
				system("pause");
				rooms();
			}else if(pil==4){
				system("cls");
				jumlahsuit();
				system("pause");
				rooms();
			}else if(pil==5){
				system("cls");
				jumlahpres();
				system("pause");
				rooms();
			}else if(pil==6){
				system("cls");
				menu_admin();
			}else{
				printf("Masukan Pilihan Yang Tepat");
				system("pause");
				menu_admin();
			}
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
	printf("\t\t\t\t|    4   |    CEK KAMAR                                 |\n");
	printf("\t\t\t\t|    5   |    HAPUS PESANAN                             |\n");
	printf("\t\t\t\t|    6   |    KELUAR MENU ADMIN                         |\n");
	printf("\t\t\t\t|    7   |    KELUAR PROGRAM                            |\n");
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
			menu_admin();
			break;
		case 4:
			rooms();
			break;
		case 5:
			system("cls");
			hapus();
			break;
		case 6:
			system("cls");
			menu_masuk();
			break;
		case 7:
			system("cls");
			keluar();
			break;
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
	printf("\t\t\t\t|    3   |    KELUAR MENU CUSTOMER                      |\n");
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
			menu_customer();
			break;
		case 2:
			system("cls");
			pilih_kamar();
			break;
		case 3:
			system("cls");
			form_customer();
			break;
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
	printf("\t\t\t\t+=======================================================+\n");
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
			loading();
			system("cls");
			printf("\t\t\t\t\t\t    +--------------+\n");
			printf("\t\t\t\t\t\t    |Login Berhasil|\n");
			printf("\t\t\t\t\t\t    +--------------+\n");
			system("pause");
			menu_customer();
		}else{
			loading();
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
		loading();
		printf("\t\t\t\t\t\t   + -------------- +\n");
		printf("\t\t\t\t\t\t   | LOGIN BERHASIL |\n");
		printf("\t\t\t\t\t\t   + -------------- +\n");
		system("pause");
		menu_admin();
	}else{
		loading();
		printf("\t\t\t\t\t     + --------------------------- +\n");
		printf("\t\t\t\t\t     | USERNAME DAN PASSWORD SALAH |\n");
		printf("\t\t\t\t\t     + --------------------------- +\n\n");
		printf("\t\t\t\t\t  + -------------------------------- +\n");
		printf("\t\t\t\t\t  | Masukan Ulang Username & Password|\n");
		printf("\t\t\t\t\t  + -------------------------------- +\n");
		system("pause");
		system("cls");
		login_admin();
	}

}
//fungsi form customer
void form_customer(){
	system("cls");
	int pilihan;
	printf("\t\t\t\t+=========================================================+\n");
	printf("\t\t\t\t|                      FORM CUSTOMER                      |\n");
	printf("\t\t\t\t+=========================================================+\n");
	printf("\t\t\t\t|                    INFORMASI PENTING                    |\n");
	printf("\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t|  1.Pilih Login jika anda sudah punya akun               |\n");
	printf("\t\t\t\t|  2.Utamakan Pilih Register jika anda belum punya akun   |\n");
	printf("\t\t\t\t|                                                         |\n");
	printf("\t\t\t\t+=========================================================+\n");
	printf("\t\t\t\t||   1   |    REGISTER                                   ||\n");
	printf("\t\t\t\t||   2   |    LOGIN                                      ||\n");
	printf("\t\t\t\t||   3   |    KELUAR FORM CUSTOMER                       ||\n");
	printf("\t\t\t\t||   4   |    KELUAR PROGRAM                             ||\n");
	printf("\t\t\t\t+---------------------------------------------------------+\n");
	printf("\t\t\t\t Masukkan nomor menu yang anda inginkan [1][2][3][4] ==> ");
	/*Fungsinya fflush(stdin) adalah untuk membersihkan (atau flush) output buffer dan memindahkan data buffer menuju console 
	(dalam kasus stdout) atau disk (pada kasus file output stream).*/
	fflush(stdin);
	scanf("%d", &pilihan);
	system("cls");
	if(pilihan==1){
		/* menyimpan data registrasi di file reg dan fungsi w menulis di file */
			FILE *reg;
			reg=fopen(akun, "w");
			if(akun==NULL){
				printf("File Tidak DItemukan!\n");
			}else{
				printf("\t\t\t\t+=========================================================+\n");
				printf("\t\t\t\t|         SILAHKAN LENGKAPI DATA KETENTUAN DIBAWAH        |\n");
				printf("\t\t\t\t+=========================================================+\n");
				printf("\t\t\t\tMasukan Nama  : ");
				scanf(" %s", user.nama);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				printf("\t\t\t\tMasukan No HP :");
				scanf("%d", user.no_hp);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				printf("\t\t\t\tMasukan Email Anda :");
				scanf("%s", user.email);
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				ulang:
				printf("\t\t\t\tMasukan Username MAX (8 Karakter) :");
				scanf("%s", user.username);
				if(strlen(user.username) >= 1 && strlen(user.username) == 8){
					printf("\n");
				}else{
					printf("\t\t\t\tHarus 8 Karakter Bebas\n");
					system("pause");
					goto ulang;
				}
				fflush(stdin);
				printf("\t\t\t\t---------------------------------------------------------\n");
				uulang:
				printf("\t\t\t\tMasukan Password MAX (8 Karakter) :");
				scanf("%s", user.password);
				if(strlen(user.password) >= 1 && strlen(user.password) <= 8){
					printf("\n");
				}else{
					printf("\t\t\t\tHarus 8 Karakter Bebas\n");
					system("pause");
					goto uulang;
				}
				fwrite(&user, 1, sizeof(user), reg);
				fclose(reg);
				fflush(stdin);
				printf("\t\t\t\t=========================================================\n");
				loading();
				system("cls");
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
		menu_masuk();
	}else if(pilihan==4){
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
	printf("\t\t\t\t|                MENU PROGRAM DIAMOND HOTEL             |\n");
	printf("\t\t\t\t========================================================\n");
	printf("\t\t\t\t|    NO  |                PILIHAN MENU                  |\n");
	printf("\t\t\t\t=========================================================\n");
	printf("\t\t\t\t|    1   |    SEBAGAI ADMIN                             |\n");
	printf("\t\t\t\t|    2   |    SEBAGAI CUSTOMER                          |\n");
	printf("\t\t\t\t|    3   |    KELUAR PROGRAM                            |\n");
	printf("\t\t\t\t+=======================================================+\n");
	printf("\t\t\t\tMasukkan nomor menu yang anda inginkan [1][2][3] ===>| ");
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
			system("pause");
			system("cls");
			break;
		default:
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			printf("\t\t\t\t|           Menu yang anda pilih tidak valid              |\n");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			printf("\t\t\t\t|             Silahkan Masukan Ulang Menu                 |\n");
			printf("\t\t\t\t+---------------------------------------------------------+\n");
			system("pause");
			fflush(stdin);
			system("cls");
			menu_masuk();
			
	}
}

int main(){
	system ("color 1");

    selamat();
	system("pause");
	system("cls");
	menu_masuk();
}
