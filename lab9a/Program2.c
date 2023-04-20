#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SAFETY 2
#define FG 3
#define TD 6
#define TDEP 7
#define TDC 8

void print_combs(int tdc,int tdep, int td,int fg,int safety){
	printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", tdc, tdep, td, fg, safety);

}

void score_combs( int score){
	for( int safety = 0; safety <= score/SAFETY; safety++){
		for( int fg = 0; fg <= score/FG; fg++){
			for( int td = 0; td <= score/TD; td++){
				for( int tdep= 0; tdep <= score/TDEP; tdep++){
					for( int tdc = 0; tdc <= score/TDC; tdc++){
						if ( tdc*TDC + tdep*TDEP + td*TD + fg*FG + safety*SAFETY  == score){
							print_combs(tdc, tdep, td, fg, safety);
						}

					}
				}
			}

		}
	}
}
main(){
	int score;
	bool yayFootball = true;
	while(yayFootball == true){
		printf("Please enter a score: ");
		scanf("%d", &score);

		if( score <=1){
			printf("Goodbye");
			yayFootball = false;
	}
		else{
			score_combs(score);

	}
	}


	return 0;

}

