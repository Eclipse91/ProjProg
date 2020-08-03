//
// Created by myself on 6/9/20.
//

#ifndef LISTMAKER10_MYCARD_H
#define LISTMAKER10_MYCARD_H

#include "Controller.h"
#include "MyCardFrame.h"

class MyCard:public wxPanel{
public:
    MyCard(std::list<string>* l,std::list<string>* ca,std::list<string>* caf,
           Model* m, Controller* c,
           wxWindow *parent,
           wxWindowID id,
           const wxPoint &pos,
           const wxSize &size);
    wxStaticText*thingToDo;
    wxButton*deleteCard;
    wxButton*infoCard;
    wxButton*UpCard;
    wxButton*DownCard;
    wxButton*LeftCard;
    wxButton*RightCard;
    MyCardFrame*cardFrame;
    wxButton*highPriority;
    wxButton*DeadL;

public:
    void DeleteCard(wxCommandEvent &evt);
    void CardUp(wxCommandEvent &evt);
    void CardDown(wxCommandEvent &evt);
    void OnCardClicked(wxCommandEvent &evt);
    void CardLeft(wxCommandEvent &evt);
    void CardRight(wxCommandEvent &evt);
    void AddFeatures();
    int* numberOfSublist=0;

private:
    Model* model;
    Controller* controller;
    std::list<string>* List;
    std::list<string>* Card;
    std::list<string>* CardFrame;
//    std::list<string>* List=model->getList();
//    std::list<string>* Card=model->getCard();
};


#endif //LISTMAKER10_MYCARD_H
