#pragma once 

class Society;
enum EventType
{
    Famine = 1,
    Disease = 2,
    War = 3,
    Rebellion = 4
};

class Event
{
    EventType type;
public:
    Event();
    void trigger(class Society& s);
};

