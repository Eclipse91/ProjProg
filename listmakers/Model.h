//
// Created by myself on 6/7/20.
//

#ifndef LISTMAKER04_MODEL_H
#define LISTMAKER04_MODEL_H

#include "Subject.h"

using namespace std;

class Model : public Subject{
public:
    virtual void addObserver(Observer*o){
        observers.push_back(o);
    }
    virtual void removeObserver(Observer*o){
        observers.remove(o);
    }
    virtual void notify() {
        for (auto observer : observers){
            observer->update();
        }
    }
    std::list<string>* getList(){
        return &List;
    }
    std::list<string>* getCard(){
        return &Card;
    }
    std::list<string>* getCardFrame(){
        return &CardFrame;
    }

private:
    std::list<string> List;
    std::list<string> Card;
    std::list<string> CardFrame;
    std::list<Observer*> observers;
};

#endif //LISTMAKER04_MODEL_H
