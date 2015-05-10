CXXFLAGS =	-std=c++11 -O2 -g -Wall -Wextra -fmessage-length=0 -mavx
AS=/Users/syerramreddy/binutils/usr/local/bin/as
OBJS = test_temp.o
OBJ_DUMPS:=$(addsuffix .objdump, $(basename $(OBJS)))
LIBS =

TARGET =	 test
#
$(TARGET):	$(OBJS) 
	g++ -o $(TARGET) $(OBJS) $(LIBS)
%.objdump:%.o
	objdump -d -S $< > $@
all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
