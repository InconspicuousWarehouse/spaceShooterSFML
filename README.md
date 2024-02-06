# Space Shooter

## Opis projektu
Space Shooter to prosta gra zręcznościowa napisana w języku C++ przy użyciu biblioteki SFML. Celem gry jest zestrzelenie jak największej liczby asteroid, unikając przy tym kolizji z nimi. 

## Wymagania
Aby uruchomić grę, wymagane jest posiadanie zainstalowanej biblioteki SFML oraz środowisko MinGW.

## Instrukcje kompilacji i uruchomienia
1. **Pobranie Repozytorium**: Sklonuj repozytorium gry ze strony GitHub, używając następującej komendy w terminalu:
   git clone https://github.com/InconspicuousWarehouse/spaceShooterSFML.git
2. **Środowisko MinGW**: Upewnij się, że masz zainstalowane i poprawnie skonfigurowane środowisko MinGW na swoim komputerze. Możesz pobrać MinGW ze strony [MinGW.org](https://osdn.net/projects/mingw/).
3. **SFML**: Pobierz i zainstaluj bibliotekę SFML. Możesz pobrać SFML ze strony [SFML website](https://www.sfml-dev.org/download.php).
4. **Kompilacja za pomocą CMake**: Przejdź do katalogu z pobranym repozytorium i utwórz katalog build. Następnie przejdź do katalogu build i skompiluj grę za pomocą CMake, wpisując następujące komendy w terminalu:
   cd spaceShooterSFML
   mkdir build
   cd build
   cmake ..
   cmake --build .
## Uruchomienie gry
Po skompilowaniu gry, możesz uruchomić ją z poziomu terminala lub Eksploratora plików, otwierając plik wykonywalny. Jeśli znajdujesz się w katalogu, gdzie zbudowany został plik wykonywalny, możesz użyć komendy `./Space` w terminalu. Jeśli chcesz uruchomić grę z innego miejsca, podaj pełną ścieżkę do pliku wykonywalnego.

Lub możesz przeprowadzić kompilację i uruchomienie gry w środowisku takim jak CLion lub innym środowisku programistycznym (IDE).
## Jak grać
- Poruszanie się statkiem odbywa się za pomocą klawiszy (w, s, a, d) (góra, dół, lewo, prawo).
- Strzelać można poprzez naciskanie/przytrzymanie lewego przycisku myszy lub spacji. (Przytrzymanie lub naciskanie odpowiednich przycisków będzie powodować wystrzelenie pocisków z ograniczonym odstępem czasu między nimi).
- Gracz posiada 3 życia. Przy kontakcie statku z asteroidą traci jedno życie, wyświetlane w lewym górnym rogu.
- Okno tworzone po uruchomieniu gry jest docelową wielkością planszy jak i wyświetlanej grafiki. (Uwaga: powiększenie okna na cały ekran może powodować błędy).
- Gra kończy się przy 3 kolizji z asteroidą, pojawia się komunikat "Game Over". (Zamknięcie okna może nastąpić przy naciśnięciu 'Esc'-Escape lub tradycyjnym naciśnięciu lewego przycisku myszy na x).
***
# Space Shooter

## Project Description
Space Shooter is a simple arcade game written in C++ using the SFML library. The goal of the game is to shoot down as many asteroids as possible while avoiding collisions with them.

## Requirements
To run the game, you need to have the SFML library installed as well as the MinGW environment.

## Compilation and Execution Instructions
1. **Repository Cloning**: Clone the game repository from GitHub using the following command in the terminal:
git clone https://github.com/InconspicuousWarehouse/spaceShooterSFML.git
2. **MinGW Environment**: Make sure you have MinGW installed and properly configured on your computer. You can download MinGW from [MinGW.org](https://osdn.net/projects/mingw/).
3. **SFML**: Download and install the SFML library. You can download SFML from the [SFML website](https://www.sfml-dev.org/download.php).
4. **Compilation with CMake**: Navigate to the directory with the downloaded repository and create a build directory. Then go to the build directory and compile the game using CMake by entering the following commands in the terminal:
   cd spaceShooterSFML
   mkdir build
   cd build
   cmake ..
   cmake --build .

## Running the Game
After compiling the game, you can run it from the terminal or File Explorer by opening the executable file. If you are in the directory where the executable file was built, you can use the command `./Space` in the terminal. If you want to run the game from a different location, provide the full path to the executable file.

Alternatively, you can compile and run the game in an environment such as CLion or another Integrated Development Environment (IDE).

## How to Play
- Movement of the ship is controlled using the keys (w, s, a, d) (up, down, left, right).
- Shooting is done by pressing/holding the left mouse button or spacebar. (Pressing or holding the corresponding buttons will fire bullets with a limited time interval between them).
- The player has 3 lives. Upon collision with an asteroid, one life is lost, displayed in the top left corner.
- The window created after starting the game is the target size of the board and displayed graphics. (Note: Enlarging the window to full screen may cause errors).
- The game ends after 3 collisions with asteroids, and a "Game Over" message appears. (Closing the window can be done by pressing 'Esc'-Escape or the traditional left mouse button on the x).
