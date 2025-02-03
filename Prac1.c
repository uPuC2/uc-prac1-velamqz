/******************************************************************************
Examples code
*******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
/*
  Ejercicios de enmascaramientos.
  Lo que se busca es que imprima el valor que esta comentado,
  alterando unicamente el valor anterior utilizando los operadores bitwise.
  Todas las conversiones deberian ser posibles con una sola operacion
*/
int main()
{
    uint16_t a = 0;
    printf("\na = %X", a);
//  Como ejemplo se da el analisis de la primera operacion

//1 B0B0
//       hex           bin
//  a =  0000 = 0000 0000 0000 0000  (valor original)
//       B0B0 = 1011 0000 1011 0000  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//     0000 0000 0000 0000  (valor original)
// OR  1011 0000 1011 0000  (mascara para lograrlo) = (1<<15) | (3<<12) | (1<<7) | (3<<4)
//------------------------------------------------
//     1011 0000 1011 0000  (valor que se desea)
    a |= (1<<15) | (3<<12) | (1<<7) | (3<<4);
    printf("\n1 = %X", a);
    
//2 BABA
//     1011 0000 1011 0000  (valor original)
// OR  0000 1010 0000 1010  (mascara para lograrlo)
//     1011 1010 1011 1010  (valor que se desea)
    a |= (1<<11) | (1<<9) | (1<<3) | (1<<1);
    printf("\n2 = %X", a);
  
//3 BEBE
//     1011 1010 1011 1010  (valor original)
// OR  0000 0110 0000 0110  (mascara para lograrlo)
//     1011 1110 1011 1110  (valor que se desea)
    a |= (3<<10) | (3<<2);
    printf("\n3 = %X", a);
  
//4 FE00
//     1011 1110 1011 1110  (valor original)
// XOR 0100 0000 1011 1110  (mascara para lograrlo)
//     1111 1110 0000 0000  (valor que se desea)
    a ^= (3<<4) ^ (14<<0) ^ (1<<14) ^ (1<<7) ;
    printf("\n4 = %X", a);
  
//5 FEAA
//     1111 1110 0000 0000  (valor original)
// OR  1011 0000 1011 0000  (mascara para lograrlo)
//     1111 1110 1010 1010  (valor que se desea)
    a |= (1<<7) | (1<<5) | (1<<3) | (1<<1);
    printf("\n5 = %X", a);
  
//6 0155
//     1111 1110 1010 1010  (valor original)
// OR  1011 0000 1011 0000  (mascara para lograrlo)
//     0000 0001 0101 0101  (valor que se desea)
    a ^= (0xFFFF);
    printf("\n6 = %X", a);
  
//7 0001
//     0000 0001 0101 0101  (valor original)
// OR  1011 0000 1011 0000  (mascara para lograrlo)
//     0000 0000 0000 0001  (valor que se desea)
    a ^= (0x0154);
    printf("\n7 = %X", a);
  
//8 0100
//     0000 0000 0000 0001  (valor original)
// OR  1011 0000 1011 0000  (mascara para lograrlo)
//     0000 0001 0000 0000  (valor que se desea)
    a ^= 0x0101;
    printf("\n8 = %X", a);

    return 0;
}







