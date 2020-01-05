

int global::campeonatocmd(std::vector<atd *> campautos)
{
    int i;
    initscr();
    
    if (debuging == 1)
    {
    
        i = 0;
        std::cout << "autodromos:" << std::endl;
        for (auto it = campautos.begin(); it != campautos.end(); ++i, ++it)
        {
            std::cout << campautos[i]->getnome() << std::endl;
        }
    }

    for (;;) {
        
        "comando> ";
        fflush(stdout);
        std::getline(std::cin, cmd);

        std::istringstream bufi(cmd);
        std::ostringstream oss;
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
    return 0;
};
