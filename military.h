#pragma once 
class Society;
class Military
{
    int soldiers;
    int morale;
    int salary;
public:
    Military();
    void train();
    void pay();
    void desertion();
    int getSoldiers(); 
    void setSoliders(int);
};



