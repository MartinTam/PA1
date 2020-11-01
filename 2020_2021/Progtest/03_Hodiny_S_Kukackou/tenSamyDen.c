#include <stdio.h>

int main(){

  int h1=12, min1=0,
      h2=12, min2=0;

  int kukani = 0;


  int firstHour = h1;
  int secondHour = h2;
  int firstMinute = min1;
  int secondMinute = min2;

  int i;

  while (firstHour <= secondHour){

            if (firstHour == secondHour){
              for (i=firstMinute; i <= secondMinute; i++){

                        if (i == 0){

                                  if (firstHour > 12){
                                    kukani += (firstHour - 12);
                                  };
                                  if (firstHour <= 12){
                                    kukani += (firstHour);
                                  };
                                  if (firstHour == 0){
                                    kukani += 12;
                                  };
                        };

                        if (i == 30){
                          kukani += 1;
                        };
                };
                break;
            };



            for (i=firstMinute; i < 59; i++){

                      if (i == 0){

                                if (firstHour > 12){
                                  kukani += (firstHour - 12);
                                };
                                if (firstHour <= 12){
                                  kukani += (firstHour);
                                };
                                if (firstHour == 0){
                                  kukani += 12;
                                };
                      };

                      if (i == 30){
                        kukani += 1;
                      };
            };
            firstMinute = 0;
            firstHour++;

  };


  printf("Kukani = %d\n", kukani);


  return 0;
}
