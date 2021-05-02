#
# Menhir, a chess engine. Copyright 2021 Jonas Mayr.
#
# Menhir is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Menhir is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Menhir. If not, see <http://www.gnu.org/licenses/>.
#

# files

NAME   = Menhir
SOURCE = main.c uci.c

# basic flags

CFLAGS = -std=c11 -O3 -flto
WFLAGS = -Wall -Wextra -Wpedantic -Wshadow
LFLAGS = -s -lm -lpthread

# targeted architecture

ifeq ($(ARCH),)
    CFLAGS += -march=native
    ARCH    = native
endif

ifeq ($(ARCH),x64)
    CFLAGS += -m64
endif

ifeq ($(ARCH),x64-popcnt)
    CFLAGS += -m64 -msse3 -mpopcnt -DPOPCNT
endif

ifeq ($(ARCH),x64-pext)
    CFLAGS += -m64 -msse3 -mpopcnt -DPOPCNT -mbmi2 -DPEXT
endif

ifeq ($(ARCH),x86)
    CFLAGS += -m32
endif

ifeq ($(ARCH),armv7)
    CFLAGS += -m32 -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mthumb
endif

ifeq ($(ARCH),armv8)
    CFLAGS += -m64 -march=armv8-a
endif

# targeted operating system

OS = $(shell uname -s)

ifneq ($(ARCH),native)
    ANNEX = -$(ARCH)
endif

ifeq ($(ARCH),$(filter $(ARCH),armv7 armv8))
    OS = Android
endif

ifeq ($(OS),Android)
    CFLAGS += -pie -fPIE -fno-strict-overflow -fno-strict-aliasing -ffunction-sections -fdata-sections -flto
    LFLAGS += -Wl,-pie -Wl,--gc-sections -static-libstdc++
endif

ifeq ($(OS),Linux)
    CFLAGS += -flto
endif

ifneq ($(OS),Linux)
ifneq ($(OS),Android)
    CFLAGS += -static
    ANNEX   = -$(ARCH).exe
endif
endif

# compiler

ifeq ($(COMP),)
    COMP = gcc
endif

# targets

all: release

release:
	$(COMP) $(CFLAGS) $(WFLAGS) -DNDEBUG $(SOURCE) $(LFLAGS) -o $(NAME)$(ANNEX)

debug:
	$(COMP) $(CFLAGS) $(WFLAGS) $(SOURCE) $(LFLAGS) -o $(NAME)$(ANNEX)

tune:
	$(COMP) $(CFLAGS) $(WFLAGS) -DNDEBUG -DTUNE $(SOURCE) $(LFLAGS) -o $(NAME)-tune-$(ANNEX)

help:
	@echo "make release [ARCH=architecture] [COMP=compiler]"
	@echo "see readme.md for more details"
