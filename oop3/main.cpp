#include <iostream>
#include "chaynik.h"
#include "kniga.h"
#include "telefon.h"
#include "ruchka.h"
#include "kupyura.h"
using namespace std;

int main() {
    chaynik chaynik;
    kniga kniga;
    telefon telefon;
    gelievaiaRuchka ruchka;
    kupyura kupyura;

    chaynik.setBrand("Bosch");
    chaynik.setPower(2200);
    chaynik.setVolume(1.5);
    chaynik.setIsOn(false);
    chaynik.setIsBoiling(false);

    kniga.setName("Война и мир");
    kniga.setAuthor("Лев Толстой");
    kniga.setNumberOfPages(1225);
    kniga.setIsOpen(false);
    kniga.setCurrentPage(0);

    telefon.setModel("iPhone 13 Pro");
    telefon.setOperatorName("Киевстар");
    telefon.setBatteryLevel(80);
    telefon.setIsOn(true);
    telefon.setIsCalling(false);

    ruchka.setInkColor("синий");
    ruchka.setBrand("Bic");
    ruchka.setIsOpen(false);
    ruchka.setHasInk(true);
    ruchka.setInkLevel(100);

    kupyura.setNominal(500);
    kupyura.setCurrency("гривны");
    kupyura.setIsWhole(true);
    kupyura.setIsInCirculation(true);

    chaynik.turnOn();
    chaynik.heatUp();
    chaynik.describe();
    cout << endl;

    kniga.open();
    kniga.turnPage();
    kniga.describe();
    cout << endl;

    telefon.makeCall();
    telefon.describe();
    cout << endl;

    ruchka.open();
    ruchka.write();
    ruchka.describe();
    cout << endl;

    kupyura.describe();

    return 0;
}