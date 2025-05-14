#include "event.h"
#include "society.h"

Event::Event()
{
    type = static_cast<EventType>(rand() % 4 + 1);
}

void Event::trigger(Society& s)
{
    switch (type)
    {
    case Famine:
        s.food -= s.food / 4;
        break;
    case Disease:
        s.sizeP -= s.sizeP / 10;
        break;
    case War: 
        s.army.pay();  
        s.money -= 200;
        break;
    case Rebellion: 
        if (s.happines > 0)
            s.happines -= 5;
        break;
    }
}
