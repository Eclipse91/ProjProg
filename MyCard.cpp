//
// Created by myself on 4/21/20.
//

#include "MyCard.h"

wxBEGIN_EVENT_TABLE(MyCard, wxPanel)
                EVT_BUTTON(10001, MyCard::OnButton1)
                EVT_BUTTON(10002, MyCard::OnButton2)
                EVT_BUTTON(10003, MyCard::OnButton3)
                EVT_BUTTON(10004, MyCard::OnButton4)
wxEND_EVENT_TABLE()

MyCard::MyCard(wxWindow *parent,
               wxWindowID id,
               const wxPoint& pos,
               const wxSize& size)
        :wxPanel(parent, id, pos, size)
{
    Card=new wxButton(this,-1,"+",wxPoint(275,0),wxSize(25,25));
    Card->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::OnCardClicked,this);


}

//MYCARDFRAME////////////////////////////////////
void MyCard::OnCardClicked(wxCommandEvent &evt) {

    cardFrame=new MyCardFrame(this,wxID_ANY,"Costumize",wxPoint(400,400),wxSize(600,600));
    cardFrame->cardAnswer=this;
    cardFrame->Show();

    //HIGHPIORITY
    cardFrame->label[0]->SetValue(things[0]);
    cardFrame->things[0]=&things[0];
    cardFrame->highPriority=&highPriority;

    //DEADLINE
    cardFrame->label[1]->SetValue(things[1]);
    cardFrame->things[1]=&things[1];
    cardFrame->deadLine=&deadLine;

    //MEMBERS
    wxButton*addMember=new wxButton(cardFrame->rightPanel,wxID_ANY,"Add",wxPoint(120,105),wxSize(50,30));
    addMember->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::NewMember,this);
    nameMember=new wxTextCtrl(cardFrame->rightPanel,wxID_ANY,"",wxPoint(170,95),wxSize(100,50));
    Member[0]=new wxButton(cardFrame->rightPanel,wxID_ANY,labelMember[0],wxPoint(13,140+0),wxSize(100,25));
    Member[1]=new wxButton(cardFrame->rightPanel,wxID_ANY,labelMember[1],wxPoint(13,140+25),wxSize(100,25));
    Member[2]=new wxButton(cardFrame->rightPanel,wxID_ANY,labelMember[2],wxPoint(13,140+50),wxSize(100,25));
    removeMember[0]= new wxButton(cardFrame->rightPanel,-1,"x",wxPoint(110,140),wxSize(25,25));
    removeMember[0]->SetForegroundColour(wxColor(255,0,0,0));
    removeMember[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveMember1,this);
    removeMember[1]= new wxButton(cardFrame->rightPanel,-1,"x",wxPoint(110,140+25),wxSize(25,25));
    removeMember[1]->SetForegroundColour(wxColor(255,0,0,0));
    removeMember[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveMember2,this);
    removeMember[2]= new wxButton(cardFrame->rightPanel,-1,"x",wxPoint(110,140+50),wxSize(25,25));
    removeMember[2]->SetForegroundColour(wxColor(255,0,0,0));
    removeMember[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveMember3,this);


    hidingPanel=new wxPanel(cardFrame->rightPanel,-1,wxPoint(10,140+numberMember*25),wxSize(130,80-numberMember*25));
    hidingPanel->SetBackgroundColour(wxColor(70,70,120,70));

    //SUBLIST
    wxButton*addSublist=new wxButton(cardFrame->leftPanel,wxID_ANY,"Add",wxPoint(120,5),wxSize(50,30));
    addSublist->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::NewSublist,this);
    nameSublist=new wxTextCtrl(cardFrame->leftPanel,wxID_ANY,"",wxPoint(170,-5),wxSize(100,50));

    panelSublist[0]=new wxPanel(cardFrame->leftPanel,wxID_ANY,wxPoint(10,40),wxSize(200,25));
    removeSublist[0]= new wxButton(panelSublist[0],-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist[0]->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist[0]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveSublist1,this);
    checkboxSublist[0]=new wxCheckBox(panelSublist[0],wxID_ANY,"",wxPoint(2,2));
    checkboxSublist[0]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCard::SetCheckBox1,this);
    checkboxSublist[0]->SetValue(labelsSublist[0]);
    staticSublist[0]=new wxStaticText(panelSublist[0],wxID_ANY,stringSublist[0],wxPoint(30,4));

    panelSublist[1]=new wxPanel(cardFrame->leftPanel,wxID_ANY,wxPoint(10,65),wxSize(200,25));
    removeSublist[1]= new wxButton(panelSublist[1],-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist[1]->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist[1]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveSublist2,this);
    checkboxSublist[1]=new wxCheckBox(panelSublist[1],wxID_ANY,"",wxPoint(2,2));
    checkboxSublist[1]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCard::SetCheckBox2,this);
    checkboxSublist[1]->SetValue(labelsSublist[1]);
    staticSublist[1]=new wxStaticText(panelSublist[1],wxID_ANY,stringSublist[1],wxPoint(30,4));

    panelSublist[2]=new wxPanel(cardFrame->leftPanel,wxID_ANY,wxPoint(10,90),wxSize(200,25));
    removeSublist[2]= new wxButton(panelSublist[2],-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist[2]->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist[2]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveSublist3,this);
    checkboxSublist[2]=new wxCheckBox(panelSublist[2],wxID_ANY,"",wxPoint(2,2));
    checkboxSublist[2]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCard::SetCheckBox3,this);
    checkboxSublist[2]->SetValue(labelsSublist[2]);
    staticSublist[2]=new wxStaticText(panelSublist[2],wxID_ANY,stringSublist[2],wxPoint(30,4));

    panelSublist[3]=new wxPanel(cardFrame->leftPanel,wxID_ANY,wxPoint(10,115),wxSize(200,25));
    removeSublist[3]= new wxButton(panelSublist[3],-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist[3]->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist[3]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveSublist4,this);
    checkboxSublist[3]=new wxCheckBox(panelSublist[3],wxID_ANY,"",wxPoint(2,2));
    checkboxSublist[3]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCard::SetCheckBox4,this);
    checkboxSublist[3]->SetValue(labelsSublist[3]);
    staticSublist[3]=new wxStaticText(panelSublist[3],wxID_ANY,stringSublist[3],wxPoint(30,4));

    panelSublist[4]=new wxPanel(cardFrame->leftPanel,wxID_ANY,wxPoint(10,140),wxSize(200,25));
    removeSublist[4]= new wxButton(panelSublist[4],-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist[4]->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist[4]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveSublist5,this);
    checkboxSublist[4]=new wxCheckBox(panelSublist[4],wxID_ANY,"",wxPoint(2,2));
    checkboxSublist[4]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCard::SetCheckBox5,this);
    checkboxSublist[4]->SetValue(labelsSublist[4]);
    staticSublist[4]=new wxStaticText(panelSublist[4],wxID_ANY,stringSublist[4],wxPoint(30,4));

    panelSublist[5]=new wxPanel(cardFrame->leftPanel,wxID_ANY,wxPoint(10,165),wxSize(200,25));
    removeSublist[5]= new wxButton(panelSublist[5],-1,"x",wxPoint(176,0),wxSize(25,25));
    removeSublist[5]->SetForegroundColour(wxColor(255,0,0,0));
    removeSublist[5]->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&MyCard::RemoveSublist6,this);
    checkboxSublist[5]=new wxCheckBox(panelSublist[5],wxID_ANY,"",wxPoint(2,2));
    checkboxSublist[5]->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&MyCard::SetCheckBox6,this);
    checkboxSublist[5]->SetValue(labelsSublist[5]);
    staticSublist[5]=new wxStaticText(panelSublist[5],wxID_ANY,stringSublist[5],wxPoint(30,4));

    coverPanel=new wxPanel(cardFrame->leftPanel,-1,wxPoint(10,40+numberSublist*25),wxSize(220,400-numberSublist*25));
    coverPanel->SetBackgroundColour(wxColor(60,60,110,60));
    //MOVE/////////////////////////////////////////////////////////////////////////////////////////////////
    CreateButtons();

}

//CREATE SUBLIST
void MyCard::NewSublist(wxCommandEvent &evt) {
    if(numberSublist==0){
        staticSublist[0]->SetLabel(nameSublist->GetValue());
        stringSublist[0]=nameSublist->GetValue();

        numberSublist++;
    }else if(numberSublist==1){
        staticSublist[1]->SetLabel(nameSublist->GetValue());
        stringSublist[1]=nameSublist->GetValue();

        numberSublist++;
    }else if(numberSublist==2){
        staticSublist[2]->SetLabel(nameSublist->GetValue());
        stringSublist[2]=nameSublist->GetValue();

        numberSublist++;
    }else if(numberSublist==3){
        staticSublist[3]->SetLabel(nameSublist->GetValue());
        stringSublist[3]=nameSublist->GetValue();

        numberSublist++;
    }else if(numberSublist==4){
        staticSublist[4]->SetLabel(nameSublist->GetValue());
        stringSublist[4]=nameSublist->GetValue();

        numberSublist++;
    }else if(numberSublist==5){
        staticSublist[5]->SetLabel(nameSublist->GetValue());
        stringSublist[5]=nameSublist->GetValue();

        numberSublist++;
    }else {
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Max number of item reached"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }
    coverPanel->SetPosition(wxPoint(10,40+numberSublist*25));
    coverPanel->SetSize(wxSize(220,400-numberSublist*25));
}

void MyCard::RemoveSublist1(wxCommandEvent &evt) {
    //Moving labels
    staticSublist[0]->SetLabel(stringSublist[1]);
    stringSublist[0]=stringSublist[1];
    staticSublist[1]->SetLabel(stringSublist[2]);
    stringSublist[1]=stringSublist[2];
    staticSublist[2]->SetLabel(stringSublist[3]);
    stringSublist[2]=stringSublist[3];
    staticSublist[3]->SetLabel(stringSublist[4]);
    stringSublist[3]=stringSublist[4];
    staticSublist[4]->SetLabel(stringSublist[5]);
    stringSublist[4]=stringSublist[5];

    //Moving checkbox
    for(int i=0;i<numberSublist;i++){
        checkboxSublist[i]->SetValue(labelsSublist[i+1]);
        labelsSublist[i]=labelsSublist[i+1];
    }
    checkboxSublist[5]->SetValue(false);

    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=coverPanel->GetPosition();
    coverPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=coverPanel->GetSize();
    coverPanel->SetSize(wxSize(220,panelSize.y+25));

    --numberSublist;
}

void MyCard::RemoveSublist2(wxCommandEvent &evt) {
    //Moving labels
    staticSublist[1]->SetLabel(stringSublist[2]);
    stringSublist[1]=stringSublist[2];
    staticSublist[2]->SetLabel(stringSublist[3]);
    stringSublist[2]=stringSublist[3];
    staticSublist[3]->SetLabel(stringSublist[4]);
    stringSublist[3]=stringSublist[4];
    staticSublist[4]->SetLabel(stringSublist[5]);
    stringSublist[4]=stringSublist[5];

    //Moving checkbox
    for(int i=1;i<numberSublist;i++){
        checkboxSublist[i]->SetValue(labelsSublist[i+1]);
        labelsSublist[i]=labelsSublist[i+1];
    }
    checkboxSublist[5]->SetValue(false);

    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=coverPanel->GetPosition();
    coverPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=coverPanel->GetSize();
    coverPanel->SetSize(wxSize(220,panelSize.y+25));

    --numberSublist;
}
void MyCard::RemoveSublist3(wxCommandEvent &evt) {
    //Moving labels
    staticSublist[2]->SetLabel(stringSublist[3]);
    stringSublist[2]=stringSublist[3];
    staticSublist[3]->SetLabel(stringSublist[4]);
    stringSublist[3]=stringSublist[4];
    staticSublist[4]->SetLabel(stringSublist[5]);
    stringSublist[4]=stringSublist[5];

    //Moving checkbox
    for(int i=2;i<numberSublist;i++){
        checkboxSublist[i]->SetValue(labelsSublist[i+1]);
        labelsSublist[i]=labelsSublist[i+1];
    }
    checkboxSublist[5]->SetValue(false);


    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=coverPanel->GetPosition();
    coverPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=coverPanel->GetSize();
    coverPanel->SetSize(wxSize(220,panelSize.y+25));

    --numberSublist;
}

void MyCard::RemoveSublist4(wxCommandEvent &evt) {
    //Moving labels
    staticSublist[3]->SetLabel(stringSublist[4]);
    stringSublist[3]=stringSublist[4];
    staticSublist[4]->SetLabel(stringSublist[5]);
    stringSublist[4]=stringSublist[5];

    //Moving checkbox
    for(int i=3;i<numberSublist;i++){
        checkboxSublist[i]->SetValue(labelsSublist[i+1]);
        labelsSublist[i]=labelsSublist[i+1];
    }
    checkboxSublist[5]->SetValue(false);


    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=coverPanel->GetPosition();
    coverPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=coverPanel->GetSize();
    coverPanel->SetSize(wxSize(220,panelSize.y+25));

    --numberSublist;
}

void MyCard::RemoveSublist5(wxCommandEvent &evt) {
    //Moving labels
    staticSublist[4]->SetLabel(stringSublist[5]);
    stringSublist[4]=stringSublist[5];

    //Moving checkbox
    for(int i=4;i<numberSublist;i++){
        checkboxSublist[i]->SetValue(labelsSublist[i+1]);
        labelsSublist[i]=labelsSublist[i+1];
    }
    checkboxSublist[5]->SetValue(false);


    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=coverPanel->GetPosition();
    coverPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=coverPanel->GetSize();
    coverPanel->SetSize(wxSize(220,panelSize.y+25));

    --numberSublist;
}

void MyCard::RemoveSublist6(wxCommandEvent &evt) {
    //Moving checkbox
    checkboxSublist[5]->SetValue(false);

    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=coverPanel->GetPosition();
    coverPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=coverPanel->GetSize();
    coverPanel->SetSize(wxSize(220,panelSize.y+25));

    --numberSublist;
}
void MyCard::SetCheckBox1(wxCommandEvent &evt) {
    if(checkboxSublist[0]->GetValue()){
        labelsSublist[0]=true;
        checkboxSublist[0]->SetValue(true);
    }else{
        labelsSublist[0]=false;
        checkboxSublist[0]->SetValue(false);
    }
    evt.Skip();
}


void MyCard::SetCheckBox2(wxCommandEvent &evt) {
    if(checkboxSublist[1]->GetValue()){
        labelsSublist[1]=true;
        checkboxSublist[1]->SetValue(true);
    }else{
        labelsSublist[1]=false;
        checkboxSublist[1]->SetValue(false);
    }
    evt.Skip();
}

void MyCard::SetCheckBox3(wxCommandEvent &evt) {
    if(checkboxSublist[2]->GetValue()){
        labelsSublist[2]=true;
        checkboxSublist[2]->SetValue(true);
    }else{
        labelsSublist[2]=false;
        checkboxSublist[2]->SetValue(false);
    }
    evt.Skip();
}

void MyCard::SetCheckBox4(wxCommandEvent &evt) {
    if(checkboxSublist[3]->GetValue()){
        labelsSublist[3]=true;
        checkboxSublist[3]->SetValue(true);
    }else{
        labelsSublist[3]=false;
        checkboxSublist[3]->SetValue(false);
    }
    evt.Skip();
}

void MyCard::SetCheckBox5(wxCommandEvent &evt) {
    if(checkboxSublist[4]->GetValue()){
        labelsSublist[4]=true;
        checkboxSublist[4]->SetValue(true);
    }else{
        labelsSublist[4]=false;
        checkboxSublist[4]->SetValue(false);
    }
    evt.Skip();
}

void MyCard::SetCheckBox6(wxCommandEvent &evt) {
    if(checkboxSublist[5]->GetValue()){
        labelsSublist[5]=true;
        checkboxSublist[5]->SetValue(true);
    }else{
        labelsSublist[5]=false;
        checkboxSublist[5]->SetValue(false);
    }
    evt.Skip();
}

//CREATE MEMBERS
void MyCard::NewMember(wxCommandEvent &evt) {
    if(numberMember==0){
        Member[0]->SetLabel(nameMember->GetValue());
        labelMember[0]=nameMember->GetValue();
        hidingPanel->SetPosition(wxPoint(10,165));
        hidingPanel->SetSize(wxSize(130,60));

        numberMember++;

    }else if(numberMember==1){
        Member[1]->SetLabel(nameMember->GetValue());
        labelMember[1]=nameMember->GetValue();
        hidingPanel->SetPosition(wxPoint(10,190));
        hidingPanel->SetSize(wxSize(130,35));

        numberMember++;

    }else if(numberMember==2){
        Member[2]->SetLabel(nameMember->GetValue());
        labelMember[2]=nameMember->GetValue();
        hidingPanel->SetPosition(wxPoint(10,215));
        hidingPanel->SetSize(wxSize(130,10));
        numberMember++;

    }else {
        wxMessageDialog *dial = new wxMessageDialog(NULL,
                                                    wxT("Max number of members reached"), wxT("Exclamation"),
                                                    wxOK | wxICON_EXCLAMATION);
        dial->ShowModal();
    }
}
void MyCard::RemoveMember1(wxCommandEvent &evt) {
    //Move labels
    Member[0]->SetLabel(Member[1]->GetLabel());
    labelMember[0]=Member[0]->GetLabel();
    Member[1]->SetLabel(Member[2]->GetLabel());
    labelMember[1]=Member[1]->GetLabel();

    //Moving and resizing panel;
    struct panelPosition{
        int x,y;
    };
    wxPoint panelPosition=hidingPanel->GetPosition();
    hidingPanel->SetPosition(wxPoint(10,panelPosition.y-25));
    struct panelSize{
        int x,y;
    };
    wxSize panelSize=hidingPanel->GetSize();
    hidingPanel->SetSize(wxSize(130,panelSize.y+25));

    --numberMember;
}

void MyCard::RemoveMember2(wxCommandEvent &evt) {
    //Move labels
    Member[1]->SetLabel(Member[2]->GetLabel());
    labelMember[1]=Member[1]->GetLabel();

    //Moving and resizing panel;
    struct panelPosition1{
        int x,y;
    };
    wxPoint panelPosition1=hidingPanel->GetPosition();
    hidingPanel->SetPosition(wxPoint(10,panelPosition1.y-25));
    struct panelPosition2{
        int x,y;
    };
    wxSize panelPosition2=hidingPanel->GetSize();
    hidingPanel->SetSize(wxSize(130,panelPosition2.y+25));

    --numberMember;
}

void MyCard::RemoveMember3(wxCommandEvent &evt) {
    //Moving and resizing panel;
    struct panelPosition1{
        int x,y;
    };
    wxPoint panelPosition1=hidingPanel->GetPosition();
    hidingPanel->SetPosition(wxPoint(10,panelPosition1.y-25));
    struct panelPosition2{
        int x,y;
    };
    wxSize panelPosition2=hidingPanel->GetSize();
    hidingPanel->SetSize(wxSize(130,panelPosition2.y+25));

    --numberMember;
}

//CREATE BUTTONS
void MyCard::CreateButtons() {
    //GetThisListName
    wxButton*thisList;
    for(int i=0;i<4;i++){
        if(this->GetParent()->GetParent()==anyPanel[i]){
            wxStaticText*current=new wxStaticText(cardFrame->rightPanel,-1,"Current List:",wxPoint(10,250));
            thisList=new wxButton(cardFrame->rightPanel,-1,anyTitle[i],wxPoint(100,250),wxSize(100,25));
        }
    }
    //Create button to move cards in other lists
    if(cardFrame){
        wxStaticText*other=new wxStaticText(cardFrame->rightPanel,-1,"Move to:",wxPoint(10,270));
        int count=0,absent=3;
        for(int i=0;i<4;i++){
            //if(!anyTitle[i])break;
            if(this->GetParent()->GetParent()==anyPanel[i])continue;//Don't create button for this card'list
            if(!!anyPanel[i]){
                if(anyPanel[i]->GetChildren()[2]->GetChildren().size()>6)continue;//Don't create button for full lists
                listName[i]=new wxButton(cardFrame->rightPanel,10001+i,anyTitle[i],wxPoint(15,300+count*25),wxSize(100,25));
                count++;
            }else{
                absent--;
            }
        }
        wxPanel*goodCover=new wxPanel(cardFrame->rightPanel,-1,wxPoint(15,300+absent*25));
        goodCover->SetBackgroundColour(wxColor(70,70,120,70));
    }
}

//MOVE BUTTON TO ANOTHER LIST
void MyCard::OnButton1(wxCommandEvent &evt) {
    //Move the cards on the top if they need
    struct panelPosition1{
        int x,y;
    };
    wxPoint panelPosition1=this->GetPosition();
    struct panelPosition2{
        int x,y;
    };
    for(int j=0;j<4;j++){
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                for(int i=3;i<(this->anyPanel[j]->GetChildren()[2]->GetChildren().size());i++){
                    wxPoint panelPosition2=this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->GetPosition();

                    if(panelPosition1.y<panelPosition2.y){
                        this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->SetPosition(wxPoint(panelPosition2.x,panelPosition2.y-70));
                    }
                }

    }
    for(int j=0;j<4;j++)
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                *numCard[j]=*numCard[j]-1;

    //Move ths card to the other list
    this->Reparent(anyPanel[0]->GetChildren()[2]);
    this->SetPosition(wxPoint(5,70+(this->anyPanel[0]->GetChildren()[2]->GetChildren().size()-3)*70));
    CreateButtons();
    *numCard[0]=*numCard[0]+1;


}
void MyCard::OnButton2(wxCommandEvent &evt) {
    //Move the cards on the top if they need
    struct panelPosition1{
        int x,y;
    };
    wxPoint panelPosition1=this->GetPosition();
    struct panelPosition2{
        int x,y;
    };
    for(int j=0;j<4;j++){
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                for(int i=3;i<(this->anyPanel[j]->GetChildren()[2]->GetChildren().size());i++){
                    wxPoint panelPosition2=this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->GetPosition();

                    if(panelPosition1.y<panelPosition2.y){
                        this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->SetPosition(wxPoint(panelPosition2.x,panelPosition2.y-70));
                    }
                }

    }
    for(int j=0;j<4;j++)
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                *numCard[j]=*numCard[j]-1;

    //Move ths card to the other list
    this->Reparent(anyPanel[1]->GetChildren()[2]);
    this->SetPosition(wxPoint(5,70+(this->anyPanel[1]->GetChildren()[2]->GetChildren().size()-3)*70));
    CreateButtons();
    *numCard[1]=*numCard[1]+1;
}
void MyCard::OnButton3(wxCommandEvent &evt) {
    //Move the cards on the top if they need
    struct panelPosition1{
        int x,y;
    };
    wxPoint panelPosition1=this->GetPosition();
    struct panelPosition2{
        int x,y;
    };
    for(int j=0;j<4;j++){
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                for(int i=3;i<(this->anyPanel[j]->GetChildren()[2]->GetChildren().size());i++){
                    wxPoint panelPosition2=this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->GetPosition();

                    if(panelPosition1.y<panelPosition2.y){
                        this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->SetPosition(wxPoint(panelPosition2.x,panelPosition2.y-70));
                    }
                }

    }
    for(int j=0;j<4;j++)
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                *numCard[j]=*numCard[j]-1;

    //Move ths card to the other list
    this->Reparent(anyPanel[2]->GetChildren()[2]);
    this->SetPosition(wxPoint(5,70+(this->anyPanel[2]->GetChildren()[2]->GetChildren().size()-3)*70));
    CreateButtons();
    *numCard[2]=*numCard[2]+1;
}
void MyCard::OnButton4(wxCommandEvent &evt) {
    //Move the cards on the top if they need
    struct panelPosition1{
        int x,y;
    };
    wxPoint panelPosition1=this->GetPosition();
    struct panelPosition2{
        int x,y;
    };
    for(int j=0;j<4;j++){
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                for(int i=3;i<(this->anyPanel[j]->GetChildren()[2]->GetChildren().size());i++){
                    wxPoint panelPosition2=this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->GetPosition();

                    if(panelPosition1.y<panelPosition2.y){
                        this->anyPanel[j]->GetChildren()[2]->GetChildren()[i]->SetPosition(wxPoint(panelPosition2.x,panelPosition2.y-70));
                    }
                }

    }
    for(int j=0;j<4;j++)
        if(anyPanel[j])
            if(this->GetParent()==this->anyPanel[j]->GetChildren()[2])
                *numCard[j]=*numCard[j]-1;

    //Move ths card to the other list
    this->Reparent(anyPanel[3]->GetChildren()[2]);
    this->SetPosition(wxPoint(5,70+(this->anyPanel[3]->GetChildren()[2]->GetChildren().size()-3)*70));
    CreateButtons();
    *numCard[3]=*numCard[3]+1;
}