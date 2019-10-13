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

void initialize ()
{
  pos = 0;
  memptr = 0;
  memlen = 30000;
}

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

void parseParameters (int argc, char** argv)
{
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

void createMemory ()
{
  mem = (char*) malloc(memlen * sizeof(char));

  for (int i = 0; i < memlen; i++)
  {
    mem[i] = 0;
  }
}

void readProgram ()
{
  FILE* fp = fopen(filename, "r");

  int ch;
  prg = realloc(NULL, sizeof(char) * 10);
  prglen = 10;

  if (!prg)
  {
    printf("[ERROR] - could not allocate memory for program.");
    exit(0);
  }

  int read = 0;

  while (EOF != (ch = fgetc(fp)))
  {
    if (ch == '<' || ch == '>' || ch == '+' || ch == '-' || ch == '.' || ch == ',' || ch == '[' || ch == ']')
    {
      if (read == prglen - 1)
      {
        prglen = prglen * 2;
        prg = realloc(prg, sizeof(char) * prglen);
      }
      prg[read] = ch;
      read++;
    }
  }

  prglen = read;
  prg = realloc(prg, sizeof(char) * prglen);
}

void interpret ()
{
  while (pos < prglen)
  {
    if (prg[pos] == '<')
    {
      if (pos == 0)
      {
        printf("\n[ERROR] - Program pointer cannot be decremented to negative numbers!\n\n");
        exit(0);
      }
      memptr--;
      pos++;
    }
    else if (prg[pos] == '>')
    {
      if (pos == memlen - 1)
      {
        printf("\n[ERROR] - Program pointer cannot be decremented to negative numbers!\n\n");
        exit(0);
      }
      memptr++;
      pos++;
    }
    else if (prg[pos] == '+')
    {
      mem[memptr]++;
      pos++;
    }
    else if (prg[pos] == '-')
    {
      mem[memptr]--;
      pos++;
    }
    else if (prg[pos] == '.')
    {
      printf("%c", mem[memptr]);
      pos++;
    }
    else if (prg[pos] == ',')
    {
      scanf("%c", mem[memptr]);
      pos++;
    }
    else if (prg[pos] == '[')
    {
      if (mem[memptr] == 0)
      {
        pos++;
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
        }
      }
      else
      {
        pos++;
      }
    }
    else if (prg[pos] == ']')
    {
      if (mem[memptr] == 0)
      {
        pos++;
      }
      else
      {
        pos--;
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
        }
      }
    }
  }
}

int main(int argc, char** argv)
{
  initialize();
  parseParameters(argc, argv);
  createMemory();
  readProgram();
  interpret();
}
