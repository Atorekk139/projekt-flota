# System Zarządzania Flotą Pojazdów

Konsolowy program napisany w języku C++ realizujący ewidencję pojazdów we flocie, obliczanie kosztów ich eksploatacji, sortowanie oraz walidację danych z wykorzystaniem programowania obiektowego.

## Architektura projektu
- **`Pojazd` (`Pojazd.h`, `Pojazd.cpp`)** – klasa bazowa przechowująca wspólne atrybuty (`marka`, `model`, `rejestracja`, `przebieg`), definiująca wirtualne metody `wypiszSzczegoly` oraz czysto wirtualną `obliczKosztEksploatacji`, a także przeciążone operatory `<` i `<<`.
- **`PojazdOsobowy` oraz `PojazdCiezarowy`** – klasy pochodne dziedziczące publicznie po klasie `Pojazd`, posiadające własne atrybuty (`liczbaMiejsc`, `ladownosc`) oraz przesłaniajace metody wirtualne (`override`).
- **`Flota` (`Flota.h`, `Flota.cpp`)** – klasa zarządzająca kolekcją wskaźników `Pojazd*` (`std::vector`), odpowiadająca za dodawanie pojazdów, sortowanie po koszcie eksploatacji, wyświetlanie listy oraz zwolnienie pamięci w destruktorze.
- **`main.cpp`** – punkt wejścia programu demonstrujący działanie polimorfizmu, sortowania oraz obsługi wyjątków (`try` / `catch`).

## Kompilacja i uruchomienie

### Za pomocą kompilatora MSVC (Developer PowerShell for VS)
```cmd
cl /EHsc main.cpp Pojazd.cpp Flota.cpp /Fe:flota.exe
.\flota.exe
g++ -std=c++17 main.cpp Pojazd.cpp Flota.cpp -o flota
./flota