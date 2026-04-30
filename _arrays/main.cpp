#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;


int main(void)
{

	/*
		NOTE
		
		this activity was given before functions were taught to us
		so i specifically didnt use functions to not "cheat" the learning
		process thats why the code is not modular and cramped in main.
	*/
	int day = 0;
	int week = 0;

	int day_counter = 1;
	int week_counter = 1;

	cout << "enter number of weeks > ";
	cin >> week;
	cout << "enter number of days per week > ";
	cin >> day;

	int sales_data[week][day] = {};


	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{ 
			cout << "week " << week_counter << " day " << day_counter << " > ";
			cin >> sales_data[i][j];
			day_counter++;
		}
		week_counter++;
		day_counter = 1;
	}


	cout << endl << "total sales per week" << endl;
	int weekly_sales = 0;
	week_counter = 1;
	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{ 
			weekly_sales += sales_data[i][j];
		}
		cout << "week " << week_counter << " sales: " << weekly_sales << endl;
		week_counter++;
		weekly_sales = 0;
	}


	cout << endl << "total sales per day" << endl;	
	int daily_sales = 0;
	day_counter = 1;
	for(int i = 0; i < day; i++) 
	{
		for(int j = 0; j < week; j++)
		{
			daily_sales += sales_data[j][i];
		}
		cout << "day " << day_counter << " total sales per week: " << daily_sales << endl;
		daily_sales = 0;
		day_counter++;
	}


	cout << endl << "total sales of all week" << endl;
	int total_weekly_sales = 0;
	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{ 
			total_weekly_sales += sales_data[i][j];
		}
	}
	cout << "total weekly sales: " << total_weekly_sales << endl;


	cout << endl << "average sales" << endl;
	int sales_data_size = week * day;
	int sales_average = total_weekly_sales / sales_data_size;
	cout << "average sales: " << sales_average << endl;
	

	int highest_sale = sales_data[0][0];
	int lowest_sale = sales_data[0][0];	
	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{
			if(sales_data[i][j] > highest_sale) 
			{
				highest_sale = sales_data[i][j];
			}

			if(sales_data[i][j] < lowest_sale) 
			{
				lowest_sale = sales_data[i][j];
			}
		}
	}

	cout << endl << "highest and lowest sale and its week and day" << endl;
	week_counter = 1;
	day_counter = 1;
	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{
			if(sales_data[i][j] == highest_sale) 
			{
				cout << "highest sale, week " << week_counter << " day " << day_counter << ": " << highest_sale << endl;
				break;
			}

			if(sales_data[i][j] == lowest_sale) 
			{
				cout << "lowest sale, week " << week_counter << " day " << day_counter << ": " << lowest_sale << endl;
				break;
			}
			day_counter++;
		}
		day_counter = 1;
		week_counter++;
	}


	weekly_sales = 0;
	int weekly_highest_sale = INT_MIN;
	int weekly_lowest_sale = INT_MAX;	
	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{ 
			weekly_sales += sales_data[i][j];
		}

		if(weekly_sales > weekly_highest_sale) 
		{
			weekly_highest_sale = weekly_sales;
		}

		if(weekly_sales < weekly_lowest_sale) 
		{
			weekly_lowest_sale = weekly_sales;
		}
		weekly_sales = 0;
	}

	cout << endl << "highest and lowest sale week" << endl;
	weekly_sales = 0;
	week_counter = 1;
	for(int i = 0; i < week; i++)
	{
		for(int j = 0; j < day; j++)
		{ 
			weekly_sales += sales_data[i][j];
		}
		
		if(weekly_sales == weekly_highest_sale) 
		{
			cout << "highest weekly sales, week " << week_counter << ": " << weekly_highest_sale << endl;
		}

		if(weekly_sales == weekly_lowest_sale) 
		{
			cout << "lowest weekly sales, week " << week_counter << ": " << weekly_lowest_sale << endl;
		}

		week_counter++;
		weekly_sales = 0;
	}

	
	cout << endl << "sales table" << endl;
	week_counter = 1;
	day_counter = 0;
	for(int j = 0; j < day + 1; j++)
	{
		if(j == 0)
		{
			cout << setfill(' ') << setw(12) << " ";
		}
		else 
		{
			cout << setfill(' ') << setw(12) << "day " << day_counter;
		}
		day_counter++;
	}
	cout << endl;
	for(int i = 0; i < week; i++)
	{		
		cout << setfill(' ') << setw(12) << "week " << week_counter;	
		week_counter++;
		for(int j = 0; j < day; j++)
		{
			cout << setfill(' ') << setw(12) << sales_data[i][j];
		}
		cout << endl;
	}

		
	cout << endl << "reverse sales table" << endl;
	week_counter = week;
	day_counter = day;
	for(int j = day + 1; j > 0 ; j--)
	{
		if(j == day + 1)
		{
			cout << setfill(' ') << setw(12) << " ";
		}
		else 
		{
			cout << setfill(' ') << setw(12) << "day " << day_counter + 1;
		}
		day_counter--;
	}
	cout << endl;
	for(int i = week - 1; i >= 0; i--)
	{		
		cout << setfill(' ') << setw(12) << "week " << week_counter;	
		week_counter--;
		for(int j = day - 1; j >= 0; j--)
		{
			cout << setfill(' ') << setw(12) << sales_data[i][j];
		}
		cout << endl;
	}
}
