// A C++ Program to Implement a Calendar
// of an year
#include<bits/stdc++.h>
using namespace std;

/*A Function that returns the index of the day
of the date- day/month/year
For e.g-

Index	 Day
0		 Sunday
1		 Monday
2		 Tuesday
3		 Wednesday
4		 Thursday
5		 Friday
6		 Saturday*/
int dayNumber(int day, int month, int year)
{

	/*static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
					4, 6, 2, 4 };
	year -= month < 3;
	return ( year + year/4 - year/100 +
			year/400 + t[month-1] + day) % 7;*/
    if(month==1||month==2)
    year--;
   //k + 12.6m - o.2l - 2C + Y + IYl4l + lcl4l (mod 7
   int yp=(2.6*11-0.2);
   int c=year/100;
   int y=year%100;
   int ybyfour=y/4;
   int cbyfour=c/4;
   //cout<<c<<" "<<cbyfour<<" "<<y<<" "<<ybyfour<<"\n";
   int dayofjan=1+yp-2*c+y+ybyfour+cbyfour;
   if(dayofjan>=0)
   {
       dayofjan=dayofjan%7;
   }
   else 
   {
       dayofjan=7+dayofjan;
   }
   return dayofjan;
}

/*
A Function that returns the name of the month
with a given month number

Month Number	 Name
0			 January
1			 February
2			 March
3			 April
4			 May
5			 June
6			 July
7			 August
8			 September
9			 October
10			 November
11			 December */
string getMonthName(int monthNumber)
{
    monthNumber--;
	string months[] = {"January", "February", "March",
					"April", "May", "June",
					"July", "August", "September",
					"October", "November", "December"
					};

	return (months[monthNumber]);
}

/* A Function to return the number of days in
a month

Month Number	 Name	 Number of Days
0			 January	 31
1			 February 28 (non-leap) / 29 (leap)
2			 March	 31
3			 April	 30
4			 May		 31
5			 June	 30
6			 July	 31
7			 August	 31
8			 September 30
9			 October	 31
10			 November 30
11			 December 31

*/
int numberOfDays (int monthNumber, int year)
{
	// January
    monthNumber--;
	if (monthNumber == 0)
		return (31);

	// February
	if (monthNumber == 1)
	{
		// If the year is leap then February has
		// 29 days
		if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}

	// March
	if (monthNumber == 2)
		return (31);

	// April
	if (monthNumber == 3)
		return (30);

	// May
	if (monthNumber == 4)
		return (31);

	// June
	if (monthNumber == 5)
		return (30);

	// July
	if (monthNumber == 6)
		return (31);

	// August
	if (monthNumber == 7)
		return (31);

	// September
	if (monthNumber == 8)
		return (30);

	// October
	if (monthNumber == 9)
		return (31);

	// November
	if (monthNumber == 10)
		return (30);

	// December
	if (monthNumber == 11)
		return (31);

        return -1;
}

// Function to print the calendar of the given year
void printCalendar(int year)
{
	printf ("		 Calendar - %d\n\n", year);
	int days;

	// Index of the day from 0 to 6
	int current = dayNumber (1, 1, year);
    cout<<current<<"\n";

	// i --> Iterate through all the months
	// j --> Iterate through all the days of the
	//	 month - i
	for (int i = 0; i < 12; i++)
	{
		days = numberOfDays (i+1, year);

		// Print the current month name
		printf("\n ------------%s-------------\n",
			getMonthName (i+1).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int k;
		for (k = 0; k<current; k++)
			printf("     ");
       
		for (int j = 1; j <= days; j++)
		{
            
          printf("%5d", j);

			if (++k > 6)
			{
				k = 0;
				printf("\n");
			}
		}

		if (k)
			printf("\n");

		current = k;
	}

	return;
}

// Driver Program to check above functions
int main()
{
	cout<<"ENTER THE YEAR WHOSE CALENDAR IS TO BE PRINTED"<<"\n";
	int year;
	cin>>year;
	printCalendar(year);

	return (0);
}

