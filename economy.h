#pragma once 
class Society;
class Economy
{
    int inflationRate;
public:
    Economy();
    void applyInflation(class Society& s); 
    int getInflation();
    void    setInflation(int);
};
