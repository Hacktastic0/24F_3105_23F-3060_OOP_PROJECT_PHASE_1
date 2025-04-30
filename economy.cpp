#include "economy.h"
#include "society.h"
Economy::Economy()
{
    inflationRate = 2;
}

void Economy::applyInflation(Society& s)
{
    if (s.money > 0)
        s.money -= s.money * inflationRate / 100;
    //s.tax += inflationRate / 5; 
}

int Economy::getInflation()
{
    return inflationRate;  
}

void Economy::setInflation(int s )
{
    inflationRate = s;
}
