#define N 100
#include <stdio.h>
#include <stdlib.h>

struct randevu{
	int   randevuNo;
	int   randevuTarihi;
    int   randevuSaati;
    char  *randevuYeri;
    char  *rAdi;
    char  *rSoyadi;
    char  *unvan;
    int   telefon;
    char  *not;
    int  randevuDurumu;
    //randevu durumu 1 ise gorusülmedi
    //randevu durumu 0 ise gorusuldu
};

void randevuEkle(struct randevu r1){
    FILE *randevular;
    randevular = fopen("randevu.txt","a");
    fprintf(randevular, "%d %d %d %s %s %s %s %d %s %d\n",
    		r1.randevuNo,r1.randevuTarihi,r1.randevuSaati,r1.randevuYeri,r1.rAdi,r1.rSoyadi,r1.unvan,r1.telefon,r1.not,r1.randevuDurumu);
	fclose(randevular);
}

int main(void) {
	int tercih=0;

		printf(" **** Randevu Takip Programýna Hoþgeldiniz **** \n");

		while(tercih==0){
			printf("Ýþlem Menüsü\n");
			printf("--> 1. Yeni Randevu Ekle\n");
			printf("--> 2. Randevu Güncelle\n");
			printf("--> 3. Randevu Sil\n");
			printf("--> 4. Randevularýmý Gör\n");
			printf("--> 5. Randevu Durumu Güncelle\n");
			printf("--> 6. Çýkýþ\n");
			printf("Lütfen Yapmak istediðiniz iþlemi seçiniz(örn:1, 2, 3)\n");
			printf("Tercih -->");
			fflush( stdout );
			scanf("%d",&tercih);

			while(tercih==1){

				struct randevu r1;
				printf(" **** Yeni Randevu Ekle ****\n");

				FILE *randevuGetir;
				randevuGetir=fopen("randevu.txt","r");
					int tarih_0,saat_0,tel_0,ranDurum_0,ranNo_0;
					char *ranYeri_0=malloc(sizeof(char)*100);
					char *ranAdi_0=malloc(sizeof(char)*100);
					char *ranSoyad_0=malloc(sizeof(char)*100);
					char *ranUnvan_0 = malloc(sizeof(char)*100);
					char *not_0 = malloc(sizeof(char)*100);
					if(randevuGetir != NULL){
					while(!feof(randevuGetir)){
						fscanf(randevuGetir, "%d %d %d %s %s %s %s %d %s %d\n",
    		&ranNo_0,&tarih_0,&saat_0,ranYeri_0,ranAdi_0,ranSoyad_0,ranUnvan_0,&tel_0,not_0,&ranDurum_0);
						printf("%d %d %d %s %s %s %s %d %s %d\n",
			ranNo_0,tarih_0,saat_0,ranYeri_0,ranAdi_0,ranSoyad_0,ranUnvan_0,tel_0,not_0,ranDurum_0);
					}
					fclose(randevuGetir);
					}
				printf("Randevu Numarasý :");
				fflush(stdout);
				scanf("%d",&r1.randevuNo);

				printf("Randevu Tarihi Giriniz :");
				fflush(stdout);
				scanf("%d",&r1.randevuTarihi);

				printf("Randevu Saati Giriniz :");
				fflush(stdout);
				scanf("%d",&r1.randevuSaati);

				r1.randevuYeri = malloc(sizeof(char)*100);
				printf("Randevu Yeri Giriniz :");
				fflush(stdout);
				scanf("%s", r1.randevuYeri);

				r1.rAdi = malloc(sizeof(char)*100);
				printf("Randevu Sahibinin Adý :");
				fflush(stdout);
				scanf("%s",r1.rAdi);

				r1.rSoyadi = malloc(sizeof(char)*100);
				printf("Randevu Sahibinin Soyadý :");
				fflush(stdout);
				scanf("%s",r1.rSoyadi);

				r1.unvan = malloc(sizeof(char)*100);
				printf("Randevu Sahibinin Unvaný :");
				fflush(stdout);
				scanf("%s",r1.unvan);

				printf("Randevu Sahibinin Telefonu :");
				fflush(stdout);
				scanf("%d",&r1.telefon);

				r1.not = malloc(sizeof(char)*100);
				printf("Randevu ile Ýlgili Not :");
				fflush(stdout);
				scanf("%s",r1.not);

				printf("Randevu Durumu :");
				fflush(stdout);
				scanf("%d",&r1.randevuDurumu);

				randevuEkle(r1);

				printf("--> Randevu Eklendi\n");

				printf("Yeni Randevu Eklemek Ýster misiniz? (Evet:1, Ana Menü:0, Çýkýþ:6)\n");
				printf("Tercih --> ");
				fflush(stdout);
				scanf("%d",&tercih);

			}

			while(tercih==2){
				printf(" **** Randevu Güncelleme Ekraný **** \n");
				printf("Güncelleme Seçeneklerinden Birini Seçiniz\n");
				printf("--> 1. Randevu Tarihi Güncelle\n");
				printf("--> 2. Randevu Saati Güncelle\n");
				printf("--> 3. Randevu Yeri Güncelle\n");
				printf("--> 4. Tümünü Güncelle\n");
				int guncelSecim=0;
				printf("Tercih -->");
				fflush( stdout );
				scanf("%d",&guncelSecim);

				while(guncelSecim == 1){
					printf(" **** Randevu Tarihi Güncelleme Ekraný **** \n");
					FILE *tarihGuncelle;
					tarihGuncelle=fopen("randevu.txt","r");
						int tarih0,saat0,tel0,ranDurum0,ranNo0;
						char *ranYeri0=malloc(sizeof(char)*100);
						char *ranAdi0=malloc(sizeof(char)*100);
						char *ranSoyad0=malloc(sizeof(char)*100);
						char *ranUnvan0 = malloc(sizeof(char)*100);
						char *not0 = malloc(sizeof(char)*100);
						while(!feof(tarihGuncelle)){
							fscanf(tarihGuncelle, "%d %d %d %s %s %s %s %d %s %d\n",
				&ranNo0,&tarih0,&saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,&tel0,not0,&ranDurum0);
							printf("%d %d %d %s %s %s %s %d %s %d\n",
				ranNo0,tarih0,saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,tel0,not0,ranDurum0);
						}
						fclose(tarihGuncelle);

					printf("Tarihini Düzenlemek Ýstediðiniz Randevunun Numarasýný Giriniz.\n");
					struct randevu r1;
					int duzenleTarih;
					FILE *eski_dosya;
					FILE *yeni_dosya;
					eski_dosya = fopen("randevu.txt", "r");
					yeni_dosya = fopen("yeni_dosya.txt", "w+");

					printf("Düzenlenecek id=");
					fflush(stdout);
					scanf("%d", &duzenleTarih);

					int tarih_1,saat_1,tel_1,ranDurum_1,ranNo_1;
					char *ranYeri_1=malloc(sizeof(char)*100);
					char *ranAdi_1=malloc(sizeof(char)*100);
					char *ranSoyad_1=malloc(sizeof(char)*100);
					char *ranUnvan_1 = malloc(sizeof(char)*100);
					char *not_1 = malloc(sizeof(char)*100);
					while (!feof(eski_dosya)) {
						fscanf(eski_dosya, "%d %d %d %s %s %s %s %d %s %d\n", &ranNo_1,&tarih_1, &saat_1,ranYeri_1,
								ranAdi_1,ranSoyad_1,ranUnvan_1,&tel_1,not_1,&ranDurum_1);
						if (duzenleTarih == ranNo_1) {

							printf("Yeni Randevu Tarihi Giriniz :");
							fflush(stdout);
							scanf("%d",&r1.randevuTarihi);

							int degisTarih=r1.randevuTarihi;

							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_1, degisTarih, saat_1,
									ranYeri_1,ranAdi_1,ranSoyad_1,ranUnvan_1,tel_1,not_1,ranDurum_1);


						} else
							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_1, tarih_1, saat_1,
									ranYeri_1,ranAdi_1,ranSoyad_1,ranUnvan_1,tel_1,not_1,ranDurum_1);
					}
					fclose(eski_dosya);
					fclose(yeni_dosya);
					remove("randevu.txt");
					rename("yeni_dosya.txt", "randevu.txt");

				printf("--> Randevu Tarihi Güncellendi\n");

				printf("Baþka Randevu Düzenlemek Ýster misiniz? (Evet:2, Ana Menü:0, Çýkýþ:6)\n");
				guncelSecim=0;

				}
				while(guncelSecim == 2){
					printf(" **** Randevu Saati Güncelleme Ekraný **** \n");

					FILE *guncelleSaat;
					guncelleSaat=fopen("randevu.txt","r");
						int tarih0,saat0,tel0,ranDurum0,ranNo0;
						char *ranYeri0=malloc(sizeof(char)*100);
						char *ranAdi0=malloc(sizeof(char)*100);
						char *ranSoyad0=malloc(sizeof(char)*100);
						char *ranUnvan0 = malloc(sizeof(char)*100);
						char *not0 = malloc(sizeof(char)*100);
						while(!feof(guncelleSaat)){
							fscanf(guncelleSaat, "%d %d %d %s %s %s %s %d %s %d\n",
				&ranNo0,&tarih0,&saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,&tel0,not0,&ranDurum0);
							printf("%d %d %d %s %s %s %s %d %s %d\n",
				ranNo0,tarih0,saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,tel0,not0,ranDurum0);
						}
						fclose(guncelleSaat);

					printf("Saatini Düzenlemek Ýstediðiniz Randevunun Numarasýný Giriniz.\n");
					struct randevu r1;
					int duzenleSaat;
					FILE *eski_dosya;
					FILE *yeni_dosya;
					eski_dosya = fopen("randevu.txt", "r");
					yeni_dosya = fopen("yeni_dosya.txt", "w+");

					printf("Düzenlenecek Id=");
					fflush(stdout);
					scanf("%d", &duzenleSaat);

					int tarih_2,saat_2,tel_2,ranDurum_2,ranNo_2;
					char *ranYeri_2=malloc(sizeof(char)*100);
					char *ranAdi_2=malloc(sizeof(char)*100);
					char *ranSoyad_2=malloc(sizeof(char)*100);
					char *ranUnvan_2 = malloc(sizeof(char)*100);
					char *not_2 = malloc(sizeof(char)*100);
					while (!feof(eski_dosya)) {
						fscanf(eski_dosya, "%d %d %d %s %s %s %s %d %s %d\n", &ranNo_2,&tarih_2, &saat_2,ranYeri_2,
								ranAdi_2,ranSoyad_2,ranUnvan_2,&tel_2,not_2,&ranDurum_2);
						if (duzenleSaat == ranNo_2) {

							printf("Yeni Randevu Saati Giriniz :");
							fflush(stdout);
							scanf("%d",&r1.randevuSaati);

							int degisSaat=r1.randevuSaati;


							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_2, tarih_2, degisSaat,
									ranYeri_2,ranAdi_2,ranSoyad_2,ranUnvan_2,tel_2,not_2,ranDurum_2);


						} else
							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_2, tarih_2, saat_2,
									ranYeri_2,ranAdi_2,ranSoyad_2,ranUnvan_2,tel_2,not_2,ranDurum_2);
					}
					fclose(eski_dosya);
					fclose(yeni_dosya);
					remove("randevu.txt");
					rename("yeni_dosya.txt", "randevu.txt");

				printf("--> Randevu Saati Güncellendi\n");

				printf("Baþka Randevu Düzenlemek Ýster misiniz? (Evet:2, Ana Menü:0, Çýkýþ:6)\n");
				guncelSecim=0;

				}
				while(guncelSecim == 3){
					printf(" **** Randevu Yeri Güncelleme Ekraný ****\n");

					FILE *guncelleYer;
					guncelleYer=fopen("randevu.txt","r");
						int tarih0,saat0,tel0,ranDurum0,ranNo0;
						char *ranYeri0=malloc(sizeof(char)*100);
						char *ranAdi0=malloc(sizeof(char)*100);
						char *ranSoyad0=malloc(sizeof(char)*100);
						char *ranUnvan0 = malloc(sizeof(char)*100);
						char *not0 = malloc(sizeof(char)*100);
						while(!feof(guncelleYer)){
							fscanf(guncelleYer, "%d %d %d %s %s %s %s %d %s %d\n",
				&ranNo0,&tarih0,&saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,&tel0,not0,&ranDurum0);
							printf("%d %d %d %s %s %s %s %d %s %d\n",
				ranNo0,tarih0,saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,tel0,not0,ranDurum0);
						}
						fclose(guncelleYer);

					printf("Düzenlemek Ýstediðiniz Randevunun Numarasýný Giriniz.\n");
					struct randevu r1;
					int duzenleYer;
					FILE *eski_dosya;
					FILE *yeni_dosya;
					eski_dosya = fopen("randevu.txt", "r");
					yeni_dosya = fopen("yeni_dosya.txt", "w+");

					printf("Düzenlenecek id=");
					fflush(stdout);
					scanf("%d", &duzenleYer);

					int tarih_3,saat_3,tel_3,ranDurum_3,ranNo_3;
					char *ranYeri_3=malloc(sizeof(char)*100);
					char *ranAdi_3=malloc(sizeof(char)*100);
					char *ranSoyad_3=malloc(sizeof(char)*100);
					char *ranUnvan_3 = malloc(sizeof(char)*100);
					char *not_3 = malloc(sizeof(char)*100);
					while (!feof(eski_dosya)) {
						fscanf(eski_dosya, "%d %d %d %s %s %s %s %d %s %d\n", &ranNo_3,&tarih_3, &saat_3,ranYeri_3,
								ranAdi_3,ranSoyad_3,ranUnvan_3,&tel_3,not_3,&ranDurum_3);
						if (duzenleYer == ranNo_3) {

							r1.randevuYeri=malloc(sizeof(char)*100);
							printf("Yeni Randevu Yeri Giriniz :");
							fflush(stdout);
							scanf("%s",r1.randevuYeri);

							char *degisYer=malloc(sizeof(char)*100);
							degisYer=r1.randevuYeri;

							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_3, tarih_3, saat_3,
									degisYer,ranAdi_3,ranSoyad_3,ranUnvan_3,tel_3,not_3,ranDurum_3);


						} else
							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_3, tarih_3, saat_3,
									ranYeri_3,ranAdi_3,ranSoyad_3,ranUnvan_3,tel_3,not_3,ranDurum_3);
					}
					fclose(eski_dosya);
					fclose(yeni_dosya);
					remove("randevu.txt");
					rename("yeni_dosya.txt", "randevu.txt");

				printf("--> Randevu Yeri Güncellendi\n");
				guncelSecim=0;

				}
				while(guncelSecim == 4){
					printf(" **** Randevu Tarihi, Saati ve Yeri Güncelleme Ekraný **** \n");

					FILE *tumRandevu;
					tumRandevu=fopen("randevu.txt","r");
						int tarih0,saat0,tel0,ranDurum0,ranNo0;
						char *ranYeri0=malloc(sizeof(char)*100);
						char *ranAdi0=malloc(sizeof(char)*100);
						char *ranSoyad0=malloc(sizeof(char)*100);
						char *ranUnvan0 = malloc(sizeof(char)*100);
						char *not0 = malloc(sizeof(char)*100);
						while(!feof(tumRandevu)){
							fscanf(tumRandevu, "%d %d %d %s %s %s %s %d %s %d\n",
				&ranNo0,&tarih0,&saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,&tel0,not0,&ranDurum0);
							printf("%d %d %d %s %s %s %s %d %s %d\n",
				ranNo0,tarih0,saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,tel0,not0,ranDurum0);
						}
						fclose(tumRandevu);

					printf("Düzenlemek Ýstediðiniz Randevunun Numarasýný Giriniz.\n");
					struct randevu r1;
					int duzenle;
					FILE *eski_dosya;
					FILE *yeni_dosya;
					eski_dosya = fopen("randevu.txt", "r");
					yeni_dosya = fopen("yeni_dosya.txt", "w+");

					printf("Düzenlenecek id=");
					fflush(stdout);
					scanf("%d", &duzenle);

					int tarih_1,saat_1,tel_1,ranDurum_1,ranNo_1;
					char *ranYeri_1=malloc(sizeof(char)*100);
					char *ranAdi_1=malloc(sizeof(char)*100);
					char *ranSoyad_1=malloc(sizeof(char)*100);
					char *ranUnvan_1 = malloc(sizeof(char)*100);
					char *not_1 = malloc(sizeof(char)*100);
					while (!feof(eski_dosya)) {
						fscanf(eski_dosya, "%d %d %d %s %s %s %s %d %s %d\n", &ranNo_1,&tarih_1, &saat_1,ranYeri_1,
								ranAdi_1,ranSoyad_1,ranUnvan_1,&tel_1,not_1,&ranDurum_1);
						if (duzenle == ranNo_1) {

							printf("Yeni Randevu Tarihi Giriniz :");
							fflush(stdout);
							scanf("%d",&r1.randevuTarihi);

							printf("Yeni Randevu Saati Giriniz :");
							fflush(stdout);
							scanf("%d",&r1.randevuSaati);

							r1.randevuYeri=malloc(sizeof(char)*100);
							printf("Yeni Randevu Yeri Giriniz :");
							fflush(stdout);
							scanf("%s",r1.randevuYeri);

							char *degisYer=malloc(sizeof(char)*100);
							int degisTarih=r1.randevuTarihi;
							int degisSaat=r1.randevuSaati;
							degisYer=r1.randevuYeri;

							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_1, degisTarih, degisSaat,
									degisYer,ranAdi_1,ranSoyad_1,ranUnvan_1,tel_1,not_1,ranDurum_1);


						} else
							fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_1, tarih_1, saat_1,
									ranYeri_1,ranAdi_1,ranSoyad_1,ranUnvan_1,tel_1,not_1,ranDurum_1);
					}
					fclose(eski_dosya);
					fclose(yeni_dosya);
					remove("randevu.txt");
					rename("yeni_dosya.txt", "randevu.txt");

				printf("--> Randevu Güncellendi\n");
				guncelSecim=0;

				}

				printf("Baþka Randevu Düzenlemek Ýster misiniz? (Evet:2, Ana Menü:0, Çýkýþ:6)\n");
				printf("Tercih --> ");
				fflush(stdout);
				scanf("%d",&tercih);


			}
			while(tercih==3){

				printf(" **** Randevu Sil Ekraný **** \n");

				FILE *tumRandevu;
				tumRandevu=fopen("randevu.txt","r");
					int tarih0,saat0,tel0,ranDurum0,ranNo0;
					char *ranYeri0=malloc(sizeof(char)*100);
					char *ranAdi0=malloc(sizeof(char)*100);
					char *ranSoyad0=malloc(sizeof(char)*100);
					char *ranUnvan0 = malloc(sizeof(char)*100);
					char *not0 = malloc(sizeof(char)*100);
					while(!feof(tumRandevu)){
						fscanf(tumRandevu, "%d %d %d %s %s %s %s %d %s %d\n",
    		&ranNo0,&tarih0,&saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,&tel0,not0,&ranDurum0);
						printf("%d %d %d %s %s %s %s %d %s %d\n",
			ranNo0,tarih0,saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,tel0,not0,ranDurum0);
					}
					fclose(tumRandevu);

				printf("Silmek istediðiniz randevu ID'sini giriniz.\n");
				int sil;
				printf("Silinecek Randevu = ");
				fflush(stdout);
				scanf("%d", &sil);
				FILE *eski_dosya;

				eski_dosya = fopen("randevu.txt", "r");
				FILE *yeni_dosya;
				yeni_dosya = fopen("yeni_dosya.txt", "a");
				int tarih,saat,tel,ranDurum,ranNo;
				char *ranYeri=malloc(sizeof(char)*100);
				char *ranAdi=malloc(sizeof(char)*100);
				char *ranSoyad=malloc(sizeof(char)*100);
				char *ranUnvan = malloc(sizeof(char)*100);
				char *not = malloc(sizeof(char)*100);
				while ( !feof(eski_dosya)) {
					fscanf(eski_dosya, "%d %d %d %s %s %s %s %d %s %d\n", &ranNo, &tarih, &saat,
							ranYeri,ranAdi,ranSoyad,ranUnvan,&tel,not,&ranDurum);
					if (sil == ranNo){

					}

					else{
						fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo, tarih, saat,
							ranYeri,ranAdi,ranSoyad,ranUnvan,tel,not,ranDurum);

					}

				}
				fclose(eski_dosya);
				fclose(yeni_dosya);
				remove("randevu.txt");
				rename("yeni_dosya.txt", "randevu.txt");
				printf("Randevu Silindi!\n");


				printf("Baþka Randevu Silmek Ýster misiniz? (Evet:3, Ana Menü:0, Çýkýþ:6)\n");
				printf("Tercih --> ");
				fflush(stdout);
				scanf("%d",&tercih);


			}
			while(tercih == 4){

				printf(" **** Randevularýmý Gör **** \n");
				int secim=0;
				printf("--> 1. Geçmiþ Randevularý Gör\n");
				printf("--> 2. Gelecek Randevularý Gör\n");
				printf("Seçim -->");
				fflush(stdout);
				scanf("%d",&secim);

				while(secim==1){
					printf(" **** Geçmiþ Randevular **** \n");
				FILE *gecmisRandevu;
					gecmisRandevu=fopen("randevu.txt","r");
					int tarih,saat,tel,ranDurum,ranNo;
					int durum = 0;
					char *ranYeri=malloc(sizeof(char)*100);
					char *ranAdi=malloc(sizeof(char)*100);
					char *ranSoyad=malloc(sizeof(char)*100);
					char *ranUnvan = malloc(sizeof(char)*100);
					char *not = malloc(sizeof(char)*100);
					while(!feof(gecmisRandevu)){
						fscanf(gecmisRandevu, "%d %d %d %s %s %s %s %d %s %d\n",
    		&ranNo,&tarih,&saat,ranYeri,ranAdi,ranSoyad,ranUnvan,&tel,not,&ranDurum);
						if(ranDurum == durum){
							printf("%d %d %d %s %s %s %s %d %s %d\n",
			ranNo,tarih,saat,ranYeri,ranAdi,ranSoyad,ranUnvan,tel,not,ranDurum);
						}
					}
					fclose(gecmisRandevu);
					secim=0;


				}
				while(secim==2){
					printf(" **** Gelecek Randevular **** \n");
				FILE *bekleyenRandevu;
					bekleyenRandevu=fopen("randevu.txt","r");
					int tarih1,saat1,tel1,ranDurum1,ranNo1;
					int durum1 = 1;
					char *ranYeri1=malloc(sizeof(char)*100);
					char *ranAdi1=malloc(sizeof(char)*100);
					char *ranSoyad1=malloc(sizeof(char)*100);
					char *ranUnvan1 = malloc(sizeof(char)*100);
					char *not1 = malloc(sizeof(char)*100);
					while(!feof(bekleyenRandevu)){
						fscanf(bekleyenRandevu, "%d %d %d %s %s %s %s %d %s %d\n",
    		&ranNo1,&tarih1,&saat1,ranYeri1,ranAdi1,ranSoyad1,ranUnvan1,&tel1,not1,&ranDurum1);
						if(ranDurum1 == durum1){
							printf("%d %d %d %s %s %s %s %d %s %d\n",
			ranNo1,tarih1,saat1,ranYeri1,ranAdi1,ranSoyad1,ranUnvan1,tel1,not1,ranDurum1);
						}
					}
					fclose(bekleyenRandevu);
					secim=0;

				}

				printf("\n");
				printf("Baþka Randevu Görüntülemek Ýster misiniz? (Evet:4, Ana Menü:0, Çýkýþ:6)\n");
				printf("Tercih --> ");
				fflush(stdout);
				scanf("%d",&tercih);

			}
			while(tercih == 5){
				printf(" **** Randevu Durumu Düzenleme Ekraný **** \n");

				FILE *guncelleDurum;
				guncelleDurum=fopen("randevu.txt","r");
					int tarih0,saat0,tel0,ranDurum0,ranNo0;
					char *ranYeri0=malloc(sizeof(char)*100);
					char *ranAdi0=malloc(sizeof(char)*100);
					char *ranSoyad0=malloc(sizeof(char)*100);
					char *ranUnvan0 = malloc(sizeof(char)*100);
					char *not0 = malloc(sizeof(char)*100);
					while(!feof(guncelleDurum)){
						fscanf(guncelleDurum, "%d %d %d %s %s %s %s %d %s %d\n",
			&ranNo0,&tarih0,&saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,&tel0,not0,&ranDurum0);
						printf("%d %d %d %s %s %s %s %d %s %d\n",
			ranNo0,tarih0,saat0,ranYeri0,ranAdi0,ranSoyad0,ranUnvan0,tel0,not0,ranDurum0);
					}
					fclose(guncelleDurum);

				printf("Düzenlemek Ýstediðiniz Randevu Durumunun Numarasýný Giriniz.\n");
				struct randevu r1;
				int duzenleDurum;
				FILE *eski_dosya;
				FILE *yeni_dosya;
				eski_dosya = fopen("randevu.txt", "r");
				yeni_dosya = fopen("yeni_dosya.txt", "w+");

				printf("Düzenlenecek id=");
				fflush(stdout);
				scanf("%d", &duzenleDurum);

				int tarih_3,saat_3,tel_3,ranDurum_3,ranNo_3;
				char *ranYeri_3=malloc(sizeof(char)*100);
				char *ranAdi_3=malloc(sizeof(char)*100);
				char *ranSoyad_3=malloc(sizeof(char)*100);
				char *ranUnvan_3 = malloc(sizeof(char)*100);
				char *not_3 = malloc(sizeof(char)*100);
				while (!feof(eski_dosya)) {
					fscanf(eski_dosya, "%d %d %d %s %s %s %s %d %s %d\n", &ranNo_3,&tarih_3, &saat_3,ranYeri_3,
							ranAdi_3,ranSoyad_3,ranUnvan_3,&tel_3,not_3,&ranDurum_3);
					if (duzenleDurum == ranNo_3) {

						printf("Yeni Randevu Durumunu Giriniz :");
						fflush(stdout);
						scanf("%d",&r1.randevuDurumu);

						int durumRandevu = r1.randevuDurumu;

						fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_3, tarih_3, saat_3,
								ranYeri_3,ranAdi_3,ranSoyad_3,ranUnvan_3,tel_3,not_3,durumRandevu);


					} else
						fprintf(yeni_dosya , "%d %d %d %s %s %s %s %d %s %d\n", ranNo_3, tarih_3, saat_3,
								ranYeri_3,ranAdi_3,ranSoyad_3,ranUnvan_3,tel_3,not_3,ranDurum_3);
				}
				fclose(eski_dosya);
				fclose(yeni_dosya);
				remove("randevu.txt");
				rename("yeni_dosya.txt", "randevu.txt");

			printf("--> Randevu Durumu Güncellendi\n");

				printf("\n");
				printf("Baþka Randevu Durumu Düzenlemek Ýster misiniz? (Evet:5, Ana Menü:0, Çýkýþ:6)\n");
				printf("Tercih --> ");
				fflush(stdout);
				scanf("%d",&tercih);
			}
		}
		printf("Program Kapatýlýyor...");


	return 0;
}
