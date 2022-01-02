CC = g++
#add flags here -> NOT separate for iconmaker
#for iconmaker -> separate make file (in iconmaker) with more CFLAGS
CFLAGS = -g -std=c++17

controller: controller.cpp light.cpp controller_helper.cpp csv_reader.cpp events.cpp csv_writer.cpp
	$(CC) $(CFLAGS) -o controller controller.cpp light.cpp controller_helper.cpp csv_reader.cpp events.cpp csv_writer.cpp

clean :
	$(RM) controller