  #include<stdio.h> 
  #include<conio.h> 
  #include<stdlib.h> 
  #include<time.h> 
  #include<locale.h>
  
   
  struct yilan{ 
         int x,y;
  }; 
  
  int len=1; 
  int bulundu=0; 
  int col=6,row=9; 
  char map[12][12];
  int tamammi_devammi(struct yilan snake[]){ 
      int i,k1=0,k2=0;
      if(snake[0].y>=11 || snake[0].y<=0 || snake[0].x>=11 || snake[0].x<=0 ){
      	k1=1;
}	  
      for(i=1;i<len;i++){ 
         if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y){ 
             k2=1; 
             break; 
         } 
      } 
      if(k1==1||k2==1) return 1; 
      else return 0; 
  } 
  
           
  void yemleme(){  	   
       srand(time(NULL)); 
       row=rand()%10+1; 
       col=rand()%10+1; }
   
  void yem(char dizi[12][12],struct yilan snake[]){ 
       if(snake[len-1].x==row&&snake[len-1].y==col){ 
                     snake[len].x=row; 
                     snake[len].y=col;
                     bulundu++;
                     yemleme(); }
                  		     
                           
  } 
  void duvar(char dizi[12][12]){ 
       int i,j; 
       for(i=0;i<12;i++){ 
          if(i==0||i==11){ 
              for(j=0;j<12;j++){ 
                  dizi[i][j]='-'; 
              } 
          } 
          else{ 
               dizi[i][0]='|'; 
               for(j=1;j<11;j++){ 
                   dizi[i][j]='.'; 
               } 
               dizi[i][11]='|'; 
          } 
           
       } 
       map[row][col]='*'; 
  } 
  void ciz(char dizi[12][12]){ 
       system("CLS"); 
       printf("Yilan Oyununa Hosgeldiniz,hareket icin wasd tuslarini kullaniniz.\n"); 
       int i,j;
	   char k; 
       for(i=0;i<12;i++){ 
          for(j=0;j<12;j++){ 
              printf("%c",dizi[i][j]); 
          } 
          printf("\n"); 
       } 
      
  } 
  void baslangic(struct yilan yil[]){ 
       yil[0].x=1; 
       yil[0].y=2; 
      
  }
  void yilan (char dizi[12][12],struct yilan yil[]){ 
       yem(map,yil); 
       int i; 
       for(i=0;i<len;i++){ 
           dizi[yil[i].x][yil[i].y]='X'; 
       } 
  } 
  void sag(struct yilan snake[],int uzunluk){ 
       int i; 
       for(i=uzunluk-1;i>0;i--){ 
               snake[i].x=snake[i-1].x; 
               snake[i].y=snake[i-1].y; 
               } 
               snake[0].y++;  
  } 
  void sol(struct yilan snake[],int uzunluk){ 
       int i; 
       for(i=uzunluk-1;i>0;i--){ 
               snake[i].x=snake[i-1].x; 
               snake[i].y=snake[i-1].y; 
               } 
               snake[0].y--;  
  }  
  void yukari(struct yilan snake[],int uzunluk){ 
       int i; 
       for(i=uzunluk-1;i>0;i--){ 
               snake[i].x=snake[i-1].x; 
               snake[i].y=snake[i-1].y; 
               } 
               snake[0].x--;  
  }  
  void asagi(struct yilan snake[],int uzunluk){ 
       int i; 
       for(i=uzunluk-1;i>0;i--){ 
               snake[i].x=snake[i-1].x; 
               snake[i].y=snake[i-1].y; 
       } 
        snake[0].x++;  
   
  } 
          
        
   
   
  int main(){ 
      int carpma=0;
      setlocale(LC_ALL,"Turkish");
      time_t start,end; 
      time (&start);
      double dif;      
      char right='d'; 
      char left='a'; 
      char up='w'; 
      char down='s'; 
      char yon; 
      long i; 
      int kontrol=0;
      struct yilan snake[100];        
	  duvar(map); 
      baslangic(snake); 
      yilan(map,snake); 
      ciz(map);	  
	   
      while(yon!='Q' && yon!='q'){   
      	  yon=getch();
          i=0;        
          if(yon==right){ 
            while(i<10){ 
             if(i%2000==0){ 
              if(tamammi_devammi(snake)){ 
                   ciz(map); 
                   kontrol=1; 
                   break; 
               } 
                            
               sag(snake,len); 
               duvar(map); 
               yilan(map,snake); 
               ciz(map); 
             } 
             i++; 
             if(kbhit()) break; 
            } 
              
          }  
          else if(yon==left){ 
            while(i<10){ 
             if(i%2000==0){ 
              if(tamammi_devammi(snake)){ 
                   ciz(map); 
                   kontrol=1; 
                   break; 
               } 
               sol(snake,len); 
               duvar(map); 
               yilan(map,snake); 
               ciz(map); 
             } 
             i++; 
             if(kbhit()) break; 
            }            
          } 
          else if(yon==up){ 
            while(i<10){ 
             if(i%2000==0){ 
              if(tamammi_devammi(snake)){ 
                   ciz(map); 
                   kontrol=1; 
                   break; 
               } 
               yukari(snake,len); 
               duvar(map); 
               yilan(map,snake); 
               ciz(map); 
               } 
             i++; 
             if(kbhit()) break; 
            }    
          } 
          else if(yon==down){ 
            while(i<10){ 
             if(i%2000==0){ 
               if(tamammi_devammi(snake)){ 
                   ciz(map); 
                   kontrol=1; 
                   break; 
               } 
               asagi(snake,len); 
               duvar(map); 
               yilan(map,snake); 
               ciz(map);  
               } 
             i++; 
             if(kbhit()) break; 
            }   
          }
          printf("\n\n%c",yon);
          if(bulundu!=0){
          	printf("\n\nTebrikler Kazandýnýz!");
          	break;  
		  }		  
          if(kontrol==1){
          	  carpma=carpma+1;   			
			 }
		  if(carpma==3){
		  	printf("\n\n Baþarýsýz üç hakkýnýzý tamamladýnýz!");
		  	break;
		  }
		  time (&end); 
          dif = difftime (end,start); 
		  if(dif>=120){
		  	printf("\n\nSize verilen sürede oyunu tamamlayamadýnýz!");
		  	break;
		  }    

} }  
	 

 

  
