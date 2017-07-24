#define MAX 6
int mensaje[MAX];
int cont,b;
int w,v,W,V;

void obtener_valores();
int checksum();
void actualizar();
//int reloj;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
}

void loop(){
  // t your main code here, to run repeatedly:
  
   
    if(Serial.available()>0)
    {
      
      if( Serial.read()==255)
        {
          obtener_valores();
          if(checksum()==1)
             actualizar();
          else{
             Serial.write("\n");
             Serial.write("Error en al transmision");
          }
        
      }
    }
 
    //if(Serial.read()=255 && Serial.read()==1)//paquete de velocidad
      // 
                
      //       
     

}

void obtener_valores()
{
  int i;
    //Serial.print("\n");
   //reloj= micros();
    for(i=0;i<MAX;i++)
     {
      delay(2);
      mensaje[i]=Serial.read();
      
      //Serial.print(mensaje[i]);
     }
     //reloj=micros()-reloj;
   //Serial.println(reloj);
}
int checksum()
  {
    int V,W,check;
    v=(mensaje[2]<<4)+mensaje[1];
    w=(mensaje[4]<<4)+mensaje[3];
    
    if(lowByte(v+w)==mensaje[5])
     {
         check=1;
     }
    else
     {
         check=0;
     }
     return check;
  }
void actualizar()
 {
   W=w;
   V=v;
   Serial.print("\n");
   Serial.print(W);
   Serial.print(" ");
   Serial.print(V);
   
 }
 

