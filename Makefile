#  最終目的のファイル
TARGET = VectorTest.exe

#  ソースファイル(*.c)の一覧
SRCDIR = src/
SRCS = Vector.c main.c

#  オブジェクトファイル(*.o)の一覧
OBJDIR = obj/
OBJS = ${patsubst %.c,%.o,${SRCS}}
OBJECTS = ${addprefix ${OBJDIR}, ${notdir ${OBJS}}}

#  ヘッダファイルの一覧
HEADDIR = inc/
HEADERS = Vector.h

#  コンパイラ・リンカの指定
CC = i686-pc-cygwin-gcc
CCFLAGS = -Wall -I/usr/include/opengl -I ./inc
LD = $(CC)
LDFLAGS = 
LIBS = -lm -lglpng -lglut32 -lglu32 -lopengl32

#  *.cから*.oを作る方法
.c.o :
		$(CC) $(CCFLAGS) -o -c $< 

#  OBJECTSからTARGETSを作る方法
$(TARGET) : $(OBJS)
		$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBS)

#  make cleanとしたときに実行されるコマンド
clean :
		rm -f $(OBJECTS) $(TARGET) core *~

exe : $(TARGET)
	./$(TARGET)

all : clean $(TARGET) exe