NAME =	grandmaTD

SRC = AtkTower.cpp  	\
    BuffTower.cpp   	\
    Logger.cpp      	\
    main.cpp        	\
    Map.cpp         	\
    Mob.cpp         	\
    ProdTower.cpp   	\
    Screen.cpp      	\
    Sprite.cpp      	\
    Tower.cpp       	\
    CookingGrandMa.cpp	\
    CakeGrandGa.cpp		\
    TvGrandMa.cpp		\
    Game.cpp    		\
    CaramelGrandGa.cpp

OBJ =	$(SRC:%.cpp=src/%.o)

INC =	-Iinclude		\

SFML = -lsfml-audio		\
	-lsfml-graphics		\
	-lsfml-network		\
	-lsfml-system		\
	-lsfml-window		\


LDFLAGS =

CXXFLAGS= $(INC)\
	-W			\
	-Wall		\
	-Wextra		\

CXX =	g++

RULE =	all

LIBS =

RES =	

all:	$(LIBS) $(NAME)

windows:RES = icon.res
windows:LDFLAGS += -mwindows
windows:icon.res all

icon.res:
	windres icon.rc -O coff -o icon.res

$(NAME):$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(SFML) $(RES)

clean:
	$(RM) $(OBJ)
	$(RM) icon.res

fclean:	clean
	$(RM) $(NAME) $(NAME).exe

ffclean:fclean

re:	fclean all

dbg:	CXXFLAGS += -g -O0
dbg:	RULE = dbg
dbg:	ffclean all
