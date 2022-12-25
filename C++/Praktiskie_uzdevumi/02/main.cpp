// PS > g++ main.cpp program.cpp; ./a.exe

// Izveidot C++ programmu, kura veic sekojošas darbības:
// Attēlo lietotājam sekojošu izvēlni:
// 1: Ievadīt skaitļus
// 2: Rinda
// 3. Steks
// 4. Divi steki (Rinda)
// 5. Jebkuru no STL konteineriem, kas nav doti programmā
// 6. Izvada skaitļu virkni
// 7. Beigt darbību
// Lietotājs ievada vienu no izvēlnēm (1-7) un programma izpilda tās darbību.

// Programmas sākumā jau ir doti 5 skaitļi - tie ir uzglabāti vektorā: 4, 5, 6, 7, 8
// Programma beidz darbību tikai tad, kad ir ievadīta izvēlne 7
// Programma nedrīkst uzkārties. Jāparedz gadījumi, kad ievadīta ir nekorekta izvēlne
// (1) ievadītos skaitļus saglabā vektorā
// (2), (3), (4), (5), (6) - visus skaitļus iegūst no vektora
// (2) - No vektora iegūtos skaitļus pa vienam liek rindā. Kad visi skaitļi ir ievietoti, tad pa vienam ņem laukā un izņemto elementu izdrukā uz ekrāna
// (3) - No vektora iegūtos skaitļus pa vienam liek stekā. Kad visi skaitļi ir ievietoti, tad pa vienam ņem laukā un izņemto elementu izdrukā uz ekrāna
// (4) - No vektora iegūtos skaitļus pa vienam liek pirmajā stekā. Kad visi skaitļi ir ievietoti, tad pa vienam ņem laukā un liek otrajā stekā. Tad pa vienam ņem laukā no otrā steka un izņemto elementu izdrukā uz ekrāna
// (5) - izvēlaties kādu STL konteineri un realizējat viņa darbību ar skaitļiem, kas uzglabāti vektorā
// (6) - Izdrukā uz ekrāna vektorā uzglabātos skaitļus

// Visām darbībām ir jābūt norealizētām kā funkcijām
// Izvēlnes programmā ir norealizētas, izmantojot switch. Visi case gadījumi ir jāapraksta, izmantojot enum tipu.
// Programmas laikā nedrīkst izmantot globāli definētus mainīgos.

// 1. Papildināt ar izvēlni - “map”, kura veic sekojošas darbības:
// Ņem pa vienam skaitlim no vektora un lietotājam prasa ievadīt tā skaitļa tekstuālo vērtību, piemēram, 4 - cetri (bez mīkstinājuma burtiem) un pievieno to map sarakstā (skaitli kā atslēgu, tekstuālo kā vērtību). Tā tiek izdarīts visiem unikāliem skaitļiem vektorā
// Pēc ievades, lietotājam prasa atrast kādu skaitli map sarakstā, ja ievadīto atrod, tad izdrukā uz ekrāna tā tekstuālo atspoguļojumu, ja nē - tad to paziņo lietotājam
// Ja vienu reizi lietotājs ir aizpildījis jau kādam skaitlim tekstuālo vērtību, tad atkārtoti to neprasa. Pat tajā gadījumā, ja vektorā tiek ievadīti jauni skaitļi, kur kāds jau atrodas iekš map. Pēc jaunu skaitļu ievades vektorā, visi neaktuālie skaitļi (tādi, kuri ir map, bet vairs nav skaitļu vektorā) no map ir jāizdzēš laukā.
// 2. Izveidot header failu, kurā ievietot visas funkcijas, kuras ir saistītas ar konteineriem. Funkcijām header failā ir jāatrodas namespace apgabalā MI_Utils. Pievienot header failu programmai un izmantot apgabala MI_Utils funkcijas galvenajā programmā.
// 3. Izdomāt, kādu algoritmu - uzdevumu (kaut cik jēdzīgu), kurā tiktu izmantots “multiset”. Papildināt ar izvēlni

#include "header.hpp"
#include <iostream>
#include <limits>
#include <vector>

#define F first
#define S second

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::vector;

enum Digit
{
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine
};

int main()
{
    vector<double> vector({4, 5, 6, 7, 8});

    cout << "1: Enter numbers" << endl
         << "2: Queue" << endl
         << "3. Stack" << endl
         << "4. Two stack (queue)" << endl
         << "5. Set" << endl
         << "6. Output numbers" << endl
         << "7. End program" << endl
         << "8. Map" << endl
         << "9. Multiset" << endl;

    bool ok = true;
    do
    {
        const Digit choice = static_cast<Digit>((int)MI_Utils::get_number("Choice: "));
        switch (choice)
        {
        case one:
            MI_Utils::first(vector);
            break;
        case two:
            MI_Utils::second(vector);
            break;
        case three:
            MI_Utils::third(vector);
            break;
        case four:
            MI_Utils::fourth(vector);
            break;
        case five:
            MI_Utils::fifth(vector);
            break;
        case six:
            MI_Utils::sixth(vector);
            break;
        case seven:
            ok = false;
            break;
        case eight:
            MI_Utils::eighth(vector);
            break;
        case nine:
            MI_Utils::ninth();
            break;
        default:
            break;
        }
    } while (ok);

    return 0;
}