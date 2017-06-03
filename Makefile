SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:.cpp=.o)

FLAGS = -std=c++11
INCLUDES = -I../GL_Context/src/ -F/Library/Frameworks/
FRAMEWORKS = -framework SDL2 -framework OpenGL

all: $(OBJS)
	mv *.o ./bin

%.o: %.cpp
	g++ -c $< $(INCLUDES) $(FLAGS)

test: all
	$(MAKE) -C ../GL_Context
	cd bin && g++ $(FLAGS) $(INCLUDES) $(FRAMEWORKS) *.o ../../GL_Context/bin/*.o -o $@

clean:
	cd bin && rm *.o
