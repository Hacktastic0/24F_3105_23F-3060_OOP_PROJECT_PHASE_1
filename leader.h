#pragma once 

class Society;
enum LeaderType
{
    King = 1,
    Council = 2,
    Dictator = 3
};

class Leader
{ 
    LeaderType type;
    int popularity;
public:
    Leader();
    void leadershipEffect(Society& s);
    void coup(Society& s);
};
