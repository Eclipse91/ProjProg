//
// Created by myself on 6/7/20.
//

#ifndef LISTMAKER04_SUBJECT_H
#define LISTMAKER04_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){}
    virtual void notify()=0;
    virtual void addObserver(Observer*o)=0;
    virtual void removeObserver(Observer*o)=0;
};

#endif //LISTMAKER04_SUBJECT_H
