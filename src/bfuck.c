#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//  The array with program
int prglen;
char* prg;

//  The position in program
int pos;

//  The memory for program
int memptr;
int memlen;
char* mem;

//  The file with program
char* filename;

//  Intializes the program variables
void initialize ()
{
  pos = 0;
  memptr = 0;
  memlen = 30000;
}

//  Writes help on screen
void showHelp ()
{
  printf("\n");
  printf("Bfuck - Simple Branfuck interpreter written in C as an excercise.\n");
  printf("(c) 2019, Roman Janků, GNU GPL v3\n");

  printf("-----------------------------------------------------------------\n");

  printf("This program is free software: you can redistribute it and/or\n");
  printf("modify it under the terms of the GNU General Public License as\n");
  printf("published by the Free Software Foundation, either version 3 of\n");
  printf("the License, or (at your option) any later version.\n\n");

  printf("This program is distributed in the hope that it will be useful,\n");
  printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
  printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n");
  printf("GNU General Public License for more details.\n");

  printf("-----------------------------------------------------------------\n");

  printf("bfuck [OPTIONS] FILE\n\n");

   printf("-h   Shows this short help.\n");
   printf("-m   Sets the size of memory, must be followed by integer\n");
   printf("     (For example: bfuck -m 100 source.b)\n");

  printf("\n");
}

//  Parses parameters from the command line
void parseParameters (int argc, char** argv)
{
  //  Loops thru the parameters skipping first (name of binary)
  for (int i = 1; i < argc;)
  {
    //  User wants to show help
    if (strcmp("-h", argv[i]) == 0)
    {
      showHelp();
      exit(0);
    }
    //  User wants to change memory size
    else if (strcmp("-m", argv[i]) == 0)
    {
      if (i == argc - 1)
      {
        printf("[ERROR] - no number after -m option! Will use previous (default) value.\n");
        i++;
      }
      else
      {
        i++;
        memlen = atoi(argv[i]);
        i++;
      }
    }
    //  This should be brainfuck source
    else
    {
      filename = argv[i];
      i++;
    }
  }
}

//  Allocates and clears the memory
void createMemory ()
{
  mem = (char*) malloc(memlen * sizeof(char));

  for (int i = 0; i < memlen; i++)
  {
    mem[i] = 0;
  }
}

//  Reads program from a file
void readProgram ()
{
  //  Variables intialization
  FILE* fp = fopen(filename, "r");
  int ch;
  prglen = 10;

  //  Allocating memory for program
  prg = realloc(NULL, sizeof(char) * 10);
  if (!prg)
  {
    printf("[ERROR] - could not allocate memory for program.");
    exit(0);
  }

  //  The number of char that is Brainfuck instruction that is being read
  int read = 1;

  //  Looping thru each char in file till EOF
  while (EOF != (ch = fgetc(fp)))
  {
    //  Is it Brainfuck instruction?
    if (ch == '<' || ch == '>' || ch == '+' || ch == '-' || ch == '.' || ch == ',' || ch == '[' || ch == ']')
    {
      //  Available memory is filled
      if (read == prglen)
      {
        //  Extending memory
        prglen = prglen * 2;
        prg = realloc(prg, sizeof(char) * prglen);
      }
      //  Putting instruction into program array
      prg[read - 1] = ch;
      read++;
    }
  }
  //  Saving the length of program and trimming excess space
  prglen = read;
  prg = realloc(prg, sizeof(char) * prglen);
}

//  interprets the brainfuck program
void interpret ()
{
  //  Loop till end of the program
  while (pos < prglen - 1)
  {
    //  Move memory pointer left
    if (prg[pos] == '<')
    {
      //  Outside of memory
      if (pos == 0)
      {
        printf("\n[ERROR] - Program pointer cannot be decremented to negative numbers!\n\n");
        exit(0);
      }
      memptr--;
      pos++;
    }
    //  Move memory pointer right
    else if (prg[pos] == '>')
    {
      //  Out of memory
      if (pos == memlen - 1)
      {
        printf("\n[ERROR] - Program pointer cannot be decremented to negative numbers!\n\n");
        exit(0);
      }
      memptr++;
      pos++;
    }
    //  Increment current memory cell
    else if (prg[pos] == '+')
    {
      mem[memptr]++;
      pos++;
    }
    //  Decrement current memory cell
    else if (prg[pos] == '-')
    {
      mem[memptr]--;
      pos++;
    }
    //  Print current memory cell
    else if (prg[pos] == '.')
    {
      printf("%c", mem[memptr]);
      pos++;
    }
    // Read into current memory cell
    else if (prg[pos] == ',')
    {
      scanf("%c", mem[memptr]);
      pos++;
    }
    // The start of loop
    else if (prg[pos] == '[')
    {
      //  Zero in memory, skip the loop
      if (mem[memptr] == 0)
      {
        int cls = pos;
        pos++;
        if (pos == prglen)
        {
          printf("\n[ERROR] - Unclosed loop at %u!\n\n", cls);
          exit(0);
        }
        //  Skip instructions in loop and inner loops
        int depth = 0;
        while(!(prg[pos] == ']' && depth == 0))
        {
          if (prg[pos] == '[')
          {
            depth++;
          }
          else if (prg[pos] == ']')
          {
            depth--;
          }
          pos++;
          if (pos == prglen)
          {
            printf("\n[ERROR] - Unclosed loop at %u!\n\n", cls);
            exit(0);
          }
        }
      }
      //  Start executing loop
      else
      {
        pos++;
      }
    }
    //  The end of a loop
    else if (prg[pos] == ']')
    {
      //  Not executing the loop again
      if (mem[memptr] == 0)
      {
        pos++;
      }
      //  Go to the start of the loop and execute it
      else
      {
        int cls = pos;
        pos--;
        if (pos < 0)
        {
          printf("\n[ERROR] - Unopened loop at %u!\n\n", cls);
          exit(0);
        }
        //  Skip all instructions in loop and inner loops to the start of the loop
        int depth = 0;
        while(!(prg[pos] == '[' && depth == 0))
        {
          if (prg[pos] == ']')
          {
            depth++;
          }
          else if (prg[pos] == '[')
          {
            depth--;
          }
          pos--;
          if (pos < 0)
          {
            printf("\n[ERROR] - Unopened loop at %u!\n\n", cls);
            exit(0);
          }
        }
      }
    }
  }
}

//  The main function of this program
int main(int argc, char** argv)
{
  initialize();
  parseParameters(argc, argv);
  createMemory();
  readProgram();
  interpret();
}
