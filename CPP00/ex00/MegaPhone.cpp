#include <iostream>

int main(int arc, char *arv[])
{
    if (arc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (1);
    }
    for (int i = 1; i < arc ; i++)
    {
        for (int j = 0; arv[i][j]; j++)
            std::cout << (char)std::toupper(arv[i][j]);
        std::cout << " ";
    }
    std::cout << "\n";
    return 0;
}