# Bfuck

Bfuck is a minimalistic Brainfuck interpreter written in C as a small excercise
I made up for my self.

## Getting Started


### Prerequisites

This interpreter will run on any hardware that can run C programs and have at
least TUI (text user interface), keyboard and some Brainfuck source files on
a permanent storage. The size of memory array can be adjusted to the programers
needs and machines limitations.

### Installing



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
* Is a first working version.

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
