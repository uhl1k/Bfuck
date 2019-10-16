# Bfuck

Bfuck is a minimalistic Brainfuck interpreter written in C as a small excercise
I made up for my self.

## Getting Started

This chapter will guide you thru the process of downloading, compiling and
running the Bfuck

### Prerequisites

This interpreter will run on any hardware that can run C programs and have at
least TUI (text user interface), keyboard and some Brainfuck source files on
a permanent storage. The size of memory array can be adjusted to the programers
needs and machines limitations.

### Downloading

For downloading the Bfuck go to the release page of this project and download
the source code of the version you fancy (latest version is recommended).
After downloading you have to compile the source code (see the next subchapter)
and you are ready to run.

If you don't want to compile the source code your self you can download already
compiled binaries in the release page. The `bfuck` is for UNIX systems and
`bfuck.exe` is for Windows systems. Then skip to the *Running* subchapter, as
you don't have to compile.

### Compiling

After downloading the source code you have to compile in order to be able to run
it. This can be easily made by `make` command on UNIX systems. On Windows
systems you have to compile it all by your self. The compiled binary will be
placed in `/bin` file (default behaviour). Copy the executable to the
desired location and you are ready to run.

The source code is compiling on gcc version 7.4.0 without any errors and
warnings. If you want to compile the source code your self you are welcome.
The only source file you have to worry about is `/src/bfuck.c`. All functions
are implemented in this file and it has no dependecies but those that should
be available in standard library.

Available targets in make command are:

* **all** will call both clean and build in this order. It is also default
target.
* **clean** will clean all binaries.
* **build** will build the binary.

### Running

```
bfuck [options] FILENAME
```

**FILENAME** is the name of the file with Brainfuck source code that should be
interpreted.

Available **options** are:

* *-h* shows help and terminates the interpreter.
* *-m* sets size of the byte array used as memory. Must be followed by a number
in range 1 - 65535. If used multiple of these options only last is used.

## Built With

* [atom] - (https://atom.io/) - programing
* [gcc] - (gcc 7.4.0) - compiling

## Versioning

* **0.9-beta**
  * firt release version

## Authors

* **Roman Janků** - [uhl1k](https://github.com/uhl1k/)

## License

```
Bfuck - minimalistic brainfuck interpreter written in C
Copyright (C) 2019  uhl1k (Roman Janků)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
