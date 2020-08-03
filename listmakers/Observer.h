//
// Created by myself on 6/7/20.
//

#ifndef LISTMAKER04_OBSERVER_H
#define LISTMAKER04_OBSERVER_H

#include <iostream>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
//#include <wx/wx.h>

class Observer {
public:
    virtual ~Observer(){}
    virtual void update()=0;
};
#endif //LISTMAKER04_OBSERVER_H
