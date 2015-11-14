/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2)
{
	int i = 0, date1 = 0, date2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0;
	for (; dob1[i]!='\0' && dob2[i] != '\0'; i++)
	{
		if (dob1[i] == '\0' || dob1[i] == '\0')
			return -1;
		else if (dob1[i] == '-')
		{
			if (!((i == 2 || i == 5) && dob2[i] == '-'))
				return -1;
		}
		else if (!(dob1[i] - '0' >= 0 && dob1[i] - '0' <= 9) || !(dob2[i] - '0' >= 0 && dob2[i] - '0' <= 9))
			return -1;
	}
	for (i = 0; i < 10; i++)
	{
		
			if (i < 2)
			{
				date1 = date1 * 10 + (dob1[i] - '0');
				date2 = date2 * 10 + (dob2[i] - '0');
			}
			else if (i > 2 && i < 5)
			{
				month2 = month2 * 10 + (dob2[i] - '0');
				month1 = month1 * 10 + (dob1[i] - '0');
			}
			else if (i>5 && i < 10)
			{
				year1 = year1 * 10 + (dob1[i] - '0');
				year2 = year2 * 10 + (dob2[i] - '0');
			}
	}

	if (date1 > 31 || date2 > 31)
		return -1;
	if (month1 > 12 || month2 > 12)
		return -1;
	if ((month1 == 2 && year1 % 4 == 0) && date1 > 29)
		return -1;
	else if ((month1 == 2 && year1 % 4 != 0) && date1 > 28)
		return -1;
	if ((month2 == 2 && year2 % 4 == 0) && date2 > 29)
		return -1;
	else if ((month2 == 2 && year2 % 4 != 0) && date2 > 28)
		return -1;
		if (year1 > year2)
		{
			return 2;
		}
		else if (year1 == year2)
		{
			if (month1 > month2)
				return 2;
			else if (month1 < month2)
				return 1;
			else
			{
				if (date1>date2)
					return 2;
				else if (date1 == date2)
					return 0;
				else
					return 1;
			}
		}
		else if (year1 < year2)
			return 1;
	}