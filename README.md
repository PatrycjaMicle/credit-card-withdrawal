# Program controlling credit card withdrawals

You can set a customer and choose a credit card for him. 
Set a balance , withdraw, show balance.
For now the program works in the console.

## Instructions
As example we set already 2 customers and credit cards for them in a main function. 
You can clear the main function to set your own customers.

After clearing set up the function as follow:

1.Create a new customer
 
To create a new customer write :
 "customer @name" - @name: set a name for your customer.

2.Set a credit card
To set a credi card for him use: 
"@name.mCustomer=CustomerState::@status" - @status:"Standard" or "Premium".


<p align="center">
    <img src="https://github.com/PatrycjaMicle/credit-card-withdrawal/blob/main/images/Screenshot1.jpg?raw=true" alt="app_screenshot" />
</p>

3.Use functions to showing balance and withdrawing the money.

withdrawMoney(@name,@amount) - @amount: how much money do you want to withdraw. If you want to add money to an account write minus. for example -50.

<p align="center">
    <img src="https://github.com/PatrycjaMicle/credit-card-withdrawal/blob/main/images/Screenshot2.jpg?raw=true" alt="app_screenshot" />
</p>

showBalance(@name.mCreditCard)

<p align="center">
    <img src="https://github.com/PatrycjaMicle/credit-card-withdrawal/blob/main/images/Screenshot3.jpg?raw=true" alt="app_screenshot" />
</p>


## Used technologies

C++
