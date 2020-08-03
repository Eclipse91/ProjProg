//
// Created by myself on 5/1/20.
//

#include "MyCardFrame.h"

MyCardFrame::MyCardFrame(std::list<string>* l,std::list<string>* ca,std::list<string>* caf,
                         Model *m, Controller *c,
                         int *numberOfSublists,
                         wxWindow *parent,
                         wxWindowID id,
                         const wxString& name,
                         const wxPoint& pos,
                         const wxSize& size)
        :wxFrame(parent,id,name,pos,size)
{
    //LEFT PANEL
    leftPanel = new wxPanel(this);
    leftPanel->SetBackgroundColour(wxColor(60,60,110,60));

    //RIGHT PANEL
    rightPanel=new wxPanel(leftPanel,-1,wxDefaultPosition,wxDefaultSize);
    rightPanel->SetBackgroundColour(wxColor(70,70,120,70));

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(rightPanel, 1, wxEXPAND | wxLEFT, 300);
    leftPanel->SetSizer(vbox);
    //END///////////////////////////////////////////////////
    model = m;
    controller = c;
    List=l;
    Card=ca;
    CardFrame=caf;

    //LEFT PANEL
    //Sublist
    sublists=new wxStaticText(leftPanel,wxID_ANY,"SUBLIST",wxPoint(13,10));
    wxButton*addSublist=new wxButton(leftPanel,wxID_ANY,"Add",wxPoint(120,5),wxSize(50,30));
    addSublist->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCardFrame::AddSublist,this);
    nameSublist=new wxTextCtrl(leftPanel,wxID_ANY,"",wxPoint(170,-5),wxSize(100,50));

    //RIGHT PANEL
    //Labels
    labels=new wxStaticText(rightPanel,wxID_ANY,"LABELS",wxPoint(13,10));
    CheckHigh=new wxCheckBox(rightPanel,wxID_ANY,"High Priority",wxPoint(10,30));
    CheckHigh->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCardFrame::AddHighPriority,this);
    CheckDead=new wxCheckBox(rightPanel,wxID_ANY,"Dead Line",wxPoint(10,60));
    CheckDead->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCardFrame::AddDeadLine,this);
    TxtDead=new wxTextCtrl(rightPanel,wxID_ANY,"",wxPoint(100,55),wxSize(100,30));
    //Members
    members=new wxStaticText(rightPanel,wxID_ANY,"MEMBERS",wxPoint(13,110));
    //Move
    MoveCards=new wxStaticText(rightPanel,wxID_ANY,"MOVE TO ANOTHER LIST",wxPoint(13,230));

    DisplayMyCardFrame();
}

void MyCardFrame::AddHighPriority(wxCommandEvent &evt) {
    std::string NameList=GetPanelName();
    std::string CheckPri;
    if(CheckHigh->GetValue()){
        CheckPri="HIGHPRIORITY";
        *highPriority=new wxButton(this->GetParent(),-1,"High priority",wxPoint(0,0),wxSize(100,25));

    }else{
        CheckPri="NOHIGHPRIORITY";
        if(*highPriority){
            delete *highPriority;
        }
    }
    controller->AddHighPriority(NameList,std::string(this->GetLabel()),CheckPri);
}

void MyCardFrame::AddDeadLine(wxCommandEvent &evt) {
    std::string NameList=GetPanelName();
    std::string CheckLine;
    if(TxtDead->GetValue().empty() && CheckDead->GetValue()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write a deadline"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
        CheckDead->SetValue(false);
    }else{
        if(CheckDead->GetValue()){
            CheckLine=TxtDead->GetValue();
            *DeadL=new wxButton(this->GetParent(),-1,TxtDead->GetValue(),wxPoint(100,0),wxSize(94,25));
        }else{
            CheckLine="NODEADLINE";
            if(*DeadL){
                delete *DeadL;
            }
        }
        controller->AddDeadLine(NameList,std::string(this->GetLabel()),CheckLine);
    }
}
void MyCardFrame::AddSublist(wxCommandEvent &evt) {
    std::string NameList=GetPanelName();
    std::string Sublist;

    if(nameSublist->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write a deadline"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else{
        Sublist=nameSublist->GetValue();
        MySublist*phisicSublist=new MySublist(NameList,std::string(this->GetLabel()),model,controller,&num,leftPanel,wxID_ANY,wxString(Sublist),wxPoint(10,40+(num*25)),wxSize(200,25));
        num++;
        controller->AddSublist(NameList,std::string(this->GetLabel()),Sublist,num);

    }
}
std::string MyCardFrame::GetPanelName() {
    std::string NameList;
    for(auto name:*Card){
        if(name==std::string(this->GetLabel())){
            break;
        }
        NameList=name;
    }
    return NameList;
}

void MyCardFrame::DisplayMyCardFrame() {
    std::string NameList=GetPanelName();
    std::list<string>::iterator it1;
    for(std::list<string>::iterator it=CardFrame->begin();it!=CardFrame->end(); it++){
        if(*it==NameList){
            std::advance(it,1);
            if(*it==std::string(this->GetLabel())){
                std::advance(it,1);

                num=std::stoi(*it);
                for(int i=0;i<num;i++){
                    std::advance(it,1);
                    it1=it;
                    std::advance(it,1);
                    MySublist*phisicSublist=new MySublist(NameList,std::string(this->GetLabel()),model,controller,&num,leftPanel,wxID_ANY,wxString(*it1),wxPoint(10,40+(i*25)),wxSize(200,25));
                    phisicSublist->checkboxSublist->SetValue(*it == "1");
                }
                std::advance(it,1);
                std::advance(it,1);
                CheckHigh->SetValue(*it != "NOHIGHPRIORITY");
                std::advance(it,1);
                CheckDead->SetValue(*it != "NODEADLINE");
            }else continue;
        }
    }
    if(CardFrame->empty()){
        num=0;
    }
}

