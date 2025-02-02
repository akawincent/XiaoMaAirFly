#include "viewer.h"

#define OLED_CMD  0
#define OLED_DATA 1


const unsigned char F6x8[][6] =		
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H
0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
0x00, 0x40, 0x40, 0x40, 0x40, 0x40,// _
0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// horiz lines
};


/**
		==== hardware function ====
*/
/**
	@brief soft iic start signal
	@param void
	
	@return void
*/
void soft_iic_start()
{
	gpio_iic_scl_set();
	gpio_iic_sda_set();
	gpio_iic_sda_reset();
	gpio_iic_scl_reset();
}

/**
	@brief soft iic stop signal
	@param void
	
	@return void
*/
void soft_iic_stop()
{
	gpio_iic_scl_set();
	gpio_iic_sda_reset();
	gpio_iic_sda_set();
}

/**
	@brief soft iic wait for ack signal
	@param void
	
	@return void
*/
void soft_iic_wait_ack()
{
	gpio_iic_scl_set();
	gpio_iic_scl_reset();
}

/**
	@brief soft iic write byte
	@param byte
	
	@return void
*/
void soft_iic_write_byte(uint8_t _Byte)
{
	uint8_t iter, bit ;
	gpio_iic_scl_reset();
	for(iter=0;iter<8;iter++)		
	{
		bit = _Byte;
		bit = bit & 0x80;
		if( bit == 0x80 ) gpio_iic_sda_set();
		else gpio_iic_sda_reset();
		_Byte = _Byte <<1;
		gpio_iic_scl_set();
		gpio_iic_scl_reset();
	}
}


/**
		==== oled function ====
*/
/**
	@brief write command to oled , device address is 0x78 , register address is 0x00
	@param byte
	
	@return void
*/
void oled_write_cmd(uint8_t _command)
{
  soft_iic_start();
  soft_iic_write_byte(0x78);
	soft_iic_wait_ack();	
  soft_iic_write_byte(0x00);
	soft_iic_wait_ack();	
  soft_iic_write_byte(_command); 
	soft_iic_wait_ack();	
  soft_iic_stop();
}

/**
	@brief write data to oled , device address is 0x78 , register address is 0x00
	@param byte
	
	@return void
*/
void oled_write_data(uint8_t _data)
{
  soft_iic_start();
  soft_iic_write_byte(0x78);
	soft_iic_wait_ack();	
  soft_iic_write_byte(0x40);
	soft_iic_wait_ack();	
  soft_iic_write_byte(_data); 
	soft_iic_wait_ack();	
  soft_iic_stop();
}

/*
	  ==== application ====
*/
/**
	@brief set configs to the oled
	@param void
	
	@return void
*/
void oled_set_config(void)
{ 	
	oled_write_cmd(0xAE);//--display off
	oled_write_cmd(0x02);//---set low column address
	oled_write_cmd(0x10);//---set high column address
	oled_write_cmd(0x40);//--set start line address  
	oled_write_cmd(0xB0);//--set page address
	oled_write_cmd(0x81); // contract control
	oled_write_cmd(0xFF);//--128   
	oled_write_cmd(0xA1);//set segment remap 
	oled_write_cmd(0xA6);//--normal / reverse
	oled_write_cmd(0xA8);//--set multiplex ratio(1 to 64)
	oled_write_cmd(0x3F);//--1/32 duty
	oled_write_cmd(0xC8);//Com scan direction
	oled_write_cmd(0xD3);//-set display offset
	oled_write_cmd(0x00);//
	oled_write_cmd(0xD5);//set osc division
	oled_write_cmd(0x80);//
	oled_write_cmd(0xD8);//set area color mode off
	oled_write_cmd(0x05);//
	oled_write_cmd(0xD9);//Set Pre-Charge Period
	oled_write_cmd(0xF1);//
	oled_write_cmd(0xDA);//set com pin configuartion
	oled_write_cmd(0x12);//
	oled_write_cmd(0xDB);//set Vcomh
	oled_write_cmd(0x30);//
	oled_write_cmd(0x8D);//set charge pump enable
	oled_write_cmd(0x14);//
	oled_write_cmd(0xAF);//--turn on oled panel
}  

/**
	@brief set configs to the oled
	@param void
	
	@return void
*/
void oled_set_pose(uint8_t _col, uint8_t _page) 
{ 
	oled_write_cmd(0xb0 + _page);
	oled_write_cmd(( 0x10| ((_col+2)&0xf0)>>4));
	oled_write_cmd(( (_col+2)&0x0f)); 
} 

/**
	@brief show single asscii char
	@param void
	
	@return void
*/
void oled_show_single_asscii(uint8_t _col, uint8_t _page, uint8_t _char)
{
	_char = _char - ' ';
	if(_col>127-6) _col=0;
	
	oled_set_pose(_col , _page);
	for(uint8_t iter=0 ; iter<6 ; iter++)
	oled_write_data(F6x8[_char][iter]);
}

/**
	@brief show strings in line
	@param void
	
	@return void
*/
void oled_show_multi_asscii(uint8_t _col , uint8_t _page , uint8_t* _ptr_data , uint8_t _len , uint8_t _speed)
{
	for(int iter = 0; iter<_len ; iter++)
	{
		oled_show_single_asscii(_col + iter*6 , _page , _ptr_data[iter]);
		delay_ms(_speed);
	}
}

/**
	@brief oled fill screen
	@param byte
	
	@return void
*/
void oled_fill_screen(uint8_t _fill_Data)
{
	unsigned char page , col ;
	for(page=0 ; page<8 ; page++)
	{
		oled_set_pose(0,page);
		for(col=0 ; col<128 ; col++) oled_write_data(_fill_Data);
	}
}

/**
	@brief oled show line by line
	@param void
	
	@return void
*/
void oled_show_line_by_line()
{
	uint8_t page , col;
	for(page = 0 ; page < 8 ; page++){
		oled_fill_screen(0x00);
		oled_set_pose(0,page);
		for(int n=0;n<128;n++)
		{
				oled_write_data(0xff);
				delay_ms(50);
		}
		delay_ms(500);
	}
}

void oled_show_start_info()
{
	oled_fill_screen(0x00);
	uint8_t data_0[] = "XiaoMaAirFly  -v0.1.2";
	oled_show_multi_asscii(0,0,data_0,21,10);
	
	uint8_t data_1[] = "  by MianZhi";
	oled_show_multi_asscii(0,1,data_1,12,10);
	
	uint8_t data_2[] = "  by Wincent";
	oled_show_multi_asscii(0,2,data_2,12,10);
	
	uint8_t data_4[] = "System init:";
	oled_show_multi_asscii(0,4,data_4,12,10);
	
	uint8_t data_6[] = "LOG:imu starting...";
	oled_show_multi_asscii(0,6,data_6,19,10);
	
	uint8_t data_7[] = "LOG:imu has init";
	oled_show_multi_asscii(0,7,data_7,16,5);
}


void oled_show_imu_data(void)
{
	oled_fill_screen(0x00);
	uint8_t data_0[] = "Calibration:";
	oled_show_multi_asscii(0,0,data_0,12,10);
	uint8_t data_1[] = " A:";
	oled_show_multi_asscii(0,1,data_1,3,10);
	uint8_t data_2[] = " G:";
	oled_show_multi_asscii(0,2,data_2,3,10);
}




