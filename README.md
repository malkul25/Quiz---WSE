#                                            QUIZ
## Zaliczenie przedmiotu narzędzia procesu tworzenia oprogramowania Informatyka Stosowana WSE 2024 #




### **Wprowadzenie**
Aplikacja powstała na zaliczenie przedmiotu. Jest to standardowy quiz z pytaniami i jedną poprawną odpowiedzią. Wczytuje pytania, na które należy udzielić odpowiedzi z pliku tekstowego. Zlicza punkty za poprawnie udzieloną odpowiedź, a po ukończeniu quizu wyświetla wyniki.

### **Technologie**
Aplikacja napisana w języku C.
Zawiera standardową bibliotekę <stdio.h>.

### **Funkcje**
- **ADRES dodajDoListyP(ADRES pocz, char poprawna)** - funkcja odpowiada za dodanie poprawnej odpowiedzi do listy;
- **void wypiszListeP(ADRES pocz)** - funkcja odpowiada za wypisanie listy z poprawnie udzielonymi odpowiedziami;
- **ADRES dodajDoListyO(ADRES pocz, char odczytana)** - funkcja odpowiada za dodanie do listy odpowiedzi udzielonych przez użytkownika;
- **void wypiszListeO(ADRES pocz)** - funkcja odpowiada za wypisanie listy odpowiedzi udzielonych przez użytkownika;
- **void czyscListeP(ADRES pocz)** - funkcja odpowiada za wyczyszczenie listy poprawnie udzielonych odpowiedzi;
- **void czyscListeO(ADRES pocz)** - odpowiada za wyczyszczenie listy odczytanych odpowiedzi;

 W funkcji main zaimplementowany jest cały quiz oraz wywoływane są wyżej wymienione funkcje.

### **Uruchomienie aplikacji**
Aby uruchomić aplikację należy pobrać plik main.c oraz plik pytania.txt z [repozytorium](https://github.com/malkul25/Quiz---WSE). Należy zapisać oba pliki w tym samym folderze, następnie za pomocą kompilator GCC skompilować kod.


+ Wykonała: Małgorzata Kulik
+ Kontakt e-mail: gosia.kulik222@gmail.com


