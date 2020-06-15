#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"             // Contains the structures used in the project
#include "catalogueHandler.h"   // Contains the functions to handle Netflix, business logic

//    printf("Type the operation you want to perform\n"
//           "0 -> add a show \n"
//           "1 -> remove a show\n"
//           "2 -> edit a show\n"
//           "3 -> scroll playlist menu\n"
//           "4 -> merge playlists");
//    int userSelection = getNumericAnswerFromUser(4);

int main()
{
    //Creazione di una PLAYLIST. Utilizzare e riempire questa playlist
    PlayList p;
    strcpy(p.name, "My favourite TV Series");
    p.top = NULL;


    //altre chiamate e istruzioni per testare il funzionamento delle funzioni create

    // testing on top insert:
    TVS topT = {"Doraemon", "Comics", 500};
    insertTVSeries(&p, &topT);
    printPlayList(&p);
    // insert a second show
    TVS second = {"Kiss Me Licia", "Comics", 300};
    insertTVSeries(&p, &second);
    printPlayList(&p);
    //insert a third show
    TVS third = {"Biancaneve e i 7 nani", "Comics", 300};
    insertTVSeries(&p, &third);
    printPlayList(&p);

    // the applicaton is now showing a scrolling menu
    playlistScroll(&p);

    // deleting two shows
    deleteTVSeries(&p, &third);
    deleteTVSeries(&p, &topT);

    // editing another one
    modifyTVSeries(&p, &second);

    // printing the playlist
    printPlayList(&p);

    return 0;
}