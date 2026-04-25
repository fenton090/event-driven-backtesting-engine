#ifndef EVENT_H
#define EVENT_H

enum class EventType {
    MARKET,
    SIGNAL,
    ORDER,
    FILL
};

class Event {
public: 
    EventType type;
    virtual ~Event() {}
};

#endif