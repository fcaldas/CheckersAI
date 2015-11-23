CXXFLAGS =	-O0 -g -Wall -fmessage-length=0 -std=gnu++11

OBJS =	CheckersAI.o utils/sdlfunctions.o objects/Piece.o objects/Game.o objects/Table.o objects/Drawable.o objects/Player.o objects/players/AI.o objects/players/Human.o objects/players/AImove.o  objects/players/AITable.o objects/TableBase.o

LIBS =	-lSDL -lSDL_image

TARGET =	CheckersAI

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
