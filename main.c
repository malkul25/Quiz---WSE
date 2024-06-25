#include <stdio.h>

struct element                    //deklaracja struktury element
{
    char poprawna, odczytana;
    struct element* nast;
};                                //koniec struktury

typedef struct element ELEMENT;
typedef ELEMENT* ADRES;  

ADRES dodajDoListyP (ADRES pocz, char poprawna)   //dodaje poprawną odpowiedź do listy 
{
    ADRES pom;                                    //pom - zmienna pomocnicza typu ADRES, pocz - początek typu ADRES, poprawna - zmienna przechowująca poprawną odpowiedź
    pom = (ADRES)malloc(sizeof(ELEMENT));
    pom -> poprawna=poprawna;
    if(pocz == NULL)
        pom -> nast=NULL;
    else
        pom -> nast=pocz;
    return pom;                                    //zwraca listę poprawnych odpowiedzi szczytanych z pliku
}

void wypiszListeP (ADRES pocz)        //wypisuje listę poprawnych odpowiedzi
{
     ADRES biez=pocz;                   //pocz - początek, biez - bieżąca, obie zmienene typu ADRES
    while(biez!=NULL)
    {
        printf("%c ", biez->poprawna);
        biez = biez->nast;
    }
}                                        //nic nie zwraca

ADRES dodajDoListyO (ADRES pocz, char odczytana)  //dodaje do listy odpowiedzi udzielone przez użytkownika
{
    ADRES pom;                                    //pom - zmienna pomocnicza, pocz - początek, odczytana
    pom = (ADRES)malloc(sizeof(ELEMENT));
    pom->odczytana=odczytana;
    if(pocz == NULL)
        pom -> nast=NULL;
    else
        pom -> nast=pocz;
    return pom;                                   //zwraca wartość zmiennej pomocniczej
}

void wypiszListeO(ADRES pocz)   //tworzy listę odpowiedzi udzielonych przez użytkownika
{
     ADRES biez=pocz;
    while(biez!=NULL)
    {
        printf("%c ", biez->odczytana);
        biez = biez->nast;
    }
}                               //nic nie zwraca

void czyscListeP(ADRES pocz)   //czyści listę poprawnych odpowiedzi
{
    ADRES pom;
    while (pocz!=NULL)
    {
        pom=pocz->nast;
        free(pocz);
        pocz=pom;
    }
}                //nic nie zwraca

void czyscListeO(ADRES pom)    //czyści listę odpowiedzi udzielonych przez użytkownika
{
    ADRES pocz;                //pom - pomocnicza zmienna, pocz - początek
    while (pom!=NULL)
    {
        pocz=pom->nast;
        free(pom);
        pom=pocz;
    }
}                            //nic nie zwraca

int main()
{

    int menu=0;
    FILE *plik;
    char pytania[] = "pytania.txt";
    char tresc[100], odpA[50], odpB[50], odpC[50], odpD[50], puste[100];  //zdefiniowanie buforów
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
            case 1: fopen(pytania,"rt"); break;        //po wybraniu 1. w menu otwiera plik tekstowy
            case 2: printf("Koniec quizu\n"); exit(0); break;
        }


   plik = fopen(pytania, "rt"); //otwarcie pliku do odczytu
    if (!plik)
    {
        printf("Nie mozna otworzyc pytan! %s\n", pytania);  //sprawdza, czy plik istnieje
        return -1;
    }
        for(i=0;i<=4;i++)
        {            //wprowadzenie tekstu z pliku i wyświetenie
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

    fclose(plik);                                  //zamkniecię pliku tekstowego


        if(punkty==5)
            printf("\n\t%d/5!\n\tWysmienicie, jestes prawdziwym fanem!\n", punkty);
        if(punkty==4 || punkty==3)
            printf("\n\t%d/5!\n\tNiezle!\n",punkty);
        if(punkty==1||punkty==2)                                                        //wyświetlanie wyników
            printf("\n\t%d/5!\n\tNie poszlo Ci najlepiej!\n",punkty);
        if(punkty==0)
        printf("\n\t%d/5!\n\tPrzykro mi, musisz sie jeszcze podszkolic!\n", punkty);

    return 0;
}
