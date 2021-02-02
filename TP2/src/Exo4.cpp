#include <iostream>
#include <string>

int Exo4()
{
    std::cout << "veillier entrer un phrase" << std::endl;
    std::string phrase;
    std::cin >> phrase;

    std::string Inf = "INF";

    int i = 0;
    int correctPosition = 0;
    while (i < phrase.length())
    {

        int temp = i;
        int j = 0;
        while (j < Inf.length())
        {
            if (Inf[j] == phrase[temp])
            {
                correctPosition++;
                j++;
                temp++;
            }
        }

        if (correctPosition == Inf.length())
        {
            std::cout << i << std::endl;
            return 0;
        }
        else
        {
            correctPosition = 0;
            i++;
        }
    }
}
