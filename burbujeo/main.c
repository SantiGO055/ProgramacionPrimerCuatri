#include <stdio.h>
#include <stdlib.h>
#define CANT 5
int main()
{
    int pts[CANT]={1,0,3,3,1};
    int auxPts;
    int difg[CANT]={8,10,5,3,4};
    int auxDg;
    int i,j;
    for (i=0;i<CANT-1;i++){
        for(j=i+1;j<CANT;j++){
        if(pts[i]<pts[j]){
            auxPts=pts[i];
            pts[i]=pts[j];
            pts[j]=auxPts;
            auxDg=difg[i];
            difg[i]=difg[j];
            difg[j]=auxDg;
            }
        else {
            if(pts[i]==pts[j]){ //recien aca se va a preguntar por el segundo array que contiene diferencia de goles
                if(difg[i]<difg[j]){
                    auxDg=difg[i];
                    difg[i]=difg[j];
                    difg[j]=auxDg;
                    }
                }
            }
        }
    }
    for(i=0;i<CANT;i++){
        printf("Puntos: %d Diferencia de goles: %d\n", pts[i],difg[i]);
    }

    return 0;
}
