/*
  Menhir, a chess engine. Copyright 2021 Jonas Mayr.

  Menhir is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Menhir is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Menhir. If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

// including libraries that need to be accessible by all other source files

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// defining all limiting constants of the engine

#define LIM_PATH 4096
#define LIM_INPUT 4096
#define LIM_FEN 128