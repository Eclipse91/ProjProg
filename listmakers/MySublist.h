//
// Created by myself on 6/16/20.
//

#ifndef LISTMAKER41_MYSUBLIST_H
#define LISTMAKER41_MYSUBLIST_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <wx/wx.h>
#include "Controller.h"

class MySublist: public wxPanel {
public:
    MySublist(std::string l, std::string c,
              Model *m, Controller *con,
              int *n,
              wxWindow *parent,
              wxWindowID id,
              const wxString& name,
              const wxPoint& pos,
              const wxSize& size);
    void DeleteSublist(wxCommandEvent &evt);
    void AddSublitsCheck(wxCommandEvent &evt);
    wxCheckBox*checkboxSublist;
private:
    int *number;
    Model* model;
    Controller* controller;
    std::string NameList;
    std::string NameCard;
    std::string NameCheck;
};


#endif //LISTMAKER41_MYSUBLIST_H
