#ifndef   SNAKE_H
#define	  SNAKE_H

typedef struct snakeNode {
	s8 row_i;
	s8 col_i;
	struct snakeNode* next;
} SnakeNode;

typedef struct {
	u16 size;
	SnakeNode* tail;
	SnakeNode* head;
} Snake;
typedef enum {
	IDLE,UP, RIGHT, DOWN, LEFT
} DIR;
void Snake_voidInit(Snake*);
void Snake_voidEnQueue(Snake*, s8, s8);
void Snake_voidPrint(Snake*);
void Snake_voidDeQueue(Snake*);
s16  Snake_s16IsEmpty(Snake*);
s16  Snake_s16Size(Snake*);
s16  Snake_s16NodeExists(Snake*,s8,s8);
void snake_setup(void);
void snake_logic(u8);
DIR  snake_input(DIR old_dir);
void snake_food(void);
void Snake_GameOver(void);
#endif
