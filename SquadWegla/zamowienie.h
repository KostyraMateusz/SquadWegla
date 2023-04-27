#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H
#include "wegiel.h"

class Zamowienie
{
private:
   int ilosc;
   Wegiel wegiel;

public:
   // Konstruktory
   Zamowienie();

   // Akcesory
   void setIlosc(int _ilosc);
   void setWegiel(Wegiel _wegiel);
   int getIlosc();
   Wegiel getWegiel();

};

#endif // ZAMOWIENIE_H
