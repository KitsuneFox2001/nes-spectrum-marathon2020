/* NES spectrum marathon thing, 2020 adrian09_01 */
 
#include "LIB/neslib.h"
#include "LIB/nesdoug.h" 
#include "nesspect.h" 

#define BLACK 0x0f
#define DK_GY 0x00
#define LT_GY 0x10
#define WHITE 0x30
// there's some oddities in the palette code, black must be 0x0f, white must be 0x30
 
 
 
#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
// all variables should be global for speed
// zeropage global is even faster

unsigned char i;

const unsigned char flag1[]={
0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92
};

const unsigned char flag2[]={
0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92
};

const unsigned char flag3[]={
0x92,0xA6,0x84,0x82,0x82,0x82,0x82,0x82,0x94,0xB6,0x92
};

const unsigned char flag4[]={
0x92,0x84,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x94,0x92	
};

const unsigned char flag5[]={
0x92,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0x92
};

const unsigned char flag6[]={
	0x92,
	0xa2,
	0xa2,
	0xb3,
	0xb5,
	0x92,
	0xa7,
	0xa3,
	0xa2,
	0xa2,
	0x92
};

const unsigned char flag7[]={
	0x92,
	0x83,
	0x83,
	0xb5,
	0x92,
	0x92,
	0x92,
	0xa5,
	0x83,
	0x83,
	0x92
};

const unsigned char flag8[]={
	0x92,
	0x83,
	0x83,
	0x92,
	0x92,
	0x92,
	0x92,
	0x92,
	0x83,
	0x83,
	0x92
};

const unsigned char flag9[]={
	0x92,
	0x82,
	0x82,
	0xb6,
	0x92,
	0x92,
	0x92,
	0xa6,
	0x82,
	0x82,
	0x92
};

const unsigned char flag10[]={
	0x92,
	0x85,
	0x82,
	0x94,
	0xb6,
	0x92,
	0xa6,
	0x84,
	0x82,
	0x95,
	0x92
};

const unsigned char flag11[]={
	0x92,
	0xa7,
	0xa3,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xb3,
	0xb7,
	0x92
};

const unsigned char flag12[]={
	0x92,
	0x92,
	0xd4,
	0xa1,
	0xa2,
	0xa2,
	0xa2,
	0xc1,
	0xc4,
	0x92,
	0x92
};

const unsigned char flag13[]={
	0x92,
	0xa4,
	0xb2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xb1,
	0xb4,
	0x92
};

const unsigned char flag14[]={
	0x92,
	0x86,
	0x83,
	0x97,
	0xb5,
	0x92,
	0xa5,
	0x87,
	0x83,
	0x96,
	0x92
};

const unsigned char flag15[]={
	0x92,
	0x83,
	0x83,
	0xb5,
	0x92,
	0x92,
	0x92,
	0xa5,
	0x83,
	0x83,
	0x92
};

const unsigned char flag16[]={
	0x92,
	0x93,
	0x93,
	0x92,
	0x92,
	0x92,
	0x92,
	0x92,
	0x93,
	0x93,
	0x92
};

const unsigned char flag17[]={
	0x92,
	0x93,
	0x93,
	0xb6,
	0x92,
	0x92,
	0x92,
	0xa6,
	0x93,
	0x93,
	0x92
};

const unsigned char flag18[]={
	0x92,
	0xa2,
	0xa2,
	0xb1,
	0xb6,
	0x92,
	0xa4,
	0xb2,
	0xa2,
	0xa2,
	0x92
};

const unsigned char flag19[]={
	0x92,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0xa2,
	0x92
};

const unsigned char flag20[]={
	0x92,
	0x87,
	0x83,
	0x83,
	0x83,
	0x83,
	0x83,
	0x83,
	0x83,
	0x97,
	0x92
};

const unsigned char flag21[]={
	0x92,
	0xa5,
	0x87,
	0x83,
	0x83,
	0x83,
	0x83,
	0x83,
	0x97,
	0xb5,
	0x92
};

const unsigned char flag22[]={
0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92
};

const unsigned char flag23[]={
0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92
};

const unsigned char * flag_segments[]={
flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8,flag9,flag10,flag11,flag12,flag13,flag14,flag15,flag16,flag17,flag18,flag19,flag20,flag21,flag22,flag23
};

char current_flag[11];
char flag_memory[13];

//global variable
int address;
int j;
int k;
int l;

char ntx = 0;
char nty = 26;
char current_letter = 0;
char next_timer = 0;
char current_message = 0;
const unsigned char empty[] = "                               ";
const unsigned char credits1[] = " NES DEMO BY ADRIAN09_01       ";
const unsigned char credits2[] = " POEM BY KEVIN DEGIDEN         ";
const unsigned char credits3[] = " MUSIC BY OWL CITY/ADAM YOUNG  ";
const unsigned char credits4[] = " FOR NES SPECTRUM MARATHON '20 ";
const unsigned char fellow[]   = " (AN AUTISTIC SPECTRUM FELLOW) ";
const unsigned char separator[]= " ----------------------------- ";
const unsigned char message1[] = " I AM AUTISTIC I PROCLAIM.     ";
const unsigned char message2[] = " AND I SAY IT WITH NO SHAME,   ";
const unsigned char message3[] = " FOR I WASN%T MEANT TO BE THE  ";
const unsigned char message4[] = " SAME.                         ";
const unsigned char message5[] = " I%M NOT AN ACCIDENT OF NATURE ";
const unsigned char message6[] = " BUT THE HANDIWORK OF A LOVING ";
const unsigned char message7[] = " CREATOR.                      ";
const unsigned char message8[] = " MADE FOR A CAUSE WITH FRESH   ";
const unsigned char message9[] = " EYES TO SEE,                  ";
const unsigned char message10[] =" ALL WONDERS THAT THIS WORLD   ";
const unsigned char message11[] =" COULD BE.                     ";
const unsigned char message12[] =" TO LOOK UPON CONVENTION NOT   ";
const unsigned char message13[] =" WITH DEFIANCE,                ";
const unsigned char message14[] =" BUT SIMPLY IGNORE ITS MERE    ";
const unsigned char message15[] =" EXISTENCE.                    ";
const unsigned char message16[] =" FOR IN ITS PREJUDICES FORM    ";
const unsigned char message17[] =" THE FEEDBACK LOOP OF VIOLENCE ";
const unsigned char message18[] =" AND DEPRAVITY,                ";
const unsigned char message19[] =" BREAK LOOSE FOR FREEDOM,      ";
const unsigned char message20[] =" PROGRESS AND HUMANITY.        ";
const unsigned char message21[] =" TO TEACH TO TRUE MEANING OF   ";
const unsigned char message22[] =" CIVIC SOCIETY.                ";
const unsigned char message23[] =" FOR MY DIFFERENT EMPATHY DOTH ";
const unsigned char message24[] =" SURMISE,                      ";
const unsigned char message25[] =" SEES NO COLOR, SHAPE OR SIZE, ";
const unsigned char message26[] =" ONLY LOVE OF LIFE AS THE      ";
const unsigned char message27[] =" GREAT PRIZE.                  ";
const unsigned char message28[] =" FOR ALL EXISTENCE STUDY AND   ";
const unsigned char message29[] =" TRAVERSE,                     ";
const unsigned char message30[] =" HIDDEN STRINGS THAT BIND OUR  ";
const unsigned char message31[] =" UNIVERSE,                     ";
const unsigned char message32[] =" TO SOLVE MAN%S PERILS AT      ";
const unsigned char message33[] =" THEIR WORST.                  ";
const unsigned char message34[] =" GO FORTH AND MEND OUR WORLD   ";
const unsigned char message35[] =" SO TORN,                      ";
const unsigned char message36[] =" SING PRAISE FOR ALL BLESSED   ";
const unsigned char message37[] =" BORN,                         ";
const unsigned char message38[] =" AS INNOVATORS NONCONFORMED.   ";
const unsigned char greetz1[] =  " GREETZ TO:                    ";
const unsigned char greetz2[] =  " @PINOBATCH, @DOUGEFF / NESDEV ";
const unsigned char greetz3[] =  " @DENINE,@NORILL/POLISH NESDEV ";
const unsigned char greetz4[] =  " REST OF THE NESDEV COMMUNITY  ";
const unsigned char greetz5[] =  " THE FAMITRACKER COMMUNITY     ";
const unsigned char greetz6[] =  " ALL NEURODIVERSE PEOPLE       ";
const unsigned char greetz7[] =  " KEVIN HANLEY/@ATONOFGLACIERS  ";
const unsigned char greetz8[] =  " EVERYONE WATCHING THIS STREAM ";
const unsigned char greetz9[] =  " AND FINALLY, YOU!!!           ";
unsigned char temp_message[] = "                               ";
const unsigned char * messages[] = {credits1, fellow, credits2, fellow, credits3, fellow, credits4, separator, message1, message2, message3, message4, message5, message6, message7, message8, message9, message10, message11,
message12, message13, message14, message15, message16, message17, message18, message19, message20, message21, message22, message23, message24, message25, message26, message27, message28, message29, message30, message31,
message32, message33, message34, message35, message36, message37, message38, separator, greetz1, greetz2, greetz3, greetz4, greetz5, greetz6, greetz7, greetz8, greetz9, separator, credits1};

char temp;
char sfx_table[] = {0, 2, 1};
char sfx;

char wavey[] = {1,1,2,2,2,2,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,1,1};

const unsigned char palette[16]={ 0x21,0x06,0x16,0x26,0x21,0x15,0x26,0x30,0x21,0x37,0x29,0x30,0x21,0x21,0x14,0x30 };

char clearcount = 0;
char hascleared = 0;

	

void main (void) {
	
	ppu_off(); // screen off
	music_play(0);
	pal_bg(palette); //	load the BG palette
	
	vram_adr(NAMETABLE_A);
	vram_unrle(nesspect);
	
	ppu_on_all();
	
	while (1){
		
		i = i + 1;
		l = l + 1;
		
		flag_memory[0] = 0x00;
		flag_memory[1] = 0x92;
		flag_memory[12] = 0x00;
		for (j = 1; j < 11; ++j)
		{
			flag_memory[j+1] = flag_segments[i-1][j];
		};
		
		clearcount = clearcount + 1;
		
		if (clearcount >= 5) {
		if (current_letter > 30) {
		if (current_message > 0) {
		  ppu_wait_nmi(); // waits till nmi, and push new updates to the ppu
		  clear_vram_buffer(); // clear the buffer at the start of each frame
		  multi_vram_buffer_horz(messages[current_message], 30, NTADR_A(0,26)); // pushes 12 bytes, horz	
		  multi_vram_buffer_horz(empty, 30, NTADR_A(0,27)); // pushes 12 bytes, horz	
		  ntx = 0;
		  current_message = current_message + 1;
		  if (current_message > 57) {
			  current_message = 1;
		  }
		  current_letter = 0;
		}
		if (current_message == 0) {
		nty = nty+1;
		ntx = 0;
		current_message = current_message + 1;
		current_letter = 0;
		}
		}
		if (current_letter < 31) {
		next_timer = next_timer + 1;
		sfx = rand8() % 3;
		if (next_timer > 1) {
		if (messages[current_message][current_letter] != 0x20) {
			sfx_play(sfx_table[sfx], 0);
		}
		one_vram_buffer(messages[current_message][current_letter], NTADR_A(ntx,nty)); // pushes 1 byte worth of data to the vram_buffer
		current_letter = current_letter + 1;
		ntx = ntx+1;
		next_timer = 0;
		}
		}
		//NMI every 3rd line
		// we've done 51 bytes of transfer to the ppu in 1 v-blank
		
		// do not try to push much more than 30 non-sequential or 70 sequential bytes at once
		
		ppu_wait_nmi(); // waits till nmi, and push new updates to the ppu
		
		clear_vram_buffer(); // clear the buffer at the start of each frame
		
				ppu_wait_nmi(); // wait
		
		// now fill the vram_buffer
		
		set_vram_buffer(); // points ppu update to vram_buffer, do this at least once
		
		clear_vram_buffer(); // resets the index to zero, to start filling the buffer
							 // do this at the beginning of every frame
		
		clearcount = 0;
		}
		
		multi_vram_buffer_vert(flag_memory, sizeof(flag_memory), NTADR_A(5+i,2+wavey[i+l])); // vertical
		
		if (i > 22) {
			i = 0;
		}
		if (l > 21) {
			l = 0;
		}
		
	}
}
	
	