#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#define MAX 99
// Erhan Özdoğan 160201039
void ozvektorbul(int r,int matris[MAX][MAX]);
int ozdegerbul(int r,int matris[MAX][MAX],double schur1[r],int sanal[1]);
void nilpotent(int N,long a[][N],long c[][N],long temp[][N]);
void schur(int N,int matris[][N]);
int cark(int donmesayisi);
int determ(int a[MAX][MAX],int n);
int main(){
    int donmesayisi,hangi_islem;
    restart:
    printf("Carkin Donme Sayisini Giriniz: ");
    scanf("%d",&donmesayisi);
    printf("\n");
    hangi_islem=cark(donmesayisi)+1;

    if(hangi_islem==3){
            printf("\nYapilacak Islem= %d. Islem (OZVEKTOR BULMA)\n\n",hangi_islem);
               int i,j,r,a[MAX][MAX],det=0,sanal[1];

    while(1){
    printf("Matrisin Boyutunu Giriniz (Sadece 2): ");
    scanf("%d",&r);
    if(r==2){
        break;
    }

    }

    double schur1[r];

       printf("\nMatrisin Elemanlarini Giriniz:\n");
       for(i=0;i<r;i++){
          for(j=0;j<r;j++){
             scanf("%d",&a[i][j]);

          }
       }
       det=determ(a,r);
       printf("\nVerilen matris:\n");
       for(i=0;i<r;i++){
          for(j=0;j<r;j++)
          {
             printf("%d\t",a[i][j]);
          }
          printf("\n");
       }
       printf("\nMatrisin Determinanti: %d\n",det);

       ozvektorbul(r,a);

    }

//-----------------------------------------------------------------------------------------------------------------------------------------------
    if(hangi_islem==1){
printf("\nYapilacak Islem= %d. Islem (OZDEGER BULMA)\n\n",hangi_islem);

        int i,j,r,a[MAX][MAX],det=0,sanal[1];
while(1){
    printf("Matrisin Boyutunu Giriniz ( 3 e Kadar): ");
    scanf("%d",&r);
    if(r<=3 && r>0)
        break;
}
    double schur1[r];

       printf("\nMatrisin Elemanlarini Giriniz:\n");
       for(i=0;i<r;i++){
          for(j=0;j<r;j++){
             scanf("%d",&a[i][j]);
          }
       }
       det=determ(a,r);
       printf("\nVerilen matris:\n");
       for(i=0;i<r;i++){
          for(j=0;j<r;j++)
          {
             printf("%d\t",a[i][j]);
          }
          printf("\n");
       }
       printf("\nMatrisin Determinanti: %d\n",det);

       ozdegerbul(r,a,schur1,sanal);

    }
    //-----------------------------------------------------------------------------------------------------------------------------------
    else if(hangi_islem==2){
            printf("\nYapilacak Islem= %d. Islem (SCHUR ESITSIZLIGI)\n\n",hangi_islem);
             int i,j,r,a[MAX][MAX];
             while(1){
    printf("Matrisin Boyutunu Giriniz (3 e Kadar): ");
    scanf("%d",&r);
    if(r<=3 && r>0)
        break;
             }
       printf("\nMatrisin Elemanlarini Giriniz:\n");
       for(i=0;i<r;i++){
          for(j=0;j<r;j++){
             scanf("%d",&a[i][j]);
          }
       }
       printf("\nVerilen matris:\n");
       for(i=0;i<r;i++){
          for(j=0;j<r;j++)
          {
             printf("%d\t",a[i][j]);
          }
          printf("\n");
       }
       schur(r,a);
    }
//-----------------------------------------------------------------------------------------------------------------------------------------
   else if(hangi_islem==4){
        printf("\nYapilacak Islem= %d. Islem (NILPOTENT BULMA)\n\n",hangi_islem);
        srand(time(NULL));
    int N=3,i,j;
    printf("Matrisin Boyutunu Giriniz: ");
    scanf("%d",&N);
    long a[N][N],c[N][N],temp[N][N];
    printf("Girilen Matris:\n");
    //Matrise rastgele sayilar atandi ve ayny matris temp matrisine atandy. temp matrisi üs almanyn do?ru çaly?masy için gerekli.
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            a[i][j]=15-rand()%30;
            c[i][j]=0;
            temp[i][j]=a[i][j];

            printf("%4ld ",a[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");
    nilpotent(N,a,c,temp);
    }

        int restart;
        while(restart != 99 || restart != -1){
    printf("\nCikmak icin -1 Yeniden Hesaplama icin 99\n");
    scanf("%d",&restart);
        if(restart == -1){
            printf("\nCikis Yapildi\n");
            break;
        }
        else if(restart == 99){
            printf("\nYeniden Hesaplaniyor\n");
            goto restart;
        }
    }

    return 0;
}
//===========================================================================================================================================================
//===================//CARK DONME DURDURMA VE YAPILACAK ISLEM BELIRLEME //===================================================================================
//===========================================================================================================================================================
int cark(int donmesayisi){

    srand(time(NULL));

int i,olusan_sayi,yapilacak_islem;

printf("Olusan Sayilar:\n");
for(i=1;i<=donmesayisi;i++){
    olusan_sayi=rand()%241;
    printf("%d.Donus=%d\n",i,olusan_sayi);
}
yapilacak_islem=olusan_sayi%4;

return yapilacak_islem;
}
//===========================================================================================================================================================
//==============================// ÖZDEGER BULMA FONKSIYONU //===============================================================================================
//===========================================================================================================================================================

int ozdegerbul(int n, int matris[MAX][MAX],double schur1[],int sanal[]){

    double a,b,c,d,r,s,t,x1,x2,x3,delta;

    FILE*fp;
    fp=fopen("ozdeger.txt","w");
    int son_matris[MAX][MAX],ll,i,j,kk,det=0,es=0;
    fprintf(fp,"Girilen Matris:\n");

    //-----Esas kosegen matris olma kontrolu-----------------
        for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i!=j){
               if(matris[i][j]==0){
                    es=1;
                }
                else{
                    es=0;
                    break;
                }
            }
        }
    }
//-----------------------------------------------------
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        son_matris[i][j]=matris[i][j];
        fprintf(fp,"%d\t",son_matris[i][j]);
    }
    fprintf(fp,"\n");
    }


    int em[3][3];

    for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                em[i][j]=-1*matris[i][j];
            }
        }

    if(es==1){
        printf("\nOzdegerler: ");
        fprintf(fp,"\nOzdegerler: ");
     for(i=0; i<n; i++){
            printf("x%d= %d\t",i+1,matris[i][i]);
            schur1[i]=matris[i][i];
            fprintf(fp,"x%d= %d\t",i+1,matris[i][i]);

     }

    }
    else if(n==1)
    {
        return matris[0][0];
        fprintf(fp,"\nOzdeger: %d",matris[0][0]);
        schur1[0]=matris[0][0];
    }

    else if(n==2)
    {
        a=1, b=em[0][0]+em[1][1], c=em[0][0]*em[1][1]-em[0][1]*em[1][0];
        delta=b*b+(-4*a*c);
        x1=(-1*b+sqrt(delta))/(2*a), x2=(-1*b-sqrt(delta))/(2*a);

        if(delta>0){

            printf("\nOzdegerler: %.2lf, %.2lf",x1,x2);
            fprintf(fp,"\nOzdegerler: %.3lf, %.3lf",x1,x2);
            schur1[0]=x1;schur1[1]=x2;
        }

        else if(delta==0){
            printf("\nOzdeger: %.2lf",x1);
            fprintf(fp,"\nOzdeger: %.2lf",x1);
            schur1[0]=x1;
        }

        else{
            printf("Reel ozdeger yok.");
            fprintf(fp,"\nReel ozdeger yok.");
            sanal[0]=0;

        }

    }
    else if(n==3){

//---------------------- Karakteristik Polinom bulma-------------
        a=1;
        b=em[2][2]+em[0][0]+em[1][1];
        c=em[0][0]*em[1][1]+ (em[0][0]+em[1][1])*em[2][2]- (  em[0][2]*em[2][0]+em[1][2]*em[2][1]+em[0][1]*em[1][0]   );
        d=em[0][0]*em[1][1]*em[2][2]+em[1][0]*em[2][1]*em[0][2]+em[2][0]*em[0][1]*em[1][2] - (   em[0][2]*em[1][1]*em[2][0]+em[1][2]*em[2][1]*em[0][0]+em[2][2]*em[0][1]*em[1][0]     );

        printf("\nMatrisin karakteristik polinomu: %.0lfx^3 + %.0lfx^2 + %.0lfx + %.0lf\n",a,b,c,d);
        fprintf(fp,"\nMatrisin karakteristik polinomu: %.0lfx^3 + %.0lfx^2 + %.0lfx + %.0lf\n",a,b,c,d);
//------------------------------------------------------------------

//------------ 3. Dereceden Polinomun Köklerini Bulma --------------------------------------------------------
// KAYNAK: http://www.dreamincode.net/forums/topic/21670-cubic-equation/page__view__findpost__p__189454
        double e,f,g,h,i,j,k,l,m,n,p,u;
	int w;
	e=2.7182818284590;
	f=((3*c/a)-(b*b/(a*a)))/3;
	g=((2*b*b*b/(a*a*a))-(9*b*c/(a*a))+(27*d/a))/27;
	h=(g*g/4)+(f*f*f/27);
	i=sqrt(((g*g/4)-h));
	j=exp(log10(i)/log10(e)/3);
	k=acos((-1)*(g/(2*i)));
	l=j*(-1);
	m=cos(k/3);
	n=sqrt(3)*sin(k/3);
	p=(b/3*a)*(-1);
	r=(-1)*(g/2)+sqrt(h);
	s=exp(log10(r)/log10(e)/3);
	t=(-1)*(g/2)-sqrt(h);
	u=exp(log10(t)/log10(e)/3);
	if (h>0) w=1;
	if (h<=0) w=3;
	if ((f==0) && (g==0) && (h==0)) w=2;
	switch (w){
	case 1:
		x1=(s+u)-(b/3*a);
		x2=(-1)*(s+u)/2-(b/3*a);
		x3=(s-u)*sqrt(3)/2;
		printf("\n\nOzdegerler:  x1: %.2lf,  x2(sanal): %.2lf +i*%.2lf,  x3(sanal):%.2lf -i*%lf", x1, x2, x3, x2, x3);
		fprintf(fp,"\nOzdegerler:  x1: %.2lf,  x2(sanal): %.2lf +i*%.2lf,  x3(sanal):%.2lf -i*%lf", x1, x2, x3, x2, x3);
		sanal[0]=0;
		break;
	case 2:
		x1=exp(log10(d/a)/log10(e)/3)*(-1);
		printf("\nOzdeger: x1: %.2lf", x1);
		fprintf(fp,"\nOzdeger:  x1: %.2lf",x1);
		schur1[0]=x1;schur1[1]=x1;schur1[2]=x1;
		break;
	case 3:
		x1=2*j*cos(k/3)-(b/3*a);
		x2=l*(m+n)+p;
		x3=l*(m-n)+p;
		printf("\nOzdegerler: x1: %.2lf, x2: %.2lf, x3: %.2lf\n", x1, x2, x3);
		fprintf(fp,"\nOzdegerler: x1: %.2lf, x2: %.2lf, x3: %.2lf\n", x1, x2, x3);
		schur1[0]=x1;schur1[1]=x2;schur1[2]=x3;
		break;
	}
    }

    return 0;
}

//===========================================================================================================================================================
//=================================// DETERMINANT BULMA FONKSIYONU //========================================================================================
//===========================================================================================================================================================
//https://gist.github.com/mertyildiran/8054471 Internet sitesinden alinmistir
int determ(int a[MAX][MAX],int n)
{
  int det=0,p,h,k,i,j,temp[MAX][MAX];
  if(n==1)
  {
      return a[0][0];
  }
  else if(n==2)
  {
      det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
      return det;
  }
  else
  {
    for(p=0;p<n;p++)
    {
       h = 0;
       k = 0;
       for(i=1;i<n;i++)
       {
         for( j=0;j<n;j++)
         {
            if(j==p)
                {
                    continue;
                }
                temp[h][k] = a[i][j];
            k++;
                if(k==n-1)
                {
                      h++;
                      k = 0;
            }
             }
       }
       det=det+a[0][p]*pow(-1,p)*determ(temp,n-1);
    }
    return det;
  }

}
//=======================================================================================================================================================
//===============================// NYLPOTENT MATRYS FONKSYYONU //=======================================================================================
//=======================================================================================================================================================

void nilpotent(int N,long a[][N],long c[][N],long temp[][N]){
    FILE*fp;
    fp=fopen("nilpotent.txt","w");
    int i,j,k,sayac=2;
    //==== NİLPOTENT İÇİN İLK MATRİS DOSYAYA YAZDIRILDI=============================
    fprintf(fp,"Girilen Matris:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
                fprintf(fp,"%10ld",a[i][j]);

        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"-------------------------------------\n");
    //===== MATRIS CARPIMI ============================================================
   Loop:
      for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           c[i][j]=0;
            for(k=0;k<N;k++){
                c[i][j]=c[i][j]+(a[i][k]*temp[k][j]);
            }
        }
    }
    //====== MATRIS YAZDIRILDI ==============================================================
    printf("Matris^%d:\n\n",sayac);
    fprintf(fp,"Matris^%d:\n\n",sayac);

     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%10ld ",c[i][j]);
            fprintf(fp,"%10ld",c[i][j]);

        }
        printf("\n");
        fprintf(fp,"\n");
    }
    printf("\n");
    //=== MATRISIN SIFIR MATRIS OLUP OLMAMASININ KONTROLÜ
   //=== MATRISIN HERHANGI BIR DEGERI SIFIRDAN FARKLI ISE OLUSTURULAN C MATRISI, ÜZREINDE ISLEM YAPILAN A MATRISINE ATANIR VE ÇARPIMA GÖNDERILIR

     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
         if(c[i][j]!=0){
             for(i=0;i<N;i++){
               for(j=0;j<N;j++){
            a[i][j]=c[i][j];
        }
    }
    sayac++;
    if(sayac>10){
            printf("\n");
            printf("Nilpotent Degil.\n");
            printf("%d.Indekse Kadar Denendi.",sayac-1);
        break;
    }
    goto Loop;
           }
        }
    }
    if(sayac!=11){
        printf("Nilpotenttir.");
    }
}

//=========================================================================================================================================================
//=================================// SCHUR FONKSIYONU //==================================================================================================
//=========================================================================================================================================================
void schur(int N,int matris[MAX][MAX]){
   FILE*fp;
    fp=fopen("schur.txt","w");
     int toplam=0,sanal[1];
     double ozdeger_toplam=0;
     int i,j;
     double schur1[N];
     ozdegerbul(N,matris,schur1,sanal);
     if(sanal[0]!=0){
     if(schur1[10]==-999){
        printf("Sanal Ozdegerler Vardir.\n");
        fprintf(fp,"Sanal Ozdegerler Vardir");
     }
     fprintf(fp,"Girilen Matris:\n");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        fprintf(fp,"%d ",matris[i][j]);
        toplam=toplam+(matris[i][j]*matris[i][j]);
    }
    fprintf(fp,"\n");
    ozdeger_toplam=ozdeger_toplam+(schur1[i]*schur1[i]);
}
printf("\nSchur Esitsizligi= %.2lf < %d\n",ozdeger_toplam,toplam);
fprintf(fp,"\nSchur Esitsizligi= %.2lf < %d\n",ozdeger_toplam,toplam);
     }
     else{
        printf("\nMatriste Sanal Kok vardir");
        fprintf(fp,"\nMatriste Sanal Kok vardir");
    }
}
//===========================================================================================================================================================
//=========================// OZVEKTOR FONKSİYONU //=========================================================================================================
//===========================================================================================================================================================

void ozvektorbul(int r,int matris[MAX][MAX]){
    FILE*fp;
    fp=fopen("ozvektor.txt","w");
    int i,j,k,sanal[1];
    // ALT VE UST UCGENSEL MATRISLER ICIN----------------------------------------------------------------------------
    if(r==2  && matris[1][0]==0 && matris[0][1]==0){
        printf("\nMatrisin Ozdegerleri: %d  ,  %d\n",matris[0][0],matris[1][1]);
        fprintf(fp,"\nMatrisin Ozdegerleri: %d  ,  %d\n",matris[0][0],matris[1][1]);
        printf("OZVEKTOR = ( a , b )");
        fprintf(fp,"OZVEKTOR = ( a , b )");
}

   else if(r==2  && matris[1][0]==0 || matris[0][1]==0){
            int tempson2[MAX][MAX];
        printf("\nMatrisin Ozdegerleri: %d  ,  %d\n",matris[0][0],matris[1][1]);
        fprintf(fp,"\nMatrisin Ozdegerleri: %d  ,  %d\n",matris[0][0],matris[1][1]);
        for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                tempson2[i][j]=matris[i][j];
            }
        }
        printf("\n\n-------- OZDEGER = %d ICIN: ---------\n",matris[0][0]);
        fprintf(fp,"\n\n-------- OZDEGER = %d ICIN: ---------\n",matris[0][0]);

        for(i=0;i<r;i++){
            tempson2[i][i]=tempson2[i][i]-matris[0][0];
        }
        for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                printf("%d ",tempson2[i][j]);
                fprintf(fp,"%d ",tempson2[i][j]);
            }
            printf("\n");
            fprintf(fp,"\n");
        }
        printf("\n\n");
        fprintf(fp,"\n\n");
        printf("%d * a + %d * b = 0\n",tempson2[0][0],tempson2[0][1]);
        fprintf(fp,"%d * a + %d * b = 0\n",tempson2[0][0],tempson2[0][1]);
        printf("%d * a + %d * b = 0\n\n",tempson2[1][0],tempson2[1][1]);
        fprintf(fp,"%d * a + %d * b = 0\n\n",tempson2[1][0],tempson2[1][1]);
        // ust ucgensel icin
        if(matris[0][1]==0){
                printf("a = %.2lf\n\n",(0-tempson2[1][0])/(double)tempson2[1][1]);
                fprintf(fp,"a = %.2lf\n\n",(0-tempson2[1][0])/(double)tempson2[1][1]);
                printf("OZVEKTOR = b * ( %.2lf , 1 )\n",(0-tempson2[1][0])/(double)tempson2[1][1]);
                fprintf(fp,"OZVEKTOR = b * ( %.2lf , 1 )\n",(0-tempson2[1][0])/(double)tempson2[1][1]);

        }
        //alt ucgensel ıcın
        else{
        printf("a = 0\n");
        fprintf(fp,"a = 0\n");
        printf("a = 0\n\n");
        fprintf(fp,"a = 0\n");
        printf("OZVEKTOR = b * ( 1 , 0 )\n");
        fprintf(fp,"OZVEKTOR = b * ( 1 , 0 )\n");
        }

        for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                tempson2[i][j]=matris[i][j];
            }
        }

        printf("\n\n-------- OZDEGER = %d ICIN: ---------\n",matris[1][1]);
        fprintf(fp,"\n\n-------- OZDEGER = %d ICIN: ---------\n",matris[1][1]);

        for(i=0;i<r;i++){
            tempson2[i][i]=tempson2[i][i]-matris[1][1];
        }
        for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                printf("%d ",tempson2[i][j]);
                fprintf(fp,"%d ",tempson2[i][j]);
            }
            printf("\n");
            fprintf(fp,"\n");

        }
        printf("\n\n");
        fprintf(fp,"\n\n");
        printf("%d * a + %d * b = 0\n",tempson2[0][0],tempson2[0][1]);
        fprintf(fp,"%d * a + %d * b = 0\n",tempson2[0][0],tempson2[0][1]);
        printf("% d * a + %d * b = 0\n\n",tempson2[1][0],tempson2[1][1]);
        fprintf(fp,"% d * a + %d * b = 0\n\n",tempson2[1][0],tempson2[1][1]);
        printf("a = b * %.2lf\n",(0-tempson2[0][1])/(double)tempson2[0][0]);
        fprintf(fp,"a = b * %.2lf\n",(0-tempson2[0][1])/(double)tempson2[0][0]);

        printf("\nOZVEKTOR = b * ( %.2lf , 1 )\n",(0-tempson2[0][1])/(double)tempson2[0][0]);
        fprintf(fp,"\nOZVEKTOR = b * ( %.2lf , 1 )\n",(0-tempson2[0][1])/(double)tempson2[0][0]);



    }
    //NORMAL MATRISLER ICIN----------------------------------------------------------------------------------------------

    else if(r==2 && sanal[0]!=0){
            double schur1[2],tempson1[MAX][MAX];
    ozdegerbul(r,matris,schur1,sanal);
    printf("\n------------------------------------------------------------\n");
    fprintf(fp,"\n---------------------------------------------------------\n");


    // her bir ozdeger sırayla calısması icin k her bir ozdeger cıkarılıp islem yapidiktan sonra matris eski haline dondurulur
    for(k=0;k<2;k++){
            printf("\n\n-------- OZDEGER= %.2lf ICIN: ---------\n",schur1[k]);
            fprintf(fp,"\n\n-------- OZDEGER= %.2lf ICIN: ---------\n",schur1[k]);
             for(i=0;i<r;i++){
        for(j=0;j<r;j++){
                tempson1[i][j]=matris[i][j];
        }
    }
    for(i=0;i<r;i++){
        tempson1[i][i]=(tempson1[i][i]-schur1[k]);
    }

    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
                printf("%4.2lf ",tempson1[i][j]);
                fprintf(fp,"%4.2lf ",tempson1[i][j]);

        }
        printf("\n");
        fprintf(fp,"\n");
    }
    printf("\n");
    fprintf(fp,"\n");
    printf("%4.2lf * a + %4.2lf * b = 0\n",tempson1[0][0],tempson1[0][1]);
      fprintf(fp,"%4.2lf * a + %4.2lf * b = 0\n",tempson1[0][0],tempson1[0][1]);
    printf("%4.2lf * a + %4.2lf * b = 0\n\n",tempson1[1][0],tempson1[1][1]);
      fprintf(fp,"%4.2lf * a + %4.2lf * b = 0\n\n",tempson1[1][0],tempson1[1][1]);
    printf("a = b * %.2lf\n",(0-tempson1[0][1])/tempson1[0][0]);
      fprintf(fp,"a = b * %.2lf\n",(0-tempson1[0][1])/tempson1[0][0]);
    printf("a = b * %.2lf\n\n",(0-tempson1[1][1])/(tempson1[1][0]));
      fprintf(fp,"a = b * %.2lf\n\n",(0-tempson1[1][1])/tempson1[1][0]);
    printf("OZVEKTOR = b * ( %.2lf , 1 )",(0-tempson1[1][1])/tempson1[1][0]);
      fprintf(fp,"OZVEKTOR = b * ( %.2lf , 1 )",(0-tempson1[1][1])/(tempson1[1][0]));
    }

    }
}

