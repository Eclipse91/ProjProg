//
// Created by myself on 4/2/20.
//

#ifndef TEST00_MYCARDFRAME_H
#define TEST00_MYCARDFRAME_H


#include "wx/wx.h"

class MyCardFrame: public wxFrame {
public:
    MyCardFrame(wxWindow *parent,
                wxWindowID id,
                const wxString& name,
                const wxPoint& pos,
                const wxSize& size);
    wxButton*Card;

    wxCheckBox*Label1;
    wxButton*highPriority;
    wxListBox*SubList;
    void AddLabel(wxCommandEvent &evt);
    wxPanel*PanelUno;
    wxPanel*PanelDue;
    wxPanel*PanelTre;
    wxPanel*PanelQuattro;
};


#endif //TEST00_MYCARDFRAME_H
