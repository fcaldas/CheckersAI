CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		CheckersAI.o ./utils/sdlfunctions.o ./objects/Piece.o ./objects/Game.o ./objects/Table.o

LIBS =	-lSDL

TARGET =	CheckersAI

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
