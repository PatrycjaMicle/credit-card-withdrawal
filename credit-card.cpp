#include <iostream>

enum class CustomerState{
    New,
    Standard,
    Premium
};

enum class CreditCardState{
    New,
    Valid,
    TransferInProgress,
    Invalid,
    Error
};

struct CreditCard{
 CreditCardState mState = CreditCardState::New;
 int mBalance= 100;
};

struct Customer{
CustomerState mCustomer = CustomerState::New;
CreditCard mCreditCard;
};

bool verifystatus(const Customer &cust)
{
    if(cust.mCreditCard.mState==CreditCardState::Invalid){
    return false;
   }
   return true;
    //TODo: Alle Karten muesssen gueltig (valid)sein.

}

void withdrawMoney(Customer &cust,const int amnt )
{
    if (verifystatus(cust)==false){
        std::cerr<<"Karte ist nicht guelitig!"<<std::endl;
    }else if(cust.mCustomer==CustomerState::Standard && cust.mCreditCard.mBalance<amnt){
    std::cerr<<"Du hast nicht genugend Geld auf dem Konto, um die Transaktion durchzuehren."<<std::endl;
    }else{
        cust.mCreditCard.mBalance-=amnt;
    }
    //TODO: Pruefen ob Kunde uebrehaupt Geld abheben darf, Fehler melden, falls nicht
    //TODO:Premium-Kunden duerften sich weiterhin verschulden, standardkunden nicht.
    //TODO: Dann Geld abheben
}

void showBalance(const CreditCard &card)
{
    //TODO:Anlegen wieviel Geld noch auf der Kreditkarte ist
}

int main()
{
    Customer peter;
    Customer John;

    peter.mCustomer=CustomerState::Premium;
    John.mCustomer=CustomerState::Standard;

    std::cout<<"John als Standard Kunde hat zur Verfuegung: "<<John.mCreditCard.mBalance<<std::endl;
    std::cout<<"Peter als Premium Kunde hat zur Verfuegung: "<<peter.mCreditCard.mBalance<<std::endl;

    //TODO: Zeige hier an, wieviel Geld Sie zur Verfuegunghaben

    std::cout<<"Each is going to withdraw some Money: First50, then 100, and finally 200."<<std::endl;

    if(verifystatus(peter)==true){

    }

    withdrawMoney(John,50);
    withdrawMoney(peter,50);

    withdrawMoney(John,100);
    withdrawMoney(peter,100);

    withdrawMoney(John,200);
    withdrawMoney(peter,200);

    std::cout<<"Aktueller Kontostand fuer John: "<<John.mCreditCard.mBalance<<std::endl;
    std::cout<<"Aktueller Kontostand fuer Peter: "<<peter.mCreditCard.mBalance<<std::endl;

    //TODO:Zeige hier an, wie viel Geld beide jetzt zur Verfuegung habene




    return 0;
}
