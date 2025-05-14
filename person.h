#pragma once 
#include <iostream> 
using namespace std;

enum PersonType
{
    Peasant = 1,
    Merchant = 2,
    Noble = 3,
    Blacksmith = 4,
    Farmer = 5,
    Scholar = 6,
    Doctor = 7,
    Servant = 8,
    Baker = 9,
    Hunter = 10
};
 
struct name
{
    string names[20];
};
extern name n;
class person
{
    PersonType type;
    string name;
    int age;
public:
    person();
    void display();
};

string getCitizenTypeName(PersonType type);



 