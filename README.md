# Zaliczenie przedmiotu Narzędzia procesu tworzenia oprogramowania - Informatyka Stosowana WSE 2024

**Wykonała: Małgorzata Kulik**
Repozytorium zawiera aplikacje zaliczeniową wykonaną w jezyku C
Aby uruchomić aplikacje należy


Kontakt e-mail: gosia.kulik222@gmail.com

Link do projektu:


##**Opis**
Aplikacja powstała w ramach zaliczeń zajęć Narzędzia procesu tworzenia oprogramowania. Wczytuje pytania i odpowiedzi z pliku tekstowego oraz pozwala na udzielenie na nie odpowiedzi. Zlicza punkty za poprawnie udzieloną odpowiedź, a pod koniec pliku je wyświetla.

###**Funkcje**
**ADRES dodajDoListyP (ADRES pocz, char poprawna)** - funkcja odpowiada za dodanie poprawnej odpowiedzi do listy;
**void wypiszListeP (ADRES pocz)** - funkcja odpowiada za wypisanie listy z poprawnie udzielonymi odpowiedziami;
**ADRES dodajDoListyO (ADRES pocz, char odczytana)** - funkcja odpowiada za dodanie do listy odpowiedzi udzielonych przez użytkownika;
**void wypiszListeO(ADRES pocz)** - funkcja odpowiada za wypisanie listy odpowiedzi udzielonych przez użytkownika;
**void czyscListeP(ADRES pocz)** - funkcja odpowiada za wyczyszczenie listy poprawnie udzielonych odpowiedzi;
**void czyscListeO(ADRES pocz)** - odpowiada za wyczyszczenie listy odczytanych odpowiedzi;
W funkcji main zaimplementowany jest cały quiz, wywoływane są wyżej wymienione funkcje.
####**Obsługa aplikacji**
Aby uruchomić aplikację Nalezy skompilować program. Następnie wyświetli się menu w konsoli. Naciskając 2, wychodzimy z konsoli, a naciskając 1, uruchamiamy quiz, pojawia sie pierwsze pytanie wraz z odpowiedziami. Odpowiadamy wielkimi literami. Po udzieleniu odpowiedzi wyswietla sie komunikat i przechodzimy do kolejnego pytania. Program zlicza punkty i po ukończeniu quizu program wyświetla zdobyte punkty wraz z komentarzem.
