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


#include "uci.h"

bool uci_stop = true;
bool uci_infinite = false;

bool read_line(char* line) {
	// reading a new line of input

	memset(line, '\0', LIM_INPUT);
	if (fgets(line, LIM_INPUT, stdin) != NULL) {
		char* ptr = strchr(line, '\n');
		if (ptr != NULL)
			*ptr = '\0';
		return true;
	}
	return false;
}

void uci_options() {
	// reacting to the 'uci' command
	// outputting all available settings of the engine

	printf("id name Menhir\n");
	printf("id author Jonas Mayr\n");
	printf("uciok\n");
	fflush(NULL);
}

void uci_newgame() {
	// reacting to the 'ucinewgame' command

}

void uci_setoption() {
	// reacting to the 'setoption' command

}

void uci_position() {
	// reacting to the 'position' command

}

void uci_isready() {
	// reacting to the 'isready' command

	printf("readyok\n");
	fflush(NULL);
}

void uci_go() {
	// reacting to the 'go' command

}

void uci_protocol() {
	// communication with the user interface is established using the UCI protocol
	// https://www.chessprogramming.org/UCI
	
	char line[LIM_INPUT] = { 0 };
	uci_newgame();

	do { // communication loop
		
		read_line(&line[0]);

		if (!strcmp(line, "uci"))
		{
			if (!uci_stop) continue;
			uci_options();
		}
		else if (!strcmp(line, "ucinewgame"))
		{
			if (!uci_stop) continue;
			// stop search
			uci_newgame();
		}
		else if (strstr(line, "setoption") == line)
		{
			if (!uci_stop) continue;
			// stop search
			uci_setoption();
		}
		else if (strstr(line, "position") == line)
		{
			if (!uci_stop) continue;
			// stop search
			uci_position();
		}
		else if (!strcmp(line, "isready"))
		{
			uci_isready();
		}
		else if (strstr(line, "go") == line)
		{
			if (!uci_stop) continue;
			// stop search
			uci_go();
		}
		else if (!strcmp(line, "ponderhit"))
		{
			uci_infinite = false;
		}
		else if (!strcmp(line, "stop"))
		{
			// stop search
			uci_infinite = false;
		}

	} while (strcmp(line, "quit"));
}
