#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*

<program>  Copyright (C) <year>  <name of author>
    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
    This is free software, and you are welcome to redistribute it
    under certain conditions; type `show c' for details.

*/

bool about = false;
bool help = false;

FILE * file;



void cycle (int start)
{

}

void inter ()
{

}

void printAbout ()
{
    printf("Bfuck 0.9 beta (c) 2019  Roman Janků\n\n");

    printf("Bfuck is a minimalistick brainfuck language interpreter written\n");
    printf("in c as a fun project to learn how to code in c.\n\n");

    printf("This program is free software: you can redistribute it and/or modify\n");
    printf("it under the terms of the GNU General Public License as published by\n");
    printf("the Free Software Foundation, either version 3 of the License, or\n");
    printf("(at your option) any later version.\n\n");

    printf("This program is distributed in the hope that it will be useful,\n");
    printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
    printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
    printf("GNU General Public License for more details.\n\n");

    printf("You should have received a copy of the GNU General Public License\n");
    printf("along with this program.  If not, see <https://www.gnu.org/licenses/>.\n");
}

void parseParams (int argc, char** argv)
{
    //  looping thru parameters
    for (int i = 1; i < argc;)
    {
        //  the about parameter
        if (strcmp(argv[i], "-a") == 0)
        {
            about = true;
            i++;
        }
        //  the help parameter
        else if (strcmp(argv[i], "-h") == 0)
        {

        }
        //  the file parameter
        else if (strcmp(argv[i], "-f") == 0)
        {

        }
        //  the parameter changing size of the array
        else if (strcmp(argv[i], "-f") == 0)
        {

        }
        //  unknown parameter
        else
        {
            printf("[WARNING] - Parameter %s is not valid and was skipped.\n", argv[i]);
            i++;
        }
    }
}

int main(int argc, char** argv)
{
    parseParams(argc, argv);

    if (about)
    {
        printAbout();
    }
    else if (help)
    {

    }
    else if (file != NULL)
    {

    }
    else
    {

    }

    return (EXIT_SUCCESS);
}
