#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>

   int a;
   int password[] = {1,2,3,4};
   int inputPassword[4];
   int index = 0;

   
   void showInput()
   {
      switch(a)
      {
        case 0b01111000:
         printf(lcd_putc,"0");
         printf(lcd_putc,"%d",index);
         inputPassword[index] = 0; 
         index++;
         break;
       
        
        case 0b00101000:
         printf(lcd_putc,"1");
         printf(lcd_putc,"%d",index);
         inputPassword[index] = 1;
         index++;
         break;
        
        case 0b01101000:
         printf(lcd_putc,"2");
         printf(lcd_putc,"%d",index);
         inputPassword[index] = 2;
         index++;
         break;
        
        case 0b10101000:
         printf(lcd_putc,"3");
         printf(lcd_putc,"%d",index);
         inputPassword[index] = 3;
         index++;
         break;
        
        case 0b00011000:
         printf(lcd_putc,"4");
         printf(lcd_putc,"%d",index);
         inputPassword[index] = 4;
         index++;
         break;
        
        case 0b01011000:
         printf(lcd_putc,"5");
         inputPassword[index] = 5;
         index++;
         break;
        
        case 0b10011000:
         printf(lcd_putc,"6");
         inputPassword[index] = 6;
         index++;
         break;
        
        case 0b00001000:
         printf(lcd_putc,"7");
         inputPassword[index] = 7;
         index++;
         break;
        
        case 0b01001000:
         printf(lcd_putc,"8");
         inputPassword[index] = 8;
         index++;
         break;
        
        case 0b10001000:
         printf(lcd_putc,"9");
         inputPassword[index] = 9;
         index++;
         break;
      }
      
   }
   
   int passwordControl(){
      
   for(int i = 0; i<4; i++)
   {
      if(inputPassword[i] == Password[i] )
      continue;
      else{
       printf(lcd_putc,"Sifre yanlis.");
       return 0;
      }
      
       
   }
   printf(lcd_putc,"/fSifre dogru.");
   return 1;
   }
   

void main()
{
   set_tris_b(0x00);
   set_tris_d(0xFF);
   lcd_init();
   

   while(TRUE)
   {
         
      

      while(input(pin_D3) == 0);
      delay_ms(20);
      a = input_d();
      showInput();
      while(input(pin_D3) == 1);
      delay_ms(20);
      
      if(index == 4)
      break;
      
   
 }
 
 passwordControl();

   
   
   

}
