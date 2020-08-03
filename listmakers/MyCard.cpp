//
// Created by myself on 6/9/20.
//

#include "MyCard.h"

MyCard::MyCard(std::list<string>* l,std::list<string>* ca,std::list<string>* caf,
        Model *m, Controller *c,
        wxWindow *parent,
        wxWindowID id,
        const wxPoint &pos,
        const wxSize &size)
        :wxPanel(parent, id, pos, size)
{
    controller = c;
    List=l;
    Card=ca;
    CardFrame=caf;

    infoCard=new wxButton(this,-1,"+",wxPoint(275,0),wxSize(25,25));
    infoCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::OnCardClicked,this);
    thingToDo=new wxStaticText(this,wxID_ANY,wxString(),wxPoint(10,25));
    deleteCard=new wxButton(this,wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
    deleteCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::DeleteCard,this);
    UpCard=new wxButton(this,wxID_ANY,"^",wxPoint(254,0),wxSize(25,25));
    UpCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::CardUp,this);
    DownCard=new wxButton(this,wxID_ANY,"v",wxPoint(233,0),wxSize(25,25));
    DownCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::CardDown,this);
    LeftCard=new wxButton(this,wxID_ANY,"<-",wxPoint(191,0),wxSize(25,25));
    LeftCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::CardLeft,this);
    RightCard=new wxButton(this,wxID_ANY,"->",wxPoint(212,0),wxSize(25,25));
    RightCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::CardRight,this);
}

void MyCard::DeleteCard(wxCommandEvent &evt) {
    controller->DeleteCard(std::string(thingToDo->GetLabel()));
}
void MyCard::CardRight(wxCommandEvent &evt) {
    std::string NameList;
    for(auto name:*Card){
        if(name==std::string(thingToDo->GetLabel())){
            break;
        }
        NameList=name;
    }
    std::string NewList;
    int count=0;
    for(auto name:*List){
        if(count==1){
            NewList=name;
            break;
        }
        if(name==NameList){
            count=1;
        }
    }
    controller->MoveCardRight(NewList,std::string(thingToDo->GetLabel()));
}

void MyCard::CardLeft(wxCommandEvent &evt) {
    std::string NameList;
    for(auto name:*Card){
        if(name==std::string(thingToDo->GetLabel())){
            break;
        }
        NameList=name;
    }
    std::string NewList;
    for(auto name:*List){
        if(name==NameList){
            break;
        }
        NewList=name;
    }
    controller->MoveCardLeft(NewList,std::string(thingToDo->GetLabel()));
}

void MyCard::CardDown(wxCommandEvent &evt) {
    std::string NameList;
    for(auto name:*Card){
        if(name==std::string(thingToDo->GetLabel())){
            break;
        }
        NameList=name;
    }
    controller->MoveCardDown(NameList,std::string(thingToDo->GetLabel()));
}

void MyCard::CardUp(wxCommandEvent &evt) {
    std::string NameList;
    for(auto name:*Card){
        if(name==std::string(thingToDo->GetLabel())){
            break;
        }
        NameList=name;
    }
    controller->MoveCardUp(NameList,std::string(thingToDo->GetLabel()));
}

void MyCard::OnCardClicked(wxCommandEvent &evt) {
    //controller->notify();
    //MyCardFrame*cardFrame=new MyCardFrame(List,Card,CardFrame,model,controller,numberOfSublist,this,wxID_ANY,thingToDo->GetLabel(),wxPoint(400,400),wxSize(600,600));
    cardFrame=new MyCardFrame(List,Card,CardFrame,model,controller,numberOfSublist,this,wxID_ANY,thingToDo->GetLabel(),wxPoint(400,400),wxSize(600,600));
    cardFrame->Show();
    cardFrame->highPriority=&highPriority;
    cardFrame->DeadL=&DeadL;

    //while(!cardFrame->Show()){}
    //controller->notify();
    //std::cout<<cardFrame->Show()<<std::endl;
    //    MyCardFrame copyCardFrame(*cardFrame);
//    copyCardFrame.Show();
//    evt.Skip();
//    std::cout<<" kkkkkkkkkkkkk "<<std::endl;

}

void MyCard::AddFeatures() {

}


