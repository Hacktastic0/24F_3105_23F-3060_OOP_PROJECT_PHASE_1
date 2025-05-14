#include "leader.h"
#include "society.h"

Leader::Leader()
{
    type = static_cast<LeaderType>(rand() % 3 + 1);
    popularity = 20;
}

void Leader::leadershipEffect(Society& s)
{
    if (type == King)
    {
        if (s.happines < 10)
            s.happines += popularity / 20;
    }
    if (type == Council)
        if (s.tax > 0)
            s.tax -= 1;
    if (type == Dictator)
        s.money += 100;  
} 

void Leader::coup(Society& s)
{
    if (rand() % 100 > popularity)
    {
        type = static_cast<LeaderType>(rand() % 3 + 1);
        popularity = 50;
    }
    else 
        popularity -= 10;
}
