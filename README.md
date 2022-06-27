
## FE-Clib fit to Decomp

A newer C headers with references fit to [FE8U decomp](https://github.com/FireEmblemUniverse/fireemblem8u.git) at date 2022.05.03 by Mokha.


## Usage

Please refer to StanH's [GBAFE hack in C toturial]().

Here is an [example](https://github.com/MokhaLeee/FE-cHack-Template.git) via new C-Lib to build Decomp-based CHAX.


## Usage (with DevkitARM):

Build makefile as below:

```
include $(DEVKITARM)/base_tools

CLIB_DIR := $(realpath .)/Tools/FE-CLib-Mokha
INC_DIRS := Wizardry/include $(CLI_DIR)/include 
INCFLAGS := $(foreach dir, $(INC_DIRS), -I "$(dir)")
ARCH    := -mcpu=arm7tdmi -mthumb -mthumb-interwork
CFLAGS  := $(ARCH) $(INCFLAGS) -Wall -O2 -mtune=arm7tdmi -ffreestanding -mlong-calls
CDEPFLAGS = -MMD -MT "$*.o" -MT "$*.asm" -MF "$(CACHE_DIR)/$(notdir $*).d" -MP

%.o: %.c
	@$(CC) $(CFLAGS) $(CDEPFLAGS) -g -c $< -o $@ $(ERROR_FILTER)


LYN_REF := Tools/FE-CLib-Mokha/reference/FE8U-Decomp-20220503.o
LYN := EventAssembler/Tools/lyn.exe

%.lyn.event: %.o $(LYN_REF)
	@$(LYN) $< $(LYN_REF) > $@
``` 

Finally, type `#include "gbafe.h"` in the header of your own C files.

Then you can use command `make *.lyn.event` to compile your own c-code through Msys2.

Note that `$(CC)` is set as `$(DEVKITARM)/arm-none-eabi-gcc` which is defined in `$(DEVKITARM)/base_tools`, you can also use ARM tool chains for master hackers. `$(LYN)` is path to lyn.exe, usually it can be found in `EventAssembler/Tools`, and the `$(LYN_REF)` holds all of the functions and variables pointers.





## Thanks
- `StanH` and `Laqieer`, constructor of original FE-Clib, Decomp. proj., etc. Cool guys.
- FEU friends, cool guys.
