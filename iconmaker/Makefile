CC = g++
#add flags here -> NOT separate for iconmaker
#for iconmaker -> separate make file (in iconmaker) with more CFLAGS
CFLAGS = -g -Wall -DNO_FREETYPE -lpng -lz -std=c++17

iconmaker: iconmaker.cpp pngwriter.cpp
	$(CC) -o iconmaker -Wall -g -DNO_FREETYPE iconmaker.cpp pngwriter.cpp -lpng -lz

# iconmaker.o: iconmaker.cpp pngwriter.hpp
# 	$(CC) $(CFLAGS) -c iconmaker.cpp

# pngwriter.o: pngwriter.hpp

# types.o: types.hpp

clean :
	$(RM) iconmaker