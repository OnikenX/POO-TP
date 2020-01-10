#include "headers/global.hpp"
#include <ncurses.h>
#include <string.h>

int global::campeonatocmd(std::vector<atd *> campautos)
{
    int i, f, maxx, maxy;
    getmaxyx(stdscr, maxy, maxx);
    char strc[maxx];
    
    std::vector<std::string> history;
    //std::string cmd, str, copia, nomefich;

    if (debuging == 1)
    {

        i = 0;
        std::cout << "autodromos:" << std::endl;
        for (auto it = campautos.begin(); it != campautos.end(); ++i, ++it)
        {
            std::cout << campautos[i]->getnome() << std::endl;
        }
    }

    initscr();
    echo();

    for (i = 0; i < 5; ++i)
        history.push_back(" ");

    WINDOW *racewin = newwin(maxy - 7, maxx - 1, 0, 0); //window for the race
    WINDOW *cmdwin = newwin(1, maxx - 1, maxy - 5, 0);  //window for the cmd
    WINDOW *outwin = newwin(3, maxx - 1, maxy - 3, 0);  //window for output(up to 3 lines of history)
    if (!racewin || !cmdwin || !outwin)
    {
        printf("OOPSIE WOOPSIE!! Uwu We made a fucky wucky!! A wittle fucko boingo! The code monkeys at our headquarters are working VEWY HAWD to fix this!\n");
        endwin();
        return 3;
    }
    for (i = 0; i < maxx; ++i)
        mvprintw(maxy - 6, i, "-");
    for (i = 0; i < maxx; ++i)
        mvprintw(maxy - 4, i, "-");

    wrefresh(stdscr);
    while (strcmp(strc, "sair"))
    {
        wclear(cmdwin);
        wrefresh(cmdwin);
        wprintw(cmdwin, "comand> ");
        wrefresh(cmdwin);
        wgetstr(cmdwin, strc);
        history.push_back(strc);

        wclear(outwin);
        i = history.size() - 1;
        f = 0;

        for (; i > history.size() - 4; --i, f++)
        {
            mvwprintw(outwin, f, 0, "%s", history[i].c_str());
        }
        wrefresh(outwin);
    }
    /*
    for (;;)
    {

        
        std::ostringstream Aindex;

        while (bufi >> str)
        {
            copia = str;
            if (copia == "")
            {
                bufi >> nomefich;
            }
        }
    }
    */
    endwin();
    return 0;
};
