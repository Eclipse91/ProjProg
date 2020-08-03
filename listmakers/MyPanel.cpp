//
// Created by myself on 6/9/20.
//

#include "MyPanel.h"

MyPanel::MyPanel(Model* m, Controller* c,
                 wxWindow *parent,
                 wxWindowID id,
                 const wxPoint& pos,
                 const wxSize& size)
        :wxPanel(parent, id, pos, size)
{
    model = m;
    controller = c;
    listName=new wxStaticText(this,wxID_ANY,wxString(),wxPoint(5,2));
    deleteList=new wxButton(this,wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
    deleteList->SetForegroundColour(wxColor(255,0,0,0));
    deleteList->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::DeleteList,this);
    rightList=new wxButton(this,wxID_ANY,"->",wxPoint(295,0),wxSize(25,20));
    rightList->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::MoveRight,this);
    leftList=new wxButton(this,wxID_ANY,"<-",wxPoint(272,0),wxSize(25,20));
    leftList->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::MoveLeft,this);

    frontPanel=new wxPanel(this,wxID_ANY,wxPoint(5,20),wxSize(330,420));
    frontPanel->SetBackgroundColour(wxColor(60,60,110,60));
    newCard=new wxButton(frontPanel,wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
    newCard->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyPanel::NewCard,this);
    txt=new wxTextCtrl(frontPanel,wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
}

void MyPanel::DeleteList(wxCommandEvent & evt) {
    controller->DeleteList(std::string(listName->GetLabel()));
}

void MyPanel::NewCard(wxCommandEvent &evt) {
    if(txt->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write something on the card"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else{
        int exist=0;
        for(auto name:*model->getCard()) {
            if(std::string(txt->GetValue())==name){
                exist++;
            }
        }
        if(exist){
            wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                        wxT("This card already exist"), wxT("Exclamation"),
                                                        wxOK | wxICON_EXCLAMATION);
            dial->ShowModal();
        }else{
            controller->AddCard(std::string(listName->GetLabel()),std::string(txt->GetValue()));
        }
    }
}

void MyPanel::MoveLeft(wxCommandEvent &evt) {
    controller->MoveListLeft(std::string(listName->GetLabel()));
}

void MyPanel::MoveRight(wxCommandEvent &evt) {
    controller->MoveListRight(std::string(listName->GetLabel()));

}