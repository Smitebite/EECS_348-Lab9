#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char months[12][12] = {"January", "February", "March", "April","May","June", "July","August","September", "October","November", "December"};
	float sales[12];
	FILE *fp;
	char tempsales[200];
	fp = fopen("Input.txt", "r");
	int lcv;
	printf("Monthly sales report 2022:\n");
	printf("\nMonth\tSales\n");
	for (lcv = 0; lcv < 12; lcv++)
	{
		fscanf(fp, "%s",tempsales);
		printf("\n%s  ",months[lcv]);

	printf("$%s", tempsales);
	float newsales = (float)atof(tempsales);
	sales[lcv] = newsales;
	}
	fclose(fp);

	printf("\n\nSales summary:\n");
	int minvalue = 0;
	float min = sales[0];
	int maxvalue = 0;
	float max = sales[0];
	float avgvalue = 0;
	for (lcv = 0; lcv < 12; lcv++){


		if (sales[lcv] < sales[lcv++]){
			minvalue = lcv;
			min = sales[lcv];
	}

}
	for (lcv = 0; lcv < 12; lcv++){

		if(sales[lcv++] < sales[lcv]){
			maxvalue = lcv;
			max = sales[lcv];
	}
}
	for (lcv = 0; lcv < 12; lcv++){

	avgvalue = avgvalue + sales[lcv];
	}

	float avg = avgvalue /12;
	printf("Minimum sales:  $");
	printf("%.2f  ",min);
	printf("(%s)\n",months[minvalue]);
	printf("Maximum sales:  $");
	printf("%.2f  ",max);
	printf("(%s)\n",months[maxvalue]);
	printf("Average sales:  $");
	printf("%.2f  \n\n",avg);


	for (lcv = 0; lcv < 7; lcv++){
		float SixMonthAvg = 0;
		for( int i = lcv; i < lcv+6; i++ ){
			SixMonthAvg += sales[i];

		}
		printf("%s - %s : $%.2f\n",months[lcv],months[lcv+5],SixMonthAvg/6);

	}

	printf("\nSales Report(Highest to Lowest): ");
	printf("\nMonth\t Sales\n");
	for (lcv = 0; lcv < 12; lcv++){

		float max = 0;
		int maxIndex = 0;

		for(int i= 0; i < 12; i++){
			if (sales[i] > max){
				max = sales[i];
				maxIndex = i;
				//printf("%.2f\n", sales[i]);
			}
		}



		printf("%s $%.2f\n",months[maxIndex], max);
		sales[maxIndex] = 0;


	}
	return 0;
}






