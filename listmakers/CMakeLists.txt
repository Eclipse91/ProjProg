project(listmakers)

set(HEADER_FILES
        Observer.h
        Subject.h
        Model.h
        Controller.h
        View.h
        MyApp.h
        MyPanel.h
        MyCard.h
        MyCardFrame.h
        MySublist.h
        )

set(SOURCE_FILES
        View.cpp
        MyPanel.cpp
        MyCard.cpp
        MyCardFrame.cpp
        MySublist.cpp
        )

add_library(listmakers STATIC ${SOURCE_FILES} ${HEADER_FILES})