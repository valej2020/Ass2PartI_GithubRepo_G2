#include "M5Atom.h"

void setup()
{
    M5.begin(true, false, true);
    delay(50);
    M5.dis.drawpix(0, 0xf00000);
}

uint8_t FSM = 0;

void loop()
{
    if (M5.Btn.wasPressed())
    { 

//      FSM++;
//        if (FSM >= 5)
//        {
//            FSM = 1;
//        }

        switch (FSM)
        {
        case 0:
            M5.dis.clear();
            break;
        case 1:
        
     while (1==1)

        {
            M5.dis.drawpix(0, 0x00f000);
            M5.dis.drawpix(1, 0x00f000);
            M5.dis.drawpix(2, 0x00f000);
            M5.dis.drawpix(3, 0x00f000);
            M5.dis.drawpix(4, 0x00f000);
            M5.dis.drawpix(5, 0x00f000);
            M5.dis.drawpix(6, 0x00f000);
            M5.dis.drawpix(7, 0x00f000);
            M5.dis.drawpix(8, 0x00f000);
            M5.dis.drawpix(9, 0x00f000);
            M5.dis.drawpix(10, 0x00f000);
            M5.dis.drawpix(11, 0x00f000);
            M5.dis.drawpix(12, 0x00f000);
            M5.dis.drawpix(13, 0x00f000);
            M5.dis.drawpix(14, 0x00f000);
            M5.dis.drawpix(15, 0x00f000);
            M5.dis.drawpix(16, 0x00f000);
            M5.dis.drawpix(17, 0x00f000);
            M5.dis.drawpix(18, 0x00f000);
            M5.dis.drawpix(19, 0x00f000);
            M5.dis.drawpix(20, 0x00f000);
            M5.dis.drawpix(21, 0x00f000);
            M5.dis.drawpix(22, 0x00f000);
            M5.dis.drawpix(23, 0x00f000);
            M5.dis.drawpix(24, 0x00f000);
            M5.dis.drawpix(25, 0x00f000);
            delay(100);
            M5.dis.clear();
            delay(100);
            
        }
        break;
        case 2:
            M5.dis.clear();
  
            M5.dis.drawpix(0, 0x0000f0);
            break;
        case 3:
            M5.dis.drawpix(0, 0x707070);
            break;
        default:
            break;
        }
        FSM++;
        if (FSM >= 4)
        {
            FSM = 0;
        }
    }

    delay(50);
    M5.update();
}
