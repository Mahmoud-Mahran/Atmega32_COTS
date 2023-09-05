#include    <stdio.h>
#include    <stdlib.h>
#include    "../00 LIB/STD_TYPES.h"
#include    "../02 HAL/03 LCD/LCD_interface.h"
#include    "../02 HAL/04 KEYPAD/KEYPAD_interface.h"
#include    "snake.h"
Snake Draco;
static u8 score   = 0;
static u8 foodExists = 0;
void Snake_voidInit(Snake* q) {
	q->tail = NULL;
	q->head = NULL;
	q->size = 0;
}
void Snake_voidEnQueue(Snake* q, s8 cpy_s8Row, s8 cpy_s8Col) {
	SnakeNode* pn = (SnakeNode*) malloc(sizeof(SnakeNode));
	pn->row_i = cpy_s8Row;
	pn->col_i = cpy_s8Col;
	pn->next = NULL;
	if (Snake_s16IsEmpty(q)) {
		q->tail = pn;
	} else {
		q->head->next = pn;
	}
	q->head = pn;
	q->size++;
	HLCD_voidGoToCursor(pn->row_i, pn->col_i);
	HLCD_voidSendChar(0xFF);
}
void Snake_voidPrint(Snake* q) {
	SnakeNode* pn = q->tail;
	if (Snake_s16IsEmpty(q)) {
		return;
	}
	u16 i = 1;
	while (pn != NULL) {
		pn = pn->next;
		i++;
	}
}
void Snake_voidDeQueue(Snake* q) {
	if (Snake_s16IsEmpty(q)) {
	} else {
		SnakeNode* pn = q->tail;
		q->tail = q->tail->next;
		HLCD_voidGoToCursor(pn->row_i, pn->col_i);
		HLCD_voidSendChar(' ');
		free(pn);
		if (Snake_s16IsEmpty(q)) {
			q->head = NULL;
		}
		q->size--;
	}
}
s16 Snake_s16IsEmpty(Snake* q) {
	return (q->tail == NULL);
}
s16 Snake_s16Size(Snake* q) {
	return q->size;
}
s16  Snake_s16NodeExists(Snake* q,s8 row,s8 col){
	SnakeNode* pn = q->tail;
	while (pn != q->head) {
		if(pn->row_i == row && pn->col_i == col) return 1;
		pn = pn->next;
	}
	return 0;
}
void snake_setup(void) {

	HKEYBAD_voidInit();
	HLCD_voidInit();
	Snake_voidInit(&Draco);
	//Snake_voidEnQueue(&Draco, 1, 7);
	Snake_voidEnQueue(&Draco, 1, 8);
	score = 0;
	foodExists = 0;
	//snake_logic(RIGHT);
}
void snake_logic(u8 d) {
	static u8 counter = 1;
	if (counter == 2){
		s8 row = Draco.head->row_i;
			s8 col = Draco.head->col_i;

			Snake_voidDeQueue(&Draco);
			switch (d) {
			case UP:
				row--;
				break;
			case RIGHT:
				col++;
				break;
			case DOWN:
				row++;
				break;
			case LEFT:
				col--;
				break;
			}
			if (row > 2)
				row = 1;
			if (row < 1)
				row = 2;
			if (col > 16)
				col = 1;
			if (col < 1)
				col = 16;
			Snake_voidEnQueue(&Draco, row, col);
			if(Snake_s16NodeExists(&Draco, row, col)){
				Snake_GameOver();
				snake_setup();
			}
			counter = 1;
	} else {
		counter++;
	}
}
DIR snake_input(DIR old_dir) {
	DIR temp = IDLE;
	u8 key = 0xff;
	if (HKEYBAD_u8GetPressed() != 0xff) {
		key = HKEYBAD_u8GetPressed();
	}
	switch (key) {
	case 2:
		if (old_dir != DOWN)
			temp = UP;
		break;
	case 5:
		if (old_dir != RIGHT)
			temp = LEFT;
		break;
	case 7:
		if (old_dir != LEFT)
			temp = RIGHT;
		break;
	case 10:
		if (old_dir != UP)
			temp = DOWN;
		break;
	default:
		temp = IDLE;
		break;
	}
	return temp;
}
void snake_food(void) {
	static s8 foodRow = 0;
	static s8 foodCol = 0;
	if (foodExists == 1) {
		if (Draco.head->col_i == foodCol && Draco.head->row_i == foodRow) {
			Snake_voidEnQueue(&Draco, foodRow, foodCol);
			score++;
			foodExists = 0;
		}
	} else if (foodExists == 0) {
		foodCol = Draco.tail->col_i + 2;
		foodRow = Draco.tail->row_i + 1;
		if (foodRow > 2)
			foodRow = 1;
		if (foodRow < 1)
			foodRow = 2;
		if (foodCol > 16)
			foodCol = 1;
		if (foodCol < 1)
			foodCol = 16;
		HLCD_voidGoToCursor(foodRow, foodCol);
		HLCD_voidSendChar(0xDB);
		foodExists = 1;
	}

}
void Snake_GameOver(void){
	for(int i = 0; i < 3; i++){
		HLCD_voidSendCommand(LCD_DISPLAY_OFF);
		delay_ms(500);
		HLCD_voidSendCommand(LCD_DISPLAY_ON);
		delay_ms(500);
	}
	u8 key = 0xff;

	HLCD_voidSendCommand(LCD_CLEAR_SC);
	HLCD_voidSendString((u8*)"   YOU DIED!");
	HLCD_voidGoToCursor(2,4);
	HLCD_voidSendString((u8*)"Score:");
	HLCD_voidSendNum(score);
	while(key != 6){
		if (HKEYBAD_u8GetPressed() != 0xff) {
			key = HKEYBAD_u8GetPressed();
		}
	}
	HLCD_voidSendCommand(LCD_CLEAR_SC);

}
