//
// Created by myself on 3/28/20.
//

#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame,wxMDIParentFrame)
                EVT_MENU(10001,MyFrame::OnMenuNew)
                EVT_MENU(10002,MyFrame::OnMenuOpen)
                EVT_MENU(10003,MyFrame::OnMenuSave)
                EVT_MENU(10004,MyFrame::OnMenuExit)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(): wxFrame(nullptr,wxID_ANY,"wxListMaker",wxPoint(50,50),wxSize(1410,615)) {
    m_MenuBar=new wxMenuBar();
    this->SetMenuBar(m_MenuBar);

    wxMenu *menuFile=new wxMenu();
    menuFile->Append(10001,"New");
    menuFile->Append(10002,"Open");
    menuFile->Append(10003,"Save");
    menuFile->Append(10004,"Exit");

    m_MenuBar->Append(menuFile,"File");


    topPanel = new wxPanel(this);
    topPanel->SetBackgroundColour(wxColor(60,60,110,60));

    bottomPanel=new wxPanel(topPanel,-1,wxDefaultPosition,wxDefaultSize);
    bottomPanel->SetBackgroundColour(wxColor(127,127,127,127));

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(bottomPanel, 1, wxEXPAND | wxTOP, 100);
    topPanel->SetSizer(vbox);

    wxButton*Creator=new wxButton(topPanel,wxID_ANY,"Add List",wxPoint(10,35),wxSize(160,30));
    Creator->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListCreator,this);
    nameList= new wxTextCtrl(topPanel,wxID_ANY,wxEmptyString,wxPoint(13,10),wxSize(155,20));
}
//MENUBAR/////////////////////////////////////////
void MyFrame::OnMenuNew(wxCommandEvent &evt) {
    DeleteEverything();
}
void MyFrame::OnMenuOpen(wxCommandEvent &evt) {
    wxFileDialog dlg(this,"OpenFile","","",".txt Files (*.txt)|*.txt",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal()==wxID_OK){
        Open(dlg.GetPath());
    }
    evt.Skip();
}
bool MyFrame::Open(wxString fileName) {
    DeleteEverything();

    std::ifstream infile;
    infile.open(fileName);
    std::string Temp;

    int line=0,j=1,partialList=0,forMembers=0, toSublist=0;
    while (std::getline(infile, Temp)){

        if(line==0){
            std::string iperTemp;
            iperTemp=Temp;
            countList= std::stoi(iperTemp);//Get number of lists
            if(countList==0)break;
        }
        if(line>=1 && line<=countList){
            std::string iperTemp;
            iperTemp=Temp;
            wxString myString(iperTemp);
            ListTitle[line-1]=myString;//Get names of lists
        }

        if(Temp=="#StOp#"){
            line=9;
        }

        if(line>=10 && Temp!="#NoNe#" && line<=13){
            std::string iperTemp;
            iperTemp=Temp;
            numCard[line-10]=std::stoi(iperTemp);
        }

        //LISTS//////////////////////////////////////////////////////////////////
        if(Temp=="#LiSt1#"){
            line=19;
        }
        if(line>=20 && Temp!="#NoNe#" && line<=119){
            std::string iperTemp;
            iperTemp=Temp;
            wxString myString(iperTemp);
            if(Temp=="#LiSt2#"){
            }
            else{
                if(line==20*j){
                    ListCardTitle[j-1]=myString;//Get names of cards
                    j=j+1;
                }
                if(line==20*(j-1)+1){//HIGH PRIORITY
                    ListHighPriority[j-2]=myString;
                }
                if(line==20*(j-1)+2){//DEADLINE
                    ListDeadLine[j-2]=myString;
                }
                if(line==20*(j-1)+3){//MEMBERS
                    NumberMembers[j-2]= std::stoi(iperTemp);
                    forMembers=(j-2)*3;
                }
                if(line>=20*(j-1)+4 && line<20*(j-1)+4+NumberMembers[j-2]){
                    ListMemberLine[forMembers]=myString;
                    forMembers=forMembers+1;
                }
                if(line==20*(j-1)+7){//SUBLIST
                    NumberSublist[j-2]= std::stoi(iperTemp);
                    toSublist=(j-2)*12;

                }
                if(line>=20*(j-1)+8 && line<20*(j-1)+8+NumberSublist[j-2]*2) {
                    ListSublistLine[toSublist]=myString;
                    toSublist=toSublist+1;

                }
            }
        }
        if(Temp=="#LiSt2#"){
            line=219;
        }
        if(line>=220 && Temp!="#NoNe#" && line<=319){
            std::string iperTemp;
            iperTemp=Temp;
            wxString myString(iperTemp);
            partialList=numCard[0];
            if(Temp=="#LiSt3#"){
            }
            else{
                if(line==200+20*(j-partialList)){
                    ListCardTitle[j-1]=myString;//Get names of cards
                    j=j+1;
                }
                if(line==200+20*(j-partialList-1)+1){
                    ListHighPriority[j-2]=myString;
                }
                if(line==200+20*(j-partialList-1)+2){
                    ListDeadLine[j-2]=myString;
                }
                if(line==200+20*(j-partialList-1)+3){//MEMBERS
                    NumberMembers[j-2]= std::stoi(iperTemp);
                    forMembers=(j-2)*3;
                }
                if(line>=200+20*(j-partialList-1)+4 && line<=200+20*(j-partialList-1)+4+NumberMembers[j-2]){
                    ListMemberLine[forMembers]=myString;
                    forMembers=forMembers+1;
                }
                if(line==200+20*(j-partialList-1)+7){//SUBLIST
                    NumberSublist[j-2]= std::stoi(iperTemp);
                    toSublist=(j-2)*12;

                }
                if(line>=200+20*(j-partialList-1)+8 && line<200+20*(j-partialList-1)+8+NumberSublist[j-2]*2) {
                    ListSublistLine[toSublist]=myString;
                    toSublist=toSublist+1;
                }
            }
        }
        if(Temp=="#LiSt3#"){
            line=419;
        }
        if(line>=420 && Temp!="#NoNe#" && line<=519){
            std::string iperTemp;
            iperTemp=Temp;
            wxString myString(iperTemp);
            partialList=numCard[0]+numCard[1];

            if(Temp=="#LiSt4#"){
            }
            else{
                if(line==400+20*(j-partialList)){
                    ListCardTitle[j-1]=myString;//Get names of cards
                    j=j+1;
                }
                if(line==400+20*(j-partialList-1)+1){
                    ListHighPriority[j-2]=myString;
                }
                if(line==400+20*(j-partialList-1)+2){
                    ListDeadLine[j-2]=myString;
                }
                if(line==400+20*(j-partialList-1)+3){//MEMBERS
                    NumberMembers[j-2]= std::stoi(iperTemp);
                    forMembers=(j-2)*3;
                }
                if(line>=400+20*(j-partialList-1)+4 && line<=400+20*(j-partialList-1)+4+NumberMembers[j-2]){
                    ListMemberLine[forMembers]=myString;
                    forMembers=forMembers+1;
                }
                if(line==400+20*(j-partialList-1)+7){//SUBLIST
                    NumberSublist[j-2]= std::stoi(iperTemp);
                    toSublist=(j-2)*12;

                }
                if(line>=400+20*(j-partialList-1)+8 && line<400+20*(j-partialList-1)+8+NumberSublist[j-2]*2) {
                    ListSublistLine[toSublist]=myString;
                    toSublist=toSublist+1;
                }
            }
        }
        if(Temp=="#LiSt4#"){
            line=619;

        }
        if(line>=620 && Temp!="#NoNe#" && line<=719){
            std::string iperTemp;
            iperTemp=Temp;
            wxString myString(iperTemp);
            partialList=numCard[0]+numCard[1]+numCard[2];
            if(line==600+20*(j-partialList)){
                ListCardTitle[j-1]=myString;//Get names of cards
                j=j+1;
            }
            if(line==600+20*(j-partialList-1)+1){
                ListHighPriority[j-2]=myString;
            }
            if(line==600+20*(j-partialList-1)+2){
                ListDeadLine[j-2]=myString;
            }
            if(line==600+20*(j-partialList-1)+3){//MEMBERS
                NumberMembers[j-2]= std::stoi(iperTemp);
                forMembers=(j-2)*3;
            }
            if(line>=600+20*(j-partialList-1)+4 && line<=600+20*(j-partialList-1)+4+NumberMembers[j-2]){
                ListMemberLine[forMembers]=myString;
                forMembers=forMembers+1;
            }
            if(line==600+20*(j-partialList-1)+7){//SUBLIST
                NumberSublist[j-2]= std::stoi(iperTemp);
                toSublist=(j-2)*12;

            }
            if(line>=600+20*(j-partialList-1)+8 && line<600+20*(j-partialList-1)+8+NumberSublist[j-2]*2) {
                ListSublistLine[toSublist]=myString;
                toSublist=toSublist+1;
            }
        }
        line=line+1;

    }

    RecreateList();
    RecreateCard();
    return false;
}
void MyFrame::RecreateCard() {
    for(int list=0;list<countList;list++)
        for(int j=0;j<numCard[list];j++){
            if(!Card[0]){
                posCard=70+j*70;
                Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
                deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(ListCardTitle[0]),wxPoint(10,25));
                if(!!ListHighPriority[0]){
                    Card[0]->highPriority=new wxButton(Card[0],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[0]->things[0]=true;
                }
                if(!!ListDeadLine[0]){
                    Card[0]->deadLine=new wxButton(Card[0],-1,ListDeadLine[0],wxPoint(100,0),wxSize(100,25));
                    Card[0]->things[1]=true;
                }
                if(NumberMembers[0]!=0){
                    Card[0]->numberMember=NumberMembers[0];//Passing the number of Members
                    for(int k=0;k<NumberMembers[0];k++){
                        Card[0]->AttemptLabelMember[k]=&ListMemberLine[k];
                    }
                }
                if(NumberSublist[0]!=0){
                    Card[0]->numberSublist=NumberSublist[0];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[0]*2;k++){
                        Card[0]->AttemptLabelSublist[k]=&ListSublistLine[k];
                    }
                }

            }else if(!Card[1]){
                posCard=70+j*70;
                Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
                deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(ListCardTitle[1]),wxPoint(10,25));
                if(!!ListHighPriority[1]){
                    Card[1]->highPriority=new wxButton(Card[1],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[1]->things[0]=true;
                }
                if(!!ListDeadLine[1]){
                    Card[1]->deadLine=new wxButton(Card[1],-1,ListDeadLine[1],wxPoint(100,0),wxSize(100,25));
                    Card[1]->things[1]=true;
                }
                if(NumberMembers[1]!=0){
                    Card[1]->numberMember=NumberMembers[1];//Passing the number of Members
                    for(int k=0;k<NumberMembers[1];k++){
                        Card[1]->AttemptLabelMember[k]=&ListMemberLine[k+3];
                    }
                }
                if(NumberSublist[1]!=0){
                    Card[1]->numberSublist=NumberSublist[1];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[1]*2;k++){
                        Card[1]->AttemptLabelSublist[k]=&ListSublistLine[k+12];
                    }
                }


            }else if(!Card[2]){
                posCard=70+j*70;
                Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
                deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(ListCardTitle[2]),wxPoint(10,25));
                if(!!ListHighPriority[2]){
                    Card[2]->highPriority=new wxButton(Card[2],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[2]->things[0]=true;
                }
                if(!!ListDeadLine[2]){
                    Card[2]->deadLine=new wxButton(Card[2],-1,ListDeadLine[2],wxPoint(100,0),wxSize(100,25));
                    Card[2]->things[1]=true;
                }
                if(NumberMembers[2]!=0){
                    Card[2]->numberMember=NumberMembers[2];//Passing the number of Members
                    for(int k=0;k<NumberMembers[2];k++){
                        Card[2]->AttemptLabelMember[k]=&ListMemberLine[k+6];
                    }
                }
                if(NumberSublist[2]!=0){
                    Card[2]->numberSublist=NumberSublist[2];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[2]*2;k++){
                        Card[2]->AttemptLabelSublist[k]=&ListSublistLine[k+24];
                    }
                }
            }else if(!Card[3]){
                posCard=70+j*70;
                Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
                deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(ListCardTitle[3]),wxPoint(10,25));
                if(!!ListHighPriority[3]){
                    Card[3]->highPriority=new wxButton(Card[3],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[3]->things[0]=true;
                }
                if(!!ListDeadLine[3]){
                    Card[3]->deadLine=new wxButton(Card[3],-1,ListDeadLine[3],wxPoint(100,0),wxSize(100,25));
                    Card[3]->things[1]=true;
                }
                if(NumberMembers[3]!=0){
                    Card[3]->numberMember=NumberMembers[3];//Passing the number of Members
                    for(int k=0;k<NumberMembers[3];k++){
                        Card[3]->AttemptLabelMember[k]=&ListMemberLine[k+9];
                    }
                }
                if(NumberSublist[3]!=0){
                    Card[3]->numberSublist=NumberSublist[3];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[3]*2;k++){
                        Card[3]->AttemptLabelSublist[k]=&ListSublistLine[k+36];
                    }
                }
            }else if(!Card[4]){
                posCard=70+j*70;
                Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
                deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(ListCardTitle[4]),wxPoint(10,25));
                if(!!ListHighPriority[4]){
                    Card[4]->highPriority=new wxButton(Card[4],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[4]->things[0]=true;
                }
                if(!!ListDeadLine[4]){
                    Card[4]->deadLine=new wxButton(Card[4],-1,ListDeadLine[4],wxPoint(100,0),wxSize(100,25));
                    Card[4]->things[1]=true;
                }
                if(NumberMembers[4]!=0){
                    Card[4]->numberMember=NumberMembers[4];//Passing the number of Members
                    for(int k=0;k<NumberMembers[4];k++){
                        Card[4]->AttemptLabelMember[k]=&ListMemberLine[k+12];
                    }
                }
                if(NumberSublist[4]!=0){
                    Card[4]->numberSublist=NumberSublist[4];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[4]*2;k++){
                        Card[4]->AttemptLabelSublist[k]=&ListSublistLine[k+48];
                    }
                }
            }else if(!Card[5]){
                posCard=70+j*70;
                Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
                deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(ListCardTitle[5]),wxPoint(10,25));
                if(!!ListHighPriority[5]){
                    Card[5]->highPriority=new wxButton(Card[5],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[5]->things[0]=true;
                }
                if(!!ListDeadLine[5]){
                    Card[5]->deadLine=new wxButton(Card[5],-1,ListDeadLine[5],wxPoint(100,0),wxSize(100,25));
                    Card[5]->things[1]=true;
                }
                if(NumberMembers[5]!=0){
                    Card[5]->numberMember=NumberMembers[5];//Passing the number of Members
                    for(int k=0;k<NumberMembers[5];k++){
                        Card[5]->AttemptLabelMember[k]=&ListMemberLine[k+15];
                    }
                }
                if(NumberSublist[5]!=0){
                    Card[5]->numberSublist=NumberSublist[5];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[5]*2;k++){
                        Card[5]->AttemptLabelSublist[k]=&ListSublistLine[k+60];
                    }
                }
            }else if(!Card[6]){
                posCard=70+j*70;
                Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
                deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(ListCardTitle[6]),wxPoint(10,25));
                if(!!ListHighPriority[6]){
                    Card[6]->highPriority=new wxButton(Card[6],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[6]->things[0]=true;
                }
                if(!!ListDeadLine[6]){
                    Card[6]->deadLine=new wxButton(Card[6],-1,ListDeadLine[6],wxPoint(100,0),wxSize(100,25));
                    Card[6]->things[1]=true;
                }
                if(NumberMembers[6]!=0){
                    Card[6]->numberMember=NumberMembers[6];//Passing the number of Members
                    for(int k=0;k<NumberMembers[6];k++){
                        Card[6]->AttemptLabelMember[k]=&ListMemberLine[k+18];
                    }
                }
                if(NumberSublist[6]!=0){
                    Card[6]->numberSublist=NumberSublist[6];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[6]*2;k++){
                        Card[6]->AttemptLabelSublist[k]=&ListSublistLine[k+72];
                    }
                }
            }else if(!Card[7]){
                posCard=70+j*70;
                Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
                deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(ListCardTitle[7]),wxPoint(10,25));
                if(!!ListHighPriority[7]){
                    Card[7]->highPriority=new wxButton(Card[7],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[7]->things[0]=true;
                }
                if(!!ListDeadLine[7]){
                    Card[7]->deadLine=new wxButton(Card[7],-1,ListDeadLine[7],wxPoint(100,0),wxSize(100,25));
                    Card[7]->things[1]=true;
                }
                if(NumberMembers[7]!=0){
                    Card[7]->numberMember=NumberMembers[7];//Passing the number of Members
                    for(int k=0;k<NumberMembers[7];k++){
                        Card[7]->AttemptLabelMember[k]=&ListMemberLine[k+21];
                    }
                }
                if(NumberSublist[7]!=0){
                    Card[7]->numberSublist=NumberSublist[7];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[7]*2;k++){
                        Card[7]->AttemptLabelSublist[k]=&ListSublistLine[k+84];
                    }
                }
            }else if(!Card[8]){
                posCard=70+j*70;
                Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
                deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(ListCardTitle[8]),wxPoint(10,25));
                if(!!ListHighPriority[8]){
                    Card[8]->highPriority=new wxButton(Card[8],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[8]->things[0]=true;
                }
                if(!!ListDeadLine[8]){
                    Card[8]->deadLine=new wxButton(Card[8],-1,ListDeadLine[8],wxPoint(100,0),wxSize(100,25));
                    Card[8]->things[1]=true;
                }
                if(NumberMembers[8]!=0){
                    Card[8]->numberMember=NumberMembers[8];//Passing the number of Members
                    for(int k=0;k<NumberMembers[8];k++){
                        Card[8]->AttemptLabelMember[k]=&ListMemberLine[k+24];
                    }
                }
                if(NumberSublist[8]!=0){
                    Card[8]->numberSublist=NumberSublist[8];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[8]*2;k++){
                        Card[8]->AttemptLabelSublist[k]=&ListSublistLine[k+96];
                    }
                }
            }else if(!Card[9]){
                posCard=70+j*70;
                Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
                deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(ListCardTitle[9]),wxPoint(10,25));
                if(!!ListHighPriority[9]){
                    Card[9]->highPriority=new wxButton(Card[9],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[9]->things[0]=true;
                }
                if(!!ListDeadLine[9]){
                    Card[9]->deadLine=new wxButton(Card[9],-1,ListDeadLine[9],wxPoint(100,0),wxSize(100,25));
                    Card[9]->things[1]=true;
                }
                if(NumberMembers[9]!=0){
                    Card[9]->numberMember=NumberMembers[9];//Passing the number of Members
                    for(int k=0;k<NumberMembers[9];k++){
                        Card[9]->AttemptLabelMember[k]=&ListMemberLine[k+27];
                    }
                }
                if(NumberSublist[9]!=0){
                    Card[9]->numberSublist=NumberSublist[9];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[9]*2;k++){
                        Card[9]->AttemptLabelSublist[k]=&ListSublistLine[k+108];
                    }
                }
            }else if(!Card[10]){
                posCard=70+j*70;
                Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
                deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(ListCardTitle[10]),wxPoint(10,25));
                if(!!ListHighPriority[10]){
                    Card[10]->highPriority=new wxButton(Card[10],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[10]->things[0]=true;
                }
                if(!!ListDeadLine[10]){
                    Card[10]->deadLine=new wxButton(Card[10],-1,ListDeadLine[10],wxPoint(100,0),wxSize(100,25));
                    Card[10]->things[1]=true;
                }
                if(NumberMembers[10]!=0){
                    Card[10]->numberMember=NumberMembers[10];//Passing the number of Members
                    for(int k=0;k<NumberMembers[10];k++){
                        Card[10]->AttemptLabelMember[k]=&ListMemberLine[k+30];
                    }
                }
                if(NumberSublist[10]!=0){
                    Card[10]->numberSublist=NumberSublist[10];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[10]*2;k++){
                        Card[10]->AttemptLabelSublist[k]=&ListSublistLine[k+120];
                    }
                }
            }else if(!Card[11]){
                posCard=70+j*70;
                Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
                deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(ListCardTitle[11]),wxPoint(10,25));
                if(!!ListHighPriority[11]){
                    Card[11]->highPriority=new wxButton(Card[11],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[11]->things[0]=true;
                }
                if(!!ListDeadLine[11]){
                    Card[11]->deadLine=new wxButton(Card[11],-1,ListDeadLine[11],wxPoint(100,0),wxSize(100,25));
                    Card[11]->things[1]=true;
                }
                if(NumberMembers[11]!=0){
                    Card[11]->numberMember=NumberMembers[11];//Passing the number of Members
                    for(int k=0;k<NumberMembers[11];k++){
                        Card[11]->AttemptLabelMember[k]=&ListMemberLine[k+33];
                    }
                }
                if(NumberSublist[11]!=0){
                    Card[11]->numberSublist=NumberSublist[11];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[11]*2;k++){
                        Card[11]->AttemptLabelSublist[k]=&ListSublistLine[k+132];
                    }
                }
            }else if(!Card[12]){
                posCard=70+j*70;
                Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
                deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(ListCardTitle[12]),wxPoint(10,25));
                if(!!ListHighPriority[12]){
                    Card[12]->highPriority=new wxButton(Card[12],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[12]->things[0]=true;
                }
                if(!!ListDeadLine[12]){
                    Card[12]->deadLine=new wxButton(Card[12],-1,ListDeadLine[12],wxPoint(100,0),wxSize(100,25));
                    Card[12]->things[1]=true;
                }
                if(NumberMembers[12]!=0){
                    Card[12]->numberMember=NumberMembers[12];//Passing the number of Members
                    for(int k=0;k<NumberMembers[12];k++){
                        Card[12]->AttemptLabelMember[k]=&ListMemberLine[k+36];
                    }
                }
                if(NumberSublist[12]!=0){
                    Card[12]->numberSublist=NumberSublist[12];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[12]*2;k++){
                        Card[12]->AttemptLabelSublist[k]=&ListSublistLine[k+144];
                    }
                }
            }else if(!Card[13]){
                posCard=70+j*70;
                Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
                deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(ListCardTitle[13]),wxPoint(10,25));
                if(!!ListHighPriority[13]){
                    Card[13]->highPriority=new wxButton(Card[13],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[13]->things[0]=true;
                }
                if(!!ListDeadLine[13]){
                    Card[13]->deadLine=new wxButton(Card[13],-1,ListDeadLine[13],wxPoint(100,0),wxSize(100,25));
                    Card[13]->things[1]=true;
                }
                if(NumberMembers[13]!=0){
                    Card[13]->numberMember=NumberMembers[13];//Passing the number of Members
                    for(int k=0;k<NumberMembers[13];k++){
                        Card[13]->AttemptLabelMember[k]=&ListMemberLine[k+39];
                    }
                }
                if(NumberSublist[13]!=0){
                    Card[13]->numberSublist=NumberSublist[13];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[13]*2;k++){
                        Card[13]->AttemptLabelSublist[k]=&ListSublistLine[k+156];
                    }
                }
            }else if(!Card[14]){
                posCard=70+j*70;
                Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
                deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(ListCardTitle[14]),wxPoint(10,25));
                if(!!ListHighPriority[14]){
                    Card[14]->highPriority=new wxButton(Card[14],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[14]->things[0]=true;
                }
                if(!!ListDeadLine[14]){
                    Card[14]->deadLine=new wxButton(Card[14],-1,ListDeadLine[14],wxPoint(100,0),wxSize(100,25));
                    Card[14]->things[1]=true;
                }
                if(NumberMembers[14]!=0){
                    Card[14]->numberMember=NumberMembers[14];//Passing the number of Members
                    for(int k=0;k<NumberMembers[14];k++){
                        Card[14]->AttemptLabelMember[k]=&ListMemberLine[k+42];
                    }
                }
                if(NumberSublist[14]!=0){
                    Card[14]->numberSublist=NumberSublist[14];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[14]*2;k++){
                        Card[14]->AttemptLabelSublist[k]=&ListSublistLine[k+168];
                    }
                }
            }else if(!Card[15]){
                posCard=70+j*70;
                Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
                deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(ListCardTitle[15]),wxPoint(10,25));
                if(!!ListHighPriority[15]){
                    Card[15]->highPriority=new wxButton(Card[15],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[15]->things[0]=true;
                }
                if(!!ListDeadLine[15]){
                    Card[15]->deadLine=new wxButton(Card[15],-1,ListDeadLine[15],wxPoint(100,0),wxSize(100,25));
                    Card[15]->things[1]=true;
                }
                if(NumberMembers[15]!=0){
                    Card[15]->numberMember=NumberMembers[15];//Passing the number of Members
                    for(int k=0;k<NumberMembers[15];k++){
                        Card[15]->AttemptLabelMember[k]=&ListMemberLine[k+45];
                    }
                }
                if(NumberSublist[15]!=0){
                    Card[15]->numberSublist=NumberSublist[15];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[15]*2;k++){
                        Card[15]->AttemptLabelSublist[k]=&ListSublistLine[k+180];
                    }
                }
            }else if(!Card[16]){
                posCard=70+j*70;
                Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
                deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(ListCardTitle[16]),wxPoint(10,25));
                if(!!ListHighPriority[16]){
                    Card[16]->highPriority=new wxButton(Card[16],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[16]->things[0]=true;
                }
                if(!!ListDeadLine[16]){
                    Card[16]->deadLine=new wxButton(Card[16],-1,ListDeadLine[16],wxPoint(100,0),wxSize(100,25));
                    Card[16]->things[1]=true;
                }
                if(NumberMembers[16]!=0){
                    Card[16]->numberMember=NumberMembers[16];//Passing the number of Members
                    for(int k=0;k<NumberMembers[16];k++){
                        Card[16]->AttemptLabelMember[k]=&ListMemberLine[k+45];
                    }
                }
                if(NumberSublist[16]!=0){
                    Card[16]->numberSublist=NumberSublist[16];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[16]*2;k++){
                        Card[16]->AttemptLabelSublist[k]=&ListSublistLine[k+192];
                    }
                }
            }else if(!Card[17]){
                posCard=70+j*70;
                Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
                deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(ListCardTitle[17]),wxPoint(10,25));
                if(!!ListHighPriority[17]){
                    Card[17]->highPriority=new wxButton(Card[17],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[17]->things[0]=true;
                }
                if(!!ListDeadLine[17]){
                    Card[17]->deadLine=new wxButton(Card[17],-1,ListDeadLine[17],wxPoint(100,0),wxSize(100,25));
                    Card[17]->things[1]=true;
                }
                if(NumberMembers[17]!=0){
                    Card[17]->numberMember=NumberMembers[17];//Passing the number of Members
                    for(int k=0;k<NumberMembers[17];k++){
                        Card[17]->AttemptLabelMember[k]=&ListMemberLine[k+51];
                    }
                }
                if(NumberSublist[17]!=0){
                    Card[17]->numberSublist=NumberSublist[17];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[17]*2;k++){
                        Card[17]->AttemptLabelSublist[k]=&ListSublistLine[k+204];
                    }
                }
            }else if(!Card[18]){
                posCard=70+j*70;
                Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
                deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(ListCardTitle[18]),wxPoint(10,25));
                if(!!ListHighPriority[18]){
                    Card[18]->highPriority=new wxButton(Card[18],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[18]->things[0]=true;
                }
                if(!!ListDeadLine[18]){
                    Card[18]->deadLine=new wxButton(Card[18],-1,ListDeadLine[18],wxPoint(100,0),wxSize(100,25));
                    Card[18]->things[1]=true;
                }
                if(NumberMembers[18]!=0){
                    Card[18]->numberMember=NumberMembers[18];//Passing the number of Members
                    for(int k=0;k<NumberMembers[18];k++){
                        Card[18]->AttemptLabelMember[k]=&ListMemberLine[k+54];
                    }
                }
                if(NumberSublist[18]!=0){
                    Card[18]->numberSublist=NumberSublist[18];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[18]*2;k++){
                        Card[18]->AttemptLabelSublist[k]=&ListSublistLine[k+216];
                    }
                }
            }else if(!Card[19]){
                posCard=70+j*70;
                Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
                deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
                deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
                deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
                pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(ListCardTitle[19]),wxPoint(10,25));
                if(!!ListHighPriority[19]){
                    Card[19]->highPriority=new wxButton(Card[19],-1,"High priority",wxPoint(0,0),wxSize(100,25));
                    Card[19]->things[0]=true;
                }
                if(!!ListDeadLine[19]){
                    Card[19]->deadLine=new wxButton(Card[19],-1,ListDeadLine[19],wxPoint(100,0),wxSize(100,25));
                    Card[19]->things[1]=true;
                }
                if(NumberMembers[19]!=0){
                    Card[19]->numberMember=NumberMembers[19];//Passing the number of Members
                    for(int k=0;k<NumberMembers[19];k++){
                        Card[19]->AttemptLabelMember[k]=&ListMemberLine[k+57];
                    }
                }
                if(NumberSublist[19]!=0){
                    Card[19]->numberSublist=NumberSublist[19];//Passing the number of Sublist
                    for(int k=0;k<NumberSublist[19]*2;k++){
                        Card[19]->AttemptLabelSublist[k]=&ListSublistLine[k+228];
                    }
                }
            }
    }
    PassList();

}


void MyFrame::RecreateList() {
    if(countList>0){
        posList=10+(0*350);
        listPanel[0]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[0]=new wxStaticText(listPanel[0],wxID_ANY,ListTitle[0],wxPoint(5,2));
        Deleter[0]=new wxButton(listPanel[0],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[0]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete1,this);
        frontPanel[0]=new wxPanel(listPanel[0],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[0]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[0]=new wxButton(frontPanel[0],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked1,this);
        txt[0]=new wxTextCtrl(frontPanel[0],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }
    if(countList>1){
        posList=10+(1*350);
        listPanel[1]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[1]=new wxStaticText(listPanel[1],wxID_ANY,ListTitle[1],wxPoint(5,2));
        Deleter[1]=new wxButton(listPanel[1],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[1]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete2,this);
        frontPanel[1]=new wxPanel(listPanel[1],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[1]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[1]=new wxButton(frontPanel[1],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked2,this);
        txt[1]=new wxTextCtrl(frontPanel[1],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }
    if(countList>2){
        posList=10+(2*350);
        listPanel[2]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[2]=new wxStaticText(listPanel[2],wxID_ANY,ListTitle[2],wxPoint(5,2));
        Deleter[2]=new wxButton(listPanel[2],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[2]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete3,this);
        frontPanel[2]=new wxPanel(listPanel[2],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[2]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[2]=new wxButton(frontPanel[2],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked3,this);
        txt[2]=new wxTextCtrl(frontPanel[2],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }
    if(countList>3){
        posList=10+(3*350);
        listPanel[3]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
        Title[3]=new wxStaticText(listPanel[3],wxID_ANY,ListTitle[3],wxPoint(5,2));
        Deleter[3]=new wxButton(listPanel[3],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
        Deleter[3]->SetForegroundColour(wxColor(255,0,0,0));
        Deleter[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete4,this);
        frontPanel[3]=new wxPanel(listPanel[3],wxID_ANY,wxPoint(5,20),wxSize(330,420));
        frontPanel[3]->SetBackgroundColour(wxColor(60,60,110,60));
        newText[3]=new wxButton(frontPanel[3],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
        newText[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked4,this);
        txt[3]=new wxTextCtrl(frontPanel[3],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
        PassList();
    }
}


void MyFrame::OnMenuSave(wxCommandEvent &evt) {
    wxFileDialog dlg(this,"SaveFile","","",".txt Files (*.txt)|*.txt",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if(dlg.ShowModal()==wxID_OK){
        Save(dlg.GetPath());
    }
    evt.Skip();
}
bool MyFrame::Save(wxString fileName) {
    std::ofstream outfile;
    outfile.open(fileName);

    outfile<<countList<<std::endl;
    for(int i=0;i<countList;i++){
        outfile<<Title[i]->GetLabel()<<" "<<std::endl;
    }
//    for(int i=0;i<(4-countList);i++){
//        outfile<<"#NoNe#"<<std::endl;
//    }

    outfile<<"#StOp#"<<std::endl;
    for(int i=0;i<countList;i++){
        outfile<<numCard[i]<<std::endl;
    }
    for(int i=0;i<(4-countList);i++){
        outfile<<"#NoNe#"<<std::endl;
    }

    //outfile<<"#StEp1#"<<std::endl;
    for(int i=0;i<countList;i++){
        if(i==0){
            outfile<<"#LiSt1#"<<std::endl;
        }else if(i==1){
            outfile<<"#LiSt2#"<<std::endl;
        }else if(i==2){
            outfile<<"#LiSt3#"<<std::endl;
        }else if(i==3){
            outfile<<"#LiSt4#"<<std::endl;
        }
        for(int k=0;k<20;k++){
            for(int l=2;l<frontPanel[i]->GetChildren().size();l++){
                if(frontPanel[i]->GetChildren()[l]==Card[k]){

                    outfile<<pointsToDo[k]->GetLabel()<<std::endl;

                    if(Card[k]->things[0])
                        outfile<<(Card[k])->highPriority->GetLabel()<<std::endl;
                    else
                        outfile<<"#NoNe#"<<std::endl;
                    if(Card[k]->things[1])
                        outfile<<(Card[k])->deadLine->GetLabel()<<std::endl;
                    else
                        outfile<<"#NoNe#"<<std::endl;
                    if(Card[k]->numberMember){
                        outfile<<(Card[k])->numberMember<<std::endl;
                        for(int m=0;m<Card[k]->numberMember;m++){
                            if((Card[k])->labelMember[m]==""){
                                outfile<<*(Card[k])->AttemptLabelMember[m]<<std::endl;
                            }else{
                                outfile<<(Card[k])->labelMember[m]<<std::endl;
                                
                            }

                        }
                        for(int m=0;m<(3-Card[k]->numberMember);m++){
                            outfile<<"#NoNe#"<<std::endl;
                        }
                    }else{
                        outfile<<"#NoNe#"<<std::endl;//Number of member=0
                        outfile<<"#NoNe#"<<std::endl;
                        outfile<<"#NoNe#"<<std::endl;
                        outfile<<"#NoNe#"<<std::endl;
                    }

                    if((Card[k])->numberSublist){
                        outfile<<(Card[k])->numberSublist<<std::endl;
                        for(int n=0;n<(Card[k])->numberSublist;n++){
                            if((Card[k])->stringSublist[n]==""){
                                outfile<<*(Card[k])->AttemptLabelSublist[n*2]<<std::endl;
                                outfile<<*(Card[k])->AttemptLabelSublist[n*2+1]<<std::endl;

                            }else{
                                outfile<<(Card[k])->stringSublist[n]<<std::endl;
                                outfile<<(Card[k])->labelsSublist[n]<<std::endl;
                            }

                        }
                        for(int n=0;n<(6-(Card[k])->numberSublist);n++){
                            outfile<<"#NoNe#"<<std::endl;
                            outfile<<"#NoNe#"<<std::endl;
                        }
                    }else{
                        outfile<<"#NoNe#"<<std::endl;
                        for(int o=0;o<12;o++)
                            outfile<<"#NoNe#"<<std::endl;
                    }
                }
            }
        }
    }
    return false;
}

void MyFrame::OnMenuExit(wxCommandEvent &evt) {
    Close();
    evt.Skip();
}
void MyFrame::DeleteEverything() {
    if (listPanel[0]) {
        //Delete any card on the list
        for (int k = 2; k < listPanel[0]->GetChildren()[2]->GetChildren().size(); k++) {
            if (listPanel[0]->GetChildren()[2]->GetChildren()[k]) {
                for (int j = 0; j < 20; j++) {
                    if (Card[j]) {
                        if (Card[j] == listPanel[0]->GetChildren()[2]->GetChildren()[k]) {
                            delete Card[j];
                            Card[j] = nullptr;
                            k = k - 1;
                            break;
                        }
                    }
                }
            }
        }
        numCard[0] = 0;
        //Delete the list
        struct panelPosition {
            int x, y;
        };
        wxPoint panelPosition = listPanel[0]->GetPosition();
        SetListPosition(panelPosition.x);
        delete listPanel[0];
        listPanel[0] = nullptr;
        PassList();
    }
    if (listPanel[1]) {
        //Delete any card on the list
        for (int k = 2; k < listPanel[1]->GetChildren()[2]->GetChildren().size(); k++) {
            if (listPanel[1]->GetChildren()[2]->GetChildren()[k]) {
                for (int j = 0; j < 20; j++) {
                    if (Card[j]) {
                        if (Card[j] == listPanel[1]->GetChildren()[2]->GetChildren()[k]) {
                            delete Card[j];
                            Card[j] = nullptr;
                            k = k - 1;
                            break;
                        }
                    }
                }
            }
        }
        numCard[1] = 0;
        //Delete the list
        struct panelPosition {
            int x, y;
        };
        wxPoint panelPosition = listPanel[1]->GetPosition();
        SetListPosition(panelPosition.x);
        delete listPanel[1];
        listPanel[1] = nullptr;
        PassList();
    }
    if(listPanel[2]){
        //Delete any card on the list
        for (int k=2;k<listPanel[2]->GetChildren()[2]->GetChildren().size();k++){
            if(listPanel[2]->GetChildren()[2]->GetChildren()[k]){
                for (int j=0;j<20;j++){
                    if(Card[j]){
                        if(Card[j]==listPanel[2]->GetChildren()[2]->GetChildren()[k]){
                            delete Card[j];
                            Card[j]=nullptr;
                            k=k-1;
                            break;
                        }
                    }
                }
            }
        }
        numCard[2]=0;
        //Delete the list
        struct panelPosition{
            int x,y;
        };
        wxPoint panelPosition=listPanel[2]->GetPosition();
        SetListPosition(panelPosition.x);
        delete listPanel[2];
        listPanel[2]=nullptr;
        PassList();
    }
    if(listPanel[3]) {
        //Delete any card on the list
        for (int k=2;k<listPanel[3]->GetChildren()[2]->GetChildren().size();k++){
            if(listPanel[3]->GetChildren()[2]->GetChildren()[k]){
                for (int j=0;j<20;j++){
                    if(Card[j]){
                        if(Card[j]==listPanel[3]->GetChildren()[2]->GetChildren()[k]){
                            delete Card[j];
                            Card[j]=nullptr;
                            k=k-1;
                            break;
                        }
                    }
                }
            }
        }
        numCard[3]=0;
        //Delete the list
        struct panelPosition{
            int x,y;
        };
        wxPoint panelPosition=listPanel[3]->GetPosition();
        SetListPosition(panelPosition.x);
        delete listPanel[3];
        listPanel[3]=nullptr;
        PassList();
    }
}
//END////////////////////////////////////////////

//PANELS/////////////////////////////////////////
void MyFrame::ListCreator(wxCommandEvent &evt) {
    if(nameList->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write the name of the list"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else{
        if(!listPanel[0]){
            posList=10+(countList*350);
            listPanel[0]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
            Title[0]=new wxStaticText(listPanel[0],wxID_ANY,wxString(),wxPoint(5,2));
            Title[0]->SetLabel(nameList->GetValue());
            Deleter[0]=new wxButton(listPanel[0],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
            Deleter[0]->SetForegroundColour(wxColor(255,0,0,0));
            Deleter[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete1,this);
            countList++;
            frontPanel[0]=new wxPanel(listPanel[0],wxID_ANY,wxPoint(5,20),wxSize(330,420));
            frontPanel[0]->SetBackgroundColour(wxColor(60,60,110,60));
            newText[0]=new wxButton(frontPanel[0],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
            newText[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked1,this);
            txt[0]=new wxTextCtrl(frontPanel[0],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
            PassList();
        }else if(!listPanel[1]){
            posList=10+(countList*350);
            listPanel[1]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
            Title[1]=new wxStaticText(listPanel[1],wxID_ANY,wxString(),wxPoint(5,2));
            Title[1]->SetLabel(nameList->GetValue());
            Deleter[1]=new wxButton(listPanel[1],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
            Deleter[1]->SetForegroundColour(wxColor(255,0,0,0));
            Deleter[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete2,this);
            countList++;
            frontPanel[1]=new wxPanel(listPanel[1],wxID_ANY,wxPoint(5,20),wxSize(330,420));
            frontPanel[1]->SetBackgroundColour(wxColor(60,60,110,60));
            newText[1]=new wxButton(frontPanel[1],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
            newText[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked2,this);
            txt[1]=new wxTextCtrl(frontPanel[1],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
            PassList();
        }else if(!listPanel[2]){
            posList=10+(countList*350);
            listPanel[2]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
            Title[2]=new wxStaticText(listPanel[2],wxID_ANY,wxString(),wxPoint(5,2));
            Title[2]->SetLabel(nameList->GetValue());
            Deleter[2]=new wxButton(listPanel[2],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
            Deleter[2]->SetForegroundColour(wxColor(255,0,0,0));
            Deleter[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete3,this);
            countList++;
            frontPanel[2]=new wxPanel(listPanel[2],wxID_ANY,wxPoint(5,20),wxSize(330,420));
            frontPanel[2]->SetBackgroundColour(wxColor(60,60,110,60));
            newText[2]=new wxButton(frontPanel[2],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
            newText[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked3,this);
            txt[2]=new wxTextCtrl(frontPanel[2],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
            PassList();
        }else if(!listPanel[3]){
            posList=10+(countList*350);
            listPanel[3]=new wxPanel(bottomPanel,wxID_ANY,wxPoint(posList,10),wxSize(340,445));
            Title[3]=new wxStaticText(listPanel[3],wxID_ANY,wxString(),wxPoint(5,2));
            Title[3]->SetLabel(nameList->GetValue());
            Deleter[3]=new wxButton(listPanel[3],wxID_ANY,"X",wxPoint(318,0),wxSize(25,20));
            Deleter[3]->SetForegroundColour(wxColor(255,0,0,0));
            Deleter[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::ListDelete4,this);
            countList++;
            frontPanel[3]=new wxPanel(listPanel[3],wxID_ANY,wxPoint(5,20),wxSize(330,420));
            frontPanel[3]->SetBackgroundColour(wxColor(60,60,110,60));
            newText[3]=new wxButton(frontPanel[3],wxID_ANY,"Add Card",wxPoint(5,5),wxSize(140,30));
            newText[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::OnButtonClicked4,this);
            txt[3]=new wxTextCtrl(frontPanel[3],wxID_ANY,"",wxPoint(5,35),wxSize(200,30));
            PassList();
        }else {
            wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                        wxT("Max number of lists reached"), wxT("Exclamation"),
                                                        wxOK | wxICON_EXCLAMATION);
            dial->ShowModal();
        }
    }

}
void MyFrame::ListDelete1(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[0]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[0]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[0]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[0]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[0]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[0];
    listPanel[0]=nullptr;
    PassList();
}
void MyFrame::ListDelete2(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[1]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[1]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[1]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[1]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[1]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[1];
    listPanel[1]=nullptr;
    PassList();
}
void MyFrame::ListDelete3(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[2]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[2]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[2]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[2]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[2]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[2];
    listPanel[2]=nullptr;
    PassList();
}
void MyFrame::ListDelete4(wxCommandEvent &evt) {
    //Delete any card on the list
    for (int k=2;k<listPanel[3]->GetChildren()[2]->GetChildren().size();k++){
        if(listPanel[3]->GetChildren()[2]->GetChildren()[k]){
            for (int j=0;j<20;j++){
                if(Card[j]){
                    if(Card[j]==listPanel[3]->GetChildren()[2]->GetChildren()[k]){
                        delete Card[j];
                        Card[j]=nullptr;
                        k=k-1;
                        break;
                    }
                }
            }
        }
    }
    numCard[3]=0;
    //Delete the list
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=listPanel[3]->GetPosition();
    SetListPosition(panelPosition.x);
    delete listPanel[3];
    listPanel[3]=nullptr;
    PassList();
}
void MyFrame::SetListPosition(int x) {
    int posx,posy;
    for(int i=0;i<4;i++){
        if(listPanel[i]){
            struct panelPosition{
                int x,y;
            };
            wxPoint panelPosition=listPanel[i]->GetPosition();
            posx=panelPosition.x;
            posy=panelPosition.y;
        }else continue;
        if(posx>x){
            listPanel[i]->SetPosition(wxPoint(posx-350,posy));
        }
    }
    countList--;
}
//END/////////////////////////////////////////
//CARDS///////////////////////////////////////
void MyFrame::OnButtonClicked1(wxCommandEvent &evt) {
    if(txt[0]->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write something in the card"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else
        CreateCard(0);
}
void MyFrame::OnButtonClicked2(wxCommandEvent &evt) {
    if(txt[1]->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write something in the card"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else
        CreateCard(1);}
void MyFrame::OnButtonClicked3(wxCommandEvent &evt) {
    if(txt[2]->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write something in the card"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else
        CreateCard(2);}
void MyFrame::OnButtonClicked4(wxCommandEvent &evt) {
    if(txt[3]->GetValue().empty()){
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Write something in the card"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }else
        CreateCard(3);}

void MyFrame::CreateCard(int list) {
    if(list==0 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
            //Card[0]->numCard[list]=&numCard[list];
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else if(list==1 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else if(list==2 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else if(list==3 && numCard[list]<5){
        if(!Card[0]){
            posCard=70+numCard[list]*70;
            Card[0]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[0]=new wxButton(Card[0],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard1,this);
            deleteCard[0]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[0]=new wxStaticText(Card[0],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[0]->SetLabel(txt[list]->GetValue());
            pointsToDo[0]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[1]){
            posCard=70+numCard[list]*70;
            Card[1]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[1]=new wxButton(Card[1],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard2,this);
            deleteCard[1]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[1]=new wxStaticText(Card[1],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[1]->SetLabel(txt[list]->GetValue());
            pointsToDo[1]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[2]){
            posCard=70+numCard[list]*70;
            Card[2]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[2]=new wxButton(Card[2],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard3,this);
            deleteCard[2]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[2]=new wxStaticText(Card[2],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[2]->SetLabel(txt[list]->GetValue());
            pointsToDo[2]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[3]){
            posCard=70+numCard[list]*70;
            Card[3]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[3]=new wxButton(Card[3],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard4,this);
            deleteCard[3]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[3]=new wxStaticText(Card[3],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[3]->SetLabel(txt[list]->GetValue());
            pointsToDo[3]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[4]){
            posCard=70+numCard[list]*70;
            Card[4]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[4]=new wxButton(Card[4],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard5,this);
            deleteCard[4]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[4]=new wxStaticText(Card[4],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[4]->SetLabel(txt[list]->GetValue());
            pointsToDo[4]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[5]){
            posCard=70+numCard[list]*70;
            Card[5]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[5]=new wxButton(Card[5],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard6,this);
            deleteCard[5]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[5]=new wxStaticText(Card[5],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[5]->SetLabel(txt[list]->GetValue());
            pointsToDo[5]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[6]){
            posCard=70+numCard[list]*70;
            Card[6]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[6]=new wxButton(Card[6],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[6]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard7,this);
            deleteCard[6]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[6]=new wxStaticText(Card[6],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[6]->SetLabel(txt[list]->GetValue());
            pointsToDo[6]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[7]){
            posCard=70+numCard[list]*70;
            Card[7]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[7]=new wxButton(Card[7],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[7]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard8,this);
            deleteCard[7]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[7]=new wxStaticText(Card[7],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[7]->SetLabel(txt[list]->GetValue());
            pointsToDo[7]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[8]){
            posCard=70+numCard[list]*70;
            Card[8]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[8]=new wxButton(Card[8],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[8]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard9,this);
            deleteCard[8]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[8]=new wxStaticText(Card[8],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[8]->SetLabel(txt[list]->GetValue());
            pointsToDo[8]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[9]){
            posCard=70+numCard[list]*70;
            Card[9]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[9]=new wxButton(Card[9],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[9]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard10,this);
            deleteCard[9]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[9]=new wxStaticText(Card[9],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[9]->SetLabel(txt[list]->GetValue());
            pointsToDo[9]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[10]){
            posCard=70+numCard[list]*70;
            Card[10]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[10]=new wxButton(Card[10],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[10]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard11,this);
            deleteCard[10]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[10]=new wxStaticText(Card[10],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[10]->SetLabel(txt[list]->GetValue());
            pointsToDo[10]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[11]){
            posCard=70+numCard[list]*70;
            Card[11]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[11]=new wxButton(Card[11],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[11]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard12,this);
            deleteCard[11]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[11]=new wxStaticText(Card[11],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[11]->SetLabel(txt[list]->GetValue());
            pointsToDo[11]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[12]){
            posCard=70+numCard[list]*70;
            Card[12]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[12]=new wxButton(Card[12],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[12]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard13,this);
            deleteCard[12]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[12]=new wxStaticText(Card[12],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[12]->SetLabel(txt[list]->GetValue());
            pointsToDo[12]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[13]){
            posCard=70+numCard[list]*70;
            Card[13]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[13]=new wxButton(Card[13],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[13]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard14,this);
            deleteCard[13]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[13]=new wxStaticText(Card[13],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[13]->SetLabel(txt[list]->GetValue());
            pointsToDo[13]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[14]){
            posCard=70+numCard[list]*70;
            Card[14]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[14]=new wxButton(Card[14],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[14]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard15,this);
            deleteCard[14]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[14]=new wxStaticText(Card[14],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[14]->SetLabel(txt[list]->GetValue());
            pointsToDo[14]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[15]){
            posCard=70+numCard[list]*70;
            Card[15]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[15]=new wxButton(Card[15],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[15]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard16,this);
            deleteCard[15]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[15]=new wxStaticText(Card[15],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[15]->SetLabel(txt[list]->GetValue());
            pointsToDo[15]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[16]){
            posCard=70+numCard[list]*70;
            Card[16]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[16]=new wxButton(Card[16],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[16]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard17,this);
            deleteCard[16]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[16]=new wxStaticText(Card[16],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[16]->SetLabel(txt[list]->GetValue());
            pointsToDo[16]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[17]){
            posCard=70+numCard[list]*70;
            Card[17]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[17]=new wxButton(Card[17],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[17]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard18,this);
            deleteCard[17]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[17]=new wxStaticText(Card[17],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[17]->SetLabel(txt[list]->GetValue());
            pointsToDo[17]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[18]){
            posCard=70+numCard[list]*70;
            Card[18]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[18]=new wxButton(Card[18],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[18]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard19,this);
            deleteCard[18]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[18]=new wxStaticText(Card[18],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[18]->SetLabel(txt[list]->GetValue());
            pointsToDo[18]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }else if(!Card[19]){
            posCard=70+numCard[list]*70;
            Card[19]=new MyCard(frontPanel[list],wxID_ANY,wxPoint(5,posCard),wxSize(320,65));
            deleteCard[19]=new wxButton(Card[19],wxID_ANY,"x",wxPoint(296,0),wxSize(25,25));
            deleteCard[19]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyFrame::DeleteCard20,this);
            deleteCard[19]->SetForegroundColour(wxColor(255,0,0,0));
            pointsToDo[19]=new wxStaticText(Card[19],wxID_ANY,wxString(),wxPoint(10,25));
            pointsToDo[19]->SetLabel(txt[list]->GetValue());
            pointsToDo[19]->SetBackgroundColour(wxColor(0,0,0,0));
            numCard[list]++;
        }
    }else{
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Max number of cards reached"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }
    PassList();
}

void MyFrame::DeleteCard1(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[0]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[0]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);

    delete Card[0];
    Card[0]=nullptr;
}

void MyFrame::DeleteCard2(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[1]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[1]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[1];
    Card[1]=nullptr;
}

void MyFrame::DeleteCard3(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[2]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[2]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[2];
    Card[2]=nullptr;
}

void MyFrame::DeleteCard4(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[3]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[3]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[3];
    Card[3]=nullptr;
}

void MyFrame::DeleteCard5(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[4]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[4]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[4];
    Card[4]=nullptr;
}

void MyFrame::DeleteCard6(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[5]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[5]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[5];
    Card[5]=nullptr;
}

void MyFrame::DeleteCard7(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[6]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[6]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[6];
    Card[6]=nullptr;
}

void MyFrame::DeleteCard8(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[7]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[7]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[7];
    Card[7]=nullptr;
}

void MyFrame::DeleteCard9(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[8]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[8]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[8];
    Card[8]=nullptr;
}

void MyFrame::DeleteCard10(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[9]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[9]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[9];
    Card[9]=nullptr;
}

void MyFrame::DeleteCard11(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[10]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[10]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[10];
    Card[10]=nullptr;
}

void MyFrame::DeleteCard12(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[11]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[11]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[11];
    Card[11]=nullptr;
}

void MyFrame::DeleteCard13(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[12]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[12]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[12];
    Card[12]=nullptr;
}

void MyFrame::DeleteCard14(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[13]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[13]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[13];
    Card[13]=nullptr;
}

void MyFrame::DeleteCard15(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[14]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[14]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[14];
    Card[14]=nullptr;
}

void MyFrame::DeleteCard16(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[15]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[15]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[15];
    Card[15]=nullptr;
}

void MyFrame::DeleteCard17(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[16]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[16]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[16];
    Card[16]=nullptr;
}

void MyFrame::DeleteCard18(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[17]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[17]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[17];
    Card[17]=nullptr;
}

void MyFrame::DeleteCard19(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[18]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[18]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[18];
    Card[18]=nullptr;
}

void MyFrame::DeleteCard20(wxCommandEvent &evt) {
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=Card[19]->GetPosition();
    for(int i=0;i<4;i++)
        if(listPanel[i])
            if(Card[19]->GetParent()->GetParent()==listPanel[i])
                MoveCards(listPanel[i],panelPosition.y,&numCard[i]);
    delete Card[19];
    Card[19]=nullptr;
}

void MyFrame::MoveCards(wxPanel *aList,int posCard,int *numCardList) {//aList è il frontPanel di porvenienza //posCard è la y del card //numCardList è il numero di cards
    struct panelPosition{
        int x,y;
    };
    for(int i=2;i<aList->GetChildren()[2]->GetChildren().size();i++){
        wxPoint panelPosition=aList->GetChildren()[2]->GetChildren()[i]->GetPosition();
        if(posCard<panelPosition.y)
            aList->GetChildren()[2]->GetChildren()[i]->SetPosition(wxPoint(panelPosition.x,panelPosition.y-70));//Move some Cards
    }
    *numCardList=*numCardList-1;// Decrement the numbers of cards for this list
}

void MyFrame::PassList() {
    for(int i=0;i<20;i++){
        if(Card[i])
            for(int j=0;j<4;j++)
                if(listPanel[j]){
                    Card[i]->anyPanel[j]=listPanel[j];
                    Card[i]->anyTitle[j]=Title[j]->GetLabelText();
                    Card[i]->numCard[j]=&numCard[j];
                }
    }
}