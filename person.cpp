#include "person.h"
#include "society.h"

person::person()
{
        type = static_cast<PersonType>(rand() % 10);//assing random role to a person  
        name = n.names[rand() % 20];
        age = rand() % 70;
    
}  
string getCitizenTypeName(PersonType type)
{
    switch (type)
    {
    case Peasant:
        return "Peasant";
    case Merchant:
        return "Merchant";
    case Noble:
        return "Noble";
    case Blacksmith:
        return "Blacksmith";
    case Farmer:
        return "Farmer";
    case Scholar:
        return "Scholar";
    case Doctor:
        return "Doctor";
    case Servant:
        return "Servant";
    case Baker:
        return "Baker";
    case Hunter:
        return "Hunter";
    default: return "Unknown";
    }
}

void person::display()
{
    cout << "NAME : " << name<<"\nAGE : "<<age<<"\nROLE  : "<<getCitizenTypeName(type)<<endl;
} 
name n = 
{
    {
    "Ayesha",
    "Hassan",
    "Fatima",
    "Ahmed",
    "Zainab",
    "Usman",
    "Sara",
    "Bilal",
    "Mariam",
    "Ali",
    "Hina",
    "Imran",
    "Nadia",
    "Omar", 
    "Sana",
    "Kashif",
    "Laiba",
    "Daniyal",
    "Iqra",
    "Hamza"
    } 
};
