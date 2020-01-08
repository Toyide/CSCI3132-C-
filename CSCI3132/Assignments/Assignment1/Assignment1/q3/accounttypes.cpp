/*  File: accounttypes.cpp
    Implementation of classes accounttypes  */

#include "accounttypes.h"

///////////////////// implementation of account ///////////////////////
account::account(string name, float fee)
{
    owner = name;
    balance = 0;
    withdrawfee = fee;
}

void account::write(ostream & out) const
{
    out << "owner: " << owner << endl;
    out << "balance: " << balance << endl;
    out << "withdrawfee " << withdrawfee << endl; 
}

void account::deposit(float amount)
{
    balance = balance + amount;
}

bool account::withdraw(float amount)
{
    bool result;
    if (amount > balance-withdrawfee) { 
        cout << "Insufficient funds"; 
        result = false;
    } else { 
        balance = balance - amount - withdrawfee;
        result = true;
    }

    return result;
}

float account::getbalance(void) const
{
    return balance;
}

float account::getwithdrawfee(void) const
{
    return withdrawfee;
}

///////////////////// implementation of savingsaccount ///////////////////////


///////////////////// implementation of chequingaccount ///////////////////////
