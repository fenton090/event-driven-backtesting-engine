#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <queue>
#include <memory>
#include "Event.h"

using namespace std;

class EventQueue {
private:
    queue<shared_ptr<Event>> queue;

public:
    void push(shared_ptr<Event> event) {
        queue.push(event);
    }

    shared_ptr<Event> pop() {
        if(queue.empty()) return nullptr;

        auto event = queue.front();
        queue.pop();
        return event;
    }

    bool empty() const {
        return queue.empty();
    }

};

#endif