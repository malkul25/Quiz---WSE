#include <stdio.h>

struct element
{
    char poprawna, odczytana;
    struct element* nast;
};

typedef struct element ELEMENT;
typedef ELEMENT* ADRES;

ADRES dodajDoListyP (ADRES pocz, char poprawna)
{
    ADRES pom;
    pom = (ADRES)malloc(sizeof(ELEMENT));
    pom -> poprawna=poprawna;
    if(pocz == NULL)
        pom -> nast=NULL;
    else
        pom -> nast=pocz;
    return pom;
}

void wypiszListeP (ADRES pocz)
{
     ADRES biez=pocz;
    while(biez!=NULL)
    {
        printf("%c ", biez->poprawna);
        biez = biez->nast;
    }
}

ADRES dodajDoListyO (ADRES pocz, char odczytana)
{
    ADRES pom;
    pom = (ADRES)malloc(sizeof(ELEMENT));
    pom->odczytana=odczytana;
    if(pocz == NULL)
        pom -> nast=NULL;
    else
        pom -> nast=pocz;
    return pom;
}

void wypiszListeO(ADRES pocz)
{
     ADRES biez=pocz;
    while(biez!=NULL)
    {
        printf("%c ", biez->odczytana);
        biez = biez->nast;
    }
}

void czyscListeP(ADRES pocz)
{
    ADRES pom;
    while (pocz!=NULL)
    {
        pom=pocz->nast;
        free(pocz);
        pocz=pom;
    }
}
void czyscListeO(ADRES pom)
{
    ADRES pocz;
    while (pom!=NULL)
    {
        pocz=pom->nast;
        free(pom);
        pom=pocz;
    }
}

int main()
{

    int menu=0;
    FILE *plik;
    char pytania[] = "pytania.txt";
    char tresc[100], odpA[50], odpB[50], odpC[50], odpD[50], puste[100];
    char poprawna, odczytana;
    int punkty=0, i=0;

    printf("\n\t\tSPRAWDZ, ILE WIESZ O LAO CHE!\n");
    do
    {
        printf("*********************************************************************\n");
        printf("1.QUIZ\n");
        printf("2.EXIT\n");
        printf("*********************************************************************\n");
        printf("Wybierz opcje (1. albo 2.): \n");
        scanf("%d", &menu);
        fflush(stdin);
        if(menu!=1)
            if(menu!=2)
                printf("Musisz wybrac 1 albo 2!\n");

    }while(menu>=3 || menu==0);
        switch(menu)
        {
            case 1: fopen(pytania,"rt"); break;
            case 2: printf("Koniec quizu\n"); exit(0); break;
        }


   plik = fopen(pytania, "rt");
    if (!plik)
    {
        printf("Nie mozna otworzyc pytan! %s\n", pytania);
        return 0;
    }
        for(i=0;i<=4;i++)
        {
            fgets(puste,100,plik);  puts(puste);
            fgets(tresc,100,plik);  puts(tresc);
            fgets(odpA,50,plik);    puts(odpA);
            fgets(odpB,50,plik);    puts(odpB);
            fgets(odpC,50,plik);    puts(odpC);
            fgets(odpD,50,plik);    puts(odpD);
            poprawna = fgetc(plik);

            printf("\n\tPodaj odpowiedz (A, B, C, D): ");
            scanf("%c",&odczytana);
            fflush(stdin);
            if (odczytana==poprawna)
            {
                printf("\n\tBrawo! Poprawna odpowiedz!\n");
                punkty++;
            }

            else
                printf("\n\tO nie! Nie udalo Ci sie! Poprawna odpowiedz to %c.\n", poprawna);
        }

    fclose(plik);


        if(punkty==5)
            printf("\n\t%d/5!\n\tWysmienicie, jestes prawdziwym fanem!\n", punkty);
        if(punkty==4 || punkty==3)
            printf("\n\t%d/5!\n\tNiezle!\n",punkty);
        if(punkty==1||punkty==2)
            printf("\n\t%d/5!\n\tNie poszlo Ci najlepiej!\n",punkty);
        if(punkty==0)
        printf("\n\t%d/5!\n\tPrzykro mi, musisz sie jeszcze podszkolic!\n", punkty);

    return 0;
}
