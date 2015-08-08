#include <stdio.h>
#include <time.h>

void reset_doors(int* doors, int len) {
  int i;
  for(i=0;i<len;i++)
    doors[i]=0;
}
int main(int argc, char* argv[]) {
  int i;
  int prize_door;
  int select_door;
  int open_door;
  int stay_win;
  int switch_win;

  const int NDOOR=3;
  const int N=10000;
  int doors[NDOOR];
  reset_doors(doors, NDOOR);

  stay_win=0;
  switch_win=0;

  srand(time(NULL));
  
  printf("index\tprize\tselect\topen\n");
  for(i=0; i<N; i++) {
    reset_doors(doors, NDOOR);
    prize_door = rand() % NDOOR;
    doors[prize_door]++;
    select_door = rand() % NDOOR;
    if(doors[select_door]>0) { // selected door has prize
      do {
	open_door=rand() % NDOOR;
      } while (open_door == prize_door); // note ==
    } else {
      doors[select_door]++;
      for(open_door=0;open_door<NDOOR;open_door++) {
	if(!doors[open_door]) {
	  break;
	}
      }
    }
    printf("%d\t%d\t%d\t%d\n", i, select_door, prize_door, open_door);
    if(select_door==prize_door && prize_door==open_door) {
      printf("something went wrong");
      return(1);
    }
    if(select_door==prize_door) {
      stay_win++;
    } else {
      switch_win++;
    }
  }
  printf("# total games %d\n",N); 
  printf("# stay win %d (%2.1f%%)\n",stay_win, stay_win/(N+0.0)*100); 
  printf("# switch win %d (%2.1f%%)\n",switch_win, switch_win/(N+0.0)*100); 
  return(0);
}
