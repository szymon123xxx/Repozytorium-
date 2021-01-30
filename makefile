
OBJS = main.o game.o player.o enemy.o wall.o menu.o scoreAndGraph.o menuLevels.o menuMusic.o menuListScore.o
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

game: $(OBJS)
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDLIBS)

$(OBJS): game.h

$(OBJS): player.h

$(OBJS): enemy.h

$(OBJS): wall.h

$(OBJS): menu.h

$(OBJS): scoreAndGraph.h

$(OBJS): menuLevels.h

$(OBJS): menuMusic.h

$(OBJS): menuListScore.h

clean:
	$(RM) game $(OBJS)
