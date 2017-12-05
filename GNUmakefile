MODULES := classes globals
#look for include files in each of the modules
CFLAGS += $(patsubst %,-I%,$(MODULES))
#extra libraries if required
LIBS :=
#each module will add to this
SRC := solver.cpp
#include the description for each module
include $(patsubst %,%/module.mk,$(MODULES))
#determine the object files
OBJ :=                    \
  $(patsubst %.cpp,%.o,     \
    $(filter %.cpp,$(SRC))) \
  $(patsubst %.h,%.o,     \
    $(filter %.h,$(SRC)))
#link the program
prog: $(OBJ)
  $(CC) -o $@ $(OBJ) $(LIBS)
#include the C include dependencies
include $(OBJ:.o=.d)
#calculate C include dependencies
%.d: %.c
  depend.sh ‘dirname $*.c‘ \
  $(CFLAGS) $*.c > $@
