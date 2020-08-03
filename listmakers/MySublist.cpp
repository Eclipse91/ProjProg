//
// Created by myself on 6/16/20.
//

#include "MySublist.h"

MySublist::MySublist(std::string l, std::string c,
        Model *m, Controller *con,
        int *n,
        wxWindow *parent,
        wxWindowID id,
        const wxString &name,
        const wxPoint &pos,
        const wxSize &size)
        :wxPanel(parent, id, pos, size)

{
    NameList=l;
    NameCard=c;
    NameCheck=name;
    model = m;
    controller = con;
    number=n;
    wxButton*removeSublist= new wxButton(this,-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MySublist::DeleteSublist,this);
    checkboxSublist=new wxCheckBox(this,wxID_ANY,"",wxPoint(2,2));
    checkboxSublist->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MySublist::AddSublitsCheck,this);
    //checkboxSublist->SetValue(labelsSublist[0]);
    wxStaticText*staticSublist=new wxStaticText(this,wxID_ANY,name,wxPoint(30,4));

}

void MySublist::DeleteSublist(wxCommandEvent &evt) {
    controller->DeleteSublist(NameList,NameCard,NameCheck);
    std::cout<<"AAAAAAAAAAAAAAAAAA"<<std::endl;
    std::cout<<"AAAAAAAAAAAAAAAAAA"<<std::endl;
    std::cout<<"AAAAAAAAAAAAAAAAAA"<<std::endl;
    number--;
    delete this;
}

void MySublist::AddSublitsCheck(wxCommandEvent &evt) {
    //std::cout<<NameList<<NameCard<<NameCheck<<checkboxSublist->GetValue()<<std::endl;
    if(checkboxSublist->GetValue()){
        controller->AddSublistChecker(NameList,NameCard,NameCheck,1);
    }else{
        controller->AddSublistChecker(NameList,NameCard,NameCheck,0);
    }
}
