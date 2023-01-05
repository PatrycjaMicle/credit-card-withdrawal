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
}

void withdrawMoney(Customer &cust,const int amnt )
{
    if (verifystatus(cust)==false){
        std::cerr<<"Karte ist nicht guelitig!"<<std::endl;
    }else if(cust.mCustomer==CustomerState::Standard && cust.mCreditCard.mBalance<amnt){   //Premimum Customers are allowed to go in minus
    std::cerr<<"Du hast nicht genugend Geld auf dem Konto, um die Transaktion durchzuehren."<<std::endl;
    }else{
        cust.mCreditCard.mBalance-=amnt;
    }

}

void showBalance(const CreditCard &card)
{
    std::cout<<"Du hast noch zur Verfuegung: "<<card.mBalance<<std::endl;
}

int main()
{
    Customer peter;
    Customer John;

    peter.mCustomer=CustomerState::Premium;
    John.mCustomer=CustomerState::Standard;

    std::cout<<"John: ";
    showBalance(John.mCreditCard);
    std::cout<<"Peter: ";
    showBalance(peter.mCreditCard); // showing Balance before withdrawal

    std::cout<<"Each is going to withdraw some Money: First50, then 100, and finally 200."<<std::endl;

    withdrawMoney(John,50);
    withdrawMoney(peter,50);

    withdrawMoney(John,100);
    withdrawMoney(peter,100);

    withdrawMoney(John,200);
    withdrawMoney(peter,200);

    std::cout<<"John: ";            //showing Balance after withdrawal
    showBalance(John.mCreditCard);
    std::cout<<"peter: ";
    showBalance(peter.mCreditCard);


    return 0;
}
