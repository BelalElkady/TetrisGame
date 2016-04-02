/****************util.h********************
** is aheader file to deal with register **
** or unsigned character                 **
** by / mahmoud mohamed aboyussf         **
******************************************/
///------------------------bit operations----------------------------------------

//get bit if 1 the result will be onlyy 1 if 0 the result will be 0
#define GetBit(reg,bitNo) ((reg&(0x01<<bitNo))>>bitNo)
//rotate the regBY THE BIT NO
#define rotate(reg,bitNo) ((reg<<bitNo)|(reg>>(8-bitNo)))
//clr bit at bitno
//#define Clrbit(reg,bitNo)  (reg&(rotate(0xFE,bitNo)))
#define Clrbit(reg,bitNo)  (reg&(~(1<<bitNo)))
// set bit no bitno
#define Setbit(reg,bitno) (reg|(0x01<<bitno))
//Toggle bit at bit no
#define Togglebit(reg,bitno) (reg^(0x01<<bitno))

//-------------------------register operation -------------------------------------

//set register
#define SetReg(reg) (reg=0xff)
//clr register
#define ClrReg(reg) (reg=0x00)
//Toggle rigster
#define Togreg(reg) (reg^=0xff)
//assign value to aregister
#define AssignReg(reg,val) (reg=val)
//--------------------------nibble operation----------------------------------------------
//get low nible value
#define getlow(reg) (reg&0x0f)
//get high nible
#define gethigh(reg) ((reg&0xf0)>>4)
//set low nibbles
#define setlow(reg) (reg|0x0f)
//set high nibble
#define sethigh(reg) (reg|0xf0)
//clr low nibble
#define clrlow(reg) (reg&0xf0)
//clr high nibble
#define clrhigh(reg) (reg&0x0f)
//toggle low nibble
#define togglelow(reg) (reg^0x0f)
//toggle low nibble
#define toggolehigh(reg) (reg^0xf0)
//assign value to low nibble
#define assignlow(reg,val) (reg=(reg&0x0f)|(val&0x0f))
//assign value to high nible
#define assignhigh(reg,val)()

#define ok 1
#define error 0
