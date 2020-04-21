#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"             // Contains the structures used in the project
#include "catalogueHandler.h"   // Contains the functions to handle Netflix, business logic

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

    TVS second = {"Kiss Me Licia", "Comics", 300};
    insertTVSeries(&p, &second);
    printPlayList(&p);


    TVS third = {"Biancaneve e i 7 nani", "Comics", 300};
    insertTVSeries(&p, &third);
    printPlayList(&p);

    playlistScroll(&p);

    deleteTVSeries(&p, &third);
    deleteTVSeries(&p, &topT);

    modifyTVSeries(&p, &second);

    printPlayList(&p);


    return 0;
}