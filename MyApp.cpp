//
// Created by myself on 3/4/20.
//

#include "MyApp.h"
#include "MyFrame.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    auto frame = new MyFrame();
    frame->Show(true);
    return true;
}