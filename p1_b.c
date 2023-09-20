#include <stdio.h>

unsigned char ip[16][4] = {
    {10, 250, 1, 1},
    {150, 10, 15, 0},
    {192, 14, 2, 0},
    {148, 17, 9, 1},
    {193, 0, 0, 255},
    {220, 200, 23, 1},
    {177, 100, 18, 4},
    {95, 0, 21, 0},
    {111, 111, 111, 111},
    {219, 26, 51, 0},
    {167, 0, 0, 0},
    {240, 1, 1, 1},
    {10, 1, 1, 1},
    {225, 1, 1, 1}
};
unsigned char mascaraDeRed[4]={255,0,0,0};
unsigned char verificaBroadcast(unsigned char bitsDeHost);
unsigned char verificaRed(unsigned char bitsDeHost);
unsigned char clases[4] = {'A','B','C','D'};
unsigned char k;

int main(){

unsigned char bitsDeRed;
unsigned char i,j;
unsigned char flag = 1;
unsigned char flagClaseDoE=0;


    

for(k=0;k<16;k++){

for(i=0;i<4;i++){
    if(!(ip[k][0] & 128 >> i)){
        printf("La direccion ip: %d.%d.%d.%d es de clase: %c\n",ip[k][0],ip[k][1],ip[k][2],ip[k][3],clases[i]);
        
       if(clases[3])
            flagClaseDoE=1;

        for(j=0;j<=i;j++){
        mascaraDeRed[j]=255;
        }
        if(flagClaseDoE)
            printf("Y su mascara de red es:%d.%d.%d.%d\n",mascaraDeRed[0],mascaraDeRed[1],mascaraDeRed[2],mascaraDeRed[3]);
        flag = 0;
        bitsDeRed = 8*(i+1);
        break;
    }
}

if(flag){
    printf("La direccion ip: %d.%d.%d.%d es de clase E\n",ip[k][0],ip[k][1],ip[k][2],ip[k][3]);
    printf("Mascara de Subred No aplicable\n");
} 


//Ahora viendo si es una ip de broadcast, red o es un host

//Primero calcularemos el numero de bits de host dada una mascara de subred.
//Sabemos que el numero de bits en una ip es de 32bits = 4 bytes, luego bits de Host = 32 - bitsdeRed


unsigned char bitsDeHost = 32 - bitsDeRed;

printf("Bits de Host: %d\n",bitsDeHost);
//Suponiendo que sabemos que tenemos una red de clase C
//con mascara /28, los bits de red = 28



//Ahora, si la ip comienza con un 1, entonces podemos decir que es de broadcast, si no es de host
//porque como ya tuvo un 1, entonces no puede ser de red.

//Broadcast / host
if(!flagClaseDoE){
if(ip[k][3] & 1){

    if(verificaBroadcast(bitsDeHost))
        printf("La ip es de broadcast\n");
    else
        printf("La ip es un host\n");    
}
//Suponiendo que el elemento inicial es un cero, entonces podemos decir que es ip de red o host
else
    if(verificaRed(bitsDeHost))
        printf("La ip es de Red\n");
    else
        printf("la ip es un host\n");

    printf("La ip de red es:%d.%d.%d.%d\n",ip[k][0] & mascaraDeRed[0],ip[k][1] & mascaraDeRed[1],ip[k][2] & mascaraDeRed[2],ip[k][3] & mascaraDeRed[3]);
    printf("La ip de broadcast es:%d.%d.%d.%d\n",(unsigned char) (ip[k][0] | ~(mascaraDeRed[0])),(unsigned char) (ip[k][1] | ~(mascaraDeRed[1])),(unsigned char) (ip[k][2] | ~(mascaraDeRed[2])),(unsigned char) (ip[k][3] | ~(mascaraDeRed[3])));
    printf("El rango va desde: %d.%d.%d.%d\t",ip[k][0] & mascaraDeRed[0],ip[k][1] & mascaraDeRed[1],ip[k][2] & mascaraDeRed[2],1+(ip[k][3] & mascaraDeRed[3]));
    printf("hasta %d.%d.%d.%d\n",(unsigned char) (ip[k][0] | ~(mascaraDeRed[0])),(unsigned char) (ip[k][1] | ~(mascaraDeRed[1])),(unsigned char) (ip[k][2] | ~(mascaraDeRed[2])),(unsigned char) (ip[k][3] | ~(mascaraDeRed[3]))-1);
}
}
    return 0;

}

    
unsigned char verificaBroadcast(unsigned char bitsDeHost){

        unsigned char bitActual = 1;
        unsigned char byteActual = 3;
        unsigned char endByte = 0;
        unsigned char i;

        for(i=0;i<bitsDeHost;i++){

            //comprobamos si ya llego a 8 bits con endByte, si es el caso, reducir el byteActual
            // y resetear el bitActual a 1

            if(endByte>=8){
                bitActual = 1;
                byteActual--;
                endByte=0;
            }

            if(!(ip[k][byteActual] &(bitActual)) )
                    return 0;
            bitActual = bitActual << 1;
            endByte++;
        }

        return 1;
}



unsigned char verificaRed(unsigned char bitsDeHost){

        unsigned char bitActual = 1;
        unsigned char byteActual = 3;
        unsigned char endByte = 0;
        unsigned char i;

        for(i=0;i<bitsDeHost;i++){

            //comprobamos si ya llego a 8 bits con endByte, si es el caso, reducir el byteActual
            // y resetear el bitActual a 1

            if(endByte>=8){
                bitActual = 1;
                byteActual--;
                endByte=0;
            }

            if(ip[k][byteActual] &(bitActual) )
                    return 0;

            bitActual = bitActual << 1;
            endByte++;
        }

        return 1;
}

