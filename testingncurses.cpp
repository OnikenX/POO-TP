#include <ncurses.h>
#include <string.h>

int main()
{
    int i, maxy, maxx;

    initscr();
    echo();

    getmaxyx(stdscr, maxy, maxx);
    char str[maxx];
    char history[3][maxx];
    for (i = 0; i < 3; ++i)
        strcpy(history[i], " ");
    WINDOW *racewin = newwin(maxy - 7, maxx - 1, 0, 0); //window for the race
    WINDOW *cmdwin = newwin(1, maxx - 1, maxy - 5, 0);  //window for the cmd
    WINDOW *outwin = newwin(3, maxx -1 , maxy - 3, 0);  //window for output(up to 3 lines of history)
    if (!racewin || !cmdwin || !outwin)
    {
        printf("OOPSIE WOOPSIE!! Uwu We made a fucky wucky!! A wittle fucko boingo! The code monkeys at our headquarters are working VEWY HAWD to fix this!");
        return 3;
    }
    for (i = 0; i < maxx; ++i)
        mvprintw(maxy - 6, i, "-");
    for (i = 0; i < maxx; ++i)
        mvprintw(maxy - 4, i, "-");

    wrefresh(stdscr);
    while (strcmp(str, "sair"))
    {
        wclear(cmdwin);
        wrefresh(cmdwin);
        wprintw(cmdwin, "comand> ");
        wrefresh(cmdwin);
        wgetstr(cmdwin, str);
        strcpy(history[2], history[1]);
        strcpy(history[1], history[0]);
        strcpy(history[0], str);    
        wclear(outwin);
        for (int i = 0; i < 3; ++i)
        {
            mvwprintw(outwin, i, 0, "%s", history[2 - i]);
        }
        wrefresh(outwin);
    }
    return 0;
}
