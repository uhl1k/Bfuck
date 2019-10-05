#include <stdio.h>
#include <stdlib.h>

void cycle (int start)
{

}

void inter ()
{

}

void message ()
{
   printf("Bfuck - minimalistic brainfuck interpreter 0.9\n");
   printf("(c) 2019, Roman Janků, GNU GPLv3\n\n");
}

void help ()
{

}

int main(int argc, char** argv)
{
    //  Reading parameters, skiping first as it is name of the program
    for (int i = 1; i < argc; ++i)
    {
        switch (argv[i])
        {
            case "":
                brake;

            default:
                printf("[ERROR] - Unknown parameter");
        }
    }

    //  showing startup message
    if (1)
    {
        message();
    }

    return (EXIT_SUCCESS);
}
